#include "Function.h"

// an array of file names that are required for the full operation of the program
string file_system[] = { "Language_Code.json", "Mark_from_RIS_to_TXT.json", "Country_Code.json" };

// check if the file is empty
bool Is_empty(fstream& pFile) {
	return pFile.peek() == fstream::traits_type::eof();
}
// check and open the file
bool Check_File_Fail(string name) {
	bool check = true;
	fstream file(name, ios::binary | ios::in);
	if (!file)
		check = false;
	file.close();
	return check;
}
// convert from RIS file to TXT file
bool Read(string name_read, string name_write) {
	wstring str, identifier;
	bool variant = true;

	wifstream file_read(name_read);
	wofstream file_write(name_write);
	wofstream copy_fragment("Copy_Fragment.txt");

	if (!Check_File_Fail("Copy_Fragment.txt"))
		return false;

	// file to read
	if (!Check_File_Fail(name_read))
		return false;

	// file to write
	if (!Check_File_Fail(name_write))
		return false;

	setlocale(LC_ALL, "utf-8");
	while (!file_read.eof()) {
		getline(file_read, str);
		if (variant) {
			identifier = str;
			variant = false;
		}
		copy_fragment << str << "\n";

		if (str == L"ER  - ") {
			copy_fragment.close();
			if (identifier == L"TY  - JOUR")
				JOUR jour(file_write);

			else if (identifier == L"TY  - CONF")
				CONF conf(file_write);

			else if (identifier == L"TY  - BOOK")
				BOOK book(file_write);

			copy_fragment.open("Copy_Fragment.txt", ios::out | ios::trunc);
			variant = true;
			getline(file_read, str);
		}
	}
	file_write.close();
	file_read.close();
	return true;
}
// check system files
bool System_Check() {
	int size_file_system = sizeof(file_system) / sizeof(file_system[0]);
	for (int i = 0; i < size_file_system; i++) {
		ifstream file;
		file.exceptions(ifstream::badbit | ifstream::failbit);
		try {
			file.open(file_system[i]);
		}
		catch (const ifstream::failure& ex) {
			MessageBox::Show(Convert_string_to_String("Файл " + file_system[i] + " не відкрився. \nПомилка: " + (string) ex.what()), "Увага");
			return false;
		}
	}
	return true;
}