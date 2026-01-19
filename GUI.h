#pragma once
#include <string>
#include "Game.h"

namespace chessMTUCI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	///  MyForm
	/// </summary>
	public ref class GUI : public System::Windows::Forms::Form
	{
	public:
		GUI(void)
		{
			InitializeComponent();
			//
			//TODO:
			//
		}

	protected:
		/// <summary>
		/// </summary>
		~GUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::Button^ Gstart;
	private: System::Windows::Forms::Button^ Exit;
	private: System::Windows::Forms::PictureBox^ pictureBox1;



	protected:

	protected:

	private:
		/// <summary>
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(GUI::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->Gstart = (gcnew System::Windows::Forms::Button());
			this->Exit = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(414, 48);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(213, 52);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Шахматы";
			// 
			// Gstart
			// 
			this->Gstart->BackColor = System::Drawing::Color::Blue;
			this->Gstart->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Gstart->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold));
			this->Gstart->ForeColor = System::Drawing::Color::Black;
			this->Gstart->Location = System::Drawing::Point(389, 148);
			this->Gstart->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Gstart->Name = L"Gstart";
			this->Gstart->Size = System::Drawing::Size(267, 47);
			this->Gstart->TabIndex = 2;
			this->Gstart->Text = L"Начать игру";
			this->Gstart->UseVisualStyleBackColor = false;
			this->Gstart->Click += gcnew System::EventHandler(this, &GUI::Gstart_Click);
			// 
			// Exit
			// 
			this->Exit->BackColor = System::Drawing::Color::Blue;
			this->Exit->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Exit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold));
			this->Exit->ForeColor = System::Drawing::Color::Black;
			this->Exit->Location = System::Drawing::Point(389, 222);
			this->Exit->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Exit->Name = L"Exit";
			this->Exit->Size = System::Drawing::Size(267, 49);
			this->Exit->TabIndex = 3;
			this->Exit->Text = L"Выйти";
			this->Exit->UseVisualStyleBackColor = false;
			this->Exit->Click += gcnew System::EventHandler(this, &GUI::Exit_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(-4, -7);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1069, 710);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 4;
			this->pictureBox1->TabStop = false;
			// 
			// GUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(1060, 698);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Gstart);
			this->Controls->Add(this->Exit);
			this->Controls->Add(this->pictureBox1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"GUI";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Шахматы";
			this->Load += gcnew System::EventHandler(this, &GUI::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Exit_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void Gstart_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		Game^ gameForm = gcnew Game();
		gameForm->Show();
	}
	};
}