#include "io.h"

#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>


/**
 *  Note: For input, try to use getline and stringstream for all functions
 *  Avoid cin since it will conflict with getline.
 *  For output, cout is OK.
 *
 *  This class is built by Trai
**/


bool io::IsUpperCaseLetter(char c) {
    if (isupper(c)) {
        return true;
    }
    return false;
}


bool io::IsLetter(char c) {
    if (isalpha(c)) {
        return true;
    }
    return false;
}


/**
 *  Constructor
**/
// io::IO() {}


/**
 *  @method ReadLine
 *  @return {std::string}
 *
 *  Get the whole line (with whitespaces)
**/
std::string io::ReadLine() {
    std::string line;
    std::getline(std::cin, line);

    return line;
}


/**
 *  @method NextToken
 *  @return {std::string}
 *
 *  Get a single token (string). Stop when encounter a whitespace.
 *  Hint: use stringstream
**/

std::string io::NextToken() {
    std::string line = ReadLine();

    std::stringstream ss;
    ss << line;

    std::string token;
    ss >> token;

    return token;
}


/**
 *  @method NextInt
 *  @return {int}
 *
 *  Get the next int
 *  Hint: use the NextToken() function and cast std::string to int
**/
int io::NextInt() {
    std::string token = NextToken();
    int num = std::stoi(token);
    return num;
}


/**
 *  @method NextDouble
 *  @return {double}
 *
 *  Get the next double
 *  Hint: use the NextToken() function and cast std::string to double
**/
double io::NextDouble() {
    std::string token = NextToken();
    double num = std::stof(token);
    return num;
}


std::string io::ToUpperCase(std::string s) {
    for (int i = 0; i < (int) s.length(); i++) {
        // If the character is a letter but not uppercase, uppercase it!
        if(IsLetter(s[i]) && !IsUpperCaseLetter(s[i])){
            s[i] -= 32;
        }
    }
    return s;
}


std::string io::StripWhitespaces(std::string s) {
    std::string result = "";
    for (int i = 0; i < (int) s.length(); i++) {
        if (s[i] != ' ') {
            result += s[i];
        }
    }
    return result;
}


/**
 *  Destructor
**/
// io::~IO() {}
