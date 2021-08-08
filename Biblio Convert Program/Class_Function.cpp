#include "Class_Function.h"

//class ALL
// implement AU label change
void ALL::Work_AU(const wstring& part) {
	wstring text;
	// TXT tag for the first author or for other authors
	text = number_AU++ == 0 ? L"#700: ^A" : L"#701: ^A";
	// replace labels
	line.replace(line.find(part), line.find(size_delete_dash) + size_delete_dash.size(), text);
	line.replace(line.find(L", "), 2, L"^B");
}
// implement label change AD
void ALL::Work_AD(const wstring& part) {
	int pos_str;
	json json_value;
	ifstream file("Country_Code.json");
	file >> json_value;
	file.close();
	// replace labels
	line.replace(line.find(part), line.find(size_delete_dash) + size_delete_dash.size(), L"#711: ^A");
	line.replace(line.rfind(L", "), 2, L"^S");
	// replace the country name with its code
	for (auto it : json_value.items()) {
		pos_str = line.rfind(Convert_string_to_wstring(it.key()));
		if (pos_str >= 0) {
			line.replace(pos_str, it.key().length(), Convert_string_to_wstring(it.value()));
			break;
		}
	}
}
// implement LA tag change
void ALL::Work_LA(const wstring& part) {
	wstring language;
	json json_value;
	ifstream file("Language_Code.json");
	file >> json_value;
	file.close();
	// Language search
	language.append(line.begin() + line.find(size_delete_dash) + size_delete_dash.size(), line.end());
	// replace the language with its code
	for (auto element : json_value.items())
		if (language == Convert_string_to_wstring(element.key())) {
			line.replace(line.find(language), language.length(), Convert_string_to_wstring(element.value()));
			break;
		}
	// label replacement
	line.replace(line.find(part), part.length() + 4, L"#101: ");
}
// implementation of replacement of RIS label by TXT (common for all types)
void ALL::Free_Transformation(const wstring& first_part) {
	json json_value;
	ifstream file("Mark_from_RIS_to_TXT.json");
	file >> json_value;
	file.close();

	if (first_part == L"DB") {
		wstring DB;
		Set_Mark_DB(DB.append(line.begin() + line.find(size_delete_dash) + size_delete_dash.size(), line.end()));
		line.replace(line.find(first_part), line.find(size_delete_dash) + size_delete_dash.size(), L"#902: ^A");
	}
	else if (first_part == L"AU")
		Work_AU(first_part);
	else if (first_part == L"AD")
		Work_AD(first_part);
	else if (first_part == L"LA")
		Work_LA(first_part);
	else if (first_part == L"UR") {
		line.replace(line.find(first_part), line.find(size_delete_dash) + size_delete_dash.size(), L"#951: ^I");
		line += L"^T" + Get_Mark_DB();
	}
	// other labels
	else
		for (auto element_array : json_value["ALL"].items()) {
			auto element = element_array.value().begin();
			if (first_part == Convert_string_to_wstring(element.key())) {
				line.replace(line.find(first_part), line.find(size_delete_dash) + size_delete_dash.size(), Convert_string_to_wstring(element.value()));
				break;
			}
		}
}
// method for converting labels from RIS to TXT, in a certain sequence
void ALL::Strict_Transformation(const string& type) {
	wstring temporary_line, temporary_part;
	vector<wstring> fragment_here = Get_Fragment_File();
	bool exit;
	json json_value;
	ifstream mark_file("Mark_from_RIS_to_TXT.json");
	mark_file >> json_value;
	mark_file.close();
	line.clear();
	for (size_t index = 0; index < json_value[type].size(); index++) {
		exit = false;
		for (size_t index_fragment_here = 0; index_fragment_here < fragment_here.size(); index_fragment_here++) {
			// Entrance
			if (exit) break;
			temporary_line = fragment_here[index_fragment_here];
			temporary_part.clear();
			// define the RIS label
			temporary_part.insert(0, temporary_line, 0, 2);
			// assign the beginning of an array of the appropriate type
			for (auto element_file : json_value[type].items()) 
				// check the index of the conversion sequence
				if (stoi(element_file.key()) == index) {
					// search for the required label
					auto element_object = element_file.value().begin();
					// substitute
					if (Convert_string_to_wstring(element_object.key()) == temporary_part) {
						temporary_line.replace(temporary_line.find(temporary_part), temporary_line.find(size_delete_dash) + size_delete_dash.size(), Convert_string_to_wstring(element_object.value()));
						fragment_here.erase(fragment_here.begin() + index_fragment_here);
						fragment.erase(fragment.begin() + index_fragment_here);
						if (index_fragment_here <= index_the_main_fragment)
							index_the_main_fragment--;
						exit = true;
						break;
					}
				}
		}
		line += temporary_line;
	}
	// replace label SN for type BOOK
	auto result = find_if(fragment_here.begin(), fragment_here.end(), [&](const wstring& find_fragment) { return !find_fragment.find(L"SN"); });
	if (result != fragment_here.end() && type == "BOOK") {
		int pos;
		result->replace(result->find(L"SN"), result->find(size_delete_dash) + size_delete_dash.size(), L"\n#10: ^a");
		do {
			//rework
			// delete data from parentheses
			result->replace(result->find(L"("), result->find(L")") - result->find(L"(") + 1, L"");
			pos = result->find(L"; ");
			if (pos < 0) break;
			result->replace(pos, 2, L"\n#10: ^a");
		} while (true);
		line += *result;
	}
}
//check ignore mark
bool ALL::Check_Ignore_Mark(const wstring& copy_part, const string& type) {
	json json_value;
	ifstream file("Mark_Ignore.json");
	file >> json_value;
	file.close();
	auto result = find_if(begin(json_value[type]), end(json_value[type]), [&copy_part](json element) {return copy_part == Convert_string_to_wstring(element); });
	if (result != json_value[type].end())
		return true;
	return false;
}
// method for writing the address in which the file fragment lies
void ALL::Set_Fragment_File(vector<wstring>& fragment) { this->fragment = fragment; }
// method for outputting the address in which the file fragment lies
vector<wstring>& ALL::Get_Fragment_File() { return this->fragment; }
// write the DB label
void ALL::Set_Mark_DB(const wstring& mark_DB) { this->mark_DB = mark_DB; }
// output DB label
wstring ALL::Get_Mark_DB() { return this->mark_DB; }
// initial value of each type
wstring ALL::Get_Start() { return L"#905: ^D1^11\n"; }
//label conversion method for JOUR file
void JOUR::Convert(const string& file_name_save) {
	wofstream file_write(file_name_save, ios::app);
	file_write << Get_Start();
	for (index_the_main_fragment = 0; index_the_main_fragment < Get_Fragment_File().size(); index_the_main_fragment++) {
		line = Get_Fragment_File()[index_the_main_fragment];
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
void CONF::Convert(const string& file_name_save) {
	wofstream file_write(file_name_save, ios::app);
	file_write << Get_Start();
	for (index_the_main_fragment = 0; index_the_main_fragment < Get_Fragment_File().size(); index_the_main_fragment++) {
		line = Get_Fragment_File()[index_the_main_fragment];
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
void BOOK::Convert(const string& file_name_save) {
	wofstream file_write(file_name_save, ios::app);
	file_write << Get_Start();
	for (index_the_main_fragment = 0; index_the_main_fragment < Get_Fragment_File().size(); index_the_main_fragment++) {
		line = Get_Fragment_File()[index_the_main_fragment];
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
// enter the name of the file in which you want to enter the converted information
void Start_Convert::Set_File_Name(const string& file_name) { this->file_name = file_name; }
//start program
void Start_Convert::Start(ALL* type) { type->Convert(file_name); }