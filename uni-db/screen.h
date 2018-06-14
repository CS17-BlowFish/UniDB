#ifndef SCREEN_H
#define SCREEN_H


#include <string>
#include <vector>


namespace screen {
    const int PAD_WIDTH = 5;
    const char CLEAR_SCREEN_CMD[] = "cls";
    const int MAX_TITLE_LENGTH = 60;

    void Pad();
    void PadWidth(int num_spaces);
    void PadCommand();
    void Print(std::string s);
    void PrintLine(std::string s);
    void AddEmptyLines(int num_empty_lines);
    void PrintTable(std::vector<std::string> headers, std::vector<std::vector<std::string> > table);
    void PrintTitle(std::string title);
    void ErrorMessage(std::string message);
    void PadCommand();
    void Pend();
    void Clear();
};


#endif // SCREEN_H
