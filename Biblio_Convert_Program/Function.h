#pragma once
#include <iostream>
#include <fstream>
#include <string>

#include "Class_Function.h"
#include "Convert_Character_Data_Type.h"
#include "Converting.h"
#include "Finish_Form.h"

using namespace std;
using namespace System;
using namespace System::Windows::Forms;

extern string way_file;

bool Is_empty(fstream& pFile);//перевірка чи файл пустий
bool Check_File_Fail(string name);//перевірка и відкривається файл
bool Read(string name_read, string name_write);//перетворення з файлу RIS у файл TXT
bool System_Check();//перевірка системних файлів