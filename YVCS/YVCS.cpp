#include <iostream>
#include<windows.h>
#include<string>
#include <cstdlib>
#include <filesystem>
using namespace std;
void commands(string command, string name);
int main() {
   string command;
    string name;
    string dir = "Directory_Of_Repositories";
   /* system(("mkdir " + dir).c_str());
    system("cls");
    system("cd Directory_Of_Repositories");
    cin >> command;
    getline(cin, name);
    cout << command << " " << name << endl;
    commands(command, name);*/
   filesystem::create_directory(dir);
}
void commands(string command, string name) {    
    if (command == "init") {
        system(("mkdir " + name).c_str());
    }
}