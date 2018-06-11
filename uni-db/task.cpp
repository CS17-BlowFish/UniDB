#include "task.h"

// Branching...

// this may differ

std::string user_path = "C:/Users/Someone/Desktop/project/uni-db/data/user.csv";
std::string score_path = "C:/Users/Someone/Desktop/project/uni-db/data/score.csv";
std::string student_path = "C:/Users/Someone/Desktop/project/uni-db/data/student.csv";
std::string faculty_path = "C:/Users/Someone/Desktop/project/uni-db/data/faculty.csv";
std::string course_path = "C:/Users/Someone/Desktop/project/uni-db/data/course.csv";

std::string test_path = "C:/Users/Someone/Desktop/project/uni-db/data/temp.txt";
std::string log_path = "C:/Users/Someone/Desktop/project/uni-db/data/log.txt";

void Task::readFile(std::string _path, Data st[]) {
	char c;
	std::ifstream file(_path);

	if (file.is_open()) {

		int a = 0;
		int b = 0;
		while (file.get(c)) {

			if (c != ',' && c != '\n') {
				st[b].inner[a] += c;
			};
			if (c == ',') {
				a += 1;
			}
			else if (c == '\n') {
				b += 1;
				a = 0;
			}
		}
		file.close();
	}
}

void Task::writeFile(std::string _path, std::string _text) {
	//writeFile(path, text)

	std::ofstream file;
	file.open(_path, std::ios_base::app);
	if (file.is_open()) {
		file << _text;
	}
	else {
		std::cout << "Cannot open";
	}

}

int Task::login() {
	Data userdata[2000];
	readFile(user_path, userdata);

	int a = 0;
	bool user_found = 0;
	std::string username;
	std::string password;

	while (!user_found || password != userdata[a].inner[1]) {

		std::cout << "Username: ";
		std::cin >> username;
		std::cout << "Password: ";
		std::cin >> password;

		a = 0;

		while (userdata[a].inner[0] != username) {
			a += 1;
			if (userdata[a].inner[0] == username) {
				user_found = 1;
				break;
			}
			if (a >= 2000) {
				break;
			}
		}

		if (user_found) {
			if (password != userdata[a].inner[1]) {
				std::cout << "Invalid password" << std::endl;
			}
			else {
				if (userdata[a].inner[2] == "admin") {
					return 0;
				}
				else if (userdata[a].inner[2] == "faculty") {
					return 1;
				}
				else if (userdata[a].inner[2] == "student") {
					return 2;
				}
				else {
					return 9; //invalid state
				}
			}
		}
		else {
			std::cout << "User not found" << std::endl;
		}
	}
}
// 0: admin, 1: faculty, 2: student

int Task::search_user(std::string _name) {
	Data userdata[2000];
	readFile(user_path, userdata);

	int a = 0;
	bool found = 0;
	while (a <= 2000) {
		a += 1;
		if (_name == userdata[a].inner[0]) {
			found = 1;
			break;
		}
	}
	if (found) {
		std::cout << std::setw(10) << userdata[a].inner[0] << std::setw(10) << userdata[a].inner[1] << std::setw(10) << userdata[a].inner[2];
	}
	else {
		std::cout << "User not found";
	}
	return a;
}

// The same with search_user, without cout-ing

void Task::add_user() {
	std::string _id;
	std::string _pass;
	std::string _type;
	std::cout << "Username: "; std::cin >> _id;
	std::cout << "Password: "; std::cin >> _pass;
	std::cout << "Faculty: "; std::cin >> _type;
	writeFile(user_path, _id + "," + _pass + "," + _type + "\n");
}

void Task::remove_user() {
	std::string _id;
	std::cout << "Username: "; std::cin >> _id;
	std::string line;
	std::ifstream pre_file(user_path);
	std::ofstream post_file;

	// Detect which line to delete 
	int line_del = search_user(_id) + 1;
	std::cout << std::endl << "This user will be deleted. \n";
	int num = 1;
	post_file.open(test_path);

	// Write new content to a "temp" folder
	while (getline(pre_file, line)) {
		if (num != line_del) {
			post_file << line;
			num += 1;
			post_file << "\n";
		}
		else {
			num += 1;
		}
	}
	post_file.close();
	pre_file.close();
	pre_file.open(test_path);
	post_file.open(user_path);

	// Write it back
	while (getline(pre_file, line)) {
		post_file << line;
		post_file << "\n";
	}
	post_file.close();
	pre_file.close();
}

// Find the line with that text in condition_column 
// Replace writing_column with _text data
void Task::replace_data(int condition_col, std::string _condition_data, int writing_col, std::string _text) {

	std::string line;
	std::ifstream pre_file(user_path);
	std::ofstream post_file;

	Data userdata[2000];
	readFile(user_path, userdata);

	int line_replace = 0;
	bool found = 0;
	while (line_replace <= 2000) {
		line_replace += 1;
		if (_condition_data == userdata[line_replace].inner[condition_col]) {
			found = 1;
			break;
		}
	}

	line_replace += 1;
	std::cout << line_replace;

	if (found) {

		int num = 1;
		post_file.open(test_path);

		// Write new content to a "temp" folder
		while (getline(pre_file, line)) {
			if (num != line_replace - 1) {
				post_file << line;
				num += 1;
				post_file << "\n";
			}
			else {

				post_file << line;
				num += 1;
				post_file << "\n";

				char c; int a = 0;
				while (pre_file.get(c)) {
					if (c != ',' && c != '\n' && a != writing_col) {
						post_file << c;
					};
					if (c == ',') {
						a += 1;
						if (a == writing_col) {
							post_file << "," << _text << ",";
						}
					}
					else if (c == '\n') {
						post_file << "\n";
						num += 1;
						break;
					}
					std::cout << c;
				}
			}
		}
	}
	post_file.close();
	pre_file.close();
	pre_file.open(test_path);
	post_file.open(user_path);

	// Write it back
	while (getline(pre_file, line)) {
		post_file << line;
		post_file << "\n";
	}
	post_file.close();
	pre_file.close();
	//delete userdata;
}
