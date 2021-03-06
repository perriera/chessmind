#include <fstream>
#include <iostream>// std::cout
#include <sstream>// std::stringstream
#include <string>// std::string

#include <chessmind/pgn/PGNReader.hpp>
#include "../vendor/catch.hpp"
#include <extras/strings.hpp>

using namespace std;

SCENARIO("Verify ReplayGameX", "[ReplayGame]")
{
  ifstream myfile("data/pgn/kasparov_muratkuliev_1973.pgn");
  REQUIRE(myfile.good());
  PGNReader parser;
  myfile >> parser;
  REQUIRE(parser.lines().size() == 35);
}
