#pragma once
#include "Function.h"
#include "Check_Exit.h"
#include "Start_Form.h"
#include "Finish_Form.h"
#include "Class_Type.h"

namespace BiblioConvertProgram {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO; //для роботи з файлами

	/// <summary>
	/// Сводка для Converting
	/// </summary>
	public ref class Converting : public System::Windows::Forms::Form
	{
	private: Check_Exit^ return_exit;
	private: int Combo_Index;
	public:
		Converting(int Combo_Index) {
			this->Combo_Index = Combo_Index;
		}
		Converting(void)
		{
			InitializeComponent();
			comboBox_Variant->SelectedIndex = Combo_Index;
			comboBox_Variant->Items->ToString();
			// we make the main form parental
			return_exit = gcnew Check_Exit();
			return_exit->Owner = this;
			return_exit->Hide();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Converting()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ button_Exit;
	private: System::Windows::Forms::Button^ button_Draw;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ менюToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ стартовийЕкранToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ полеВиборуКонвертатораToolStripMenuItem;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Button^ button_Search_open_File;
	private: System::Windows::Forms::TextBox^ textBox_openFile;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::TextBox^ textBox_save_File;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Button^ button_Close;
	private: System::Windows::Forms::Button^ button_Convert;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	private: System::Windows::Forms::Button^ button_Search_save_File;
	private: System::Windows::Forms::Label^ label_Open;
	private: System::Windows::Forms::Label^ label_Save;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::ComboBox^ comboBox_Variant;
	private: System::Windows::Forms::Label^ label3;
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
			this->label_Open = (gcnew System::Windows::Forms::Label());
			this->button_Search_open_File = (gcnew System::Windows::Forms::Button());
			this->textBox_openFile = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->label_Save = (gcnew System::Windows::Forms::Label());
			this->button_Search_save_File = (gcnew System::Windows::Forms::Button());
			this->textBox_save_File = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->button_Close = (gcnew System::Windows::Forms::Button());
			this->button_Convert = (gcnew System::Windows::Forms::Button());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->comboBox_Variant = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->менюToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->стартовийЕкранToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->полеВиборуКонвертатораToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel5->SuspendLayout();
			this->menuStrip1->SuspendLayout();
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
			this->panel1->Size = System::Drawing::Size(594, 40);
			this->panel1->TabIndex = 0;
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
			this->button_Draw->Location = System::Drawing::Point(494, 0);
			this->button_Draw->MaximumSize = System::Drawing::Size(50, 40);
			this->button_Draw->MinimumSize = System::Drawing::Size(50, 40);
			this->button_Draw->Name = L"button_Draw";
			this->button_Draw->Size = System::Drawing::Size(50, 40);
			this->button_Draw->TabIndex = 2;
			this->button_Draw->Text = L"-";
			this->button_Draw->UseVisualStyleBackColor = false;
			this->button_Draw->Click += gcnew System::EventHandler(this, &Converting::button_Draw_Click);
			// 
			// button_Exit
			// 
			this->button_Exit->BackColor = System::Drawing::Color::Red;
			this->button_Exit->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button_Exit->Dock = System::Windows::Forms::DockStyle::Right;
			this->button_Exit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_Exit->ForeColor = System::Drawing::Color::White;
			this->button_Exit->Location = System::Drawing::Point(544, 0);
			this->button_Exit->MaximumSize = System::Drawing::Size(50, 40);
			this->button_Exit->MinimumSize = System::Drawing::Size(50, 40);
			this->button_Exit->Name = L"button_Exit";
			this->button_Exit->Size = System::Drawing::Size(50, 40);
			this->button_Exit->TabIndex = 1;
			this->button_Exit->Text = L"X";
			this->button_Exit->UseVisualStyleBackColor = false;
			this->button_Exit->Click += gcnew System::EventHandler(this, &Converting::button_Exit_Click);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(104)), static_cast<System::Int32>(static_cast<System::Byte>(236)),
				static_cast<System::Int32>(static_cast<System::Byte>(190)));
			this->panel2->Controls->Add(this->label_Open);
			this->panel2->Controls->Add(this->button_Search_open_File);
			this->panel2->Controls->Add(this->textBox_openFile);
			this->panel2->Controls->Add(this->label1);
			this->panel2->Location = System::Drawing::Point(0, 121);
			this->panel2->Margin = System::Windows::Forms::Padding(0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(594, 150);
			this->panel2->TabIndex = 1;
			// 
			// label_Open
			// 
			this->label_Open->AutoSize = true;
			this->label_Open->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.8F));
			this->label_Open->ForeColor = System::Drawing::Color::Red;
			this->label_Open->Location = System::Drawing::Point(31, 121);
			this->label_Open->Margin = System::Windows::Forms::Padding(3, 10, 3, 0);
			this->label_Open->Name = L"label_Open";
			this->label_Open->Size = System::Drawing::Size(0, 21);
			this->label_Open->TabIndex = 3;
			// 
			// button_Search_open_File
			// 
			this->button_Search_open_File->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)),
				static_cast<System::Int32>(static_cast<System::Byte>(125)), static_cast<System::Int32>(static_cast<System::Byte>(227)));
			this->button_Search_open_File->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button_Search_open_File->ForeColor = System::Drawing::Color::White;
			this->button_Search_open_File->Location = System::Drawing::Point(449, 78);
			this->button_Search_open_File->Margin = System::Windows::Forms::Padding(3, 3, 20, 3);
			this->button_Search_open_File->MaximumSize = System::Drawing::Size(104, 30);
			this->button_Search_open_File->MinimumSize = System::Drawing::Size(104, 30);
			this->button_Search_open_File->Name = L"button_Search_open_File";
			this->button_Search_open_File->Size = System::Drawing::Size(104, 30);
			this->button_Search_open_File->TabIndex = 2;
			this->button_Search_open_File->Text = L"Обзор...";
			this->button_Search_open_File->UseVisualStyleBackColor = false;
			this->button_Search_open_File->Click += gcnew System::EventHandler(this, &Converting::button_Search_open_File_Click);
			// 
			// textBox_openFile
			// 
			this->textBox_openFile->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox_openFile->Location = System::Drawing::Point(34, 78);
			this->textBox_openFile->Margin = System::Windows::Forms::Padding(20, 20, 3, 3);
			this->textBox_openFile->MaximumSize = System::Drawing::Size(360, 30);
			this->textBox_openFile->MinimumSize = System::Drawing::Size(360, 30);
			this->textBox_openFile->Multiline = true;
			this->textBox_openFile->Name = L"textBox_openFile";
			this->textBox_openFile->Size = System::Drawing::Size(360, 30);
			this->textBox_openFile->TabIndex = 1;
			this->textBox_openFile->Text = L"C:\\";
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(29, 23);
			this->label1->Margin = System::Windows::Forms::Padding(20, 20, 3, 0);
			this->label1->MaximumSize = System::Drawing::Size(280, 35);
			this->label1->MinimumSize = System::Drawing::Size(280, 35);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(280, 35);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Введіть шлях до файлу";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(104)), static_cast<System::Int32>(static_cast<System::Byte>(236)),
				static_cast<System::Int32>(static_cast<System::Byte>(190)));
			this->panel3->Controls->Add(this->label_Save);
			this->panel3->Controls->Add(this->button_Search_save_File);
			this->panel3->Controls->Add(this->textBox_save_File);
			this->panel3->Controls->Add(this->label2);
			this->panel3->Location = System::Drawing::Point(0, 271);
			this->panel3->Margin = System::Windows::Forms::Padding(0);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(594, 151);
			this->panel3->TabIndex = 2;
			// 
			// label_Save
			// 
			this->label_Save->AutoSize = true;
			this->label_Save->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.8F));
			this->label_Save->ForeColor = System::Drawing::Color::Red;
			this->label_Save->Location = System::Drawing::Point(31, 121);
			this->label_Save->Margin = System::Windows::Forms::Padding(3, 10, 3, 0);
			this->label_Save->Name = L"label_Save";
			this->label_Save->Size = System::Drawing::Size(0, 21);
			this->label_Save->TabIndex = 4;
			// 
			// button_Search_save_File
			// 
			this->button_Search_save_File->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)),
				static_cast<System::Int32>(static_cast<System::Byte>(125)), static_cast<System::Int32>(static_cast<System::Byte>(227)));
			this->button_Search_save_File->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button_Search_save_File->ForeColor = System::Drawing::Color::White;
			this->button_Search_save_File->Location = System::Drawing::Point(449, 78);
			this->button_Search_save_File->Margin = System::Windows::Forms::Padding(3, 3, 20, 3);
			this->button_Search_save_File->MaximumSize = System::Drawing::Size(104, 30);
			this->button_Search_save_File->MinimumSize = System::Drawing::Size(104, 30);
			this->button_Search_save_File->Name = L"button_Search_save_File";
			this->button_Search_save_File->Size = System::Drawing::Size(104, 30);
			this->button_Search_save_File->TabIndex = 3;
			this->button_Search_save_File->Text = L"Обзор...";
			this->button_Search_save_File->UseVisualStyleBackColor = false;
			this->button_Search_save_File->Click += gcnew System::EventHandler(this, &Converting::button_Search_save_File_Click);
			// 
			// textBox_save_File
			// 
			this->textBox_save_File->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->textBox_save_File->Location = System::Drawing::Point(34, 78);
			this->textBox_save_File->Margin = System::Windows::Forms::Padding(20, 20, 3, 3);
			this->textBox_save_File->MaximumSize = System::Drawing::Size(360, 30);
			this->textBox_save_File->MinimumSize = System::Drawing::Size(360, 30);
			this->textBox_save_File->Multiline = true;
			this->textBox_save_File->Name = L"textBox_save_File";
			this->textBox_save_File->Size = System::Drawing::Size(360, 30);
			this->textBox_save_File->TabIndex = 1;
			this->textBox_save_File->Text = L"C:\\";
			// 
			// label2
			// 
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Bold));
			this->label2->Location = System::Drawing::Point(29, 23);
			this->label2->Margin = System::Windows::Forms::Padding(20, 20, 3, 0);
			this->label2->MaximumSize = System::Drawing::Size(390, 35);
			this->label2->MinimumSize = System::Drawing::Size(390, 35);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(390, 35);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Введіть шлях куди зберегти файл";
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(104)), static_cast<System::Int32>(static_cast<System::Byte>(236)),
				static_cast<System::Int32>(static_cast<System::Byte>(190)));
			this->panel4->Controls->Add(this->button_Close);
			this->panel4->Controls->Add(this->button_Convert);
			this->panel4->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel4->Location = System::Drawing::Point(0, 422);
			this->panel4->Margin = System::Windows::Forms::Padding(0);
			this->panel4->Name = L"panel4";
			this->panel4->Padding = System::Windows::Forms::Padding(165, 25, 45, 25);
			this->panel4->Size = System::Drawing::Size(594, 102);
			this->panel4->TabIndex = 3;
			// 
			// button_Close
			// 
			this->button_Close->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(125)),
				static_cast<System::Int32>(static_cast<System::Byte>(227)));
			this->button_Close->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button_Close->Dock = System::Windows::Forms::DockStyle::Right;
			this->button_Close->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10));
			this->button_Close->ForeColor = System::Drawing::Color::White;
			this->button_Close->Location = System::Drawing::Point(461, 25);
			this->button_Close->MaximumSize = System::Drawing::Size(88, 52);
			this->button_Close->MinimumSize = System::Drawing::Size(88, 52);
			this->button_Close->Name = L"button_Close";
			this->button_Close->Size = System::Drawing::Size(88, 52);
			this->button_Close->TabIndex = 1;
			this->button_Close->Text = L"Отмена";
			this->button_Close->UseVisualStyleBackColor = false;
			this->button_Close->Click += gcnew System::EventHandler(this, &Converting::button_Close_Click);
			// 
			// button_Convert
			// 
			this->button_Convert->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(125)),
				static_cast<System::Int32>(static_cast<System::Byte>(227)));
			this->button_Convert->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button_Convert->Dock = System::Windows::Forms::DockStyle::Left;
			this->button_Convert->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16.2F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			this->button_Convert->ForeColor = System::Drawing::Color::White;
			this->button_Convert->Location = System::Drawing::Point(165, 25);
			this->button_Convert->Margin = System::Windows::Forms::Padding(100, 20, 3, 3);
			this->button_Convert->MaximumSize = System::Drawing::Size(219, 52);
			this->button_Convert->MinimumSize = System::Drawing::Size(219, 52);
			this->button_Convert->Name = L"button_Convert";
			this->button_Convert->Size = System::Drawing::Size(219, 52);
			this->button_Convert->TabIndex = 0;
			this->button_Convert->Text = L"Конвертувати";
			this->button_Convert->UseVisualStyleBackColor = false;
			this->button_Convert->Click += gcnew System::EventHandler(this, &Converting::button_Convert_Click);
			// 
			// panel5
			// 
			this->panel5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(104)), static_cast<System::Int32>(static_cast<System::Byte>(236)),
				static_cast<System::Int32>(static_cast<System::Byte>(190)));
			this->panel5->Controls->Add(this->comboBox_Variant);
			this->panel5->Controls->Add(this->label3);
			this->panel5->Controls->Add(this->menuStrip1);
			this->panel5->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel5->Location = System::Drawing::Point(0, 40);
			this->panel5->Margin = System::Windows::Forms::Padding(0);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(594, 81);
			this->panel5->TabIndex = 4;
			// 
			// comboBox_Variant
			// 
			this->comboBox_Variant->DropDownStyle = System::Windows::Forms::ComboBoxStyle::Simple;
			this->comboBox_Variant->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F));
			this->comboBox_Variant->FormattingEnabled = true;
			this->comboBox_Variant->Items->AddRange(gcnew cli::array< System::Object^  >(1) { L"Конвертувати з RIS в TXT" });
			this->comboBox_Variant->Location = System::Drawing::Point(296, 30);
			this->comboBox_Variant->Margin = System::Windows::Forms::Padding(0, 30, 50, 20);
			this->comboBox_Variant->Name = L"comboBox_Variant";
			this->comboBox_Variant->Size = System::Drawing::Size(239, 31);
			this->comboBox_Variant->TabIndex = 1;
			this->comboBox_Variant->Text = L"Виберіть варіант";
			// 
			// label3
			// 
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(50, 30);
			this->label3->Margin = System::Windows::Forms::Padding(50, 30, 0, 20);
			this->label3->MaximumSize = System::Drawing::Size(242, 31);
			this->label3->MinimumSize = System::Drawing::Size(242, 31);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(242, 31);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Варіант конвертації:";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(104)), static_cast<System::Int32>(static_cast<System::Byte>(236)),
				static_cast<System::Int32>(static_cast<System::Byte>(190)));
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->менюToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(594, 28);
			this->menuStrip1->TabIndex = 2;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// менюToolStripMenuItem
			// 
			this->менюToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->стартовийЕкранToolStripMenuItem,
					this->полеВиборуКонвертатораToolStripMenuItem
			});
			this->менюToolStripMenuItem->ForeColor = System::Drawing::SystemColors::ControlText;
			this->менюToolStripMenuItem->Name = L"менюToolStripMenuItem";
			this->менюToolStripMenuItem->Size = System::Drawing::Size(65, 24);
			this->менюToolStripMenuItem->Text = L"Меню";
			// 
			// стартовийЕкранToolStripMenuItem
			// 
			this->стартовийЕкранToolStripMenuItem->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(104)),
				static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(190)));
			this->стартовийЕкранToolStripMenuItem->Name = L"стартовийЕкранToolStripMenuItem";
			this->стартовийЕкранToolStripMenuItem->Size = System::Drawing::Size(283, 26);
			this->стартовийЕкранToolStripMenuItem->Text = L"Стартовий екран";
			this->стартовийЕкранToolStripMenuItem->Click += gcnew System::EventHandler(this, &Converting::стартовийЕкранToolStripMenuItem_Click);
			// 
			// полеВиборуКонвертатораToolStripMenuItem
			// 
			this->полеВиборуКонвертатораToolStripMenuItem->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(104)),
				static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(190)));
			this->полеВиборуКонвертатораToolStripMenuItem->Name = L"полеВиборуКонвертатораToolStripMenuItem";
			this->полеВиборуКонвертатораToolStripMenuItem->Size = System::Drawing::Size(283, 26);
			this->полеВиборуКонвертатораToolStripMenuItem->Text = L"Поле вибору конвертатора";
			this->полеВиборуКонвертатораToolStripMenuItem->Click += gcnew System::EventHandler(this, &Converting::полеВиборуКонвертатораToolStripMenuItem_Click);
			// 
			// Converting
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(120, 120);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->ClientSize = System::Drawing::Size(594, 524);
			this->ControlBox = false;
			this->Controls->Add(this->panel5);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->MaximumSize = System::Drawing::Size(600, 530);
			this->MinimumSize = System::Drawing::Size(600, 530);
			this->Name = L"Converting";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->panel1->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->panel5->ResumeLayout(false);
			this->panel5->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void button_Exit_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_Draw_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_Search_open_File_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_Close_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_Search_save_File_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_Convert_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void стартовийЕкранToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void полеВиборуКонвертатораToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
};
}
