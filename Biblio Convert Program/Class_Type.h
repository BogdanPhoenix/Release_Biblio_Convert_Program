#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

#include "Function.h"
#include "Class_Function.h"
using namespace std;

// abstract class, used to quickly start the required converter
class Variant_Convert 
{
public: virtual void Start(const string& name_open_file, const string& name_save_file) = 0;
};
// implement file conversion from RIS to TXT
class from_RIS_to_TXT : public Variant_Convert
{
public: void Start(const string& name_open_file, const string& name_save_file) override;
};
// a class that recognizes which converter to run
class Open_Variant_Convert {
private: string name_open_file, name_save_file;
public:
	// save the name of the file to be converted
	void Set_Open_File(const string& name_open_file);
	// save the name of the file to which you want to convert the data
	void Set_Save_File(const string& name_save_file);
	// start the program
	void Start_Program(Variant_Convert* variant);
};