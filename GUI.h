#pragma once
#include <string>

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
	public ref class GUI : public System::Windows::Forms::Form
	{
	public:
		GUI(void)
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
		~GUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::PictureBox^ picMtuci;
	private: System::Windows::Forms::Button^ Gstart;
	private: System::Windows::Forms::Button^ Exit;



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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(GUI::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->picMtuci = (gcnew System::Windows::Forms::PictureBox());
			this->Gstart = (gcnew System::Windows::Forms::Button());
			this->Exit = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picMtuci))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(292, 43);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(197, 39);
			this->label1->TabIndex = 0;
			this->label1->Text = L"ШАХМАТЫ";
			// 
			// picMtuci
			// 
			this->picMtuci->Dock = System::Windows::Forms::DockStyle::Fill;
			this->picMtuci->Location = System::Drawing::Point(0, 0);
			this->picMtuci->Name = L"picMtuci";
			this->picMtuci->Size = System::Drawing::Size(795, 567);
			this->picMtuci->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->picMtuci->TabIndex = 1;
			this->picMtuci->TabStop = false;
			try {
				String^ imagePath = L"mtuci.jpg";
				if (System::IO::File::Exists(imagePath)) {
					this->picMtuci->Image = Image::FromFile(imagePath);
				}
				else {
					imagePath = L"C:\\Projects\\alg\\chessMTUCI\\mtuci.jpg";
					if (System::IO::File::Exists(imagePath)) {
						this->picMtuci->Image = Image::FromFile(imagePath);
					}
				}
			}
			catch (Exception^ ex) {
				this->picMtuci->BackColor = Color::DarkBlue;
			}
			//
			//Gstart
			//
			this->Gstart->Location = System::Drawing::Point(292, 120);
			this->Gstart->Size = System::Drawing::Size(200, 40);
			this->Gstart->Name = L"Gstart";
			this->Gstart->Text = L"Начать игру";
			this->Gstart->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold));
			this->Gstart->BackColor = System::Drawing::Color::Blue;
			this->Gstart->ForeColor = System::Drawing::Color::Black;
			this->Gstart->TabIndex = 2;
			this->Gstart->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Gstart->Click += gcnew System::EventHandler(this, &GUI::Gstart_Click);
			//
			//Exit
			//
			this->Exit->Location = System::Drawing::Point(292, 180);
			this->Exit->Size = System::Drawing::Size(200, 40);
			this->Exit->Name = L"Exit";
			this->Exit->Text = L"Выход";
			this->Exit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold));
			this->Exit->BackColor = System::Drawing::Color::Blue;
			this->Exit->ForeColor = System::Drawing::Color::Black;
			this->Exit->TabIndex = 3;
			this->Exit->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Exit->Click += gcnew System::EventHandler(this, &GUI::Exit_Click);

			// 
			// GUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(795, 567);
			this->Controls->Add(this->picMtuci);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Gstart);
			this->Controls->Add(this->Exit);
			this->picMtuci->SendToBack();
			this->Name = L"GUI";
			this->Text = L"Шахматы МТУСИ";
			this->Load += gcnew System::EventHandler(this, &GUI::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picMtuci))->EndInit();
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
	}
	};
}
