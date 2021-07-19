#include "Function.h"

// an array of file names that are required for the full operation of the program
string file_system[] = { "Country_Code.json", "Language_Code.json", "Mark_from_RIS_to_TXT.json", "Mark_Ignore.json" };

// check if the file is empty
bool Is_empty(fstream& pFile) { return pFile.peek() == fstream::traits_type::eof(); }
// check and open the file
bool Check_File_Fail(string name) {
	bool check = true;
	fstream file(name, ios::binary | ios::in);
	if (!file)
		check = false;
	file.close();
	return check;
}
// check system files
bool System_Check() {
	int size_file_system = sizeof(file_system) / sizeof(file_system[0]);
	for (int i = 0; i < size_file_system; i++) {
		ifstream file;
		file.exceptions(ifstream::badbit | ifstream::failbit);
		try { file.open(file_system[i]); }
		catch (const ifstream::failure& ex) {
			MessageBox::Show(Convert_string_to_String("Файл " + file_system[i] + " не відкрився. \nПомилка: " + (string) ex.what()), "Увага");
			return false;
		}
		file.close();
	}
	return true;
}