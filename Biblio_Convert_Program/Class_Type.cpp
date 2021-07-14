#include "Class_Type.h"
// implement file conversion from RIS to TXT
void from_RIS_to_TXT::Start(string name_open_file, string name_save_file)
{
	wstring sentence, identifier;
	bool type_convert = true;

	wifstream file_read(name_open_file);
	wofstream copy_fragment("Copy_Fragment.txt");

	setlocale(LC_ALL, "utf-8");
	// splits the file into objects which are then converted depending on their type
	while (!file_read.eof()) {
		getline(file_read, sentence);
		//rework
		// determine the type of file fragment
		if (type_convert) {
			identifier = sentence;
			type_convert = false;
		}
		copy_fragment << sentence << "\n";

		if (sentence == L"ER  - ") {
			copy_fragment.close();

			ALL* type_class;
			Start_Convert start;
			//select record type converter
			if(sentence.find(L"TY") >= 0 && sentence.find(L"JOUR") >= 0)
				type_class = new JOUR;
			else if (sentence.find(L"TY") >= 0 && sentence.find(L"CONF") >= 0)
				type_class = new CONF;
			else if (sentence.find(L"TY") >= 0 && sentence.find(L"BOOK") >= 0)
				type_class = new BOOK;
			//record the name of the file in which you want to write the converted data
			start.Set_File_Name(name_save_file);
			//start the converter
			start.Start(type_class);
			delete type_class;
			copy_fragment.open("Copy_Fragment.txt", ios::out | ios::trunc);
			type_convert = true;
			getline(file_read, sentence);
		}
	}
	file_read.close();
}
// save the name of the file to be converted
void Open_Variant_Convert::Set_Open_File(string name_open_file) { this->name_open_file = name_open_file; }
// save the name of the file to which you want to convert the data
void Open_Variant_Convert::Set_Save_File(string name_save_file) { this->name_save_file = name_save_file; }
// start the program
void Open_Variant_Convert::Start_Program(Variant_Convert* variant) { variant->Start(name_open_file, name_save_file); }