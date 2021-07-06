#include "Start_Form.h"
#include "Info.h"
#include "Converting.h"
#include "Function.h"

[STAThreadAttribute]
int main(cli::array<System::String^>^ args) {
	System::Text::Encoding^ win1251 = System::Text::Encoding::GetEncoding(1251);
	System::Text::Encoding^ utf8 = gcnew System::Text::UTF8Encoding(false, false);

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	BiblioConvertProgram::Start_Form form;
	Application::Run(% form);
	if (!System_Check())
		Application::Exit();
	else
		Application::Run(% form);
}

System::Void BiblioConvertProgram::Start_Form::button_Exit_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();
}

System::Void BiblioConvertProgram::Start_Form::button_Draw_Click(System::Object^ sender, System::EventArgs^ e)
{
	WindowState = FormWindowState::Minimized;
}

System::Void BiblioConvertProgram::Start_Form::label_Info_Click(System::Object^ sender, System::EventArgs^ e)
{
	info->Show();
}

System::Void BiblioConvertProgram::Start_Form::button_Convert_Click(System::Object^ sender, System::EventArgs^ e)
{
	Converting^ conv = gcnew Converting();
	this->Hide();
	conv->Show();
}
