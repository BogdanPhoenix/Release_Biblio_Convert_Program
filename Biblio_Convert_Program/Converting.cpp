#include "Converting.h"

string way_file = "";
// determine the file to be converted
System::Void BiblioConvertProgram::Converting::button_Search_open_File_Click(System::Object^ sender, System::EventArgs^ e)
{
    // list of available types to read
    switch (comboBox_Variant->SelectedIndex) {
    case 0: openFileDialog1->Filter = "Type file(*.ris)|*.ris| All files (*.*)|*.*"; break;
    }
    String^ File_Name = "";// variable to save the path to the file
    // open the dialog box, if the user clicks "OK" then his path will be written to a variable to save the path
    if (openFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK)
        File_Name = openFileDialog1->FileName;
    // error check
    try {
        textBox_openFile->Text = File_Name;
    }
    catch (Exception^ ex) {
        MessageBox::Show(this, "Не вдалося відкрити файл!", "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}
// determine the file in which you want to save the converted data
System::Void BiblioConvertProgram::Converting::button_Search_save_File_Click(System::Object^ sender, System::EventArgs^ e)
{
    // list of available types for writing
    switch (comboBox_Variant->SelectedIndex) {
    case 0: saveFileDialog1->Filter = "Type file(*.txt)|*.txt| All files(*.*)|*.*"; break;
    }
    String^ File_Name = "";// variable to save the path to the file
    // open the dialog box, if the user clicks "OK" then his path will be written to a variable to save the path
    if (saveFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK)
        File_Name = saveFileDialog1->FileName;
    // error check
    try {
        textBox_save_File->Text = File_Name;
    }
    catch (Exception^ ex) {
        MessageBox::Show(this, "Не вдалося відкрити файл!", "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
    Convert_String_to_string(File_Name, way_file);
}
// start the program and check if the user has filled in all the required fields
System::Void BiblioConvertProgram::Converting::button_Convert_Click(System::Object^ sender, System::EventArgs^ e)
{
    // check if the user specified the path to the file
    if (textBox_openFile->Text == "C:\\" || textBox_save_File->Text == "C:\\") {
        if (textBox_openFile->Text == "C:\\")
            label_Open->Text = "Дане поле порожнє";
        else
            label_Open->Text = "";
        if (textBox_save_File->Text == "C:\\")
            label_Save->Text = "Дане поле порожнє";
        else
            label_Save->Text = "";
        MessageBox::Show("Не вистачає деяких даних. \nБудь ласка заповніть їх.", "Увага");
    }
    else {
        string name_open_file, name_save_file;
        Convert_String_to_string(textBox_openFile->Text->ToString(), name_open_file);
        Convert_String_to_string(textBox_save_File->Text->ToString(), name_save_file);
        Open_Variant_Convert open;
        open.Set_Open_File(name_open_file);
        open.Set_Save_File(name_save_file);

        switch (comboBox_Variant->SelectedIndex) {
        case 0: {
            from_RIS_to_TXT object;
            open.Start_Program(object);
            break;
        }
        }
        Finish_Form^ finish_form = gcnew Finish_Form();
        this->Hide();
        finish_form->Show();
    }
}
// returns to the starting form
System::Void BiblioConvertProgram::Converting::стартовийЕкранToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    Start_Form^ start_form = gcnew Start_Form();
    this->Hide();
    start_form->Show();
}
// returns to the file conversion type selection form
System::Void BiblioConvertProgram::Converting::полеВиборуКонвертатораToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    Converting_Type^ converting_type = gcnew Converting_Type();
    this->Hide();
    converting_type->Show();
}
// button for great work
System::Void BiblioConvertProgram::Converting::button_Close_Click(System::Object^ sender, System::EventArgs^ e) { return_exit->Show(); }
//exit window
System::Void BiblioConvertProgram::Converting::button_Exit_Click(System::Object^ sender, System::EventArgs^ e) { Application::Exit(); }
// minimizes the window to the taskbar
System::Void BiblioConvertProgram::Converting::button_Draw_Click(System::Object^ sender, System::EventArgs^ e) { WindowState = FormWindowState::Minimized; }