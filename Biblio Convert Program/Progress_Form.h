#pragma once
#include "Class_Type.h"
#include "Finish_Form.h"
#include "Convert_Character_Data_Type.h"
namespace BiblioConvertProgram {

	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� Progress_Form
	/// </summary>
	public ref class Progress_Form : public System::Windows::Forms::Form
	{
	private: 
		string *name_open_file, *name_save_file;



		   int Combo_Index;
	public:
		Progress_Form(string name_open_file, string name_save_file, int Combo_Index);
		//void Start_Progress(string& name_open_file, string& name_save_file, int Combo_Index);
	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~Progress_Form()
		{
			if (components)
			{
				delete components, name_open_file, name_save_file;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label_Info;
	protected:


	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label_Info = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label_Info);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(494, 294);
			this->panel1->TabIndex = 0;
			// 
			// label_Info
			// 
			this->label_Info->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(104)), static_cast<System::Int32>(static_cast<System::Byte>(236)),
				static_cast<System::Int32>(static_cast<System::Byte>(190)));
			this->label_Info->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label_Info->Location = System::Drawing::Point(0, 0);
			this->label_Info->Name = L"label_Info";
			this->label_Info->Size = System::Drawing::Size(494, 294);
			this->label_Info->TabIndex = 0;
			this->label_Info->Text = L"���� ����� ���������.\r\n����������� ����������� �����.\r\n�� ���� ������� ������ ��"
				L"�";
			this->label_Info->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Progress_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(120, 120);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->ClientSize = System::Drawing::Size(494, 294);
			this->ControlBox = false;
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Name = L"Progress_Form";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	//private: System::Void Progress_Form_Activated(System::Object^ sender, System::EventArgs^ e);
	//private: System::Void Progress_Form_Enter(System::Object^ sender, System::EventArgs^ e);
	//private: System::Void Progress_Form_Validated(System::Object^ sender, System::EventArgs^ e);
};
}
