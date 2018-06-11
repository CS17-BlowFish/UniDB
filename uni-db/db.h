#ifndef DB_H
#define DB_H


#include <vector>
#include <string>


std::vector<std::vector<std::string> > SelectQuery(std::string query);


void InsertQuery(std::string query);


void DeleteQuery(std::string query);


#endif // DB_H
