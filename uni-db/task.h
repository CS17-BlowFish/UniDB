#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

#pragma once

class Data {
public:
	std::string inner[7];

	Data() {
	};


};

class Task {
public:

	class search_user {

	};

	void readFile(std::string _path, Data st[]);
	void writeFile(std::string _path, std::string _text);
	int login();
	int search_user(std::string _name);
	void add_user();
	void remove_user();
	void change_password(std::string _id);
	void replace_data(int condition_col, std::string _condition_data, int writing_col, std::string _text);
};
