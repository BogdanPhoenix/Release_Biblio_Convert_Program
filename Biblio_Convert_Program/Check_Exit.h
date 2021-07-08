#pragma once

namespace BiblioConvertProgram {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Check_Exit
	/// </summary>
	public ref class Check_Exit : public System::Windows::Forms::Form
	{
	public:
		Check_Exit(void)
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
		~Check_Exit()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Button^ button_Yes;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Button^ button_No;
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->button_Yes = (gcnew System::Windows::Forms::Button());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->button_No = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Bold));
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(302, 164);
			this->panel1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(104)), static_cast<System::Int32>(static_cast<System::Byte>(236)),
				static_cast<System::Int32>(static_cast<System::Byte>(190)));
			this->label1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label1->Location = System::Drawing::Point(0, 0);
			this->label1->MaximumSize = System::Drawing::Size(302, 164);
			this->label1->MinimumSize = System::Drawing::Size(302, 164);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(302, 164);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Ви хочете завершити\r\nроботу програми\?";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(104)), static_cast<System::Int32>(static_cast<System::Byte>(236)),
				static_cast<System::Int32>(static_cast<System::Byte>(190)));
			this->panel2->Controls->Add(this->button_Yes);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Bold));
			this->panel2->Location = System::Drawing::Point(0, 164);
			this->panel2->Name = L"panel2";
			this->panel2->Padding = System::Windows::Forms::Padding(36, 22, 36, 22);
			this->panel2->Size = System::Drawing::Size(151, 88);
			this->panel2->TabIndex = 1;
			// 
			// button_Yes
			// 
			this->button_Yes->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(125)),
				static_cast<System::Int32>(static_cast<System::Byte>(227)));
			this->button_Yes->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button_Yes->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button_Yes->ForeColor = System::Drawing::Color::White;
			this->button_Yes->Location = System::Drawing::Point(36, 22);
			this->button_Yes->MaximumSize = System::Drawing::Size(79, 44);
			this->button_Yes->MinimumSize = System::Drawing::Size(79, 44);
			this->button_Yes->Name = L"button_Yes";
			this->button_Yes->Size = System::Drawing::Size(79, 44);
			this->button_Yes->TabIndex = 0;
			this->button_Yes->Text = L"Так";
			this->button_Yes->UseVisualStyleBackColor = false;
			this->button_Yes->Click += gcnew System::EventHandler(this, &Check_Exit::button_Yes_Click);
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(104)), static_cast<System::Int32>(static_cast<System::Byte>(236)),
				static_cast<System::Int32>(static_cast<System::Byte>(190)));
			this->panel3->Controls->Add(this->button_No);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Right;
			this->panel3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Bold));
			this->panel3->Location = System::Drawing::Point(151, 164);
			this->panel3->Name = L"panel3";
			this->panel3->Padding = System::Windows::Forms::Padding(36, 22, 36, 22);
			this->panel3->Size = System::Drawing::Size(151, 88);
			this->panel3->TabIndex = 2;
			// 
			// button_No
			// 
			this->button_No->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(125)),
				static_cast<System::Int32>(static_cast<System::Byte>(227)));
			this->button_No->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button_No->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button_No->ForeColor = System::Drawing::Color::White;
			this->button_No->Location = System::Drawing::Point(36, 22);
			this->button_No->MaximumSize = System::Drawing::Size(79, 44);
			this->button_No->MinimumSize = System::Drawing::Size(79, 44);
			this->button_No->Name = L"button_No";
			this->button_No->Size = System::Drawing::Size(79, 44);
			this->button_No->TabIndex = 0;
			this->button_No->Text = L"Ні";
			this->button_No->UseVisualStyleBackColor = false;
			this->button_No->Click += gcnew System::EventHandler(this, &Check_Exit::button_No_Click);
			// 
			// Check_Exit
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(120, 120);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->ClientSize = System::Drawing::Size(302, 252);
			this->ControlBox = false;
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Name = L"Check_Exit";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->panel1->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button_Yes_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_No_Click(System::Object^ sender, System::EventArgs^ e);
};
}
