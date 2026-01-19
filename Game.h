#pragma once

namespace chessMTUCI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Game
	/// </summary>
	public ref class Game : public System::Windows::Forms::Form
	{
	public:
		Game(void)
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
		~Game()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ lblMove;
	private: System::Windows::Forms::Label^ lblMoveNumber;

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Game::typeid));
			this->lblMove = (gcnew System::Windows::Forms::Label());
			this->lblMoveNumber = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// lblMove
			// 
			this->lblMove->AutoSize = true;
			this->lblMove->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lblMove->Location = System::Drawing::Point(572, 28);
			this->lblMove->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblMove->Name = L"lblMove";
			this->lblMove->Size = System::Drawing::Size(50, 24);
			this->lblMove->TabIndex = 1;
			this->lblMove->Text = L"Ход:";
			// 
			// lblMoveNumber
			// 
			this->lblMoveNumber->AutoSize = true;
			this->lblMoveNumber->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lblMoveNumber->Location = System::Drawing::Point(617, 28);
			this->lblMoveNumber->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblMoveNumber->Name = L"lblMoveNumber";
			this->lblMoveNumber->Size = System::Drawing::Size(20, 24);
			this->lblMoveNumber->TabIndex = 2;
			this->lblMoveNumber->Text = L"1";
			// 
			// Game
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Info;
			this->ClientSize = System::Drawing::Size(648, 612);
			this->Controls->Add(this->lblMoveNumber);
			this->Controls->Add(this->lblMove);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"Game";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Шахматы";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
