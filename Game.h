#pragma once
#include "FugureClass.h"

namespace chessMTUCI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;

	/// <summary>
	/// Сводка для Game
	/// </summary>
	public ref class Game : public System::Windows::Forms::Form
	{
	public:
		Game(void)
		{
			InitializeComponent();
			AddPictureBoxesToTableLayout();
			InitializaBoard();
			DrawFigyres();
			highlightedCells = gcnew array<bool, 2>(8, 8);
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++) {
					highlightedCells[i, j] = false;
				}
			}
		}
		PictureBox^ GetChessCell(int row, int col);

		array<chessMtuci::Figure^, 2>^ BoardFigures;

		void AddPictureBoxesToTableLayout() {
			this->tableLayoutPanel1->Controls->Clear();
			this->tableLayoutPanel1->BackColor = System::Drawing::Color::Transparent;
			this->tableLayoutPanel1->CellBorderStyle = TableLayoutPanelCellBorderStyle::None;
			chessCell = gcnew array<PictureBox^, 2>(8, 8);
			for (int row = 0; row < 8; row++) {
				for (int col = 0; col < 8; col++) {
					PictureBox^ cell = gcnew PictureBox();
					cell->Dock = DockStyle::Fill;
					cell->Margin = System::Windows::Forms::Padding(0);
					cell->Padding = System::Windows::Forms::Padding(0);
					cell->Name = String::Format("cell_{0}_{1}", row, col);
					if ((row + col) % 2 == 0) {
						cell->BackColor = System::Drawing::Color::FromArgb(180, System::Drawing::Color::Purple);
					}
					else {
						cell->BackColor = System::Drawing::Color::FromArgb(180, System::Drawing::Color::Violet);
					}
					cell->BorderStyle = BorderStyle::FixedSingle;
					cell->Tag = gcnew Tuple<int, int>(row, col);

					cell->Click += gcnew System::EventHandler(this, &Game::chessCell_Click);
					cell->MouseEnter += gcnew EventHandler(this, &Game::chessCell_MouseEnter);
					cell->MouseLeave += gcnew EventHandler(this, &Game::chessCell_MouseLeave);
					cell->Cursor = Cursors::Hand;
					chessCell[row, col] = cell;

					this->tableLayoutPanel1->Controls->Add(cell, col, row);
				}
			}
		}

		void InitializaBoard() {
			BoardFigures = gcnew array<chessMtuci::Figure^, 2>(8, 8);

			BoardFigures[7, 0] = gcnew chessMtuci::Figure(7, 0, true, "rookWhite");
			BoardFigures[7, 7] = gcnew chessMtuci::Figure(7, 7, true, "rookWhite");

			BoardFigures[7, 1] = gcnew chessMtuci::Figure(7, 1, true, "knightWhite");
			BoardFigures[7, 6] = gcnew chessMtuci::Figure(7, 6, true, "knightWhite");

			BoardFigures[7, 2] = gcnew chessMtuci::Figure(7, 2, true, "bishopWhite");
			BoardFigures[7, 5] = gcnew chessMtuci::Figure(7, 5, true, "bishopWhite");

			BoardFigures[7, 3] = gcnew chessMtuci::Figure(7, 3, true, "queenWhite");
			BoardFigures[7, 4] = gcnew chessMtuci::Figure(7, 4, true, "kingWhite");

			for (int col = 0; col < 8; col++) {
				BoardFigures[6, col] = gcnew chessMtuci::Figure(6, col, true, "pawnWhite");
			}


			BoardFigures[0, 0] = gcnew chessMtuci::Figure(0, 0, false, "rookBlack");
			BoardFigures[0, 7] = gcnew chessMtuci::Figure(0, 7, false, "rookBlack");

			BoardFigures[0, 1] = gcnew chessMtuci::Figure(0, 1, false, "knightBlack");
			BoardFigures[0, 6] = gcnew chessMtuci::Figure(0, 6, false, "knightBlack");

			BoardFigures[0, 2] = gcnew chessMtuci::Figure(0, 2, false, "bishopBlack");
			BoardFigures[0, 5] = gcnew chessMtuci::Figure(0, 5, false, "bishopBlack");

			BoardFigures[0, 3] = gcnew chessMtuci::Figure(0, 3, false, "queenBlack");
			BoardFigures[0, 4] = gcnew chessMtuci::Figure(0, 4, false, "kingBlack");

			for (int col = 0; col < 8; col++) {
				BoardFigures[1, col] = gcnew chessMtuci::Figure(1, col, false, "pawnBlack");
			}
		}

		void DrawFigyres() {
			for (int row = 0; row < 8; row++) {
				for (int col = 0; col < 8; col++) {
					chessMtuci::Figure^ figure = BoardFigures[row, col];
					PictureBox^ cell = chessCell[row, col];

					if (figure != nullptr) {
						cell->Image = figure->FigureImage;
						cell->SizeMode = PictureBoxSizeMode::CenterImage;
					}
					else {
						cell->Image = nullptr;
					}
				}
			}
		}

	protected:
		cli::array<PictureBox^, 2>^ chessCell;
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
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ btnClose;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;


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
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// lblMove
			// 
			this->lblMove->AutoSize = true;
			this->lblMove->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lblMove->Location = System::Drawing::Point(536, 28);
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
			this->lblMoveNumber->Location = System::Drawing::Point(589, 28);
			this->lblMoveNumber->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblMoveNumber->Name = L"lblMoveNumber";
			this->lblMoveNumber->Size = System::Drawing::Size(20, 24);
			this->lblMoveNumber->TabIndex = 2;
			this->lblMoveNumber->Text = L"1";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(9, 11);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(482, 520);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 3;
			this->pictureBox1->TabStop = false;
			// 
			// btnClose
			// 
			this->btnClose->BackColor = System::Drawing::Color::Red;
			this->btnClose->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnClose->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnClose->Location = System::Drawing::Point(626, -1);
			this->btnClose->Margin = System::Windows::Forms::Padding(2);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(22, 28);
			this->btnClose->TabIndex = 4;
			this->btnClose->Text = L"X";
			this->btnClose->UseVisualStyleBackColor = false;
			this->btnClose->Click += gcnew System::EventHandler(this, &Game::btnClose_Click);
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 8;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				12.5F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				12.5F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				12.5F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				12.5F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				12.5F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				12.5F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				12.5F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				12.5F)));
			this->tableLayoutPanel1->Location = System::Drawing::Point(9, 10);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 8;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 12.5F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 12.5F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 12.5F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 12.5F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 12.5F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 12.5F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 12.5F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 12.5F)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(482, 521);
			this->tableLayoutPanel1->TabIndex = 5;
			this->tableLayoutPanel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Game::tableLayoutPanel1_Paint);
			// 
			// Game
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->ClientSize = System::Drawing::Size(648, 612);
			this->ControlBox = false;
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->lblMoveNumber);
			this->Controls->Add(this->lblMove);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"Game";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Шахматы";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		void ClearHighLights() {
			for (int r = 0; r < 8; r++) {
				for (int c = 0; c < 8; c++) {
					highlightedCells[r, c] = false;
					if ((r + c) % 2 == 0) {
						chessCell[r, c]->BackColor = System::Drawing::Color::FromArgb(180, System::Drawing::Color::Purple);
					}
					else {
						chessCell[r, c]->BackColor = System::Drawing::Color::FromArgb(180, System::Drawing::Color::Violet);
					}
				}
			}
		}
		bool isCellH(int frow, int fcol) {
			if (frow >= 0 && fcol >= 0 && frow < 8 && fcol < 8) {
				return highlightedCells[frow, fcol];
			}
			return false;
		}
		void Highlight(int frow, int fcol) {
			if (frow >= 0 && fcol >= 0 && frow < 8 && fcol < 8) {
				chessCell[frow, fcol]->BackColor = System::Drawing::Color::Green;
				highlightedCells[frow, fcol] = true;
			}
		}
		void MoveFigure(int fRow, int fCol, int ToRow, int ToCol) {
			BoardFigures[ToRow, ToCol] = BoardFigures[fRow, fCol];
			BoardFigures[fRow, fCol] = nullptr;
			if (BoardFigures[ToRow, ToCol] != nullptr) {
				BoardFigures[ToRow, ToCol]->Row = ToRow;
				BoardFigures[ToRow, ToCol]->Col = ToCol;
			}
			DrawFigyres();
		}
