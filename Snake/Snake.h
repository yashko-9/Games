#pragma once
#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;



enum Direction {
	Stop,
	Up,
	Down,
	Left,
	Right
};

class Snake
{
private:
	int m = 15;
	int n = 10;

	int x = n / 2;
	int y = m / 2;

	Direction d = Stop;

	bool isAlive = true;

	int* tailX = new int[100];
	int* tailY = new int[100];
	int tLength = 0;

	int fruitX = 5;
	int fruitY = 5;

	int score = 0;

public:
	Snake();
	bool is_Alive() const;

	void setX(int par);
	void setY(int par);

	int getX() const;
	int getY() const;
	int getScore() const;

	void setDirection();
	void display();
	void move();


};
