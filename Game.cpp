#include "Game.h"
#include "FugureClass.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

namespace chessMTUCI {

    PictureBox^ Game::GetChessCell(int row, int col) {
        if (row >= 0 && row < 8 && col >= 0 && col < 8 && chessCell != nullptr) {
            return chessCell[row, col];
        }
        return nullptr;
    }
}
