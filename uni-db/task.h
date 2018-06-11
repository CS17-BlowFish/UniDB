#ifndef TASK_H
#define TASK_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

class Data {
public:
	std::string inner[7];

	Data() {
	};


};

class Task {
public:
	void readFile(std::string _path, Data st[]);
	void writeFile(std::string _path, std::string _text);
	int login();
	int search_user(std::string _name);
	void add_user();
	void remove_user();
	//void change_password(std::string _id);
	void replace_data(int condition_col, int writing_col, std::string _id, std::string _text);
};

#endif