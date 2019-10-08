#include "pch.h"
#include "File.h"
#include "File_system.h"
#include <typeinfo>
#include <filesystem>
#include <io.h>
#include <fstream>
using namespace std::experimental::filesystem::v1;

File::File(std::string name)
{
	is_file = true;
	this->name = name;
	full_path = absolute(name);
	std::ifstream file(full_path,std::ifstream::ate|std::ifstream::binary);
	size=file.tellg();
	file.close();
    mode = name.substr(name.find_last_of(".") + 1);
	path temp = name;
	location = new Directory(temp.parent_path());
}

File::File(path full_path)
{
	is_file = true;
	this->full_path = full_path;
	std::string temp = full_path.u8string();
	name = temp.erase(0, temp.find_last_of("\\"));
	mode = name.substr(name.find_last_of(".") + 1);
	std::ofstream file(full_path);
	file.close();
	location = new Directory(full_path.parent_path());
	
}

File::~File()
{
}

void File::Set_path(path parent_path)
{
	std::string temp = parent_path.u8string();
	temp = temp + "\\" + name;
	full_path = temp;
}

void File::print_info()
{
	std::cout << name << std::endl;
	std::cout << full_path << std::endl;
	std::cout << "The time of the creation is " << creation << std::endl;
	std::cout << "The time of the last modification is " << modification << std::endl;
	std::cout << "Size: " << size << std::endl;
}

std::string File::Get_name()
{
	return name;
}

path File::Get_fullpath()
{
	return full_path;
}

void File::Set_name(std::string name)
{
	this->name = name;
	mode = name.substr(name.find_last_of(".") + 1);
}

std::string File::Get_mode()
{
	return mode;
}

time_t File::Get_creation()
{
	return creation;
}

time_t File::Get_modification()
{
	return modification;
}
