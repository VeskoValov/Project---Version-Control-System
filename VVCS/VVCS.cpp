#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <direct.h>
 
using namespace std;
//void commands(string command, string name);
int main() {
	string fileName;
	string toBeAddedNames[64];
	int startPosition = 0;
	int counter = 0;
	int lenght = 0;
	getline(cin, fileName);
	for (int i = 0, j = 0; i < fileName.size(); i++) {
		counter++;
		if (fileName[i] == ' ' || fileName[i + 1] == '\0') {
			toBeAddedNames[j++] = fileName.substr(startPosition, counter);
			lenght += counter;
			startPosition = lenght;
			counter = 0;
		}
	}
	for (string str : toBeAddedNames) { cout << str << endl; }

















//	string command;
//	string name;
//	string dir = "Directory_Of_Repositories";
//	//fs::create_directory(dir);
//	//fs::permissions(dir, fs::perms::owner_all | fs::perms::group_all, fs::perm_options::add);
//	cin >> command;
//	getline(cin, name);
//	cout << command << " " << name << endl;
//	commands(command, name);
//}
// 
//void commands(string command, string name) {
//	string path_str = "C:\\Users\\Vesko\\source\\Dir\\" + name;
//	string path_file_str = path_str + "\\" + "log.txt";
//	if (command == "init") {
//		_mkdir(path_str.c_str());
//		ofstream file(path_file_str.c_str());
//		if (!file.is_open()) {
//			std::cout << "File error!\n";
//		}
//		else {
//			file.write("balabalbla", 10);
//			file.close();
//		}
// 
//	}
}
// file.open(".\bla-bla\test.txt",std::ios::out);