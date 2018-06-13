#ifndef CSVFILE_H
#define CSVFILE_H


#include "cell.h"
#include <string>
#include <vector>


class CsvFile {
    private:
        std::string filename;
        int num_columns = 0;
        std::vector<std::string> column_names;
        std::vector<int> has_quotes;

        std::string ReadFirstRow();
        void GetColumnNames();
        void CheckQuotes();
        std::vector<std::string> SplitCellValuesKeepQuotes(std::string row_string);
        std::vector<std::string> SplitCellValues(std::string row_string);
        std::string GenRowString(std::vector<Cell> cells);
        void WriteRowString(std::string row_string);
        void SortCellsByColumnNumber(std::vector<Cell> &row);

    public:
        CsvFile(std::string _filename);
        std::string ReadRowString(std::ifstream &infile);
        std::vector<std::string> ReadRowStrings();
        std::vector<Cell> SplitCells(std::string row_string);
        std::vector<std::vector<Cell> > ReadRows();
        void WriteRows(std::vector<std::vector<Cell> > rows);
        void WriteRowWithCells(std::vector<Cell> cells);
        void DeleteRowWithCell(Cell given_cell);
        void DeleteRowWithCells(std::vector<Cell> given_cells);
        void ChangeRowGivenCell(Cell given_cell, Cell final_cell);
        void ChangeRowGivenCells(std::vector<Cell> given_cells, Cell final_cell);
        ~CsvFile();
};


#endif // CSVFILE_H
