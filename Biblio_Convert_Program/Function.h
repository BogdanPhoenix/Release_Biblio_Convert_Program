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

bool Is_empty(fstream& pFile);//�������� �� ���� ������
bool Check_File_Fail(string name);//�������� � ����������� ����
bool Read(string name_read, string name_write);//������������ � ����� RIS � ���� TXT
bool System_Check();//�������� ��������� �����