#pragma endregion
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e) {
	Application::Exit();
}
private: System::Void tableLayoutPanel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}



	void FigureMoves(int frow, int fcol, String^ Obj) {
		if (Obj == "pawnWhite") {
			if (frow == 6 && BoardFigures[frow - 2, fcol] == nullptr) {
				Highlight(frow - 2, fcol);

			}
			if (frow > 0 && BoardFigures[frow - 1, fcol] == nullptr) {
				Highlight(frow - 1, fcol);
			}
			if (frow > 0 && fcol < 7 && BoardFigures[frow - 1, fcol + 1] != nullptr) {
				if (BoardFigures[frow - 1, fcol + 1]->IsWhite != BoardFigures[frow, fcol]->IsWhite) {
					Highlight(frow - 1, fcol + 1);
				}
			}
			if (frow > 0 && fcol > 0 && BoardFigures[frow - 1, fcol - 1] != nullptr) {
				if (BoardFigures[frow - 1, fcol - 1]->IsWhite != BoardFigures[frow, fcol]->IsWhite) {
					Highlight(frow - 1, fcol - 1);
				}
			}
		}
		if (Obj == "pawnBlack") {
			if (frow == 1 && BoardFigures[frow + 2, fcol] == nullptr) {
				Highlight(frow + 2, fcol);

			}
			if (frow < 7 && BoardFigures[frow + 1, fcol] == nullptr) {
				Highlight(frow + 1, fcol);
			}
			if (frow < 7 && fcol < 7 && BoardFigures[frow + 1, fcol + 1] != nullptr) {
				if (BoardFigures[frow + 1, fcol + 1]->IsWhite != BoardFigures[frow, fcol]->IsWhite) {
					Highlight(frow + 1, fcol + 1);
				}
			}
			if (frow <7 && fcol > 0 && BoardFigures[frow + 1, fcol - 1] != nullptr) {
				if (BoardFigures[frow + 1, fcol - 1]->IsWhite != BoardFigures[frow, fcol]->IsWhite) {
					Highlight(frow + 1, fcol - 1);
				}
			}
		}
		if (Obj->Contains("rook")) {
			int NewRow = frow - 1;
			while (NewRow >= 0) {
				if (BoardFigures[NewRow, fcol] == nullptr) {
					Highlight(NewRow, fcol);
					NewRow -= 1;
				}
				else if (BoardFigures[frow, fcol]->IsWhite != BoardFigures[NewRow, fcol]->IsWhite) {
					Highlight(NewRow, fcol);
					break;
				}
				else {
					break;
				}
			}
			NewRow = frow + 1;
			while (NewRow < 8) {
				if (BoardFigures[NewRow, fcol] == nullptr) {
					Highlight(NewRow, fcol);
					NewRow += 1;
				}
				else if (BoardFigures[frow, fcol]->IsWhite != BoardFigures[NewRow, fcol]->IsWhite) {
					Highlight(NewRow, fcol);
					break;
				}
				else {
					break;
				}
			}
			int NewCol = fcol - 1;
			while (NewCol >= 0) {
				if (BoardFigures[frow, NewCol] == nullptr) {
					Highlight(frow, NewCol);
					NewCol -= 1;
				}
				else if (BoardFigures[frow, fcol]->IsWhite != BoardFigures[frow, NewCol]->IsWhite) {
					Highlight(frow, NewCol);
					break;
				}
				else {
					break;
				}
			}
			NewCol = fcol + 1;
			while (NewCol < 8) {
				if (BoardFigures[frow, NewCol] == nullptr) {
					Highlight(frow, NewCol);
					NewCol += 1;
				}
				else if (BoardFigures[frow, fcol]->IsWhite != BoardFigures[frow, NewCol]->IsWhite) {
					Highlight(frow, NewCol);
					break;
				}
				else {
					break;
				}
			}
		}
		if (Obj->Contains("knight")) {
			cli::array<int, 2>^ KnighMoves;
			KnighMoves = gcnew array<int, 2>(8, 2) {
				{ -2, 1 },
				{ -2, -1 },
				{ 2, 1 },
				{ 2, -1 },
				{ 1, 2 },
				{ 1, -2 },
				{ -1, 2},
				{-1, -2 }
			};
			for (int i = 0; i < 8; i++) {
				if (frow + KnighMoves[i, 0] >= 0 && frow + KnighMoves[i, 0] < 8 && fcol + KnighMoves[i, 1] >= 0 && fcol + KnighMoves[i, 1] < 8) {
					if (BoardFigures[frow + KnighMoves[i, 0], fcol + KnighMoves[i, 1]] == nullptr) {
						Highlight(frow + KnighMoves[i, 0], fcol + KnighMoves[i, 1]);
					}
					else if (BoardFigures[frow + KnighMoves[i, 0], fcol + KnighMoves[i, 1]]->IsWhite != BoardFigures[frow, fcol]->IsWhite) {
						Highlight(frow + KnighMoves[i, 0], fcol + KnighMoves[i, 1]);
					}
				}
			}
		}
		if (Obj->Contains("bishop")) {
			int NewRow = frow - 1;
			int NewCol = fcol - 1;
			while (NewRow >= 0 && NewCol >= 0) {
				if (BoardFigures[NewRow, NewCol] == nullptr) {
					Highlight(NewRow, NewCol);
					NewRow--;
					NewCol--;
				}
				else if (BoardFigures[NewRow, NewCol]->IsWhite != BoardFigures[frow, fcol]->IsWhite) {
					Highlight(NewRow, NewCol);
					break;
				}
				else {
					break;
				}
			}
			NewRow = frow + 1;
			NewCol = fcol + 1;
			while (NewRow < 8 && NewCol < 8) {
				if (BoardFigures[NewRow, NewCol] == nullptr) {
					Highlight(NewRow, NewCol);
					NewRow++;
					NewCol++;
				}
				else if (BoardFigures[NewRow, NewCol]->IsWhite != BoardFigures[frow, fcol]->IsWhite) {
					Highlight(NewRow, NewCol);
					break;
				}
				else {
					break;
				}
			}
			NewRow = frow + 1;
			NewCol = fcol - 1;
			while (NewRow < 8 && NewCol >= 0) {
				if (BoardFigures[NewRow, NewCol] == nullptr) {
					Highlight(NewRow, NewCol);
					NewRow++;
					NewCol--;
				}
				else if (BoardFigures[NewRow, NewCol]->IsWhite != BoardFigures[frow, fcol]->IsWhite) {
					Highlight(NewRow, NewCol);
					break;
				}
				else {
					break;
				}
			}
			NewRow = frow - 1;
			NewCol = fcol + 1;
			while (NewRow >= 0 && NewCol < 8) {
				if (BoardFigures[NewRow, NewCol] == nullptr) {
					Highlight(NewRow, NewCol);
					NewRow--;
					NewCol++;
				}
				else if (BoardFigures[NewRow, NewCol]->IsWhite != BoardFigures[frow, fcol]->IsWhite) {
					Highlight(NewRow, NewCol);
					break;
				}
				else {
					break;
				}
			}
		}
		if (Obj->Contains("queen")) {
			int NewRow = frow - 1;
			while (NewRow >= 0) {
				if (BoardFigures[NewRow, fcol] == nullptr) {
					Highlight(NewRow, fcol);
					NewRow -= 1;
				}
				else if (BoardFigures[frow, fcol]->IsWhite != BoardFigures[NewRow, fcol]->IsWhite) {
					Highlight(NewRow, fcol);
					break;
				}
				else {
					break;
				}
			}
			NewRow = frow + 1;
			while (NewRow < 8) {
				if (BoardFigures[NewRow, fcol] == nullptr) {
					Highlight(NewRow, fcol);
					NewRow += 1;
				}
				else if (BoardFigures[frow, fcol]->IsWhite != BoardFigures[NewRow, fcol]->IsWhite) {
					Highlight(NewRow, fcol);
					break;
				}
				else {
					break;
				}
			}
			int NewCol = fcol - 1;
			while (NewCol >= 0) {
				if (BoardFigures[frow, NewCol] == nullptr) {
					Highlight(frow, NewCol);
					NewCol -= 1;
				}
				else if (BoardFigures[frow, fcol]->IsWhite != BoardFigures[frow, NewCol]->IsWhite) {
					Highlight(frow, NewCol);
					break;
				}
				else {
					break;
				}
			}
			NewCol = fcol + 1;
			while (NewCol < 8) {
				if (BoardFigures[frow, NewCol] == nullptr) {
					Highlight(frow, NewCol);
					NewCol += 1;
				}
				else if (BoardFigures[frow, fcol]->IsWhite != BoardFigures[frow, NewCol]->IsWhite) {
					Highlight(frow, NewCol);
					break;
				}
				else {
					break;
				}
			}
			NewRow = frow - 1;
			NewCol = fcol - 1;
			while (NewRow >= 0 && NewCol >= 0) {
				if (BoardFigures[NewRow, NewCol] == nullptr) {
					Highlight(NewRow, NewCol);
					NewRow--;
					NewCol--;
				}
				else if (BoardFigures[NewRow, NewCol]->IsWhite != BoardFigures[frow, fcol]->IsWhite) {
					Highlight(NewRow, NewCol);
					break;
				}
				else {
					break;
				}
			}
			NewRow = frow + 1;
			NewCol = fcol + 1;
			while (NewRow < 8 && NewCol < 8) {
				if (BoardFigures[NewRow, NewCol] == nullptr) {
					Highlight(NewRow, NewCol);
					NewRow++;
					NewCol++;
				}
				else if (BoardFigures[NewRow, NewCol]->IsWhite != BoardFigures[frow, fcol]->IsWhite) {
					Highlight(NewRow, NewCol);
					break;
				}
				else {
					break;
				}
			}
			NewRow = frow + 1;
			NewCol = fcol - 1;
			while (NewRow < 8 && NewCol >= 0) {
				if (BoardFigures[NewRow, NewCol] == nullptr) {
					Highlight(NewRow, NewCol);
					NewRow++;
					NewCol--;
				}
				else if (BoardFigures[NewRow, NewCol]->IsWhite != BoardFigures[frow, fcol]->IsWhite) {
					Highlight(NewRow, NewCol);
					break;
				}
				else {
					break;
				}
			}
			NewRow = frow - 1;
			NewCol = fcol + 1;
			while (NewRow >= 0 && NewCol < 8) {
				if (BoardFigures[NewRow, NewCol] == nullptr) {
					Highlight(NewRow, NewCol);
					NewRow--;
					NewCol++;
				}
				else if (BoardFigures[NewRow, NewCol]->IsWhite != BoardFigures[frow, fcol]->IsWhite) {
					Highlight(NewRow, NewCol);
					break;
				}
				else {
					break;
				}
			}
		}
		if (Obj->Contains("king")) {
			cli::array<int, 2>^ KingMoves;
			KingMoves = gcnew array<int, 2>(8, 2) {
				{1 , 0},
				{-1 , 0},
				{0 , 1},
				{0 , -1},
				{1 , 1},
				{-1 , -1},
				{1 , -1},
				{-1 , 1}
			};
			for (int i = 0; i < 8; i++) {
				if (frow + KingMoves[i, 0] >= 0 && frow + KingMoves[i, 0] < 8 && fcol + KingMoves[i, 1] >= 0 && fcol + KingMoves[i, 1] < 8) {
					if (BoardFigures[frow + KingMoves[i, 0], fcol + KingMoves[i, 1]] == nullptr) {
						Highlight(frow + KingMoves[i, 0], fcol + KingMoves[i, 1]);
					}
					else if (BoardFigures[frow + KingMoves[i, 0], fcol + KingMoves[i, 1]]->IsWhite != BoardFigures[frow, fcol]->IsWhite) {
						Highlight(frow + KingMoves[i, 0], fcol + KingMoves[i, 1]);
					}
				}
			}

		}
	}

	cli::array<bool, 2>^ highlightedCells;
	int selectedRow = -1;
	int selectedCol = -1;

private: System::Void chessCell_Click(System::Object^ sender, System::EventArgs^ e) {
	PictureBox^ clickedCell = (PictureBox^)sender;
	Tuple<int, int>^ coords = (Tuple<int, int>^)clickedCell->Tag;
	int row = coords->Item1;
	int col = coords->Item2;

	if (isCellH(row, col)) {
		MoveFigure(selectedRow, selectedCol, row, col);
		ClearHighLights();
		return;
	}

	if (BoardFigures[row, col] != nullptr) {
		chessMtuci::Figure^ figure = BoardFigures[row, col];
		String^ figureName = figure->Name;
		ClearHighLights();
		clickedCell->BackColor = System::Drawing::Color::Yellow;
		FigureMoves(row, col, figureName);
		selectedCol = col;
		selectedRow = row;

	}
	else {
		ClearHighLights();
	}
}
private: System::Void chessCell_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void chessCell_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
}
};
}

