#ifndef MMFUNCTIONs_H
#define MMFUNCTIONS_H

#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <string>

using namespace std;

string CreateDirectoryNameFromFile(char * filename);
string SetWorkingDirectory(char *path);
string GetFilename(char *path);
void DisplayProgress(int current, int max);

#endif  // MMFUNCTION_H