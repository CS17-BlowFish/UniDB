#include "cell.h"

#include <string>
#include <vector>


Cell::Cell(std::string _column_name, std::string _value) {
    column_name = _column_name;
    value = _value;    
    column_number = -1;
}


Cell::Cell(std::string _column_name, std::string _value, int _column_number) {
    column_name = _column_name;
    value = _value;
    column_number = _column_number;
}


// Tested
void Cell::GetColumnNumber(std::vector<std::string> column_names) {
    for (int i = 0; i < (int) column_names.size(); i++) {
        if (column_name == column_names[i]) {
            column_number = i;
            break;
        }
    }
}


Cell::~Cell() {}