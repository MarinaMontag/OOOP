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
	void Set_name(std::string name);
	void Set_path(path parent_path);
	void Set_modification(time_t modification);
	path Get_fullpath();
	std::string Get_name();
	std::string Get_mode();
	time_t Get_creation();
	time_t Get_modification();
	path Get_fullpath();
	void print_info();
	~File();
};

