#pragma once
#include <string>
#include "Game.h"

using namespace System;
using namespace System::Drawing;

namespace chessMtuci {
	public ref class Figure {
	protected:
		int row;
		int colomn;
		bool color;
		String^ FigureName;
		Image^ FigureImage;
	public:
		Figure(int startRow, int startCol, bool isWhite, String^ name);

		property int Row {
			int get();
			void set(int v);
		}
		property int Col {
			int get();
			void set(int v);
		}
		property Tuple<int, int> Position {
			Tuple<int, int> get();
			void set(Tuple<int, int>^ pos);
		}
		property bool IsWhite {
			bool get();
		}
		property String^ Name {
			String^ get();
			void set(String^ v);
		}

		void MoveTo(int newRow, int newCol);// выполняет ход в выбранную клетку
		bool CanMoveByRules();//при нажатии на фигуру подсвесивает её 
	};
}