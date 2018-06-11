#include "io.h"


/*
    Note: For input, try to use getline and stringstream for all functions
    Avoid cin since it will conflict with getline.
    For output, cout is OK.
*/


//IO::IO(){};


/**
 *  Get the whole line (with whitespaces)
**/



std::string IO::ReadLine() {

    std::string s;
    std::getline(std::cin, s);

    return s;
}


/**
 *  @method NextToken
 *  @return {std::string}
 *
 *  Get a single token (string) without whitespaces
 *  Hint: use stringstream
**/

std::string IO::NextToken() {

    std::string s;
    std::string temp;
    std::stringstream ss;

    s = ReadLine();

    ss << s;
    s = "";

    while (!ss.eof())
    {
        ss >> temp;

        s = s + temp;
    }

    return s;
}


/**
 *  @method NextInt
 *  @return {int}
 *
 *  Get the next int
 *  Hint: use the NextToken() function and cast std::string to int
**/
int IO::NextInt() {

    int num;
    std::string s;

    s = NextToken();

    num = stoi(s);

    return num;
}


/**
 *  @method NextDouble
 *  @return {double}
 *
 *  Get the next double
 *  Hint: use the NextToken() function and cast std::string to double
**/
double IO::NextDouble() {
    double num;

    std::string s;

    s = NextToken();

    num = stof(s);

    return num;
}
