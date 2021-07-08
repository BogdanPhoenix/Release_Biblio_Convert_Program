#include "Class_Type.h"
// implement file conversion from RIS to TXT
bool from_RIS_to_TXT::Start(string name_open_file, string name_save_file)
{
	wstring str, identifier;
	bool variant = true;

	wifstream file_read(name_open_file);
	wofstream file_write(name_save_file);
	wofstream copy_fragment("Copy_Fragment.txt");

	if (!Check_File_Fail("Copy_Fragment.txt"))
		return false;
	// file to read
	if (!Check_File_Fail(name_open_file))
		return false;
	// file to write
	if (!Check_File_Fail(name_save_file))
		return false;

	setlocale(LC_ALL, "utf-8");
	// splits the file into objects which are then converted depending on their type
	while (!file_read.eof()) {
		getline(file_read, str);
		// determine the type of file fragment
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
// save the name of the file to be converted
void Open_Variant_Convert::Set_Open_File(string name_open_file) { this->name_open_file = name_open_file; }
// save the name of the file to which you want to convert the data
void Open_Variant_Convert::Set_Save_File(string name_save_file) { this->name_save_file = name_save_file; }
// start the program
void Open_Variant_Convert::Start_Program(Variant_Convert& variant) { variant.Start(name_open_file, name_save_file); }