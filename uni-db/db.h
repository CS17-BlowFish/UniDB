#ifndef DB_H
#define DB_H


#include <vector>
#include <string>


std::string SplitTableName(std::string &query_string);
std::vector<std::string> SplitTokens(std::string s);
std::vector<std::vector<std::string> > SplitConditions(std::string &query_string);
inline std::string GenFileName(std::string table_name);
void DeleteQuery(std::string query_string);
void InsertQuery(std::string query_string);
std::vector<std::string> SplitRequestColumns(std::string request);
std::vector<std::vector<std::string> > SelectQuery(std::string query_string);
std::vector<std::vector<std::string> > SearchQuery(std::string query_string);
void SetQuery(std::string query_string);


#endif // DB_H
