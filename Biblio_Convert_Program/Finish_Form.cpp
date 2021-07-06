#include "Finish_Form.h"
#include "Converting.h"
#include "Start_Form.h"

System::Void BiblioConvertProgram::Finish_Form::button_Exit_Click(System::Object^ sender, System::EventArgs^ e)
{
    Application::Exit();
}

System::Void BiblioConvertProgram::Finish_Form::button_Draw_Click(System::Object^ sender, System::EventArgs^ e)
{
    WindowState = FormWindowState::Minimized;
}

System::Void BiblioConvertProgram::Finish_Form::button_Finish_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (checkBox_Open->Checked == true)
        Process::Start("notepad.exe", Convert_string_to_String(way_file));
    Application::Exit();
}

System::Void BiblioConvertProgram::Finish_Form::button_Back_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (checkBox_Open->Checked == true)
        Process::Start("notepad.exe", Convert_string_to_String(way_file));
    Start_Form^ start = gcnew Start_Form();
    this->Hide();
    start->Show();
}


