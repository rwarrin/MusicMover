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

	string fullpath = directory + "\\";

	string tempnewpath;
	int ret = 0;

	// Move the files to the new directory
	for(int i = 1; i < argc; i++) {
		DisplayProgress(i, argc - 1);
		if(i == 1)
			ret = 1;
		else
			ret = ProcessFile(GetFilename(argv[i]), GetFilename(argv[i-1]));

		if(ret == 1) {
			//cout << "\nCreating a new directory because Artist names do not match.\n";
			newdirectory = CreateDirectoryNameFromFile(argv[i]);
			CreateDirectory(newdirectory.c_str(), NULL);
		}
		if(ret == 2) {
			//cout << "\nCreating a new directory because Album names do not match.\n";
			newdirectory = CreateDirectoryNameFromFile(argv[i]);
			CreateDirectory(newdirectory.c_str(), NULL);
		}

		tempnewpath = fullpath + newdirectory + "\\" + GetFilename(argv[i]);
		MoveFile(argv[i], tempnewpath.c_str());
		//CopyFile(argv[i], tempnewpath.c_str(), false);
		//cout << "\nMoving\nFile: " << GetFilename(argv[i]) << "\nTo: " << tempnewpath << endl;
		//cout << "\n\n\n";
	}
	//cin.get();
	return 0;
}

/*
 *
 * ToDo:
 * Fix CleanString function to only take leading and trailing spaces out and leave spaces mid string alone.
 *
*/