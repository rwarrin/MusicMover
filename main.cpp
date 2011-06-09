#include "mmfunctions.h"

#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
	// Simple error checking to prevent crash
	if(argc < 2) {
		cout << "To use this application drag and drop a selection of songs on";
		cout << "to the application and it will run automatically.\n";
		cout << "Press ENTER to exit.";
		cin.get();
		return 1;
	}

	// Set the directory
	string directory = SetWorkingDirectory(argv[0]);
	SetCurrentDirectory(directory.c_str());

	// Create a new directory using the first file to generate a name
	string newdirectory = CreateDirectoryNameFromFile(argv[1]);
	CreateDirectory(newdirectory.c_str(), NULL);

	string fullpath = directory + "\\" + newdirectory + "\\";

	// Move the files to the new directory
	for(int i = 1; i < argc; i++) {
		DisplayProgress(i, argc - 1);
		string tempnewpath = fullpath + GetFilename(argv[i]);
		MoveFile(argv[i], tempnewpath.c_str());
	}
	return 0;
}

