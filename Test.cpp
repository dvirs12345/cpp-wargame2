// Author - Dvir Sadon

#include "doctest.h"
#include "Board.hpp"
#include <vector>
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
using namespace WarGame;
using namespace std;

TEST_CASE("Test [] Operators")  // 10
{
    Board board(8, 8);
    board[{0,1}] = new FootSoldier(1);
    board[{0,3}] = new FootCommander(1);
    board[{0,5}] = new FootSoldier(1);
    board[{1,7}] = new FootSoldier(1);
    board[{0,7}] = new FootSoldier(1);
    board[{7,1}] = new FootSoldier(2);
    board[{7,3}] = new FootCommander(2);
    board[{7,5}] = new FootSoldier(2);
    board[{7,7}] = new FootSoldier(2);
    board[{0,0}] = new FootSoldier(2);
    CHECK(board[{0,1}]->player == 1);
    CHECK(board[{0,3}]->player == 1);
    CHECK(board[{0,5}]->player == 1);
    CHECK(board[{1,7}]->player == 1);
    CHECK(board[{0,7}]->player == 1);
    CHECK(board[{7,1}]->player == 2);
    CHECK(board[{7,3}]->player == 2);
    CHECK(board[{7,5}]->player == 2);
    CHECK(board[{7,7}]->player == 2);
    CHECK(board[{0,0}]->player == 2);
}


TEST_CASE("Test move") // 20
{
    /*
    Board board(8, 8);
    board[{0,1}] = new FootSoldier(1);
    board[{0,3}] = new FootCommander(1);
    board[{0,5}] = new FootSoldier(1);
    board[{1,7}] = new FootSoldier(1);
    board[{0,7}] = new FootSoldier(1);
    board[{7,1}] = new FootSoldier(2);
    board[{7,3}] = new FootCommander(2);
    board[{7,5}] = new FootSoldier(2);
    board[{7,7}] = new FootSoldier(2);
    board[{0,0}] = new FootSoldier(2);
    CHECK(board[{0,1}]->player == 1);
    CHECK(board[{0,3}]->player == 1);
    CHECK(board[{0,5}]->player == 1);
    CHECK(board[{1,7}]->player == 1);
    CHECK(board[{0,7}]->player == 1);
    CHECK(board[{7,1}]->player == 2);
    CHECK(board[{7,3}]->player == 2);
    CHECK(board[{7,5}]->player == 2);
    CHECK(board[{7,7}]->player == 2);
    CHECK(board[{0,0}]->player == 2);

    board.move(1, {0,1}, Board::Right);
    CHECK(board[{0,2}]->player == 1);
    board.move(1, {0,2}, Board::Left);
    CHECK(board[{0,1}]->player == 1);

    board.move(2, {7,5}, Board::Up);
    CHECK(board[{6,5}]->player == 2);
    board.move(2, {6,5}, Board::Down);
    CHECK(board[{7,5}]->player == 2);

    board.move(1, {0,0}, Board::Down);
    CHECK(board[{1,0}]->player == 1);
    board.move(1, {1,0}, Board::Up);
    CHECK(board[{0,0}]->player == 1);

    board.move(1, {0,0}, Board::Down);
    CHECK(board[{1,0}]->player == 1);
    board.move(1, {1,0}, Board::Down);
    CHECK(board[{2,0}]->player == 1);

    board.move(1, {2,0}, Board::Up);
    CHECK(board[{1,0}]->player == 1);
    board.move(1, {1,0}, Board::Up);
    CHECK(board[{0,0}]->player == 1);
    */
}

TEST_CASE("Test has_soldiers") // 20
{
    Board board(8, 8);

    board[{0,1}] = new FootSoldier(1);
    CHECK(board.has_soldiers(1));
    CHECK(!board.has_soldiers(2));
    board[{0,3}] = new FootCommander(1);
    CHECK(board.has_soldiers(1));
    CHECK(!board.has_soldiers(2));
    board[{0,5}] = new FootSoldier(1);
    CHECK(board.has_soldiers(1));
    CHECK(!board.has_soldiers(2));
    board[{1,7}] = new FootSoldier(1);
    CHECK(board.has_soldiers(1));
    CHECK(!board.has_soldiers(2));
    board[{0,7}] = new FootSoldier(1);
    CHECK(board.has_soldiers(1));
    CHECK(!board.has_soldiers(2));
    board[{7,1}] = new FootSoldier(2);
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board[{7,3}] = new FootCommander(2);
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board[{7,5}] = new FootSoldier(2);
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board[{7,7}] = new FootSoldier(2);
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board[{0,0}] = new FootSoldier(2);
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
}

