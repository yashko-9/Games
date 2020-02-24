#include <iostream>
#include <conio.h>
#include <windows.h>
#include "Snake.h"

using namespace std;

void cls()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}
void hidecursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}



int main()
{
	char x = 'c';
	int maxScore = 0;
	while (x == 'c') {
		Snake snake;
		snake.setX(3);
		snake.setY(5);
		while (snake.is_Alive()) {
			cout << endl;
			cout << "Max Score: " << maxScore << endl;
			snake.setDirection();
			snake.move();
			snake.display();
			cout << "score: " << snake.getScore() << endl;
			cls();
			hidecursor();
			Sleep(150);
		}
		if (snake.getScore() > maxScore) {
			maxScore = snake.getScore();
		}
		cout << "Press 'x' to exit or 'c' to continue" << endl;
		cin >> x;
		cls();
	}



	system("pause");
	return 0;
}
