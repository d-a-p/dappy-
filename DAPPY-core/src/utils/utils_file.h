//this file is created by DAP...
#pragma once

#include<fstream>
#include<string>

namespace dappy {

	std::string read_file(const char* path) {
		FILE* file =  fopen(path, "rt");
		fseek(file, 0 , SEEK_END);
		unsigned long length = ftell(file);
		
		char* result = new char[length + 1];
		memset(result, 0, length + 1);

		fseek(file,0, SEEK_SET);
		fread(result , 1, length, file);
		fclose(file);

		std::string data(result);
		delete[] result;
		return data;
	}

}
