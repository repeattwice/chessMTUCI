#pragma once
namespace chessMTUCI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ pawnFinaleWhite
	/// </summary>
	public ref class pawnFinaleWhite : public System::Windows::Forms::Form
	{
	public:
		enum class PieceType
		{
			Queen,
			Rook,
			Bishop,
			Knight
		};
		property PieceType SelectedPiece
		{
			PieceType get() { return selectedPiece; }
		}
		pawnFinaleWhite(void)
		{
			InitializeComponent();
			selectedPiece = PieceType::Queen;
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~pawnFinaleWhite()
		{
			if (components)
			{
				delete components;
			}
		}
	PieceType selectedPiece;
	private: System::Windows::Forms::PictureBox^ picQueen;
	private: System::Windows::Forms::PictureBox^ picBishop;
	private: System::Windows::Forms::PictureBox^ picRook;
	private: System::Windows::Forms::PictureBox^ picKnight;
	protected:

	protected:




	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(pawnFinaleWhite::typeid));
			this->picQueen = (gcnew System::Windows::Forms::PictureBox());
			this->picBishop = (gcnew System::Windows::Forms::PictureBox());
			this->picRook = (gcnew System::Windows::Forms::PictureBox());
			this->picKnight = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picQueen))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBishop))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picRook))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picKnight))->BeginInit();
			this->SuspendLayout();
			// 
			// picQueen
			// 
			this->picQueen->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picQueen.Image")));
			this->picQueen->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picQueen.InitialImage")));
			this->picQueen->Location = System::Drawing::Point(38, 48);
			this->picQueen->Name = L"picQueen";
			this->picQueen->Size = System::Drawing::Size(65, 62);
			this->picQueen->TabIndex = 0;
			this->picQueen->TabStop = false;
			this->picQueen->Click += gcnew System::EventHandler(this, &pawnFinaleWhite::picQueen_Click);
			this->picQueen->MouseEnter += gcnew System::EventHandler(this, &pawnFinaleWhite::picQueen_MouseEnter);
			// 
			// picBishop
			// 
			this->picBishop->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picBishop.Image")));
			this->picBishop->Location = System::Drawing::Point(121, 48);
			this->picBishop->Name = L"picBishop";
			this->picBishop->Size = System::Drawing::Size(61, 62);
			this->picBishop->TabIndex = 1;
			this->picBishop->TabStop = false;
			this->picBishop->Click += gcnew System::EventHandler(this, &pawnFinaleWhite::picBishop_Click);
			this->picBishop->MouseEnter += gcnew System::EventHandler(this, &pawnFinaleWhite::picBishop_MouseEnter);
			// 
			// picRook
			// 
			this->picRook->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picRook.Image")));
			this->picRook->Location = System::Drawing::Point(202, 48);
			this->picRook->Name = L"picRook";
			this->picRook->Size = System::Drawing::Size(61, 62);
			this->picRook->TabIndex = 2;
			this->picRook->TabStop = false;
			this->picRook->Click += gcnew System::EventHandler(this, &pawnFinaleWhite::picRook_Click);
			this->picRook->MouseEnter += gcnew System::EventHandler(this, &pawnFinaleWhite::picRook_MouseEnter);
			// 
			// picKnight
			// 
			this->picKnight->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picKnight.Image")));
			this->picKnight->Location = System::Drawing::Point(284, 48);
			this->picKnight->Name = L"picKnight";
			this->picKnight->Size = System::Drawing::Size(63, 62);
			this->picKnight->TabIndex = 3;
			this->picKnight->TabStop = false;
			this->picKnight->Click += gcnew System::EventHandler(this, &pawnFinaleWhite::picKnight_Click);
			this->picKnight->MouseEnter += gcnew System::EventHandler(this, &pawnFinaleWhite::picKnight_MouseEnter);
			// 
			// pawnFinale
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(382, 153);
			this->ControlBox = false;
			this->Controls->Add(this->picKnight);
			this->Controls->Add(this->picRook);
			this->Controls->Add(this->picBishop);
			this->Controls->Add(this->picQueen);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"pawnFinaleWhite";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"pawnFinaleWhite";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picQueen))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBishop))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picRook))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picKnight))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void picQueen_Click(System::Object^ sender, System::EventArgs^ e) {
	selectedPiece = PieceType::Queen;
	this->DialogResult = System::Windows::Forms::DialogResult::OK;
	this->Close();
}
private: System::Void picBishop_Click(System::Object^ sender, System::EventArgs^ e) {
	selectedPiece = PieceType::Bishop;
	this->DialogResult = System::Windows::Forms::DialogResult::OK;
	this->Close();
}
private: System::Void picRook_Click(System::Object^ sender, System::EventArgs^ e) {
	selectedPiece = PieceType::Rook;
	this->DialogResult = System::Windows::Forms::DialogResult::OK;
	this->Close();
}
private: System::Void picKnight_Click(System::Object^ sender, System::EventArgs^ e) {
	selectedPiece = PieceType::Knight;
	this->DialogResult = System::Windows::Forms::DialogResult::OK;
	this->Close();
}
private: System::Void picQueen_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
	picQueen->Cursor = Cursors::Hand;
}
private: System::Void picBishop_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
	picBishop->Cursor = Cursors::Hand;
}
private: System::Void picRook_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
	picRook->Cursor = Cursors::Hand;
}
private: System::Void picKnight_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
	picKnight->Cursor = Cursors::Hand;
}
};
}
