#include "Check_Exit.h"
//exit
System::Void BiblioConvertProgram::Check_Exit::button_Yes_Click(System::Object^ sender, System::EventArgs^ e) { Application::Exit(); }
// closes the exit confirmation window and returns the window from which this command was called
System::Void BiblioConvertProgram::Check_Exit::button_No_Click(System::Object^ sender, System::EventArgs^ e) { this->Hide(); }