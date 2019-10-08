#include "pch.h"
#include "Directory.h"
#include "File.h"
#include <fstream>

Directory::Directory(path full_path)
{
	is_file = false;
	this->full_path = full_path;
	std::string temp = full_path.u8string();
	name = temp.erase(0,temp.find_last_of("\\"));
	create_directory(full_path);
	
}


Directory::~Directory()
{
	delete_files(this);
}

void Directory::delete_files(Directory*directory)
{
	for (int i = 0; i < files.size(); i++)
		delete files[i];
	for (int i = 0; i < directories.size(); i++)
		delete_files(directories[i]);
	delete directory;
}

void Directory::Set_path(path parent_path)
{
	std::string temp = parent_path.u8string() + "\\";
	full_path = temp + name;
}

void Directory::addFile(std::vector<File*> files, File* file)
{
	bool find = false;
	for (int i = 0; i < files.size(); i++)
		if (files[i]->Get_name() == file->Get_name())
		{
			find = true;
			break;
		}
	if (!find)
	{
		file->Set_path(full_path);
		path temp = file->Get_fullpath();
		std::ofstream f(full_path);
		files.push_back(file);
	}
	else
	{
		std::cout << "File with such name exists!" << std::endl;
		std::cout << "Would you like to change the name of file?(Yes/No)" << std::endl;
		std::string answer;
		std::cin >> answer;
		if (answer == "Yes")
		{
			std::string name;
			std::cout << "Enter the name of file: ";
			std::cin >> name;
			file->Set_name(name);
		}
		else
			delete file;
	}
	
}

void Directory::addDirectory(std::vector<Directory*> directories, Directory* directory)
{
	directory->Set_path(full_path);
	create_directory(directory->full_path);
	directories.push_back(directory);
}

void Directory::search(std::string name)
{
	for (int i = 0; i < files.size(); i++)
	{
		if(files[i]->Get_name==name)
		{
			files[i]->print_info();
			std::cout << std::endl;
			break;
		}
	}
	for (int i = 0; i < directories.size(); i++)
		directories[i]->search( name);
}

void Directory::search(bool& find, path fullpath)
{
	for (int i = 0; i < files.size(); i++)
	{
		if (files[i]->Get_fullpath == fullpath)
		{
			find == true;
			files[i]->print_info();
			break;
		}
	}
	if (find)
		return;
	for (int i = 0; i < directories.size(); i++)
	{
		directories[i]->search(find, fullpath);
		if (find)
			return;
	}
	if (find)
		return;
}

void Directory::search_by_mode(std::string mode)
{
	for (int i = 0; i < files.size(); i++)
	{
		if (files[i]->Get_mode == mode)
		{
			files[i]->print_info();
			std::cout << std::endl;
			break;
		}
	}
	for (int i = 0; i < directories.size(); i++)
		directories[i]->search_by_mode(mode);
}

void Directory::search_by_creation(bool& find, time_t creation)
{
	for (int i = 0; i < files.size(); i++)
	{
		if (files[i]->Get_creation == creation)
		{
			find == true;
			files[i]->print_info();
			break;
		}
	}
	if (find)
		return;
	for (int i = 0; i < directories.size(); i++)
	{
		directories[i]->search_by_creation(find, creation);
		if (find)
			return;
	}
	if (find)
		return;
}

void Directory::search_by_modification(bool& find, time_t modification)
{
	for (int i = 0; i < files.size(); i++)
	{
		if (files[i]->Get_modification == creation)
		{
			find == true;
			files[i]->print_info();
			break;
		}
	}
	if (find)
		return;
	for (int i = 0; i < directories.size(); i++)
	{
		directories[i]->search_by_modification(find, modification);
		if (find)
			return;
	}
	if (find)
		return;
}
