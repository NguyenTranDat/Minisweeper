#include "Window.h"

void Window::initWindow() {
	this->video.width = IMG_WIDTH * 9;
	this->video.height = IMG_HEIGHT * 9 + IMG_HEIGHT;
	this->window = new sf::RenderWindow(
		this->video,
		"domin",
		sf::Style::Close | sf::Style::Titlebar
	);

	this->font.loadFromFile("fonts/Montserrat-Bold.ttf");
	this->text.setFont(this->font);
	this->text.setFillColor(sf::Color::Red);
}

void Window::renderImg(std::string _path, Point _pos) {
	this->img.loadFromFile(_path);
	sf::Sprite sprite;
	sprite.setTexture(this->img);
	sprite.setPosition(_pos.x * 1.0f, _pos.y * 1.0f);
	this->window->draw(sprite);
}

void Window::clear() {
	this->window->clear(sf::Color::Black);
}

void Window::render() {
	this->window->display();
}

Window::Window() {
	this->initWindow();
}

Window::~Window() {
	delete this->window;
}

const bool Window::running() const {
	return this->window->isOpen();
}