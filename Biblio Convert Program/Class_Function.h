#pragma once
#include <iostream>
#include <fstream>
#include <string.h>
#include <nlohmann/json.hpp>

#include "Convert_Character_Data_Type.h"
#include "Class_Type.h"

using json = nlohmann::json;
using namespace std;

class ALL_RIS_TXT {
private:
	int number_AU;
	wstring line, part, mark_DB, size_delete_dash = L" - ";
	vector<wstring> fragment;
	size_t index_the_main_fragment;

	// implement AU label change
	void Work_AU(const wstring& part);
	// implement label change AD
	void Work_AD(const wstring& part);
	// implement LA tag change
	void Work_LA(const wstring& part);
	// output DB label
	wstring Get_Mark_DB();
	// write the DB label
	void Set_Mark_DB(const wstring& mark_DB);
	
	// method for converting labels from RIS to TXT, in a certain sequence
	wstring Strict_Transformation(const string& type);
	// implementation of replacement of RIS label by TXT (common for all types)
	void Free_Transformation(const wstring& first_part);
	//check ignore mark
	bool Check_Ignore_Mark(const wstring& copy_part, const wstring& type);
	// the label that is placed at the beginning of the file
	wstring First_Label(); 

	// conversion of excellent tags JOUR
	void Jour();
	// conversion of excellent tags CONF
	void Conf();
	// conversion of excellent tags BOOK
	void Book();

public:
	// file conversion
	void Convert(const string& file_name_save, const wstring& identifier);
	// method for writing the address in which the file fragment lies
	void Set_Fragment_File(vector<wstring>& fragment);
};