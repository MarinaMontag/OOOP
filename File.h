#pragma once
#include "File_system.h"
#include "Directory.h"
class File :
	public File_system
{
protected:
	long size;
	std::string mode;
	Directory*location;
public:
	File(std::string name);
	File(path full_path);
	void Set_path(path parent_path);
	path Get_path();
	~File();
};

