#pragma once
#include "Info.h"
#include "Converting_Type.h"
#include "Function.h"
#include "Converting.h"

namespace BiblioConvertProgram {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Start_Form
	/// </summary>
	public ref class Start_Form : public System::Windows::Forms::Form
	{
	private: Info^ info;
	public:
		Start_Form(void)
		{
			InitializeComponent();
			info = gcnew Info();
			// we make the main form parental
			info->Owner = this;
			info->Hide();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Start_Form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ button_Draw;
	private: System::Windows::Forms::Button^ button_Exit;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label1;


	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Button^ button_Convert;


	private: System::Windows::Forms::Panel^ panel6;
	private: System::Windows::Forms::Label^ label_Info;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;

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
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->label_Info = (gcnew System::Windows::Forms::Label());
			this->button_Draw = (gcnew System::Windows::Forms::Button());
			this->button_Exit = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->button_Convert = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->panel1->SuspendLayout();
			this->panel6->SuspendLayout();
			this->panel2->SuspendLayout();
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
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(484, 40);
			this->panel1->TabIndex = 0;
			// 
			// panel6
			// 
			this->panel6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(104)), static_cast<System::Int32>(static_cast<System::Byte>(236)),
				static_cast<System::Int32>(static_cast<System::Byte>(190)));
			this->panel6->Controls->Add(this->label_Info);
			this->panel6->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel6->Location = System::Drawing::Point(0, 264);
			this->panel6->Name = L"panel6";
			this->panel6->Padding = System::Windows::Forms::Padding(7);
			this->panel6->Size = System::Drawing::Size(484, 40);
			this->panel6->TabIndex = 2;
			// 
			// label_Info
			// 
			this->label_Info->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(104)), static_cast<System::Int32>(static_cast<System::Byte>(236)),
				static_cast<System::Int32>(static_cast<System::Byte>(190)));
			this->label_Info->Cursor = System::Windows::Forms::Cursors::Hand;
			this->label_Info->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label_Info->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_Info->Location = System::Drawing::Point(7, 7);
			this->label_Info->Name = L"label_Info";
			this->label_Info->Size = System::Drawing::Size(470, 26);
			this->label_Info->TabIndex = 2;
			this->label_Info->Text = L"Про додаток";
			this->label_Info->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label_Info->Click += gcnew System::EventHandler(this, &Start_Form::label_Info_Click);
			// 
			// button_Draw
			// 
			this->button_Draw->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(88)), static_cast<System::Int32>(static_cast<System::Byte>(142)),
				static_cast<System::Int32>(static_cast<System::Byte>(231)));
			this->button_Draw->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button_Draw->Dock = System::Windows::Forms::DockStyle::Right;
			this->button_Draw->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_Draw->ForeColor = System::Drawing::Color::White;
			this->button_Draw->Location = System::Drawing::Point(384, 0);
			this->button_Draw->Name = L"button_Draw";
			this->button_Draw->Size = System::Drawing::Size(50, 40);
			this->button_Draw->TabIndex = 1;
			this->button_Draw->Text = L"-";
			this->button_Draw->UseVisualStyleBackColor = false;
			this->button_Draw->Click += gcnew System::EventHandler(this, &Start_Form::button_Draw_Click);
			// 
			// button_Exit
			// 
			this->button_Exit->BackColor = System::Drawing::Color::Red;
			this->button_Exit->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button_Exit->Dock = System::Windows::Forms::DockStyle::Right;
			this->button_Exit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_Exit->ForeColor = System::Drawing::Color::White;
			this->button_Exit->Location = System::Drawing::Point(434, 0);
			this->button_Exit->Name = L"button_Exit";
			this->button_Exit->Size = System::Drawing::Size(50, 40);
			this->button_Exit->TabIndex = 0;
			this->button_Exit->Text = L"X";
			this->button_Exit->UseVisualStyleBackColor = false;
			this->button_Exit->Click += gcnew System::EventHandler(this, &Start_Form::button_Exit_Click);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(104)), static_cast<System::Int32>(static_cast<System::Byte>(236)),
				static_cast<System::Int32>(static_cast<System::Byte>(190)));
			this->panel2->Controls->Add(this->label1);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::World,
				static_cast<System::Byte>(204)));
			this->panel2->Location = System::Drawing::Point(0, 40);
			this->panel2->Name = L"panel2";
			this->panel2->Padding = System::Windows::Forms::Padding(10, 15, 10, 15);
			this->panel2->Size = System::Drawing::Size(484, 89);
			this->panel2->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(10, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(464, 59);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Конвертування файлів";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(104)), static_cast<System::Int32>(static_cast<System::Byte>(236)),
				static_cast<System::Int32>(static_cast<System::Byte>(190)));
			this->panel4->Controls->Add(this->button_Convert);
			this->panel4->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->panel4->Location = System::Drawing::Point(0, 129);
			this->panel4->Name = L"panel4";
			this->panel4->Padding = System::Windows::Forms::Padding(130, 10, 130, 10);
			this->panel4->Size = System::Drawing::Size(484, 64);
			this->panel4->TabIndex = 3;
			// 
			// button_Convert
			// 
			this->button_Convert->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(125)),
				static_cast<System::Int32>(static_cast<System::Byte>(227)));
			this->button_Convert->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->button_Convert->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button_Convert->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button_Convert->ForeColor = System::Drawing::Color::White;
			this->button_Convert->Location = System::Drawing::Point(130, 10);
			this->button_Convert->Name = L"button_Convert";
			this->button_Convert->Size = System::Drawing::Size(224, 44);
			this->button_Convert->TabIndex = 0;
			this->button_Convert->Text = L"Старт програми";
			this->button_Convert->UseVisualStyleBackColor = false;
			this->button_Convert->Click += gcnew System::EventHandler(this, &Start_Form::button_Convert_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// Start_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(120, 120);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(104)), static_cast<System::Int32>(static_cast<System::Byte>(236)),
				static_cast<System::Int32>(static_cast<System::Byte>(190)));
			this->ClientSize = System::Drawing::Size(484, 304);
			this->ControlBox = false;
			this->Controls->Add(this->panel6);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->MaximumSize = System::Drawing::Size(490, 310);
			this->MinimumSize = System::Drawing::Size(490, 310);
			this->Name = L"Start_Form";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->panel1->ResumeLayout(false);
			this->panel6->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel4->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button_Exit_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button_Draw_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void label_Info_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button_Convert_Click(System::Object^ sender, System::EventArgs^ e);
};
}