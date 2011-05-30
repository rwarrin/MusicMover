#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <string>

using namespace std;

string CreateDirectoryNameFromFile(char * filename);
string SetWorkingDirectory(char *path);
string GetFilename(char *path);

int main(int argc, char *argv[]) {
	// Set the directory
	string directory = SetWorkingDirectory(argv[0]);
	SetCurrentDirectory(directory.c_str());

	// Create a new directory using the first file to generate a name
	string newdirectory = CreateDirectoryNameFromFile(argv[1]);
	CreateDirectory(newdirectory.c_str(), NULL);

	string fullpath = directory + "\\" + newdirectory + "\\";

	// Move the files to the new directory
	for(int i = 1; i < argc; i++) {
		string tempnewpath = fullpath + GetFilename(argv[i]);
		MoveFile(argv[i], tempnewpath.c_str());
	}

	return 0;
}

string GetFilename(char *path) {
	string temp = path;
	size_t found;

	found = temp.find_last_of("\\");

	return temp.substr(found + 1, temp.size() - found);
}

string SetWorkingDirectory(char *path) {
	string temp = path;
	size_t found;

	found = temp.find_last_of("\\");

	return temp.substr(0, found);
}

string CreateDirectoryNameFromFile(char * filename) {
	string name = filename;
	string foldername;

	size_t found;
	found = name.find_last_of("\\");
	foldername = name.substr(found + 1, name.size() - found - 5);

	return foldername;
}