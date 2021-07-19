#include "Convert_Character_Data_Type.h"

// converts String^ to string
string& Convert_String_to_string(String^ s, string& os) {
	using namespace Runtime::InteropServices;
	const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
	return os;
}
// converts string to String^
String^ Convert_string_to_String(string& os, String^ s) {
	s = gcnew String(os.c_str());
	return s;
}
// converts String^ to string
string& Convert_String_to_string(String^ s) {
	string os;
	using namespace Runtime::InteropServices;
	const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
	return os;
}
// converts string to String^
String^ Convert_string_to_String(string& os) {
	String^ s = gcnew String(os.c_str());
	return s;
}
// converts char to String^
String^ Convert_char_to_String(char ch) {
	char* chr = new char();
	chr[0] = ch;
	String^ str;
	for (int i = 0; chr[i] != '\0'; i++)
		str += wchar_t(ch);
	return str;

}
// converts char* to String^
String^ Convert_char_to_String(char* ch) {
	char* chr = new char();
	chr = ch;
	String^ str;
	for (int i = 0; chr[i] != '\0'; i++)
		str += wchar_t(ch[i]);
	return str;

}
// converts String^ to char*
char* Convert_String_to_char(String^ string) {
	using namespace Runtime::InteropServices;
	return (char*)(void*)Marshal::StringToHGlobalAnsi(string);
}
// converts wstring to string
string Convert_wstring_to_string(wstring const& wstr) {
	size_t size = sizeof(wstr.c_str());
	char* str = new char[size];
	string temp;

	wcstombs(str, wstr.c_str(), size);
	temp = str;
	delete str;
	return temp;
}
// converts string to wstring
wstring Convert_string_to_wstring(string const& str) {
	wstring wstr(str.begin(), str.end());
	return wstr;
}