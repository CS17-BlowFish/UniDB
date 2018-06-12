#ifndef CELL_H
#define CELL_H

#include <string>
#include <vector>


class Cell {
    private:

    public:
        std::string column_name;
        std::string value;
        int column_number;

        Cell(std::string _column_name, std::string _value);
        Cell(std::string _column_name, std::string _value, int _column_num);
        // bool operator < (const &Cell other) const;
        void GetColumnNumber(std::vector<std::string> column_names);
        ~Cell();
};


#endif // CELL_H
