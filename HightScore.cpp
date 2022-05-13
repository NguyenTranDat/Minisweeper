#include "Game.h"

void Game::inputFile(int _level) {
	if (_level == BEGINNER) {
		this->input.open("hightscore/begginer.inp", std::ios::in);
	}
	if(_level == INTERMEDIATE) {
		this->input.open("hightscore/intermediate.inp", std::ios::in);
	}
	if (_level == EXPERT) {
		this->input.open("hightscore/expert.inp", std::ios::in);
	}
}

void Game::outputFile(int _level) {
	if (_level == BEGINNER) {
		this->output.open("hightscore/begginer.inp", std::ios::out | std::ios::trunc);
	}
	if (_level == INTERMEDIATE) {
		this->output.open("hightscore/intermediate.inp", std::ios::out | std::ios::trunc);
	}
	if (_level == EXPERT) {
		this->output.open("hightscore/expert.inp", std::ios::out | std::ios::trunc);
	}
}

void Game::clickHightScore() {
	this->gameLogic();

	this->inputFile(this->levelGame);
	
	std::string s;
	for (int i = 1; i < 6; i++) {
		this->input >> s;
		this->renderText(convertIntToString(i) + ". " + s, {10, IMG_HEIGHT * i});
	}

	this->input.close();
}

void Game::resetScore(int _x) {
	this->inputFile(this->levelGame);
	int a[5];
	for (int i = 0; i < 5; i++) {
		this->input >> a[i];
	}
	for (int i = 0; i < 5; i++) {
		if (a[i] == 0 || a[i] > _x) {
			for (int j = 4; j >= i+1; j--) a[j] = a[j - 1];
			a[i] = _x;
			break;
		}
	}
	
	this->outputFile(this->levelGame);
	for (int i = 0; i < 5; i++) {
		this->output << a[i] << "\n";
		//std::cout << a[i] << endl;
	}

	this->output.close();
	this->input.close();
}