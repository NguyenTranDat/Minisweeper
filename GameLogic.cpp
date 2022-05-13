#include "Game.h"

const bool Game::checkEndGame() {
	int count = 0;
	for (int i = 0; i < this->getRow(); i++) {
		for (int j = 0; j < this->getCol(); j++) {
			if (!this->array[i][j].isOpen()) continue;
			if (*this->array[i][j].boom) return false;
			count++;
		}
	}
	if (count == this->getRow() * this->getCol() - this->getBoom()) return *this->endGame = true;
	return false;
}

void Game::gameLogic() {
	if (!this->gameOver()) {
		this->renderImg("img/face.png", { (int)(this->video.width / 2 - IMG_WIDTH / 2), 0 });
		this->score += clock.getElapsedTime().asSeconds();
		clock.restart();
	}
	if (this->clickBoom) {
		this->renderImg("img/face_lost.png", { (int)(this->video.width / 2 - IMG_WIDTH / 2), 0 });
		if (this->hightScore || this->setting) return;
		this->renderBoom();
		*this->endGame = true;
	}
	if (this->checkEndGame()) {
		this->renderImg("img/face_win.png", { (int)(this->video.width / 2 - IMG_WIDTH / 2), 0 });
		if (this->score != 0) this->resetScore(trunc(this->score));
		this->score = 0;
		if (this->hightScore) return;
	}
}

const bool Game::gameOver() const {
	return *(this->endGame);
}