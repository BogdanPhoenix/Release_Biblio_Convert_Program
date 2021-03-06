#include "Converting.h"
//constructor
BiblioConvertProgram::Converting::Converting(String^ text, int Combo_Index) {
    InitializeComponent();
    textBox_Variant_Convert->Text = text;
    this->Combo_Index = Combo_Index;
    // we make the main form parental
    return_exit = gcnew Check_Exit();
    return_exit->Owner = this;
    return_exit->Hide();
}
// function to check if the file is empty and ask the user whether to delete the previous contents of this file
void BiblioConvertProgram::Converting::Check_File_Is_Empty(String^ file_name){
    string name;
    Convert_Character_Data_Type::Convert_String_to_string(file_name, name);
    fstream file(name, ios::in);
    if (!Function::Is_empty(file)) {
        checkBox_Full_File->Visible = true;
        checkBox_Full_File->Text = "???????? ????? ????? " + file_name;
        checkBox_Full_File->Checked = true;
        MessageBox::Show("????? ???? " + file_name + ", ?? ? ??????. \n???? ?? ?? ??????, ??? ???? ???? ????????, ???? ????? ????????? ????????? ? ???????????? ????", "?????");
    }
    else
        checkBox_Full_File->Visible = false;
    file.close();
}
// determine the file to be converted
System::Void BiblioConvertProgram::Converting::button_Search_open_File_Click(System::Object^ sender, System::EventArgs^ e){
    // list of available types to read
    switch (Combo_Index) {
        case 0: openFileDialog1->Filter = "Type file(*.ris)|*.ris| All files (*.*)|*.*"; break;
    }
    String^ File_Name = "";// variable to save the path to the file
    // open the dialog box, if the user clicks "OK" then his path will be written to a variable to save the path
    if (openFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK) {
        File_Name = openFileDialog1->FileName;
        label_Open_Check->Text = "";
    }
    else
        label_Open_Check->Text = "???? ???? ???????";
    // error check
    try { textBox_open_File->Text = File_Name; }
    catch (Exception^ ex) { MessageBox::Show(this, "?? ??????? ???????? ????! \n???????: " + ex->ToString(), "???????", MessageBoxButtons::OK, MessageBoxIcon::Error); }
}
// determine the file in which you want to save the converted data
System::Void BiblioConvertProgram::Converting::button_Search_save_File_Click(System::Object^ sender, System::EventArgs^ e) {
    // list of available types for writing
    switch (Combo_Index) {
        case 0: saveFileDialog1->Filter = "Type file(*.txt)|*.txt| All files(*.*)|*.*"; break;
    }
    String^ File_Name = "";// variable to save the path to the file
    // open the dialog box, if the user clicks "OK" then his path will be written to a variable to save the path
    if (saveFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK) {
        File_Name = saveFileDialog1->FileName;
        label_Save_Check->Text = "";
    }
    else
        label_Save_Check->Text = "???? ???? ???????";
    // error check
    try { textBox_save_File->Text = File_Name; }
    catch (Exception^ ex) { MessageBox::Show(this, "?? ??????? ???????? ????! \n???????: " + ex->ToString(), "???????", MessageBoxButtons::OK, MessageBoxIcon::Error); }
    Check_File_Is_Empty(File_Name);
}
// file conversion
System::Void BiblioConvertProgram::Converting::button_Convert_Click(System::Object^ sender, System::EventArgs^ e){
    // check if the user specified the path to the file
    if (textBox_open_File->Text == "C:\\" || textBox_save_File->Text == "C:\\") 
        MessageBox::Show("?? ???????? ?????? ?????. \n???? ????? ????????? ??.", "?????");
    else {
        string name_open_file, name_save_file;
        //record the name of the file to be converted
        Convert_Character_Data_Type::Convert_String_to_string(textBox_open_File->Text->ToString(), name_open_file);
        //record the name of the file to which you want to convert
        Convert_Character_Data_Type::Convert_String_to_string(textBox_save_File->Text->ToString(), name_save_file);
        if (checkBox_Full_File->Checked == true) {
            wofstream file_save(name_save_file, ios::trunc);
            file_save.close();
        }
        Variant_Convert* object;
        Open_Variant_Convert open;
        open.Set_Open_File(name_open_file);
        open.Set_Save_File(name_save_file);
        // converter type
        switch (Combo_Index) {
            case 0:  object = new from_RIS_to_TXT; break;
        }
        open.Start_Program(object);
        delete object;
        this->Enabled;
        Finish_Form^ finish_form = gcnew Finish_Form();
        finish_form->Set_Way_File(Convert_Character_Data_Type::Convert_string_to_String(name_save_file));
        this->Hide();
        finish_form->Show();
    }
}
//exit window
System::Void BiblioConvertProgram::Converting::button_Exit_Click(System::Object^ sender, System::EventArgs^ e) { Application::Exit(); }
// minimizes the window to the taskbar
System::Void BiblioConvertProgram::Converting::button_Draw_Click(System::Object^ sender, System::EventArgs^ e) { WindowState = FormWindowState::Minimized; }
// returns to the starting form
System::Void BiblioConvertProgram::Converting::?????????????ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    Start_Form^ start_form = gcnew Start_Form();
    this->Hide();
    start_form->Show();
}
// returns to the file conversion type selection form
System::Void BiblioConvertProgram::Converting::???????????????????????ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    Converting_Type^ converting_type = gcnew Converting_Type();
    this->Hide();
    converting_type->Show();
}
// button for great work
System::Void BiblioConvertProgram::Converting::button_Close_Click(System::Object^ sender, System::EventArgs^ e) { return_exit->Show(); }