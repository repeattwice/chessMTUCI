#include "Game.h"
#include "FugureClass.h"
#include <stdlib.h>

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
    bool Game::CheckKing(bool isWhiteKing) {
        String^ KingName = isWhiteKing ? "kingWhite" : "kingBlack";
        String^ opponentPawn = isWhiteKing ? "pawnBlack" : "pawnWhite";

        int kingRow = -1;
        int kingCol = -1;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (BoardFigures[i, j] != nullptr && BoardFigures[i, j]->Name == KingName) {
                    kingRow = i;
                    kingCol = j;
                    break;
                }
            }
            if (kingRow != -1) {
                break;
            }
        }
        if (kingRow == -1) {
            return false;
        }

        int pawnDir = isWhiteKing ? 1 : -1;
        if (kingRow + pawnDir >= 0 && kingRow + pawnDir < 8) {
            if (kingCol - 1 >= 0 && BoardFigures[kingRow + pawnDir, kingCol - 1] != nullptr && BoardFigures[kingRow + pawnDir, kingCol - 1]->Name == opponentPawn && BoardFigures[kingRow + pawnDir, kingCol - 1]->IsWhite != isWhiteKing) {
                return true;
            }
            if (kingCol + 1 < 8 && BoardFigures[kingRow + pawnDir, kingCol + 1] != nullptr && BoardFigures[kingRow + pawnDir, kingCol + 1]->Name == opponentPawn && BoardFigures[kingRow + pawnDir, kingCol + 1]->IsWhite != isWhiteKing) {
                return true;
            }
        }
        array<Tuple<int, int>^>^ knightMoves = {
            gcnew Tuple<int,int>(-2,-1),
            gcnew Tuple<int,int>(-2,1),
            gcnew Tuple<int,int>(2,-1),
            gcnew Tuple<int,int>(2,1),
            gcnew Tuple<int,int>(-1,-2),
            gcnew Tuple<int,int>(-1,2),
            gcnew Tuple<int,int>(1,-2),
            gcnew Tuple<int,int>(1,2),
        };
        for(int m = 0; m < knightMoves->Length; m++) {
            int newRow = kingRow + knightMoves[m]->Item1;
            int newCol = kingCol + knightMoves[m]->Item2;

            if (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8 && BoardFigures[newRow, newCol] != nullptr && BoardFigures[newRow, newCol]->IsWhite != isWhiteKing && BoardFigures[newRow, newCol]->Name->Contains("knight")) {
                return true;
            }
        }
        array<Tuple<int, int>^>^ direct = {
            gcnew Tuple<int,int>(1,1),
            gcnew Tuple<int,int>(1,0),
            gcnew Tuple<int,int>(0,1),
            gcnew Tuple<int,int>(-1,-1),
            gcnew Tuple<int,int>(-1,0),
            gcnew Tuple<int,int>(0,-1),
            gcnew Tuple<int,int>(1,-1),
            gcnew Tuple<int,int>(-1,1),

        };
        for each (Tuple<int, int>^ dir in direct) {
            int row = kingRow + dir->Item1;
            int col = kingCol + dir->Item2;

            while (row >= 0 && row < 8 && col >= 0 && col < 8) {
                if (BoardFigures[row, col] != nullptr) {
                    if (BoardFigures[row, col]->IsWhite == isWhiteKing) {
                        break;
                    }
                    String^ piceName = BoardFigures[row, col]->Name;
                    bool RookOrQueen = piceName->Contains("rook") || piceName->Contains("queen");
                    bool BishOrQueen = piceName->Contains("bishop") || piceName->Contains("queen");

                    if ((dir->Item1 == 0 || dir->Item2 == 0) && RookOrQueen == true) {
                        return true;
                    }
                    if ((dir->Item1 != 0 || dir->Item2 != 0) && BishOrQueen == true) {
                        return true;
                    }
                    else if (abs(row - kingRow) <= 1 && abs(col - kingCol) <= 1 && piceName->Contains("king")) {
                        return true;
                    }
                    break;
                }
                row += dir->Item1;
                col += dir->Item2;
            }
        }
        return false;
    }
}
