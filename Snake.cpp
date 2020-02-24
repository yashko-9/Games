#include "Snake.h"



Snake::Snake()
{
}

bool Snake::is_Alive() const
{
	return isAlive;
}

void Snake::setX(int par)
{
	x = par;
}

void Snake::setY(int par)
{
	y = par;
}

int Snake::getX() const
{
	return x;
}

int Snake::getY() const
{
	return y;
}

int Snake::getScore() const
{
	return score;
}



void Snake::setDirection()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			if (d != Right)
				d = Left;
			break;
		case 'd':
			if (d != Left)
				d = Right;
			break;
		case 'w':
			if (d != Down)
				d = Up;
			break;
		case 's':
			if (d != Up)
				d = Down;
			break;
		case 'x':
			isAlive = false;
		}
	}

}

void Snake::display()
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
				cout << "#";
			}
			else if (i == x && j == y) {
				cout << "O";
			}
			else if (i == fruitX && j == fruitY) {
				cout << "$";
			}
			else {
				bool printed = false;
				for (int k = 0; k < tLength; k++) {
					if (tailX[k] == i && tailY[k] == j) {
						cout << "o";
						printed = true;
					}
				}
				if (!printed) {
					cout << " ";
				}
			}

		}
		cout << endl;
	}
}

void Snake::move()
{
	for (int i = tLength - 1; i > 0; i--) {
		tailX[i] = tailX[i - 1];
		tailY[i] = tailY[i - 1];
	}
	tailX[0] = x;
	tailY[0] = y;

	if (d == Up) {
		x--;
	}
	if (d == Down) {
		x++;
	}
	if (d == Left) {
		y--;
	}
	if (d == Right) {
		y++;
	}

	if (x == n - 1) {
		x = 1;
	}
	else if (x == 0) {
		x = n - 2;
	}
	if (y == m - 1) {
		y = 1;
	}
	else if (y == 0) {
		y = m - 2;
	}

	for (int i = 0; i < tLength; i++) {
		if (tailX[i] == x && tailY[i] == y) {
			isAlive = false;
		}
	}

	if (x == fruitX && y == fruitY) {
		bool freePlace = false;
		while (!freePlace) {
			fruitX = rand() % (n - 2) + 1;
			fruitY = rand() % (m - 2) + 1;
			freePlace = true;
			for (int i = 0; i < tLength; i++) {
				if (tailX[i] == fruitX && tailY[i] == fruitY) {
					freePlace = false;
				}
			}
		}
		score++;
		tLength++;
	}
}
