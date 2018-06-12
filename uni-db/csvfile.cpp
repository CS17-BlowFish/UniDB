#include "csvfile.h"

#include "cell.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>


// Tested
std::string CsvFile::ReadFirstRow() {
    std::ifstream infile(filename, std::ios::in);
    std::string first_row = ReadRowString(infile);
    infile.close();
    return first_row;
}


// Tested
void CsvFile::GetColumnNames() {
    std::string first_row = ReadFirstRow();
    column_names = SplitCellValues(first_row);
    num_columns = column_names.size();
}


// Tested
void CsvFile::CheckQuotes() {
    std::ifstream infile(filename, std::ios::in);
    ReadRowString(infile); // skip first row
    std::string sample_row = ReadRowString(infile);
    std::vector<std::string> cell_values_with_quotes = SplitCellValuesKeepQuotes(sample_row);
    for (std::string &cell_value : cell_values_with_quotes) {
        if (cell_value[0] == '\"') {
            has_quotes.push_back(1);
        }
        else {
            has_quotes.push_back(0);
        }
    }
}


// Tested
std::vector<std::string> CsvFile::SplitCellValuesKeepQuotes(std::string row_str) {
    std::vector<std::pair<int, int> > word_positions;

    int i = 0;
    int begin_position = 0;
    int end_position = 0;

    while (i < (int) row_str.length()) {
        // Any commas within quotation marks are ignored
        if (row_str[i] == '\"') {
            // Look for the second quote mark
            while (row_str[i + 1] != '\"') {
                i++;
            }
            end_position = i + 2;
            word_positions.emplace_back(begin_position, end_position);
            i += 3; // ignore second quote mark and comma
            begin_position = i;
        }
        else if (row_str[i] == ',') {
            end_position = i;
            word_positions.emplace_back(begin_position, end_position);
            i++;
            begin_position = i;
        }
        else {
            i++;
        }
    }

    if (row_str[row_str.length() - 1] != '\"') {
        word_positions.emplace_back(begin_position, row_str.length());
    }

    std::vector<std::string> cells;

    for (std::pair<int, int> &position : word_positions) {
        std::string token = row_str.substr(position.first, position.second - position.first);
        cells.emplace_back(token);
    }

    return cells;
}


// Tested
std::vector<std::string> CsvFile::SplitCellValues(std::string row_str) {
    std::vector<std::pair<int, int> > word_positions;

    int i = 0;
    int begin_position = 0;
    int end_position = 0;

    while (i < (int) row_str.length()) {
        // Any commas within quotation marks are ignored
        if (row_str[i] == '\"') {
            begin_position++;
            // Look for the second quote mark
            while (row_str[i + 1] != '\"') {
                i++;
            }
            end_position = i + 1;
            word_positions.emplace_back(begin_position, end_position);
            i += 3; // ignore second quote mark and comma
            begin_position = i;
        }
        else if (row_str[i] == ',') {
            end_position = i;
            word_positions.emplace_back(begin_position, end_position);
            i++;
            begin_position = i;
        }
        else {
            i++;
        }
    }

    if (row_str[row_str.length() - 1] != '\"') {
        word_positions.emplace_back(begin_position, row_str.length());
    }

    std::vector<std::string> cells;

    for (std::pair<int, int> &position : word_positions) {
        std::string token = row_str.substr(position.first, position.second - position.first);
        cells.emplace_back(token);
    }

    return cells;
}


// Tested
std::string CsvFile::GenRowString(std::vector<Cell> all_cells) {
    std::string csv_row = "";
    int num_cells = all_cells.size();

    for (int i = 0; i < num_cells; i++) {
        Cell cell = all_cells[i];

        if (has_quotes[i]) {
            csv_row += '\"' + cell.value + '\"';
        }
        else {
            csv_row += cell.value;
        }

        if (i != num_cells - 1) {
            csv_row += ',';
        }
    }

    return csv_row;
}


// Tested
void CsvFile::WriteRowString(std::string row_string) {
    std::ofstream outfile(filename, std::ios::out | std::ios::app);
    outfile << row_string << '\n';
}


// Tested
void CsvFile::SortCellsByColumnNumber(std::vector<Cell> &row) {
    std::sort(row.begin(), row.end(), [](Cell cell_a, Cell cell_b) {
        return cell_a.column_number < cell_b.column_number;
    });
}


// Tested
CsvFile::CsvFile(std::string _filename) {
    filename = _filename;
    GetColumnNames();
    CheckQuotes();
}


// Tested
std::string CsvFile::ReadRowString(std::ifstream &infile) {
    std::string row = "";
    while (!infile.eof() && infile.peek() != '\n') {
        row += infile.get();
    }
    infile.get(); // eliminate \n
    return row;
}


