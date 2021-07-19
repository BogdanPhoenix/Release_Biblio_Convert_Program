#pragma once
#include "Start_Form.h"
#include "Converting.h"

namespace BiblioConvertProgram {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Converting_Type
	/// </summary>
	public ref class Converting_Type : public System::Windows::Forms::Form
	{
	public:
		Converting_Type(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Converting_Type()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ головнийЕкранToolStripMenuItem;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Button^ button_Exit;
	private: System::Windows::Forms::Button^ button_Draw;
	private: System::Windows::Forms::ComboBox^ comboBox_Type;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label_comboBox_Type;
	protected:


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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->головнийЕкранToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label_comboBox_Type = (gcnew System::Windows::Forms::Label());
			this->comboBox_Type = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(104)), static_cast<System::Int32>(static_cast<System::Byte>(236)),
				static_cast<System::Int32>(static_cast<System::Byte>(190)));
			this->panel1->Controls->Add(this->button_Draw);
			this->panel1->Controls->Add(this->button_Exit);
			this->panel1->Controls->Add(this->menuStrip1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Margin = System::Windows::Forms::Padding(0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(594, 40);
			this->panel1->TabIndex = 0;
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
			this->button_Draw->Location = System::Drawing::Point(495, 0);
			this->button_Draw->Margin = System::Windows::Forms::Padding(0);
			this->button_Draw->Name = L"button_Draw";
			this->button_Draw->Size = System::Drawing::Size(46, 40);
			this->button_Draw->TabIndex = 2;
			this->button_Draw->Text = L"-";
			this->button_Draw->UseVisualStyleBackColor = false;
			this->button_Draw->Click += gcnew System::EventHandler(this, &Converting_Type::button_Draw_Click);
			// 
			// button_Exit
			// 
			this->button_Exit->BackColor = System::Drawing::Color::Red;
			this->button_Exit->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button_Exit->Dock = System::Windows::Forms::DockStyle::Right;
			this->button_Exit->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_Exit->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16.2F, System::Drawing::FontStyle::Bold));
			this->button_Exit->ForeColor = System::Drawing::Color::White;
			this->button_Exit->Location = System::Drawing::Point(541, 0);
			this->button_Exit->Margin = System::Windows::Forms::Padding(0);
			this->button_Exit->Name = L"button_Exit";
			this->button_Exit->Size = System::Drawing::Size(53, 40);
			this->button_Exit->TabIndex = 1;
			this->button_Exit->Text = L"X";
			this->button_Exit->UseVisualStyleBackColor = false;
			this->button_Exit->Click += gcnew System::EventHandler(this, &Converting_Type::button_Exit_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->AutoSize = false;
			this->menuStrip1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(104)), static_cast<System::Int32>(static_cast<System::Byte>(236)),
				static_cast<System::Int32>(static_cast<System::Byte>(190)));
			this->menuStrip1->Dock = System::Windows::Forms::DockStyle::Left;
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->toolStripMenuItem1 });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Margin = System::Windows::Forms::Padding(0, 5, 0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(100, 40);
			this->menuStrip1->Stretch = false;
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(104)),
				static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(190)));
			this->toolStripMenuItem1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->головнийЕкранToolStripMenuItem });
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(93, 24);
			this->toolStripMenuItem1->Text = L"Меню";
			// 
			// головнийЕкранToolStripMenuItem
			// 
			this->головнийЕкранToolStripMenuItem->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(104)),
				static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(190)));
			this->головнийЕкранToolStripMenuItem->Name = L"головнийЕкранToolStripMenuItem";
			this->головнийЕкранToolStripMenuItem->Size = System::Drawing::Size(205, 26);
			this->головнийЕкранToolStripMenuItem->Text = L"Головний екран";
			this->головнийЕкранToolStripMenuItem->Click += gcnew System::EventHandler(this, &Converting_Type::головнийЕкранToolStripMenuItem_Click);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(104)), static_cast<System::Int32>(static_cast<System::Byte>(236)),
				static_cast<System::Int32>(static_cast<System::Byte>(190)));
			this->panel2->Controls->Add(this->label_comboBox_Type);
			this->panel2->Controls->Add(this->comboBox_Type);
			this->panel2->Controls->Add(this->label1);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel2->Location = System::Drawing::Point(0, 40);
			this->panel2->Margin = System::Windows::Forms::Padding(0);
			this->panel2->Name = L"panel2";
			this->panel2->Padding = System::Windows::Forms::Padding(20, 15, 0, 5);
			this->panel2->Size = System::Drawing::Size(594, 89);
			this->panel2->TabIndex = 1;
			// 
			// label_comboBox_Type
			// 
			this->label_comboBox_Type->AutoSize = true;
			this->label_comboBox_Type->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.8F));
			this->label_comboBox_Type->ForeColor = System::Drawing::Color::Red;
			this->label_comboBox_Type->Location = System::Drawing::Point(24, 54);
			this->label_comboBox_Type->Name = L"label_comboBox_Type";
			this->label_comboBox_Type->Size = System::Drawing::Size(0, 21);
			this->label_comboBox_Type->TabIndex = 2;
			// 
			// comboBox_Type
			// 
			this->comboBox_Type->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->comboBox_Type->Cursor = System::Windows::Forms::Cursors::Hand;
			this->comboBox_Type->FormattingEnabled = true;
			this->comboBox_Type->Items->AddRange(gcnew cli::array< System::Object^  >(1) { L"Конвертувати з RIS в TXT" });
			this->comboBox_Type->Location = System::Drawing::Point(307, 24);
			this->comboBox_Type->Margin = System::Windows::Forms::Padding(0, 30, 50, 20);
			this->comboBox_Type->Name = L"comboBox_Type";
			this->comboBox_Type->Size = System::Drawing::Size(237, 27);
			this->comboBox_Type->TabIndex = 1;
			this->comboBox_Type->Text = L"Варіант конвертації";
			this->comboBox_Type->SelectedIndexChanged += gcnew System::EventHandler(this, &Converting_Type::comboBox_Type_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(23, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(239, 39);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Варіант конвертації:";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->label2);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel3->Location = System::Drawing::Point(0, 129);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(594, 415);
			this->panel3->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(104)), static_cast<System::Int32>(static_cast<System::Byte>(236)),
				static_cast<System::Int32>(static_cast<System::Byte>(190)));
			this->label2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 18));
			this->label2->Location = System::Drawing::Point(0, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(594, 415);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Поля завантажаться автоматично, коли ви виберете варіант конвертації";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Converting_Type
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(120, 120);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->ClientSize = System::Drawing::Size(594, 544);
			this->ControlBox = false;
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximumSize = System::Drawing::Size(600, 550);
			this->MinimumSize = System::Drawing::Size(600, 550);
			this->Name = L"Converting_Type";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->panel1->ResumeLayout(false);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button_Exit_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_Draw_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void головнийЕкранToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void comboBox_Type_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
};
}
