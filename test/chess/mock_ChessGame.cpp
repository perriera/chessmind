
#include <iostream>

#include "../vendor/catch.hpp"
#include <chessmind/game/ChessGame.hpp>
#include "../vendor/fakeit.hpp"

using namespace extras;
using namespace fakeit;

SCENARIO("Mock ChessGameInterface: toOctal", "[CHES-9]") {
    ChessMoves correct_answer;
    Mock<ChessGameInterface> mock;
    When(Method(mock, moves)).Return(correct_answer);

    ChessGameInterface& i = mock.get();
    REQUIRE(i.moves() == correct_answer);
    Verify(Method(mock, moves));
}