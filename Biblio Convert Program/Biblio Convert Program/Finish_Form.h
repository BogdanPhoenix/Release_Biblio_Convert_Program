#pragma once
#include "Converting.h"
#include "Start_Form.h"

namespace BiblioConvertProgram {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Diagnostics;// to open the file by pressing the button

	/// <summary>
	/// Сводка для Finish_Form
	/// </summary>
	public ref class Finish_Form : public System::Windows::Forms::Form
	{
	private: String^ way_file;
	public:
		Finish_Form(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
		void Set_Way_File(String^ way_file);
		String^ Get_Way_File();


	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Finish_Form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::Button^ button_Draw;
	private: System::Windows::Forms::Button^ button_Exit;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::CheckBox^ checkBox_Open;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Button^ button_Back;

	private: System::Windows::Forms::Button^ button_Finish;


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button_Draw = (gcnew System::Windows::Forms::Button());
			this->button_Exit = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->checkBox_Open = (gcnew System::Windows::Forms::CheckBox());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->button_Back = (gcnew System::Windows::Forms::Button());
			this->button_Finish = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel4->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(104)), static_cast<System::Int32>(static_cast<System::Byte>(236)),
				static_cast<System::Int32>(static_cast<System::Byte>(190)));
			this->panel1->Controls->Add(this->button_Draw);
			this->panel1->Controls->Add(this->button_Exit);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Margin = System::Windows::Forms::Padding(0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(579, 40);
			this->panel1->TabIndex = 2;
			// 
			// button_Draw
			// 
			this->button_Draw->BackColor = System::Drawing::Color::Blue;
			this->button_Draw->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button_Draw->Dock = System::Windows::Forms::DockStyle::Right;
			this->button_Draw->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_Draw->Font = (gcnew System::Drawing::Font(L"Times New Roman", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_Draw->ForeColor = System::Drawing::Color::White;
			this->button_Draw->Location = System::Drawing::Point(480, 0);
			this->button_Draw->Margin = System::Windows::Forms::Padding(0);
			this->button_Draw->Name = L"button_Draw";
			this->button_Draw->Size = System::Drawing::Size(46, 40);
			this->button_Draw->TabIndex = 2;
			this->button_Draw->Text = L"-";
			this->button_Draw->UseVisualStyleBackColor = false;
			this->button_Draw->Click += gcnew System::EventHandler(this, &Finish_Form::button_Draw_Click);
			// 
			// button_Exit
			// 
			this->button_Exit->BackColor = System::Drawing::Color::Red;
			this->button_Exit->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button_Exit->Dock = System::Windows::Forms::DockStyle::Right;
			this->button_Exit->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_Exit->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16.2F, System::Drawing::FontStyle::Bold));
			this->button_Exit->ForeColor = System::Drawing::Color::White;
			this->button_Exit->Location = System::Drawing::Point(526, 0);
			this->button_Exit->Margin = System::Windows::Forms::Padding(0);
			this->button_Exit->Name = L"button_Exit";
			this->button_Exit->Size = System::Drawing::Size(53, 40);
			this->button_Exit->TabIndex = 1;
			this->button_Exit->Text = L"X";
			this->button_Exit->UseVisualStyleBackColor = false;
			this->button_Exit->Click += gcnew System::EventHandler(this, &Finish_Form::button_Exit_Click);
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->label1);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel2->Location = System::Drawing::Point(0, 40);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(579, 120);
			this->panel2->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(104)), static_cast<System::Int32>(static_cast<System::Byte>(236)),
				static_cast<System::Int32>(static_cast<System::Byte>(190)));
			this->label1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label1->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 19.8F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(0, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(579, 120);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Файл конвертовано";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(104)), static_cast<System::Int32>(static_cast<System::Byte>(236)),
				static_cast<System::Int32>(static_cast<System::Byte>(190)));
			this->panel3->Controls->Add(this->checkBox_Open);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->panel3->Location = System::Drawing::Point(0, 160);
			this->panel3->Name = L"panel3";
			this->panel3->Padding = System::Windows::Forms::Padding(0, 50, 0, 50);
			this->panel3->Size = System::Drawing::Size(579, 144);
			this->panel3->TabIndex = 4;
			// 
			// checkBox_Open
			// 
			this->checkBox_Open->AutoSize = true;
			this->checkBox_Open->Cursor = System::Windows::Forms::Cursors::Hand;
			this->checkBox_Open->Dock = System::Windows::Forms::DockStyle::Right;
			this->checkBox_Open->Location = System::Drawing::Point(337, 50);
			this->checkBox_Open->MaximumSize = System::Drawing::Size(242, 60);
			this->checkBox_Open->MinimumSize = System::Drawing::Size(242, 60);
			this->checkBox_Open->Name = L"checkBox_Open";
			this->checkBox_Open->Size = System::Drawing::Size(242, 60);
			this->checkBox_Open->TabIndex = 0;
			this->checkBox_Open->Text = L"Відкрити конвертований файл";
			this->checkBox_Open->UseVisualStyleBackColor = true;
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(104)), static_cast<System::Int32>(static_cast<System::Byte>(236)),
				static_cast<System::Int32>(static_cast<System::Byte>(190)));
			this->panel4->Controls->Add(this->button_Back);
			this->panel4->Controls->Add(this->button_Finish);
			this->panel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->panel4->Location = System::Drawing::Point(0, 304);
			this->panel4->Name = L"panel4";
			this->panel4->Padding = System::Windows::Forms::Padding(55, 45, 55, 55);
			this->panel4->Size = System::Drawing::Size(579, 143);
			this->panel4->TabIndex = 5;
			// 
			// button_Back
			// 
			this->button_Back->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(125)),
				static_cast<System::Int32>(static_cast<System::Byte>(227)));
			this->button_Back->Dock = System::Windows::Forms::DockStyle::Right;
			this->button_Back->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_Back->ForeColor = System::Drawing::Color::White;
			this->button_Back->Location = System::Drawing::Point(282, 45);
			this->button_Back->MaximumSize = System::Drawing::Size(242, 52);
			this->button_Back->MinimumSize = System::Drawing::Size(242, 52);
			this->button_Back->Name = L"button_Back";
			this->button_Back->Size = System::Drawing::Size(242, 52);
			this->button_Back->TabIndex = 1;
			this->button_Back->Text = L"Головний екран";
			this->button_Back->UseVisualStyleBackColor = false;
			this->button_Back->Click += gcnew System::EventHandler(this, &Finish_Form::button_Back_Click);
			// 
			// button_Finish
			// 
			this->button_Finish->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(125)),
				static_cast<System::Int32>(static_cast<System::Byte>(227)));
			this->button_Finish->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button_Finish->Dock = System::Windows::Forms::DockStyle::Left;
			this->button_Finish->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_Finish->ForeColor = System::Drawing::Color::White;
			this->button_Finish->Location = System::Drawing::Point(55, 45);
			this->button_Finish->MaximumSize = System::Drawing::Size(202, 52);
			this->button_Finish->MinimumSize = System::Drawing::Size(202, 52);
			this->button_Finish->Name = L"button_Finish";
			this->button_Finish->Size = System::Drawing::Size(202, 52);
			this->button_Finish->TabIndex = 0;
			this->button_Finish->Text = L"Завершити";
			this->button_Finish->UseVisualStyleBackColor = false;
			this->button_Finish->Click += gcnew System::EventHandler(this, &Finish_Form::button_Finish_Click);
			// 
			// Finish_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(120, 120);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->ClientSize = System::Drawing::Size(579, 447);
			this->ControlBox = false;
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Name = L"Finish_Form";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->panel1->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button_Draw_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_Exit_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_Finish_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_Back_Click(System::Object^ sender, System::EventArgs^ e);
};
}
