#include "Start_Form.h"

[STAThreadAttribute]
int main(cli::array<System::String^>^ args) {
	System::Text::Encoding^ win1251 = System::Text::Encoding::GetEncoding(1251);
	System::Text::Encoding^ utf8 = gcnew System::Text::UTF8Encoding(false, false);

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	BiblioConvertProgram::Start_Form form;
	if (System_Check())
		Application::Run(% form);
	else
		Application::Exit();
}
//exit window
System::Void BiblioConvertProgram::Start_Form::button_Exit_Click(System::Object^ sender, System::EventArgs^ e) { Application::Exit(); }
// minimizes the window to the taskbar
System::Void BiblioConvertProgram::Start_Form::button_Draw_Click(System::Object^ sender, System::EventArgs^ e) { WindowState = FormWindowState::Minimized; }
// open the information window
System::Void BiblioConvertProgram::Start_Form::label_Info_Click(System::Object^ sender, System::EventArgs^ e) { info->Show(); }
// open the converter type selection window
System::Void BiblioConvertProgram::Start_Form::button_Convert_Click(System::Object^ sender, System::EventArgs^ e)
{
	Converting_Type^ conv = gcnew Converting_Type();
	this->Hide();
	conv->Show();
}
