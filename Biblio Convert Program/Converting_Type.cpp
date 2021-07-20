#include "Converting_Type.h"
// determine the type of conversion
System::Void BiblioConvertProgram::Converting_Type::comboBox_Type_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
    Converting^ return_converting = gcnew Converting(comboBox_Type->Text, comboBox_Type->SelectedIndex);
    this->Hide();
    return_converting->Show();
}
// return to the home screen
System::Void BiblioConvertProgram::Converting_Type::ãîëîâíèéÅêðàíToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
    Start_Form^ start_form = gcnew Start_Form();
    this->Hide();
    start_form->Show();
}
//exit
System::Void BiblioConvertProgram::Converting_Type::button_Exit_Click(System::Object^ sender, System::EventArgs^ e) { Application::Exit(); }
// minimizes the window to the taskbar
System::Void BiblioConvertProgram::Converting_Type::button_Draw_Click(System::Object^ sender, System::EventArgs^ e) { WindowState = FormWindowState::Minimized; }