TEST_CASE("Test exception throwing  ") // 40
{
    Board board(8, 8);
    board[{0,1}] = new FootSoldier(1);
    board[{0,3}] = new FootCommander(1);
    board[{0,5}] = new FootSoldier(1);
    board[{1,7}] = new FootSoldier(1);
    board[{0,7}] = new FootSoldier(1);
    board[{7,1}] = new FootSoldier(2);
    board[{7,3}] = new FootCommander(2);
    board[{7,5}] = new FootSoldier(2);
    board[{7,7}] = new FootSoldier(2);
    board[{0,0}] = new FootSoldier(2);

    /* There is no soldier in the source location (i.e., the soldier pointer is null) */
    CHECK_THROWS(board.move(1,{1,0},Board::Up));
    CHECK_THROWS(board.move(1,{2,0},Board::Up));
    CHECK_THROWS(board.move(1,{3,0},Board::Up));
    CHECK_THROWS(board.move(1,{4,0},Board::Up));
    CHECK_THROWS(board.move(1,{5,5},Board::Up));
    CHECK_THROWS(board.move(1,{6,6},Board::Up));
    CHECK_THROWS(board.move(1,{7,2},Board::Up));
    CHECK_THROWS(board.move(1,{1,2},Board::Up));
    CHECK_THROWS(board.move(1,{3,3},Board::Up));
    CHECK_THROWS(board.move(1,{3,5},Board::Up));
    
    /* The soldier in the source location belongs to the other player. */
    CHECK_THROWS(board.move(2,{0,0},Board::Down));
    CHECK_THROWS(board.move(2,{0,1},Board::Down));
    CHECK_THROWS(board.move(2,{0,3},Board::Down));
    CHECK_THROWS(board.move(2,{0,5},Board::Down));
    CHECK_THROWS(board.move(2,{0,7},Board::Left));
    CHECK_THROWS(board.move(2,{1,7},Board::Down));
    CHECK_THROWS(board.move(1,{7,1},Board::Up));
    CHECK_THROWS(board.move(1,{7,3},Board::Up));
    CHECK_THROWS(board.move(1,{7,5},Board::Up));
    CHECK_THROWS(board.move(1,{7,7},Board::Up));

    /* The target location doesn't exist */
    CHECK_THROWS(board.move(1,{0,0},Board::Up));
    CHECK_THROWS(board.move(1,{0,0},Board::Left));
    CHECK_THROWS(board.move(1,{0,1},Board::Up));
    CHECK_THROWS(board.move(1,{0,3},Board::Up));
    CHECK_THROWS(board.move(1,{0,5},Board::Up));
    CHECK_THROWS(board.move(1,{0,7},Board::Up));
    CHECK_THROWS(board.move(2,{7,1},Board::Down));
    CHECK_THROWS(board.move(2,{7,3},Board::Up));
    CHECK_THROWS(board.move(2,{7,5},Board::Up));
    CHECK_THROWS(board.move(2,{7,7},Board::Up));

    /* There is already another soldier (of this or the other player) in the target location. */
    CHECK_THROWS(board.move(1,{0,0},Board::Left));
    CHECK_THROWS(board.move(1,{0,1},Board::Right));
    CHECK_THROWS(board.move(1,{0,7},Board::Down));
    CHECK_THROWS(board.move(1,{1,7},Board::Up));

    /* Location does not exist */
    CHECK_THROWS(board.move(1,{100,0},Board::Left));
    CHECK_THROWS(board.move(1,{1001,0},Board::Up));
    CHECK_THROWS(board.move(1,{78,5},Board::Right));
    CHECK_THROWS(board.move(1,{69,2},Board::Up));
    CHECK_THROWS(board.move(1,{1,200},Board::Right));
    CHECK_THROWS(board.move(1,{6,66},Board::Up));
    CHECK_THROWS(board.move(1,{9,238},Board::Up));
    CHECK_THROWS(board.move(2,{6,66},Board::Left));
    CHECK_THROWS(board.move(2,{1,200},Board::Up));
    CHECK_THROWS(board.move(2,{6,62},Board::Up));
    CHECK_THROWS(board.move(2,{190,0},Board::Up));
    CHECK_THROWS(board.move(2,{6,66},Board::Up));
    CHECK_THROWS(board.move(1,{9,32},Board::Down));
    CHECK_THROWS(board.move(1,{-2,-1},Board::Right));
    CHECK_THROWS(board.move(1,{-1,-200},Board::Up));
    CHECK_THROWS(board.move(1,{98,3},Board::Down));

}
