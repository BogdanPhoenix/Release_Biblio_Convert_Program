#include "Check_Exit.h"
#include "Converting.h"

System::Void BiblioConvertProgram::Check_Exit::button_Yes_Click(System::Object^ sender, System::EventArgs^ e)
{
    Application::Exit();
}

System::Void BiblioConvertProgram::Check_Exit::button_No_Click(System::Object^ sender, System::EventArgs^ e)
{
    // close the window
    this->Hide();
}
