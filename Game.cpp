#include "Game.h"

void Game::initGame() {
	this->array = new Image * [this->getRow()];
	for (int i = 0; i < this->getRow(); i++) {
		this->array[i] = new Image[this->getCol()];
		for (int j = 0; j < this->getCol(); j++) {
			this->array[i][j].pos.x = i * IMG_WIDTH;
			this->array[i][j].pos.y = j * IMG_HEIGHT + IMG_HEIGHT;
			*this->array[i][j].open = false;
			*this->array[i][j].flag = false;
			*this->array[i][j].empty = false;
			*this->array[i][j].boom = false;
		}
	}
	*this->endGame = false;
	this->clickBoom = false;
	this->score = 0;
	this->setting = false;
	this->remainBoom = this->getBoom();
}

void Game::initWindow() {
	this->window->close();
	this->video.width = IMG_WIDTH * this->getRow();
	this->video.height = IMG_HEIGHT * this->getCol() + IMG_HEIGHT;
	this->window = new sf::RenderWindow(
		this->video,
		"domin",
		sf::Style::Close | sf::Style::Titlebar
	);
}

void Game::setupBoom() {
	srand(time(NULL));
	for (int i = 0; i < this->getBoom();) {
		int x = rand() % this->getRow();
		int y = rand() % this->getCol();
		if (*this->array[x][y].boom) continue;
		i++;
		*this->array[x][y].boom = true;
		this->array[x][y].numberPath = "boom.png";
	}
}

std::string Game::checkBoomSide(int _x, int _y) {
	int count = 0;
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if (i == j && j == 0) continue;
			if (_x + i < 0 || _x + i == this->getRow()) continue;
			if (_y + j < 0 || _y + j == this->getCol()) continue;
			count += *this->array[_x + i][_y + j].boom;
		}
	}
	return convertIntToString(count);
}

void Game::setupMatrix() {
	for (int i = 0; i < this->getRow(); i++) {
		for (int j = 0; j < this->getCol(); j++) {
			if (*this->array[i][j].boom) continue;
			this->array[i][j].numberPath = this->checkBoomSide(i, j) + ".png";
			if (this->checkBoomSide(i, j) == "0") *this->array[i][j].empty = true;
		}
	}
}

Game::Game() {
	this->initWindow();
	this->resetGame();
}

Game::~Game() {
	for (int i = 0; i < this->getRow(); i++) delete[] this->array[i];
	delete[] this->array;
	delete this->endGame;
}

void Game::Loop() {
	while (this->running()) {
		this->pollEvents();
		this->clear();
		this->renderImg("img/hightScore.png", { IMG_WIDTH, 0 });
		this->renderImg("img/setting.png", { 0,0 });
		this->renderScore();
		this->renderRemainBoom();
		if (this->hightScore) {
			this->clickHightScore();
		}
		else if (this->setting) {
			this->clickSetting();
		}
		else {
			this->gameLogic();
			this->renderGame();
		}
		this->render();
	}
}