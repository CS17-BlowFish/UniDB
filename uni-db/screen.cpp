#include "screen.h"

#include <algorithm>
#include <conio.h>
#include <iostream>
#include <iomanip>


void screen::Pad() {
    std::cout << std::setw(PAD_WIDTH) << "";
}


void screen::PadWidth(int width) {
    std::cout << std::setw(width) << "";
}


void screen::PadCommand() {
    std::cout << std::setw(PAD_WIDTH) << "";
    std::cout << ">> ";
}


void screen::Print(std::string s) {
    Pad();
    std::cout << s;
}


void screen::PrintLine(std::string s) {
    Pad();
    std::cout << s << '\n';
}


void screen::AddEmptyLines(int num_empty_lines) {
    for (int i = 0; i < num_empty_lines; i++) {
        std::cout << '\n';
    }
}


void screen::PrintTable(std::vector<std::string> headers, std::vector<std::vector<std::string> > table) {
    int num_rows = table.size();
    int num_columns = headers.size();
    int max_width[num_columns];

    for (int col = 0; col < num_columns; col++) {
        max_width[col] = headers[col].length();
    }

    for (int row = 0; row < num_rows; row++) {
        for (int col = 0; col < num_columns; col++) {
            max_width[col] = std::max(max_width[col], (int) table[row][col].length());
        }
    }

    int total_width = 0;

    for (int col = 0; col < num_columns; col++) {
        total_width += max_width[col];
    }

    total_width += num_columns + 1;

    for (int i = 0; i < total_width; i++) {
        std::cout << '_';
    }
    std::cout << '\n';

    for (int col = 0; col < num_columns; col++) {
        std::cout << '|';
        std::cout << std::setw(max_width[col]) << headers[col];
    }
    std::cout << "|\n";

    for (int i = 0; i < total_width; i++) {
        std::cout << '_';
    }

    for (int row = 0; row < num_rows; row++) {
        for (int col = 0; col < num_columns; col++) {
            std::cout << '|';
            std::cout << std::setw(max_width[col]) << table[row][col];
        }
        std::cout << "|\n";
    }

    for (int i = 0; i < total_width; i++) {
        std::cout << '_';
    }
    std::cout << '\n';
}


void screen::PrintTitle(std::string title) {
    int line_length = (MAX_TITLE_LENGTH - title.length()) / 2;
    for (int i = 0; i < line_length; i++) {
        std::cout << '=';
    }
    std::cout << title;
    for (int i = 0; i < line_length; i++) {
        std::cout << '=';
    }
    std::cout << "\n\n";
}


void screen::ErrorMessage(std::string message) {
    Pad();
    std::cout << "Error: ";
    std::cout << message;
    std::cout << " Please try again later.\n";
}


void screen::Pend() {
    Pad();
    std::cout << "Press any key to continue...";
    getch();
}


void screen::Clear() {
    system(CLEAR_SCREEN_CMD);
}
