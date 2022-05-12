#include "Game.h"

void Game::renderLevel() {
	this->renderText("BEGIN (9x9 10)", { 10, IMG_HEIGHT });
	this->renderText("INTER (16x16 40)", { 10, IMG_HEIGHT * 2 });
	this->renderText("EXPERT (16x30 99)", { 10, IMG_HEIGHT * 3 });
}

void Game::clickSetting() {
	this->gameLogic();
	this->renderLevel();
}