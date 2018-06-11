#ifndef DB_H
#define DB_H


#include <vector>


std::vector<std::vector<std::string> > SelectQuery(std::string query);


bool InsertQuery(std::string query);


bool DeleteQuery(std::string query);


#endif // DB_H