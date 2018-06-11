#ifndef IO_H
#define IO_H


#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib> // for ftoi, ftof


#include <stdio.h>

class IO {
    private:

    public:
        //IO();
        std::string ReadLine();
        std::string NextToken();
        int NextInt();
        double NextDouble();
        //~IO();
};


#endif IO_H
