#pragma once
#ifndef WINDOW_H_
#define WINDOW_H_

#include "Object.h"

class Window {
private:
	void initWindow();
protected:
	sf::RenderWindow* window;
	sf::VideoMode video;
	sf::Event event;
	sf::Texture img;

	sf::Font font;
	sf::Text text;

	void renderImg(std::string _path, Point _pos);

	virtual void pollEvents() = 0;
	virtual void renderGame() = 0;

	void clear();
	void render();
	void renderText(std::string, Point);
	void renderText(std::string, Point, int);
public:
	Window();
	~Window();
	const bool running() const;
};

#endif // !WINDOW_H_
