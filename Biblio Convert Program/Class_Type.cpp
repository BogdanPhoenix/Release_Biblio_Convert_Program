#include "Class_Type.h"
// implement file conversion from RIS to TXT
void from_RIS_to_TXT::Start(const string& name_open_file, const string& name_save_file)
{
	setlocale(LC_ALL, "utf-8");
	wstring sentence, identifier;
	vector<wstring> fragment;
	wifstream file_read(name_open_file);
	ALL_RIS_TXT type_class;	
	while (!file_read.eof()) { 
		getline(file_read, sentence);
		fragment.push_back(sentence);
		if (sentence == L"") {
			identifier.insert(0, fragment[0], fragment[0].find(L"- ") + 2, 4);
			type_class.Set_Fragment_File(fragment);
			type_class.Convert(name_save_file, identifier);
			fragment.clear();
			identifier.clear();
		}
	}
	file_read.close();
}
// save the name of the file to be converted
void Open_Variant_Convert::Set_Open_File(const string& name_open_file) { this->name_open_file = name_open_file; }
// save the name of the file to which you want to convert the data
void Open_Variant_Convert::Set_Save_File(const string& name_save_file) { this->name_save_file = name_save_file; }
// start the program
void Open_Variant_Convert::Start_Program(Variant_Convert* variant) { variant->Start(name_open_file, name_save_file); }