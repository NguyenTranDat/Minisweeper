#include "Game.h"

void Game::renderGame() {
	for (int i = 0; i < this->getRow(); i++) {
		for (int j = 0; j < this->getCol(); j++) {
			this->renderImg(this->array[i][j].getPath(), this->array[i][j].pos);
		}
	}
}

void Game::renderBoom() {
	for (int i = 0; i < this->getRow(); i++) {
		for (int j = 0; j < this->getCol(); j++) {
			if (!this->array[i][j].flag) continue;
			this->array[i][j].path = "img/" + this->array[i][j].numberPath;
			this->renderImg(this->array[i][j].getPath(), this->array[i][j].pos);
		}
	}
}

void Game::renderScore() {
	this->renderText("Time: " + convert(this->score) + "s", {int(this->video.width / 2 + IMG_WIDTH / 2 + 10) , 5}, 20 + 2.5 * this->getLevelGame());
}

void Game::renderRemainBoom() {
	this->renderText("Bom:" + convert(this->remainBoom), {int(IMG_WIDTH * 2 + 5) , 5}, 15 + 5 * this->getLevelGame());
}

void Window::renderText(std::string _s, Point _pos) {
	this->text.setString(_s);
	this->text.setCharacterSize(25);
	this->text.setStyle(sf::Text::Bold);
	this->text.setPosition(_pos.x, _pos.y);
	this->window->draw(this->text);
}

void Window::renderText(std::string _s, Point _pos, int _size) {
	this->text.setString(_s);
	this->text.setCharacterSize(_size);
	this->text.setStyle(sf::Text::Bold);
	this->text.setPosition(_pos.x, _pos.y);
	this->window->draw(this->text);
}