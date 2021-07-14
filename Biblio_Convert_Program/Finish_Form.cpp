#include "Finish_Form.h"
//exit window
System::Void BiblioConvertProgram::Finish_Form::button_Exit_Click(System::Object^ sender, System::EventArgs^ e) { Application::Exit(); }
// minimizes the window to the taskbar
System::Void BiblioConvertProgram::Finish_Form::button_Draw_Click(System::Object^ sender, System::EventArgs^ e) { WindowState = FormWindowState::Minimized; }
// opens the converted file and terminates the program
System::Void BiblioConvertProgram::Finish_Form::button_Finish_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (checkBox_Open->Checked == true)
        Process::Start("notepad.exe", Convert_string_to_String(way_file));
    Application::Exit();
}
// opens the converted file and goes to the home screen
System::Void BiblioConvertProgram::Finish_Form::button_Back_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (checkBox_Open->Checked == true)
        Process::Start("notepad.exe", Convert_string_to_String(way_file));
    Start_Form^ start = gcnew Start_Form();
    this->Hide();
    start->Show();
}


