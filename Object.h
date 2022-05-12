#pragma once
#ifndef OBJECT_H_
#define OBJECT_H_

#include <iostream>
#include <string>
#include <time.h>
#include <stdio.h>
#include <fstream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#define MATRIX_ROW 9
#define MATRIX_COL 9
#define BOOMD 10
#define IMG_WIDTH 34
#define IMG_HEIGHT 34

using namespace std;

std::string convertIntToString(int);
std::string convert(int);

enum Level {
	BEGINNER = 0,
	INTERMEDIATE = 1,
	EXPERT = 2
};

struct Point {
	int x, y;
	Point();
	Point(int, int);
	~Point();
};

struct Image {
	Point pos;
	bool* open = new bool;
	bool* flag = new bool;
	bool* empty = new bool;
	bool* boom = new bool;
	std::string path;
	std::string numberPath;

	const bool isOpen() const;
	std::string getPath() const;

	Image();
	Image(int, int);
	~Image();
};

#endif // !OBJECT_H_
