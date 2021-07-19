#pragma once
#include <iostream>
#include <cstdlib>

using namespace std;
using namespace System;

/* Function prototypes for forms */
string& Convert_String_to_string(String^, string&);// converts String^ to string
string& Convert_String_to_string(String^);// converts String^ to string

String^ Convert_string_to_String(string&, String^);// converts string to String^
String^ Convert_string_to_String(string&);// converts string to String^

char* Convert_String_to_char(String^);// converts String^ to char*

String^ Convert_char_to_String(char); // converts char to String^
String^ Convert_char_to_String(char*);// converts char* to String^

string Convert_wstring_to_string(wstring const& wstr);// converts wstring to string
wstring Convert_string_to_wstring(string const& str);// converts string to wstring