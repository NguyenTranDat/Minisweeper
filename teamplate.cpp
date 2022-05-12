#include "Game.h"

bool Game::clickBeginner(Point _pos) {
	if (_pos.x < 10) return false;
	if (_pos.x > this->video.width - 10) return false;
	if (_pos.y <= IMG_HEIGHT) return false;
	if (_pos.y > IMG_HEIGHT * 2) return false;
	return true;
}

bool Game::clickInter(Point _pos) {
	if (_pos.x < 10) return false;
	if (_pos.x > this->video.width - 10) return false;
	if (_pos.y <= IMG_HEIGHT * 2) return false;
	if (_pos.y > IMG_HEIGHT * 3) return false;
	return true;
}

bool Game::clickExpert(Point _pos) {
	if (_pos.x < 10) return false;
	if (_pos.x > this->video.width - 10) return false;
	if (_pos.y <= IMG_HEIGHT * 3) return false;
	if (_pos.y > IMG_HEIGHT * 4) return false;
	return true;
}