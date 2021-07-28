#include "Class_Type.h"
// implement file conversion from RIS to TXT
void from_RIS_to_TXT::Start(const string& name_open_file, const string& name_save_file)
{
	wstring sentence, identifier;
	vector<wstring> fragment;
	wifstream file_read(name_open_file);
	ALL* type_class;
	setlocale(LC_ALL, "utf-8");	
	while (!file_read.eof()) { 
		getline(file_read, sentence);
		fragment.push_back(sentence);
		if (sentence == L"") {
			identifier.insert(0, fragment[0], fragment[0].find(L"- ") + 2, 4);
			Start_Convert start;
			//select record type converter
			if (identifier == L"JOUR")
				type_class = new JOUR;
			else if (identifier == L"CONF")
				type_class = new CONF;
			else
				type_class = new BOOK;
			//record the name of the file in which you want to write the converted data
			start.Set_File_Name(name_save_file);
			//start the converter
			type_class->Set_Fragment_File(fragment);
			start.Start(type_class);
			fragment.clear();
			identifier.clear();
		}
	}
	delete type_class;
	file_read.close();
}
// save the name of the file to be converted
void Open_Variant_Convert::Set_Open_File(const string& name_open_file) { this->name_open_file = name_open_file; }
// save the name of the file to which you want to convert the data
void Open_Variant_Convert::Set_Save_File(const string& name_save_file) { this->name_save_file = name_save_file; }
// start the program
void Open_Variant_Convert::Start_Program(Variant_Convert* variant) { variant->Start(name_open_file, name_save_file); }