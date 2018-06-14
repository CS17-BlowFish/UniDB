#include "db.h"
#include "cell.h"
#include "csvfile.h"
#include "io.h"

#include <unordered_map>
#include <sstream>
#include <string>
#include <vector>


/**
 *  @function SplitTableName
 *  @return {std::string}
 *
 *  Get the table name from the query
 *  Tested
**/
std::string SplitTableName(std::string &query_string) {
    std::string table_name = "";
    int pos = 3;  // skip keyword IN
    while (query_string[pos] != ' ') {
        table_name += query_string[pos];
        pos++;
    }
    query_string = query_string.substr(pos + 1);
    return table_name;
}


std::vector<std::string> SplitTokens(std::string s) {
    std::stringstream ss;
    ss << s;
    std::vector<std::string> tokens;
    std::string tmp;
    while (ss >> tmp) {
        tokens.push_back(tmp);
    }
    return tokens;
}


std::vector<std::vector<std::string> > SplitConditions(std::string &query_string) {
    int pos = 0;
    int start_pos = 0;
    int end_pos = 0;

    std::vector<std::pair<int, int> > condition_positions;

    while (pos < (int) query_string.length()) {
        if (query_string[pos] == '(') {
            start_pos = pos + 1;
            while (query_string[pos] != ')') {
                pos++;
            }
            end_pos = pos;
            condition_positions.emplace_back(start_pos, end_pos);
        }
        pos++;
    }

    std::vector<std::string> condition_strings;

    for (std::pair<int, int> &position : condition_positions) {
        int start_pos = position.first;
        int length = position.second - position.first;
        condition_strings.emplace_back(query_string.substr(start_pos, length));
    }

    std::vector<std::vector<std::string> > conditions;

    for (std::string &condition_string : condition_strings) {
        conditions.emplace_back(SplitTokens(condition_string));
    }

    return conditions;
}


inline std::string GenFileName(std::string table_name) {
    return "data/" + table_name + ".csv";
}


/**
 *  @function DeleteQuery
 *  @return {void}
 *
 *  Call a DELETE query
 *  DELETE query syntax:
 *  IN <table_name>
**/
void DeleteQuery(std::string query_string) {
    std::string table_name = SplitTableName(query_string);

    int condition_start_pos = query_string.find('(') + 1;
    int condition_length = query_string.find(')') - condition_start_pos;

    std::string condition = query_string.substr(condition_start_pos, condition_length);

    std::vector<std::string> tokens = SplitTokens(condition);
    std::string column_name = tokens[0];
    std::string value = tokens[2];

    Cell given_cell(column_name, value);
    CsvFile csvfile(GenFileName(table_name));
    csvfile.DeleteRowWithCell(given_cell);
}


/**
 *  @function InsertQuery
 *  @return {void}
 *
 *  Call a INSERT query
**/
void InsertQuery(std::string query_string) {
    std::string table_name = SplitTableName(query_string);

    std::vector<std::vector<std::string> > cell_insertions = SplitConditions(query_string);

    std::vector<Cell> cells;

    for (std::vector<std::string> &cell_insertion: cell_insertions) {
        std::string column_name = cell_insertion[0];
        std::string value = cell_insertion[2];
        cells.emplace_back(column_name, value);
    }

    CsvFile csvfile(GenFileName(table_name));

    csvfile.WriteRowWithCells(cells);
}


std::vector<std::string> SplitRequestColumns(std::string request) {
    IO io;
    std::vector<std::string> result;
    request = io.StripWhitespaces(request);
    int start_pos = 0;
    for (int i = 0; i < (int) request.length(); i++) {
        if (request[i] == ',') {
            std::string request_column = request.substr(start_pos, i - start_pos);
            result.emplace_back(request_column);
            start_pos = i + 1;
        }
    }
    return result;
}


