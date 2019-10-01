#include "pch.h"
#include "Directory.h"
#include "File.h"
#include <fstream>

Directory::Directory(path full_path)
{
	this->full_path = full_path;
	std::string temp = full_path.u8string();
	name = temp.erase(0,temp.find_last_of("\\"));
	create_directory(full_path);
	
}


Directory::~Directory()
{
}

void Directory::Set_path(path parent_path)
{
	std::string temp = parent_path.u8string() + "\\";
	full_path = temp + name;
}

void Directory::addFile(std::vector<File*> files, File* file)
{
	file->Set_path(full_path);
	path temp = file->Get_path();
	std::ofstream f(full_path);
	files.push_back(file);
}

void Directory::addDirectory(std::vector<Directory*> directories, Directory* directory)
{
	directory->Set_path(full_path);
	create_directory(directory->full_path);
	directories.push_back(directory);
}