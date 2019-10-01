#include "pch.h"
#include "File_system.h"


File_system::File_system()
{
	auto time = std::chrono::system_clock::now();
	creation = std::chrono::system_clock::to_time_t(time);
	modification = creation;
}


File_system::~File_system()
{
}
