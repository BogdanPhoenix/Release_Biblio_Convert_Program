#include "Class_Function.h"

//class ALL
// implement AU label change
void ALL::Work_AU(wstring part) {
	wstring text;
	// TXT tag for the first author
	if (number_AU++ == 0)
		text = L"#700: ^A";
	// TXT tag for other authors
	else
		text = L"#701: ^A";
	// replace labels
	line.replace(line.find(part), part.length() + 4, text);
	line.replace(line.find(L", "), 2, L"^B");
}
// implement label change AD
void ALL::Work_AD(wstring part) {
	json json_value;
	int pos_str = 0;
	ifstream file("Country_Code.json");
	file >> json_value;
	file.close();
	// replace labels
	line.replace(line.find(part), part.length() + 4, L"#711: ^A");
	line.replace(line.rfind(L", "), 2, L"^S");
	// replace the country name with its code
	for (json::iterator it = json_value.begin(); it != json_value.end(); ++it)
		if (RFind(line, Convert_string_to_wstring(it.key()), pos_str)) {
			line.replace(pos_str, it.key().length(), Convert_string_to_wstring(it.value()));
			break;
		}
}
// implement LA tag change
void ALL::Work_LA(wstring part) {
	wstring language;
	json json_value;
	// Language search
	language.append(line.begin() + part.length() + 4, line.end());
	ifstream file("Language_Code.json");
	file >> json_value;
	file.close();
	// replace the language with its code
	for(json::iterator element = json_value.begin(); element != json_value.end(); ++element)
		if (language == Convert_string_to_wstring(element.key())) {
			line.replace(line.find(language), language.length(), Convert_string_to_wstring(element.value()));
			break;
		}
	// label replacement
	line.replace(line.find(part), part.length() + 4, L"#101: ");
}
// implementation of replacement of RIS label by TXT (common for all types)
void ALL::Free_Transformation(wstring& first_part) {
	json json_value;
	bool exit = false;
	ifstream file("Mark_from_RIS_to_TXT.json");
	file >> json_value;
	file.close();

	if (first_part == L"DB") {
		wstring DB;
		Set_Mark_DB(DB.append(line.begin() + first_part.length() + 4, line.end()));
		line.replace(line.find(first_part), first_part.length() + 4, L"#902: ^A");
	}
	else if (first_part == L"AU")
		Work_AU(first_part);
	else if (first_part == L"AD")
		Work_AD(first_part);
	else if (first_part == L"LA")
		Work_LA(first_part);
	else if (first_part == L"UR") {
		line.replace(line.find(first_part), first_part.length() + 4, L"#951: ^I");
		line += L"^T" + Get_Mark_DB();
	}
	// other labels
	else {
		for (json::iterator element_array = json_value["ALL"].begin(); element_array != json_value["ALL"].end(); ++element_array) {
			if (exit) break;
			for (json::iterator element = element_array.value().begin(); element != element_array.value().end(); ++element)
				if (first_part == Convert_string_to_wstring(element.key())) {
					line.replace(line.find(first_part), first_part.length() + 4, Convert_string_to_wstring(element.value()));
					exit = true;
					break;
				}
		}
	}
}
// method for converting labels from RIS to TXT, in a certain sequence
void ALL::Strict_Transformation(string type) {
	wstring temporary_line, temporary_part;
	vector<wstring> fragment_here = Get_Fragment_File();
	json json_value;
	bool exit;
	ifstream mark_file("Mark_from_RIS_to_TXT.json");
	mark_file >> json_value;
	mark_file.close();
	line.clear();
	/*if (type == "BOOK")
		json_size_object++;*/
	for (int index = 0; index < json_value[type].size(); index++) {
		exit = false;
		for (int index_fragment = 0; index_fragment < fragment_here.size(); index_fragment++) {
			// Entrance
			if (exit) break;
			temporary_line = fragment_here[index_fragment];
			temporary_part.clear();
			// define the RIS label
			temporary_part.insert(0, temporary_line, 0, 2);
			// rework
			// replace label SN for type BOOK
			if (type == "BOOK" && temporary_part == L"SN" && index == json_value[type].size() - 1) {
				int pos;
				temporary_line.replace(temporary_line.find(temporary_part), temporary_part.length() + 4, L"\n#10: ^a");
				do {
					// delete data from parentheses
					temporary_line.replace(temporary_line.find(L"("), temporary_line.find(L")") - temporary_line.find(L"(") + 1, L"");
					pos = temporary_line.find(L"; ");
					if (pos < 0)
						break;
					temporary_line.replace(pos, 2, L"\n#10: ^a");
				} while (true);
				break;
			}
			// assign the beginning of an array of the appropriate type
			for (json::iterator element_file = json_value[type].begin(); element_file != json_value[type].end(); ++element_file) {
				// loop to find the appropriate object in the array
				for (json::iterator element_array = element_file.value().begin(); element_array != element_file.value().end(); ++element_array) {
					// Entrance
					if (exit) break;
					if (stoi(element_array.key()) == index) {
						// assign key and variable value
						for (json::iterator element_object = element_array.value().begin(); element_object != element_array.value().end(); ++element_object) {
							// substitute
							if (Convert_string_to_wstring(element_object.key()) == temporary_part && element_object.value() != "") {
								temporary_line.replace(temporary_line.find(temporary_part), temporary_part.length() + 4, Convert_string_to_wstring(element_object.value()));
								exit = true;
								break;
							}
						}
					}
				}
			}
		}
		line += temporary_line;
	}
}
//check ignore mark
bool ALL::Check_Ignore_Mark(wstring copy_part, string type){
	json json_value;
	ifstream file("Mark_Ignore.json");
	file >> json_value;
	file.close();
	for (json::iterator element = json_value[type].begin(); element != json_value[type].end(); ++element)
		if (copy_part == Convert_string_to_wstring(element.value()))
			return true;
	return false;
}
// method for writing the address in which the file fragment lies
void ALL::Set_Fragment_File(vector<wstring>& fragment) { this->fragment = fragment; }
// method for outputting the address in which the file fragment lies
vector<wstring>& ALL::Get_Fragment_File() { return this->fragment; }
// search for the specified character/word from right to left
bool ALL::RFind(wstring sentence, wstring word, int& position) {
	position = sentence.rfind(word);
	if (position > 0)
		return true;
	else
		return false;
}
// write the DB label
void ALL::Set_Mark_DB(wstring mark_DB) { this->mark_DB = mark_DB; }
// output DB label
wstring ALL::Get_Mark_DB() { return this->mark_DB; }
// initial value of each type
wstring ALL::Get_Start() { return L"#905: ^D1^11\n"; }
//label conversion method for JOUR file
void JOUR::Convert(string file_name_save) {
	wofstream file_write(file_name_save, ios::app);
	vector<wstring> fragment_here = Get_Fragment_File();
	file_write << Get_Start();
	for (int index = 0; index < fragment_here.size(); index++) {
		line = fragment_here[index];
		part.clear();
		// define the RIS label
		part.insert(0, line, 0, 2);
		// check whether to ignore the label or not
		if (Check_Ignore_Mark(part, "JOUR") || Check_Ignore_Mark(part, "ALL"))
			continue;
		else if (part == L"TY")
			line.assign(L"#920: ASP");
		else if (part == L"T2")
			Strict_Transformation("JOUR");
		else
			Free_Transformation(part);
		// write a string to a file
		file_write << line + L"\n";
	}
	file_write.close();
}
//label conversion method for CONF file
void CONF::Convert(string file_name_save) {
	wofstream file_write(file_name_save, ios::app);
	vector<wstring> fragment_here = Get_Fragment_File();
	file_write << Get_Start();
	for (int index = 0; index < fragment_here.size(); index++) {
		line = fragment_here[index];
		part.clear();
		// define the RIS label
		part.insert(0, line, 0, 2);
		// check whether to ignore the label or not
		if (Check_Ignore_Mark(part, "CONF") || Check_Ignore_Mark(part, "ALL"))
			continue;
		else if (part == L"TY")
			line.assign(L"#920: ASP");
		else if (part == L"C3")
			Strict_Transformation("CONF");
		else
			Free_Transformation(part);
		// write a string to a file
		file_write << line + L"\n";
	}
	file_write.close();
}
//label conversion method for BOOK file
void BOOK::Convert(string file_name_save) {
	wofstream file_write(file_name_save, ios::app);
	vector<wstring> fragment_here = Get_Fragment_File();
	file_write << Get_Start();
	for (int index = 0; index < fragment_here.size(); index++) {
		line = fragment_here[index];
		part.clear();
		// define the RIS label
		part.insert(0, line, 0, 2);
		// check whether to ignore the label or not
		if (Check_Ignore_Mark(part, "BOOK") || Check_Ignore_Mark(part, "ALL"))
			continue;
		else if (part == L"TY")
			line.assign(L"#920: PAZK");
		else if (part == L"EP") {
			line.replace(line.find(part), part.length() + 4, L"#215: ^A");
			line += L"^1p.";
		}
		else if (part == L"PY")
			Strict_Transformation("BOOK");
		else
			Free_Transformation(part);
		// write a string to a file
		file_write << line + L"\n";
	}
	file_write.close();
}

void Start_Convert::Set_File_Name(string file_name) { this->file_name = file_name; }

void Start_Convert::Start(ALL* type){ 
	type->Convert(file_name);
}