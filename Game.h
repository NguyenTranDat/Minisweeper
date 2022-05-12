#pragma once
#ifndef GAME_H_
#define GAME_H_

#include "Window.h"
#include "Object.h"
#include <queue>

class Game : public Window {
private:
	Image** array;
	bool* endGame = new bool;
	bool clickBoom = false;
	int* matrixRow = new int;
	int* matrixCol = new int;
	Level levelGame = BEGINNER;
	sf::Clock clock;
	float score = 0;
	int remainBoom = this->getBoom();

	// hightScore
	std::fstream input;
	std::fstream output;
	bool hightScore = false;
	void inputFile(int);
	void outputFile(int);
	void clickHightScore();
	void resetScore(int);

	// setting
	bool setting = false;
	void renderLevel();
	void clickSetting();
	bool clickBeginner(Point);
	bool clickInter(Point);
	bool clickExpert(Point);

	// init
	void initGame();
	void initWindow();

	void setupBoom();
	void setupMatrix();
	std::string checkBoomSide(int, int);

	//function game
	void resetGame();
	void buttonEmpty(int, int);

	Level getLevelGame();

	void setFlag(Point);
	void openButton(Point);
	void mouseButton(Point, bool);
	void pollEvents();

	// game logic
	void gameLogic();
	const bool checkEndGame();

	// render
	void renderGame();
	void renderBoom();
	void renderScore();
	void renderRemainBoom();

public:
	Game();
	~Game();

	const int getRow();
	const int getCol();
	const int getBoom();

	void Loop();
	const bool gameOver() const;
};

#endif // !GAME_H_