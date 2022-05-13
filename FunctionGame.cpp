#include "Game.h"

void Game::resetGame() {
	this->initWindow();
	this->initGame();
	this->setupBoom();
	this->setupMatrix();
}

void Game::buttonEmpty(int _x, int _y) {
	std::queue<std::pair<int, int> > myQueue;
	while (!myQueue.empty()) myQueue.pop();

	myQueue.push({ _x, _y });
	while (!myQueue.empty()) {
		int x = myQueue.front().first;
		int y = myQueue.front().second;
		myQueue.pop();

		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				if (x + i < 0 || x + i == this->getRow()) continue;
				if (y + j < 0 || y + j == this->getCol()) continue;
				if (!(*this->array[x + i][y + j].boom) && !(*this->array[x + i][y + j].open)) {
					*this->array[x + i][y + j].open = true;
					this->array[x + i][y + j].path = "img/" + this->array[x + i][y + j].numberPath;
					if(this->array[x + i][y + j].numberPath[0] == '0') myQueue.push({ x + i, y + j });
				}
			}
		}
	}
}

void Game::setFlag(Point _pos) {
	if (this->remainBoom == 0) return;
	*this->array[_pos.x][_pos.y].flag = !(*this->array[_pos.x][_pos.y].flag);
	if (*this->array[_pos.x][_pos.y].flag) {
		this->array[_pos.x][_pos.y].path = "img/" + std::string("flag.png");
		this->remainBoom--;
	}
	else {
		this->array[_pos.x][_pos.y].path = "img/" + std::string("aa.png");
		this->remainBoom++;
	}
}

void Game::openButton(Point _pos) {
	if (*this->array[_pos.x][_pos.y].flag) return;
	this->array[_pos.x][_pos.y].path = "img/" + this->array[_pos.x][_pos.y].numberPath;
	*this->array[_pos.x][_pos.y].open = true;
	if (*this->array[_pos.x][_pos.y].empty) this->buttonEmpty(_pos.x, _pos.y);
	*this->endGame |= *this->array[_pos.x][_pos.y].boom;
	this->clickBoom |= *this->array[_pos.x][_pos.y].boom;
}

void Game::mouseButton(Point _pos,const bool mouseButtonLeft) {
	static int count;
	count = (count + 1) % 2;
	if (!count) return;

	int x = _pos.x;
	int y = _pos.y;

	if (x > (int)this->video.width || y > (int)this->video.height || x < 0 || y < 0) return;

	if (this->video.width / 2 - IMG_WIDTH / 2 < x && x < this->video.width / 2 + IMG_WIDTH / 2) {
		if (y <= IMG_HEIGHT && mouseButtonLeft == true) this->resetGame();
	}

	if (IMG_WIDTH <= x && x <= IMG_WIDTH * 2 && 0 <= y && y < IMG_HEIGHT) {
		this->hightScore = !this->hightScore;
		this->setting = false;
	}

	if (0 <= x && x <= IMG_WIDTH && 0 <= y && y <= IMG_HEIGHT) {
		this->setting = !this->setting;
		this->hightScore = false;
	}

	if (this->setting) {
		if (this->clickBeginner({x, y})) {
			if(this->levelGame == BEGINNER) return;
			this->levelGame = BEGINNER;
			this->resetGame();
		}

		if (this->clickInter({ x, y })) {
			if (this->levelGame == INTERMEDIATE) return;
			this->levelGame = INTERMEDIATE;
			this->resetGame();
		}

		if (this->clickExpert({ x, y })) {
			if (this->levelGame == EXPERT) return;
			this->levelGame = EXPERT;
			this->resetGame();
		}
	}

	if (this->hightScore || this->setting || this->gameOver() || x < 0 || y - IMG_HEIGHT < 0) return;

	x = x / IMG_WIDTH;
	y = (y - IMG_HEIGHT) / IMG_HEIGHT;

	if (this->array[x][y].isOpen()) return;
	if (mouseButtonLeft) this->openButton({ x, y });
	if (!mouseButtonLeft) this->setFlag({ x, y });
}

void Game::pollEvents() {
	while (this->window->pollEvent(this->event)) {
		if (this->event.type == sf::Event::Closed) {
			this->window->close();
		}
		if (this->event.mouseButton.button == sf::Mouse::Left) {
			//std::cout << this->event.mouseButton.x << " " << this->event.mouseButton.y << endl;
			this->mouseButton({this->event.mouseButton.x, this->event.mouseButton.y}, true);
		}
		if (this->event.mouseButton.button == sf::Mouse::Right) {
			//std::cout << this->event.mouseButton.x << " " << this->event.mouseButton.y << endl;
			this->mouseButton({ this->event.mouseButton.x, this->event.mouseButton.y }, false);
		}
	}
}

Level Game::getLevelGame() {
	return this->levelGame;
}

const int Game::getRow() {
	if (this->getLevelGame() == BEGINNER) return 9;
	if (this->getLevelGame() == INTERMEDIATE) return 16;
	if (this->getLevelGame() == EXPERT) return 40;
}

const int Game::getCol() {
	if (this->getLevelGame() == BEGINNER) return 9;
	if (this->getLevelGame() == INTERMEDIATE) return 16;
	if (this->getLevelGame() == EXPERT) return 16;
}

const int Game::getBoom() {
	if (this->getLevelGame() == BEGINNER) return 10;
	if (this->getLevelGame() == INTERMEDIATE) return 40;
	if (this->getLevelGame() == EXPERT) return 99;
}