#pragma once
#include "File_system.h"
#include "File.h"
#include <vector>
#include <windows.h>
#include "Directory.h"
#include <ctime>
#include <filesystem>

class Directory :
	public File_system
{
protected:
	std::vector<File*> files;
	std::vector<Directory*> directories;
public:
	Directory(path full_path);
	void addFile(std::vector<File*> files, File* file);
	void addDirectory(std::vector<Directory*> directories, Directory* directory);
	void Set_path(path parent_path);
	void search(std::string name);
	void search(bool& find, path fullpath);
	void search_by_mode(std::string mode);
	void search_by_creation(bool& find, time_t creation);
	void search_by_modification(bool& find, time_t creation);
	void delete_files(Directory*direcory);

	~Directory();
};

