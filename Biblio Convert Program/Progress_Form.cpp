#include "Progress_Form.h"

BiblioConvertProgram::Progress_Form::Progress_Form(string name_open_file, string name_save_file, int Combo_Index)
{
    InitializeComponent();
    this->name_open_file = &name_open_file;
    this->name_save_file = &name_save_file;
    this->Combo_Index = Combo_Index;
}

//System::Void BiblioConvertProgram::Progress_Form::Progress_Form_Validated(System::Object^ sender, System::EventArgs^ e)
//{
//    this->Show();
//    Variant_Convert* object;
//    Open_Variant_Convert open;
//    open.Set_Open_File(*name_open_file);
//    open.Set_Save_File(*name_save_file);
//    // converter type
//    switch (Combo_Index) {
//    case 0:  object = new from_RIS_to_TXT; break;
//    }
//    open.Start_Program(object);
//    delete object;
//
//    Finish_Form^ finish_form = gcnew Finish_Form();
//    finish_form->Set_Way_File(Convert_string_to_String(*name_save_file));
//    this->Hide();
//    finish_form->Show();
//}

//System::Void BiblioConvertProgram::Progress_Form::Progress_Form_Enter(System::Object^ sender, System::EventArgs^ e)
//{
//    Variant_Convert* object;
//    Open_Variant_Convert open;
//    open.Set_Open_File(*name_open_file);
//    open.Set_Save_File(*name_save_file);
//    // converter type
//    switch (Combo_Index) {
//    case 0:  object = new from_RIS_to_TXT; break;
//    }
//    open.Start_Program(object);
//    delete object;
//
//    Finish_Form^ finish_form = gcnew Finish_Form();
//    finish_form->Set_Way_File(Convert_string_to_String(*name_save_file));
//    this->Hide();
//    finish_form->Show();
//}

//void BiblioConvertProgram::Progress_Form::Start_Progress(string& name_open_file, string& name_save_file, int Combo_Index)
//{
//    Variant_Convert* object;
//    Open_Variant_Convert open;
//    open.Set_Open_File(name_open_file);
//    open.Set_Save_File(name_save_file);
//    // converter type
//    switch (Combo_Index) {
//        case 0:  object = new from_RIS_to_TXT; break;
//    }
//    open.Start_Program(object);
//    delete object;
//    //this->Hide();
//}

//System::Void BiblioConvertProgram::Progress_Form::Progress_Form_Activated(System::Object^ sender, System::EventArgs^ e)
//{
//    Variant_Convert* object;
//    Open_Variant_Convert open;
//    open.Set_Open_File(*name_open_file);
//    open.Set_Save_File(*name_save_file);
//    // converter type
//    switch (Combo_Index) {
//    case 0:  object = new from_RIS_to_TXT; break;
//    }
//    open.Start_Program(object);
//    delete object;
//    
//    Finish_Form^ finish_form = gcnew Finish_Form();
//    finish_form->Set_Way_File(Convert_string_to_String(*name_save_file));
//    this->Hide();
//    finish_form->Show();
//}
