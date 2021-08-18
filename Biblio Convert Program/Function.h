#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Convert_Character_Data_Type.h"

using namespace std;
using namespace System;
using namespace System::Windows::Forms;

public class Function 
{
private: static vector<string> file_system;
public: 
	static bool Is_empty(fstream& pFile);// check if the file is empty
	static bool Check_File_Fail(const string& name);// check and open the file
	static bool System_Check();// check system files
};

