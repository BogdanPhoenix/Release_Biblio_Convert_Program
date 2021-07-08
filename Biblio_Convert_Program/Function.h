#pragma once
#include <iostream>
#include <fstream>
#include <string>

#include "Convert_Character_Data_Type.h"

using namespace std;
using namespace System;
using namespace System::Windows::Forms;

extern string way_file;

bool Is_empty(fstream& pFile);// check if the file is empty
bool Check_File_Fail(string name);// check and open the file
bool System_Check();// check system files