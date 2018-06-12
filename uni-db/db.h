#ifndef DB_H
#define DB_H


#include <vector>
#include <string>


void DeleteQuery(std::string query);
void InsertQuery(std::string query);
std::vector<std::vector<std::string> > SelectQuery(std::string query);
void SetQuery(std::string query);


#endif // DB_H
