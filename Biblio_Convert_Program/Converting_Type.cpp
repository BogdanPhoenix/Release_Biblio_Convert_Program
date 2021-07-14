#include "Converting_Type.h"
// select the type of converter
System::Void BiblioConvertProgram::Converting_Type::comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
    if (comboBox_Type->SelectedIndex >= 0) {
        label_comboBox_Type->Text = "";
        Converting convert(comboBox_Type->SelectedIndex);
        Converting^ return_converting = gcnew Converting();
        this->Hide();
        return_converting->Show();
    }
    else {
        label_comboBox_Type->Text = "Ви не вибрали варіант конвертації";
        MessageBox::Show("Сталася помилка. \nПрограма завершила свою роботу.", "Увага");
    }
}
//exit
System::Void BiblioConvertProgram::Converting_Type::button_Exit_Click(System::Object^ sender, System::EventArgs^ e) { Application::Exit(); }
// minimizes the window to the taskbar
System::Void BiblioConvertProgram::Converting_Type::button_Draw_Click(System::Object^ sender, System::EventArgs^ e) { WindowState = FormWindowState::Minimized; }
// return to the home screen
System::Void BiblioConvertProgram::Converting_Type::стартовийЕкранToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    Start_Form^ start_form = gcnew Start_Form();
    this->Hide();
    start_form->Show();
}