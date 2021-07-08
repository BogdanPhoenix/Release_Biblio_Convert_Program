#pragma once
#include <iostream>
#include <fstream>
#include <string.h>
#include <nlohmann/json.hpp>
#include "Convert_Character_Data_Type.h"

using json = nlohmann::json;
using namespace std;

class ALL {
private:
	int number_AU = 0;
	wstring mark_DB;

	void Work_AU(wstring& sentence, wstring part); // implement AU label change
	void Work_AD(wstring& sentence, wstring part); // implement label change AD
	void Work_LA(wstring& sentence, wstring first_part); // implement LA tag change
	bool RFind(wstring sentence, wstring word, int& position); // search for the specified character / word from right to left
protected:
	wstring line, part;

	void Free_Transformation(wstring& sentence, wstring first_part); // implementation of replacement of RIS label by TXT (common for all types)
	void Strict_Transformation(string type, int end); // method for converting labels from RIS to TXT, in a certain sequence
	void Set_Mark_DB(wstring mark_DB); // write the DB label
	wstring Get_Mark_DB(); // output DB label
	wstring Get_Start(); // initial value of each type
	bool Check_Ignore_Mark(wstring copy_part, string type);//check ignore mark
};

class JOUR : public ALL {
public:
	JOUR();// constructor for the heir class CONF
	JOUR(wofstream& file_write);// label conversion constructor for JOUR file
};

class CONF : public JOUR {
public:
	CONF(wofstream& file_write); // label conversion constructor for CONF file
};

class BOOK : public ALL {
public:
	BOOK(wofstream& file_write); // label conversion constructor for BOOK file
};
