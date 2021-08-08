#pragma once
#include <iostream>
#include <fstream>
#include <string.h>
#include <nlohmann/json.hpp>

#include "Convert_Character_Data_Type.h"
#include "Class_Type.h"

using json = nlohmann::json;
using namespace std;
//parent class
class ALL {
private:
	int number_AU;
	wstring mark_DB, size_delete_dash = L" - ";
	vector<wstring> fragment;
	void Work_AU(const wstring&); // implement AU label change
	void Work_AD(const wstring&); // implement label change AD
	void Work_LA(const wstring&); // implement LA tag change
	
protected:
	size_t index_the_main_fragment;
	wstring line, part;
	void Free_Transformation(const wstring&); // implementation of replacement of RIS label by TXT (common for all types)
	void Strict_Transformation(const string&); // method for converting labels from RIS to TXT, in a certain sequence
	void Set_Mark_DB(const wstring&); // write the DB label
	wstring Get_Mark_DB(); // output DB label
	wstring Get_Start(); // initial value of each type
	bool Check_Ignore_Mark(const wstring&, const string&);//check ignore mark\

public:
	virtual void Convert(const string&) = 0;
	void Set_Fragment_File(vector<wstring>&);// method for writing the address in which the file fragment lies
	vector<wstring>& Get_Fragment_File(); // method for outputting the address in which the file fragment lies
};
class JOUR : public ALL {
public:
	void Convert(const string& file_name_save) override; //label conversion method for JOUR file
};

class CONF : public ALL {
public:
	void Convert(const string&) override; //label conversion method for CONF file
};

class BOOK : public ALL {
public:
	void Convert(const string&) override; // label conversion method for BOOK file
};
//class to determine the type of conversion
class Start_Convert {
private: string file_name;
public:
	void Set_File_Name(const string&);
	void Start(ALL*);
};
