#include "Function.h"

// an array of file names that are required for the full operation of the program
vector<string> Function::file_system = { "Country_Code.json", "Language_Code.json", "Mark_from_RIS_to_TXT.json", "Mark_Ignore.json" };
// check if the file is empty
bool Function::Is_empty(fstream& pFile) { return pFile.peek() == fstream::traits_type::eof(); }
// check and open the file
bool Function::Check_File_Fail(const string& name){
	bool check = true;
	fstream file(name, ios::binary | ios::in);
	if (!file)
		check = false;
	file.close();
	return check;
}
// check system files
bool Function::System_Check(){
	bool check = true;
	for (size_t i = 0; i < file_system.size(); i++) {
		ifstream file;
		file.exceptions(ifstream::badbit | ifstream::failbit);
		try { file.open(file_system[i]); }
		catch (const ifstream::failure& ex) {
			MessageBox::Show(Convert_Character_Data_Type::Convert_string_to_String("???? " + file_system[i] + " ?? ?????????. \n???????: " + (string)ex.what()), "?????");
			check = false;
		}
		file.close();
		if (!check) break;
	}
	return check;
}