/**
 *  @function SelectQuery
 *  @return {2d vector of string}
 *
 *  Call a SELECT query
 *  The outer vector contains the rows
 *  The inner vector contains the value of the cells of each row
**/
std::vector<std::vector<std::string> > SelectQuery(std::string query_string) {
    std::string table_name = SplitTableName(query_string);
    CsvFile csvfile(GenFileName(table_name));

    std::vector<std::vector<Cell> > table = csvfile.ReadRows();
    int num_rows = table.size();
    std::vector<std::string> column_names = csvfile.ColumnNames();

    int request_start_pos = query_string.find("SELECT") + 7;
    int request_end_pos = query_string.find("WHERE") - 1;
    std::string request_string
            = query_string.substr(request_start_pos, request_end_pos - request_start_pos);
    std::vector<std::string> request_columns;

    if (request_string.find('*')) {
        request_columns = column_names;
    }
    else {
        request_columns = SplitRequestColumns(request_string);
    }

    int conditions_start_pos = query_string.find("WHERE") + 6;
    int conditions_end_pos = query_string.length();
    std::string condition_string
            = query_string.substr(conditions_start_pos, conditions_end_pos - conditions_start_pos);

    std::vector<std::vector<std::string> > conditions = SplitConditions(condition_string);

    std::vector<Cell> condition_cells;

    for (std::vector<std::string> &condition : conditions) {
        condition_cells.emplace_back(condition[0], condition[2]);
    }

    for (Cell &cell : condition_cells) {
        cell.GetColumnNumber(column_names);
    }

    bool to_select[num_rows];
    std::fill(to_select, to_select + num_rows, true);

    for (int i = 0; i < num_rows; i++) {
        for (Cell &condition_cell : condition_cells) {
            Cell cell_to_compare = table[i][condition_cell.column_number];

            if (cell_to_compare.value != condition_cell.value) {
                to_select[i] = false;
                break;
            }
        }
    }

    std::vector<std::vector<std::string> > query_result;

    for (int i = 0; i < num_rows; i++) {
        if (to_select[i]) {
            std::vector<Cell> &row = table[i];

            std::unordered_map<std::string, std::string> dict;
            for (Cell &cell : row) {
                dict.emplace(cell.column_name, cell.value);
            }

            std::vector<std::string> row_selection;
            for (std::string &column_name : request_columns) {
                row_selection.emplace_back(dict[column_name]);
            }

            query_result.emplace_back(row_selection);
        }
    }

    return query_result;
}


std::vector<std::vector<std::string> > SearchQuery(std::string query_string) {
    std::string table_name = SplitTableName(query_string);
    CsvFile csvfile(GenFileName(table_name));

    std::vector<std::vector<Cell> > table = csvfile.ReadRows();
    int num_rows = table.size();
    std::vector<std::string> column_names = csvfile.ColumnNames();

    int request_start_pos = query_string.find("SEARCH") + 7;
    int request_end_pos = query_string.find("WHERE") - 1;
    std::string request_string
            = query_string.substr(request_start_pos, request_end_pos - request_start_pos);
    std::vector<std::string> request_columns;

    if (request_string.find('*')) {
        request_columns = column_names;
    }
    else {
        request_columns = SplitRequestColumns(request_string);
    }

    int condition_pos = query_string.find("WHERE") + 6;
    std::string condition_string = query_string.substr(condition_pos);
    std::vector<std::string> tokens = SplitTokens(condition_string);
    std::string search_column = tokens[0];
    std::string search_key = tokens[2];

    Cell search_cell(search_column, search_key);
    search_cell.GetColumnNumber(column_names);

    bool to_select[num_rows];
    std::fill(to_select, to_select + num_rows, true);

    for (int i = 0; i < num_rows; i++) {
        Cell cell_to_compare = table[i][search_cell.column_number];

        if (cell_to_compare.value.find(search_cell.value) == cell_to_compare.value.length()) {
            to_select[i] = false;
        }
    }

    std::vector<std::vector<std::string> > query_result;

    for (int i = 0; i < num_rows; i++) {
        if (to_select[i]) {
            std::vector<Cell> &row = table[i];

            std::unordered_map<std::string, std::string> dict;
            for (Cell &cell : row) {
                dict.emplace(cell.column_name, cell.value);
            }

            std::vector<std::string> row_selection;
            for (std::string &column_name : request_columns) {
                row_selection.emplace_back(dict[column_name]);
            }

            query_result.emplace_back(row_selection);
        }
    }

    return query_result;
}




/**
 *  @function SetQuery
 *  @return {void}
 *
 *  Call a SET query
**/
void SetQuery(std::string query_string) {
    std::string table_name = SplitTableName(query_string);

    int set_string_start_pos = query_string.find("SET") + 4;
    int set_string_end_pos = query_string.find("WHERE") - 1;

    std::string set_string = query_string.substr(set_string_start_pos, set_string_end_pos - set_string_start_pos);

    std::vector<std::vector<std::string> > set_requests = SplitConditions(set_string);

    std::vector<Cell> set_cells;

    for (std::vector<std::string> &set_request : set_requests) {
        set_cells.emplace_back(set_request[0], set_request[2]);
    }

    int conditions_start_pos = query_string.find("WHERE") + 6;
    int conditions_end_pos = query_string.length();
    std::string condition_string
            = query_string.substr(conditions_start_pos, conditions_end_pos - conditions_start_pos);

    std::vector<std::vector<std::string> > conditions = SplitConditions(condition_string);

    std::vector<Cell> condition_cells;

    for (std::vector<std::string> &condition : conditions) {
        condition_cells.emplace_back(condition[0], condition[2]);
    }

    CsvFile csvfile(GenFileName(table_name));

    for (Cell &set_cell : set_cells) {
        csvfile.ChangeRowGivenCells(condition_cells, set_cell);
    }
}
