#pragma once
#include <iostream>
#include <ctime>
#include <filesystem>
#include<string>
using namespace std::experimental::filesystem::v1;

class File_system
{
protected:
	std::string name;
	path full_path;
	time_t creation;
	time_t modification;
	bool is_file;
public:
	File_system();
	~File_system();
};

