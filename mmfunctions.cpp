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

void ParseFilename(string filename) {
	string artist;
	string album;
	string song;
	size_t found_first = 0;
	size_t found_last = 0;

	found_first = filename.find_first_of("-");
	artist = filename.substr(0, found_first);

	found_last = filename.find_first_of("-", found_first + 1);
	album = filename.substr(found_first + 1, filename.size() - found_last);

	song = filename.substr(found_last + 1);
}

void ParseFilename(string filename, string &artist, string &album, string &song) {
	size_t found_first = 0;
	size_t found_last = 0;

	found_first = filename.find_first_of("-");
	artist = filename.substr(0, found_first);
	
	found_last = filename.find_first_of("-", found_first + 1);
	album = filename.substr(found_first + 1, (found_last - found_first) - 1);

	song = filename.substr(found_last + 1);
}

int ProcessFile(string filename, string previousfilename) {
	string current_artist;
	string current_album;
	string current_song;
	string previous_artist;
	string previous_album;
	string previous_song;

	ParseFilename(filename, current_artist, current_album, current_song);
	ParseFilename(previousfilename, previous_artist, previous_album, previous_song);

	if(current_artist != previous_artist)
		return 1;

	if(current_album != previous_album)
		return 2;

	// Artist and Album are the same
	return 0;
}