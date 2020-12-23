/*
Program name : Final Project Game
Author : Adam Slusser
Date : 12/ 6 / 2019
Description : This is a game where a character has a broken ship and they have to fix 3 of the ships
problems in order to win the game. Each problem requires a unique tool which can be found at different
locations throughout the ship. The player must pick up the tool and go back to the problem area in order
to fix it. They must do this within 50 turns before their "air supply" runs out. If they fail to do this 
the lose the game.
and percentages.
*/
#include "Space.hpp"
#include "Bridge.hpp"
#include "CargoBay.hpp"
#include "CommonArea.hpp"
#include "EngineBay.hpp"
#include "LivingArea.hpp"
#include "Outside.hpp"
#include "Game.hpp"
#include "validation.hpp"

int main(void) {

	//Create new instances of each class.
	Bridge* bridge = new Bridge();
	CargoBay* cargoBay = new CargoBay();
	CommonArea* commonArea = new CommonArea();
	EngineBay* engineBay = new EngineBay();
	LivingArea* livingArea = new LivingArea();
	Outside* outside = new Outside();
	Game* game = new Game(bridge);


	//Set the directions for each pointer in each class so that player can
	//move in the game.
	bridge->set_south(commonArea);
	commonArea->set_north(bridge);
	commonArea->set_east(livingArea);
	commonArea->set_south(engineBay);
	commonArea->set_west(cargoBay);
	cargoBay->set_east(commonArea);
	engineBay->set_north(commonArea);
	livingArea->set_west(commonArea);
	livingArea->set_north(outside);
	outside->set_south(livingArea);

	//Start the game.
	game->game_start();

	//Delete Objects
	delete bridge;
	delete cargoBay;
	delete commonArea;
	delete engineBay;
	delete livingArea;
	delete outside;
	delete game;
}