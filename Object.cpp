#include "Object.h"

std::string convertIntToString(int _number) {
	if (_number == 0) return "0";
	if (_number == 1) return "1";
	if (_number == 2) return "2";
	if (_number == 3) return "3";
	if (_number == 4) return "4";
	if (_number == 5) return "5";
	if (_number == 6) return "6";
	if (_number == 7) return "7";
	if (_number == 8) return "8";
	if (_number == 9) return "9";
}

std::string convert(int number) {
	std::string s = "";
	while (number > 0) {
		s = convertIntToString(number % 10) + s;
		number /= 10;
	}
	return s;
}

Point::Point() {
	this->x = 0;
	this->y = 0;
}

Point::Point(int _x, int _y) {
	this->x = _x;
	this->y = _y;
}

Point::~Point() {
}

const bool Image::isOpen() const {
	return *this->open;
}

Image::Image() {
	*this->open = false;
	*this->flag = false;
	*this->empty = false;
	*this->boom = false;
	this->path = "img/aa.png";
	this->numberPath = "aa.png";
}

Image::Image(int _x, int _y) {
	this->pos.x = _x;
	this->pos.y = _y;
}

std::string Image::getPath() const{
	return this->path;
}

Image::~Image() {
	delete this->flag;
	delete this->open;
	delete this->boom;
	delete this->empty;
}

