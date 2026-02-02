#pragma once
namespace System {
	namespace Drawing {
		ref class Image;
	}
}
using namespace System;
namespace chessMtuci {
	public ref class Figure {
	private:
		int row;
		int colomn;
		bool color;// 1 - белый, 0 - черный
		String^ FigureName;
		System::Drawing::Image^ figureImage;

	public:
		array <Tuple <int, int>^>^ PosibleMoves;
		Figure(int startRow, int startCol, bool isWhite, String^ name);

		property int Row{
			int get();
			void set(int v);
		}
			property int Col{
				int get();
				void set(int v);
		}
			property Tuple<int, int>^ Position{
				Tuple<int, int> ^ get();
				void set(Tuple<int, int>^ pos);
		}
			property bool IsWhite{
				bool get();
		}
			property String^ Name{
				String ^ get();
		}
			property System::Drawing::Image^ FigureImage{
				System::Drawing::Image ^ get();
				void set(System::Drawing::Image^ link);
		}


		void Highlite();
		void MoveTo(int newRow, int newCol);// выполняет ход в выбранную клетку
		bool CanMoveByRules();//при нажатии на фигуру подсвесивает её 
		void LoadFigureImage();// для подгрузки картинок
	};
}