#pragma once
#include "File_system.h"
#include "File.h"
#include <vector>
#include <windows.h>
#include "Directory.h"
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
	~Directory();
};

