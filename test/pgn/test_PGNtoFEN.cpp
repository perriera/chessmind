#include <fstream>
#include <iostream> 
#include <sstream> 
#include <string>
#include "../vendor/catch.hpp"
#include <extras/strings.hpp>
#include <chessmind/pgn/PGNGame.hpp>
#include <chessmind/game/ChessBoard.hpp>

using namespace std;

SCENARIO("Verify PGNtoFENInterface can be read PGN file", "[PGNtoFEN]")
{
    ifstream myfile("data/pgn/kasparov_muratkuliev_1973.pgn");
    REQUIRE(myfile.good());
    PGNGame game;
    myfile >> game;
    REQUIRE(game.parameters().size() == 12);
    REQUIRE(game.pgnmoves().size() == 32);
}

SCENARIO("Verify PGNtoFENInterface can convertToFEN", "[PGNtoFEN]")
{
    ifstream myfile("data/pgn/kasparov_muratkuliev_1973.pgn");
    REQUIRE(myfile.good());
    PGNGame game;
    myfile >> game;
    //    game.convertToFEN();


}

