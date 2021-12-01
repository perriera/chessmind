#include <fstream>
#include <iostream>// std::cout
#include <sstream>// std::stringstream
#include <string>// std::string

#include <chessmind/ai/CrossTableLine.hpp>
#include <chessmind/fen/FENReader.hpp>
#include <chessmind/stat/StatWriter.hpp>
#include "../vendor/catch.hpp"
#include <extras/devices/ansi_colors.hpp>
#include <extras/crcs.hpp>
#include <extras/crcs.hpp>
#include <extras/strings.hpp>

using namespace std;

SCENARIO("Verify CrossTableLine ('KASPAROV.ct')", "[CrossTableLine]")
{
  ifstream myFENfile("data/fen/KASPAROV.FEN");
  REQUIRE(myFENfile.good());
  ifstream myPGNfile("data/pgn/KASPAROV.PGN");
  REQUIRE(myPGNfile.good());

  try {
    while (myFENfile.good() && myPGNfile.good()) {
      FENReader fenReader;
      myFENfile >> fenReader;

      PGNGame pgnReader;
      myPGNfile >> pgnReader;

      StatWriter statWriter;
      statWriter.convert(fenReader, pgnReader);

      auto statLines = statWriter.lines();
      for (auto statLine : statLines) {
        cout << statLine << endl;
      }
    }
  }
  catch (exception& ex) {
    cout << ex.what() << endl;
  }
}
