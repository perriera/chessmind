#include <chessmind/game/ChessKing.hpp>
#include <chessmind/game/ChessBoard.hpp>
#include <chessmind/game/ChessExceptions.hpp>
#include <chessmind/game/ChessPawn.hpp>
#include <extras/strings.hpp>
#include <iostream>

using namespace std;

MovesTable ChessKing::allCalculatedMoves(const ChessBoard* board) {
  MovesTable possibleMoves;
  char _col = col();
  char _row = row();
  possibleMoves.push_back(ChessPawn::addPosition(_col + 1, _row + 1));
  possibleMoves.push_back(ChessPawn::addPosition(_col + 0, _row + 1));
  possibleMoves.push_back(ChessPawn::addPosition(_col - 1, _row + 1));
  possibleMoves.push_back(ChessPawn::addPosition(_col + 1, _row - 1));
  possibleMoves.push_back(ChessPawn::addPosition(_col + 0, _row - 1));
  possibleMoves.push_back(ChessPawn::addPosition(_col - 1, _row - 1));
  possibleMoves.push_back(ChessPawn::addPosition(_col + 1, _row + 0));
  possibleMoves.push_back(ChessPawn::addPosition(_col - 1, _row + 0));
  return allLegalMoves(possibleMoves, board);
}