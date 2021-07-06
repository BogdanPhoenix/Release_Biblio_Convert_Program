#include "Converting.h"
#include "Start_Form.h"
#include "Finish_Form.h"

string way_file = "";
System::Void BiblioConvertProgram::Converting::button_Exit_Click(System::Object^ sender, System::EventArgs^ e)
{
    Application::Exit();
}

System::Void BiblioConvertProgram::Converting::button_Draw_Click(System::Object^ sender, System::EventArgs^ e)
{
    WindowState = FormWindowState::Minimized;
}

System::Void BiblioConvertProgram::Converting::button_Search_open_File_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ File_Name = "";// variable to save the path to the file
    // list of available types to read
    openFileDialog1->Filter = "Type file(*.ris)|*.ris| All files (*.*)|*.*";
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

System::Void BiblioConvertProgram::Converting::button_Search_save_File_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ File_Name = "";// variable to save the path to the file
    // list of available types for writing
    saveFileDialog1->Filter = "Type file(*.txt)|*.txt| All files(*.*)|*.*";
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

System::Void BiblioConvertProgram::Converting::button_Convert_Click(System::Object^ sender, System::EventArgs^ e)
{
    string file_name_RIS, file_name_TXT;
    Convert_String_to_string(textBox_openFile->Text->ToString(), file_name_RIS);
    Convert_String_to_string(textBox_save_File->Text->ToString(), file_name_TXT);
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
        if (!Read(file_name_RIS, file_name_TXT)) {
            MessageBox::Show("Рекомендовано завершити роботу програми! \nЗв'яжіться з техпідтримкою.", "Увага");
            Application::Exit();
        }
        else {
            Finish_Form^ finish_form = gcnew Finish_Form();
            this->Hide();
            finish_form->Show();
        }
    }
}

System::Void BiblioConvertProgram::Converting::button_Back_Click(System::Object^ sender, System::EventArgs^ e)
{
    Start_Form^ start = gcnew Start_Form();
    this->Hide();
    start->Show();
}

System::Void BiblioConvertProgram::Converting::button_Close_Click(System::Object^ sender, System::EventArgs^ e)
{
    // check exit
    return_from_exit->Show();
}