// Tested
std::vector<std::string> CsvFile::ReadRowStrings() {
    std::ifstream infile(filename, std::ios::in);
    std::vector<std::string> row_strings;
    ReadRowString(infile); // skip first row
    while (!infile.eof()) {
        std::string row_string = ReadRowString(infile);
        row_strings.emplace_back(row_string);
    }
    row_strings.pop_back(); // omit last row (1 empty character before EOF)
    infile.close();
    return row_strings;
}


// Tested
std::vector<Cell> CsvFile::SplitCells(std::string row_string) {
    std::vector<std::string> cell_values = SplitCellValues(row_string);

    std::vector<Cell> row;

    for (int column_number = 0; column_number < num_columns; column_number++) {
        row.emplace_back(column_names[column_number], cell_values[column_number], column_number);
    }

    return row;
}


// Tested
std::vector<std::vector<Cell> > CsvFile::ReadRows() {
    std::vector<std::string> row_strings = ReadRowStrings();

    std::vector<std::vector<Cell> > rows;

    for (std::string &row_string : row_strings) {
        rows.emplace_back(SplitCells(row_string));
    }

    return rows;
}


// Tested
void CsvFile::WriteRows(std::vector<std::vector<Cell> > rows) {
    std::string first_row = ReadFirstRow();
    std::ofstream outfile(filename, std::ios::out | std::ios::trunc);
    outfile << first_row << '\n';
    for (std::vector<Cell> &row : rows) {
        outfile << GenRowString(row) << '\n';
    }
    outfile.close();
}


// Tested
void CsvFile::WriteRowWithCells(std::vector<Cell> cells) {
    // Find the column numbers for cells that are being inserted
    for (Cell &cell : cells) {
        cell.GetColumnNumber(column_names);
    }

    // Mark the cells that are being inserted
    bool is_inserted[num_columns];
    std::fill(is_inserted, is_inserted + num_columns, false);
    for (Cell &cell : cells) {
        is_inserted[cell.column_number] = true;
    }

    // Generate empty cells for cells that are not being inserted
    for (int column_number = 0; column_number < num_columns; column_number++) {
        if (!is_inserted[column_number]) {
            cells.emplace_back("", "", column_number);
        }
    }

    // Sort the cells in order of cell number
    SortCellsByColumnNumber(cells);

    // Generate csv row
    std::string row_string = GenRowString(cells);

    // Insert the row to the end of file
    WriteRowString(row_string);
}


// Tested
void CsvFile::DeleteRowWithCell(Cell given_cell) {
    given_cell.GetColumnNumber(column_names);
    std::vector<std::vector<Cell> > rows = ReadRows();
    int num_rows = rows.size();
    bool to_delete[num_rows];
    std::fill(to_delete, to_delete + num_rows, true);
    for (int i = 0; i < (int) rows.size(); i++) {
        for (int j = 0; j < num_columns; j++) {
            Cell cell = rows[i][j];
            cell.GetColumnNumber(column_names);
        }
        SortCellsByColumnNumber(rows[i]);
        Cell cell_to_compare = rows[i][given_cell.column_number];
        if (cell_to_compare.value != given_cell.value) {
            to_delete[i] = false;
        }
    }
    std::vector<std::vector<Cell> > new_rows;
    for (int i = 0; i < num_rows; i++) {
        if (!to_delete[i]) {
            new_rows.emplace_back(rows[i]);
        }
    }
    WriteRows(new_rows);
}


// Tested
void CsvFile::DeleteRowWithCells(std::vector<Cell> given_cells) {
    for (Cell &given_cell : given_cells) {
        given_cell.GetColumnNumber(column_names);
    }
    std::vector<std::vector<Cell> > rows = ReadRows();
    int num_rows = rows.size();
    bool to_delete[num_rows];
    std::fill(to_delete, to_delete + num_rows, true);
    for (int i = 0; i < (int) rows.size(); i++) {
        for (int j = 0; j < num_columns; j++) {
            Cell cell = rows[i][j];
            cell.GetColumnNumber(column_names);
        }
        SortCellsByColumnNumber(rows[i]);
        for (Cell &given_cell : given_cells) {
            Cell cell_to_compare = rows[i][given_cell.column_number];
            if (cell_to_compare.value != given_cell.value) {
                to_delete[i] = false;
                break;
            }
        }
    }
    std::vector<std::vector<Cell> > new_rows;
    for (int i = 0; i < num_rows; i++) {
        if (!to_delete[i]) {
            new_rows.emplace_back(rows[i]);
        }
    }
    WriteRows(new_rows);
}


// TODO
void ChangeCellWithCell(Cell cell_to_change, Cell given_cell) {

}

// TODO
void ChangeCellWithCells(Cell cell_to_change, Cell given_cells) {
    
}

CsvFile::~CsvFile() {}
