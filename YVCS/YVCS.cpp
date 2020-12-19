#include <iostream>
#include <windows.h>
#include <string>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <cstring>
#include <direct.h>
#include <time.h>
#pragma warning(disable:4996);
using namespace std;
namespace fs = filesystem; // c++ 17
void commands(string command, string name, string message, string toBeAddedNames[64]);
int main() {
	string command;
	string message;
	string fileName;
	string toBeAddedNames[64];
	string name;
	bool isEntered = false;
	string dir = "C:\\Directory_Of_Repositories";
	cout << "Your diractory is located in disk C:\\Directory_Of_Repositories" << endl;
	fs::create_directory(dir);
	do {
		cout << "Create a new repo with 'init' or load an existing one with 'load'";
		cin >> command;
		if (command != "exit" && !isEntered) {
			if (command == "init") {
				cout << "A new repository is created successfully.";
			}
			do  {
				cin.ignore();
				getline(cin, name);
				isEntered = true;
				if (!(command == "load" || command == "init")) {
					cout << "Enter a valid command! ";
				}
			} while (command != "load" || command != "init");
		}
		if (command == "commit") {
			getline(cin, message);
		}
		if (command == "add") {
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
		}
		//cout << command << " " << name << endl;
		commands(command, name, message, toBeAddedNames);
	} while (command != "exit");
}
void commands(string command, string name, string message, string toBeAddedNames[64]) {
	string path_str = "C:\\Directory_Of_Repositories\\" + name;
	string path_file_str = path_str + "\\" + "log.txt";
	string path_version = "C:\\Directory_Of_Repositories\\" + name + "\\" + message;
	ofstream file;
	if (command == "init") {
		_mkdir(path_str.c_str());
		file.open(path_file_str.c_str(), std::ios::out);
		file.close();
	}
	else if (command == "commit") {
		const int MAX_TIME_CHARACTERS = 64;
		time_t rawtime;
		tm* timeinfo;
		char date[MAX_TIME_CHARACTERS];
		time(&rawtime);
		timeinfo = localtime(&rawtime);
		strftime(date, MAX_TIME_CHARACTERS, "%d/%m/%Y | %R", timeinfo);
		file.open(path_file_str.c_str(), std::ios::out | std::ios::app);
		cout << name << endl;
		cout << strerror(errno);
		file << date << " | " << message << endl;
		file.close();
		_mkdir(path_version.c_str());
	}
	else if (command == "push") {
		for (int i = 0; toBeAddedNames[i] != "\0"; i++) {
		fs:move(path_version);
		}
	}
	
	/*else if (command == "add") {
	
	}*/
}
//$USER
//std::ios::out | std::ios::append
//std::ios::in
// file.open(".\bla-bla\test.txt",std::ios::out);