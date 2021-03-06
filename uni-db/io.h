#ifndef IO_H
#define IO_H


#include <string>


//class IO {
//    private:
//        bool IsLetter(char c);
//        bool IsUpperCaseLetter(char c);
//
//    public:
//        IO();
//        std::string ReadLine();
//        std::string NextToken();
//        int NextInt();
//        double NextDouble();
//        std::string ToUpperCase(std::string);
//        std::string StripWhitespaces(std::string s);
//        ~IO();
//};

namespace io {
        bool IsLetter(char c);
        bool IsUpperCaseLetter(char c);
        std::string ReadLine();
        std::string NextToken();
        int NextInt();
        double NextDouble();
        std::string ToUpperCase(std::string);
        std::string StripWhitespaces(std::string s);
};


#endif // IO_H
