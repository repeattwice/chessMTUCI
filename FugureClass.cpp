#include "FugureClass.h"


using namespace System;
using namespace System::Drawing;


namespace chessMtuci {

	Figure::Figure(int startRow, int startCol, bool isWhite, String^ name)
	{
		row = startRow;
		colomn = startCol;
		color = isWhite;
		FigureName = name;
		figureImage = nullptr;
		PosibleMoves = gcnew cli::array<Tuple<int, int>^>(0);
	}

	void Figure::Highlite()
	{
		
	}

	void Figure::MoveTo(int newRow, int newCol)
	{
		
	}

	bool Figure::CanMoveByRules()
	{
		return false;
	}

	void Figure::LoadFigureImage()
	{
		try {
			String^ path = String::Format("images\\figures\\{0}.png", FigureName);
			if (System::IO::File::Exists(path)) {
				figureImage = Image::FromFile(path);
				return;
			}
			else {
				figureImage = nullptr;
				System::Diagnostics::Debug::WriteLine("Image not found" + path);
			}
		}
		catch (Exception^ ex) {
			figureImage = nullptr;
			System::Diagnostics::Debug::WriteLine("Image not found" + ex->Message);
		}
	}


	int Figure::Row::get()
	{
		return row;
	}

	void Figure::Row::set(int v)
	{
		this->row = v;
	}

	int Figure::Col::get()
	{
		return colomn;
	}

	void Figure::Col::set(int v)
	{
		this->colomn = v;
	}

	Tuple<int, int>^ Figure::Position::get()
	{
		return gcnew Tuple<int, int>(row, colomn);
	}

	void Figure::Position::set(Tuple<int, int>^ pos)
	{
		row = pos->Item1;
		colomn = pos->Item2;
	}

	bool Figure::IsWhite::get()
	{
		return color;
	}

	String^ Figure::Name::get()
	{
		return FigureName;
	}

	Image^ Figure::FigureImage::get()
	{
		if (figureImage == nullptr) {
			LoadFigureImage();
		}
		return figureImage;
	}

	void Figure::FigureImage::set(Image^ link)
	{
		this->figureImage = link;
	}
}