#include <iostream>
#include<windows.h>
#include<string>
#include <cstdlib>
#include <filesystem>
#include <fstream>
using namespace std;
namespace fs = filesystem; // c++ 17
void commands(string command, string name);
int main() {
	string command;
	string name;
	string dir = "Directory_Of_Repositories";
	/* system(("mkdir " + dir).c_str());
	 system("cls");
	 system("cd Directory_Of_Repositories");
	 */
	fs::create_directory(dir);
	cin >> command;
	getline(cin, name);
	cout << command << " " << name << endl;
	commands(command, name);
}
void commands(string command, string name) {
	if (command == "init") {
		fs::create_directory(".\\Directory_Of_Repositories\\" + name);
		fstream file;
		file.open(".\\Directory_Of_Repositories\\" + name + "\\log.txt", std::ios::out);
		file.write("balabalbla", 10);
		file.close();
	}
}
// file.open(".\bla-bla\test.txt",std::ios::out);