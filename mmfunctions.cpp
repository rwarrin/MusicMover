#include "mmfunctions.h"

void DisplayProgress(int current, int max) {
	cout << "\b\b\b\b\b\b\b";
	cout << current << " / " << max;
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