#pragma once

namespace BiblioConvertProgram {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ?????? ??? Info
	/// </summary>
	public ref class Info : public System::Windows::Forms::Form
	{
	public:
		Info(void)
		{
			InitializeComponent();
			//
			//TODO: ???????? ??? ????????????
			//
		}

	protected:
		/// <summary>
		/// ?????????? ??? ???????????? ???????.
		/// </summary>
		~Info()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label_Info;
	protected:

	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Button^ button_Exit;


	private:
		/// <summary>
		/// ???????????? ?????????? ????????????.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ????????? ????? ??? ????????? ???????????? ? ?? ????????? 
		/// ?????????? ????? ?????? ? ??????? ????????? ????.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Info::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label_Info = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->button_Exit = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label_Info);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(556, 257);
			this->panel1->TabIndex = 0;
			// 
			// label_Info
			// 
			this->label_Info->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(104)), static_cast<System::Int32>(static_cast<System::Byte>(236)),
				static_cast<System::Int32>(static_cast<System::Byte>(190)));
			this->label_Info->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label_Info->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_Info->Location = System::Drawing::Point(0, 0);
			this->label_Info->Name = L"label_Info";
			this->label_Info->Size = System::Drawing::Size(556, 257);
			this->label_Info->TabIndex = 0;
			this->label_Info->Text = resources->GetString(L"label_Info.Text");
			this->label_Info->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(104)), static_cast<System::Int32>(static_cast<System::Byte>(236)),
				static_cast<System::Int32>(static_cast<System::Byte>(190)));
			this->panel2->Controls->Add(this->button_Exit);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel2->Location = System::Drawing::Point(0, 257);
			this->panel2->Name = L"panel2";
			this->panel2->Padding = System::Windows::Forms::Padding(190, 25, 190, 25);
			this->panel2->Size = System::Drawing::Size(556, 89);
			this->panel2->TabIndex = 1;
			// 
			// button_Exit
			// 
			this->button_Exit->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(125)),
				static_cast<System::Int32>(static_cast<System::Byte>(227)));
			this->button_Exit->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button_Exit->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button_Exit->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_Exit->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_Exit->ForeColor = System::Drawing::Color::White;
			this->button_Exit->Location = System::Drawing::Point(190, 25);
			this->button_Exit->MaximumSize = System::Drawing::Size(182, 45);
			this->button_Exit->MinimumSize = System::Drawing::Size(182, 45);
			this->button_Exit->Name = L"button_Exit";
			this->button_Exit->Size = System::Drawing::Size(182, 45);
			this->button_Exit->TabIndex = 0;
			this->button_Exit->Text = L"???????";
			this->button_Exit->UseVisualStyleBackColor = false;
			this->button_Exit->Click += gcnew System::EventHandler(this, &Info::button_Exit_Click);
			// 
			// Info
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(120, 120);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->ClientSize = System::Drawing::Size(556, 346);
			this->ControlBox = false;
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Name = L"Info";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->panel1->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button_Exit_Click(System::Object^ sender, System::EventArgs^ e);
};
}
