#ifndef IO_H
#define IO_H


#include <string>


class IO {
    private:

    public:
        IO();
        std::string ReadLine();
        std::string NextToken();
        int NextInt();
        double NextDouble();
        ~IO();
};


#endif // IO_H
