#ifndef CSVFILE_H
#define CSVFILE_H


#include "cell.h"
#include <string>
#include <vector>


class CsvFile {
    private:
        std::string filename;
        std::vector<std::string> column_names;

    public:
        CsvFile(std::string _filename);
        std::vector<std::string> ReadLines();
        std::vector<std::string> SplitColumns(std::string line);
        void InsertRow(std::vector<Cell> cells);
        void DeleteRowContaining(Cell cell);
        ~CsvFile();
};


#endif // CSVFILE_H
