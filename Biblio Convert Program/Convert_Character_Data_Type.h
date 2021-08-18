#pragma once
#include <iostream>
#include <cstdlib>

using namespace std;
using namespace System;
/* Method prototypes for forms */
class Convert_Character_Data_Type {
public:
	static string& Convert_String_to_string(String^, string&);// converts String^ to string
	static string& Convert_String_to_string(String^);// converts String^ to string

	static String^ Convert_string_to_String(string&, String^);// converts string to String^
	static String^ Convert_string_to_String(string&);// converts string to String^

	static char* Convert_String_to_char(String^);// converts String^ to char*

	static String^ Convert_char_to_String(char); // converts char to String^
	static String^ Convert_char_to_String(char*);// converts char* to String^

	static string Convert_wstring_to_string(wstring const& wstr);// converts wstring to string
	static wstring Convert_string_to_wstring(string const& str);// converts string to wstring
};