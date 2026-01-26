#pragma once
#include "GUI.h"
#include "RegForm.h"

namespace chessMTUCI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class Autorization : public System::Windows::Forms::Form
	{
	public:
		Autorization(void)
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
		~Autorization()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ UsName;
	private: System::Windows::Forms::Label^ Pswrd;
	private: System::Windows::Forms::Label^ Autrization;
	private: System::Windows::Forms::TextBox^ EnterUsName;
	private: System::Windows::Forms::TextBox^ EnterPasword;
	private: System::Windows::Forms::Button^ Enter;
	private: System::Windows::Forms::Button^ registration;


	protected:


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
			this->UsName = (gcnew System::Windows::Forms::Label());
			this->Pswrd = (gcnew System::Windows::Forms::Label());
			this->Autrization = (gcnew System::Windows::Forms::Label());
			this->EnterUsName = (gcnew System::Windows::Forms::TextBox());
			this->EnterPasword = (gcnew System::Windows::Forms::TextBox());
			this->Enter = (gcnew System::Windows::Forms::Button());
			this->registration = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// UsName
			// 
			this->UsName->AutoSize = true;
			this->UsName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->UsName->Location = System::Drawing::Point(12, 83);
			this->UsName->Name = L"UsName";
			this->UsName->Size = System::Drawing::Size(100, 24);
			this->UsName->TabIndex = 0;
			this->UsName->Text = L"UserName";
			// 
			// Pswrd
			// 
			this->Pswrd->AutoSize = true;
			this->Pswrd->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Pswrd->Location = System::Drawing::Point(12, 121);
			this->Pswrd->Name = L"Pswrd";
			this->Pswrd->Size = System::Drawing::Size(83, 24);
			this->Pswrd->TabIndex = 1;
			this->Pswrd->Text = L"Pasword";
			// 
			// Autrization
			// 
			this->Autrization->AutoSize = true;
			this->Autrization->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Autrization->Location = System::Drawing::Point(214, 9);
			this->Autrization->Name = L"Autrization";
			this->Autrization->Size = System::Drawing::Size(129, 24);
			this->Autrization->TabIndex = 2;
			this->Autrization->Text = L"Авторизация";
			this->Autrization->Click += gcnew System::EventHandler(this, &Autorization::Autrization_Click);
			// 
			// EnterUsName
			// 
			this->EnterUsName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->EnterUsName->Location = System::Drawing::Point(140, 86);
			this->EnterUsName->Name = L"EnterUsName";
			this->EnterUsName->Size = System::Drawing::Size(327, 22);
			this->EnterUsName->TabIndex = 3;
			this->EnterUsName->TextChanged += gcnew System::EventHandler(this, &Autorization::EnterUsName_TextChanged);
			// 
			// EnterPasword
			// 
			this->EnterPasword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->EnterPasword->Location = System::Drawing::Point(140, 125);
			this->EnterPasword->Name = L"EnterPasword";
			this->EnterPasword->Size = System::Drawing::Size(327, 22);
			this->EnterPasword->TabIndex = 4;
			this->EnterPasword->TextChanged += gcnew System::EventHandler(this, &Autorization::EnterPasword_TextChanged);
			// 
			// Enter
			// 
			this->Enter->BackColor = System::Drawing::Color::Plum;
			this->Enter->Location = System::Drawing::Point(384, 199);
			this->Enter->Name = L"Enter";
			this->Enter->Size = System::Drawing::Size(156, 79);
			this->Enter->TabIndex = 5;
			this->Enter->Text = L"Войти";
			this->Enter->UseVisualStyleBackColor = false;
			this->Enter->Click += gcnew System::EventHandler(this, &Autorization::Enter_Click);
			// 
			// registration
			// 
			this->registration->BackColor = System::Drawing::Color::SlateBlue;
			this->registration->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->registration->Location = System::Drawing::Point(16, 242);
			this->registration->Name = L"registration";
			this->registration->Size = System::Drawing::Size(111, 29);
			this->registration->TabIndex = 6;
			this->registration->Text = L"Регистрация";
			this->registration->UseVisualStyleBackColor = false;
			this->registration->Click += gcnew System::EventHandler(this, &Autorization::registration_Click);
			// 
			// Autorization
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Thistle;
			this->ClientSize = System::Drawing::Size(552, 290);
			this->Controls->Add(this->registration);
			this->Controls->Add(this->Enter);
			this->Controls->Add(this->EnterPasword);
			this->Controls->Add(this->EnterUsName);
			this->Controls->Add(this->Autrization);
			this->Controls->Add(this->Pswrd);
			this->Controls->Add(this->UsName);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"Autorization";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &Autorization::Autorization_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Autorization_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Autrization_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void Enter_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	GUI^ choose = gcnew GUI();
	choose->Show();
}
private: System::Void EnterUsName_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void EnterPasword_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void registration_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	RegForm^ choose = gcnew RegForm();
	choose->Show();
}
};
}
