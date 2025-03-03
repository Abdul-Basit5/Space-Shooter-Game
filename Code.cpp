//Final Project Game Endless Runner
#include <iostream>
#include<cstdlib>
#include<time.h>
#include<conio.h>
#include<fstream>
#include<windows.h>


// function to set console color
void setConsoleColor(int color)
 {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(consoleHandle, color);
}


using namespace std;

int coin = 0, health = 3, meters = 0;

char arr[40][40];

void arrPopulation(int size, char arr[][40])
{
	// array population
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i == size - 1)
			{
			
				arr[i][j] = '_';
			
				
			}
			else if (j == 0 || j == size - 1)
			{
				arr[i][j] = '|';
			}
			else
			{
				arr[i][j] = ' ';
			}
		}
	}
}

void showBoard(int size, char arr[][40], int score)
{
    system("cls"); // clear the console screen
    setConsoleColor(10);
    cout << " HEALTH: ";
    setConsoleColor(14);
    cout << health;
    setConsoleColor(10);
    cout << " Distance: ";
    setConsoleColor(14);
    cout << meters;
    setConsoleColor(10);
    cout << " Coin: ";
    setConsoleColor(14);
    cout << coin << endl;
    setConsoleColor(15);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr[i][j] == '|'||arr[i][j] == 'H'||arr[i][j] == '_')
			 {
                setConsoleColor(4);
            }
            else if (arr[i][j] == '$' || arr[i][j] == 'O')
		 {
                setConsoleColor(14);
            }
            else if (arr[i][j] == 'o') 
		{
                setConsoleColor(14);
            }
            else 
		{
                setConsoleColor(15);
            }
            cout << arr[i][j];
        }
        cout << endl;
    }
     
}



void showRunner(int size, char arr[][40])
{
	// (size - 4) is liye kia hy ta k 3rd last row pr Runner ka mun ho:-
	arr[size - 4][size / 2 - 1] = 'O';
	// ( a = -1) is liye q k Runner k darmiyan wala hissa (half - 1) sy shuru karna tha or loop 3 dafa chalana hy:-
	for (int i = size / 2; i > size / 2 - 3; i--)
	{
		arr[size - 3][i] = 'O';
	}
	// ( k = -2) is liye q k Runner k darmiyan wala hissa (half - 2) sy shuru karna tha or loop 4 dafa chalana hy:-
	//for (int i = size / 2; i > size / 2 - 3; i--)
	arr[size - 2][size / 2 - 2] = '$';
	arr[size - 2][size / 2] = '$';

}


void moveUp(int size, char arr[][40])
{
	char temp;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (arr[i][j] == '$' || arr[i][j] == 'O' && i > 1)
			{
				// Check for collision with top wall
				if (arr[i - 1][j] == '_')
					return; // Stop movement if collision occurs
				temp = arr[i][j];
				arr[i][j] = arr[i - 1][j];
				arr[i - 1][j] = temp;
			}
		}
	}
}


void jump(int size, char arr[][40])
{
	char temp;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (arr[i][j] == '$' || arr[i][j] == 'O' && i > 1)
			{
				
				// Check for collision with top wall
				if (arr[i - 3][j] == '_')
					return; // Stop movement if collision occurs
				temp = arr[i][j];
				arr[i][j] = arr[i - 3][j];
				arr[i - 3][j] = temp;
			}
		}
	}
}


void moveDown(int size, char arr[][40])
{
	char temp;
	for (int i = size - 1; i >= 0; i--)
	{
		for (int j = size - 1; j >= 0; j--)
		{
			if (arr[i][j] == '$' || arr[i][j] == 'O' && i < size)
			{
				// Check for collision with bottom wall
				if (arr[i + 1][j] == '_')
					return; // Stop movement if collision occurs
				temp = arr[i][j];
				arr[i][j] = arr[i + 1][j];
				arr[i + 1][j] = temp;
			}

		}
	}
}


void moveRight(int size, char arr[][40])
{
	char temp;
	for (int i = size - 1; i >= 0; i--)
	{
		for (int j = size - 1; j >= 0; j--)
		{
			if (arr[i][j] == '$' || arr[i][j] == 'O' && i > 0 && j < 38)
			{if (arr[i][j + 1] == '|')
					return; // Stop movement if collision occurs
				temp = arr[i][j];
				arr[i][j] = arr[i][j + 1];
				arr[i][j + 1] = temp;
			}

		}
	}
}


void moveLeft(int size, char arr[][40])
{
	char temp;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (arr[i][j] == '$' || arr[i][j] == 'O' && j > 1)
			{
				// Check for collision with left wall
				if (arr[i][j - 1] == '|')
					return; // Stop movement if collision occurs
				temp = arr[i][j];
				arr[i][j] = arr[i][j - 1];
				arr[i][j - 1] = temp;
			}

		}
	}
}


void MoveRunner(int size, char arr[][40])
{
	char key = ' ';    ////checks the console for a recent keystroke
	if (_kbhit())
	{
		key = _getch();
		if (key == 'w')
		{
			moveUp(size, arr);
		}
		else if (key == 's')
		{
			moveDown(size, arr);
		}
		else if (key == 'd')
		{
			moveRight(size, arr);
		}
		else if (key == 'a')
		{
			moveLeft(size, arr);
		}
		else if (key == ' ')
		{
			jump(size, arr);
		}
		else if (key == 'p')
		{
			system("pause");
		}
	}
}


void GameOver(int size, int health, char arr[][40], int coin)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (arr[i][j] == 'H')
			{
				if (arr[i + 1][j] == '$')
				{
					health = health - 1;
				}
			}
			if (health <= 0)
			{
				if (arr[i + 1][j] == '$' && health == 0)
				{
					system("CLS");
					for (int c = 0; c < 7; c++)
					{
						cout << "\n";
					}
                      setConsoleColor(9);
					cout << "\t\t\t\tDistance = " << meters << endl;
					
					
					for (int a = 0; a < 3; a++)
					{
						cout << "\n";
					}
					setConsoleColor(14);
					cout << "\t\t\t\tCoins = " << coin << endl;
					
					for (int a = 0; a < 3; a++)
					{
						cout << "\n";
					}
					setConsoleColor(4);
					cout << "\t\t\t\t---------" << endl;
					cout << "\t\t\t\tGAME OVER" << endl;
					cout << "\t\t\t\t---------";
					
					break;
				}
			}
		}
	}
}


void Hurdle(int size, char arr[][40])
{
	static int speed = 0;
	speed++;
	if (speed == 30)
	{
		speed = 0;
		// select a random j between 0 and size
		// replace arr[1][j] = 'H';
		int j = (rand() % size) + 1;
		if (j > 3 && j < 37)
		{
		
			arr[1][j] = 'H';
			arr[1][j + 1] = 'H';
			arr[1][j + 2] = 'H';
			
		}

	}

}


void Hurdle02(int size, char arr[][40])
{
	static int speed = 0;
	speed++;
	if (speed == 10)
	{
		speed = 0;
		// select a random j between 0 and size
		// replace arr[1][j] = 'H';
		int j = (rand() % size) + 1;
		if (j > 3 && j < 37)
		{
			arr[1][j] = 'H';
			arr[1][j + 1] = 'H';
			arr[1][j + 2] = 'H';
		}

	}

}


void HurdleDown(int size, char arr[][40])
{
	static int speed = 0;
	speed++;	// hurdle k niche jane ki speed 

	if (speed == 6)
	{
		speed = 0;

		for (int i = 39; i >= 0; i--)
		{
			for (int j = 39; j >= 0; j--)
			{
				if (arr[i][j] == 'H' && i == 38)
				{
					break;
					arr[i][j] = ' ';
				}

				if (arr[i][j] == 'H')
				{
					arr[i][j] = ' ';
					arr[i + 1][j] = 'H';
				}
			//	if (arr[i][j] == 'H' && arr[i + 1][j] == 'O' || arr[i + 1][j] == '$')
			//	{
					// plane health
			//	}
			}
		}
	}
}


void HurdleDown02(int size, char arr[][40])
{
	static int speed = 0;
	speed++;	// hurdle k niche jane ki speed 

	if (speed == 3)
	{
		speed = 0;

		for (int i = 39; i >= 0; i--)
		{
			for (int j = 39; j >= 0; j--)
			{
				if (arr[i][j] == 'H' && i == 38)
				{
					break;
					arr[i][j] = ' ';
				}

				if (arr[i][j] == 'H')
				{
					arr[i][j] = ' ';
					arr[i + 1][j] = 'H';
				}
			//	if (arr[i][j] == 'H' && arr[i + 1][j] == 'O' || arr[i + 1][j] == '$')
			//	{
					// plane health
			//	}
			}
		}
	}
}


void RunnerHealth(int size, char arr[][40])
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (arr[i][j] == 'H' && arr[i + 1][j] == '$')
			{
				arr[i][j] = ' ';
				health--;
			}
			else if (arr[i][j] == 'H' && arr[i + 1][j] == 'O')
			{
				arr[i][j] = ' ';
				health--;
			}
			else if (health == 0)
			{
				GameOver(size, health, arr, coin);
			}

		}
	}
}


void coins(int size, char arr[][40])
{
	static int speed = 0;
	speed++;
	if (speed == 10)
	{
		speed = 0;
		// select a random j between 0 and size
		// replace arr[1][j] = '$';
		int j = (rand() % size) + 1;
		if (j > 0 && j < 39)
		{
			arr[1][j] = 'o';
		}

	}

}


void coins02(int size, char arr[][40])
{
	static int speed = 0;
	speed++;
	if (speed == 5)
	{
		speed = 0;
		// select a random j between 0 and size
		// replace arr[1][j] = '$';
		int j = (rand() % size) + 1;
		if (j > 0 && j < 39)
		{
			arr[1][j] = 'o';
		}

	}

}


void coinsDown(int size, char arr[][40])
{
	static int speed = 0;
	speed++;    // coins k niche jane ki speed 

	if (speed == 4)
	{
		speed = 0;
		int collected = 0; // initialize the counter for collected coins

		for (int i = 39; i >= 0; i--)
		{
			for (int j = 39; j >= 0; j--)
			{
				if (arr[i][j] == 'o' && arr[i + 1][j] == 'H')
				{
					arr[i][j] = ' ';
					break;
				}
				if (arr[i][j] == 'o' && i == 38)
				{
					break;
				}

				if (arr[i][j] == 'o' && arr[i + 1][j] != 'O')
				{
					arr[i][j] = ' ';
					arr[i + 1][j] = 'o';
				}
				if (arr[i][j] == 'o' && arr[i + 1][j] == 'O')
				{
					arr[i][j] = ' ';
					collected++; // increment the counter for collected coins
				}
			}
		}

		coin += collected; // update the global coin count

		// save the coin count to file
		ofstream outFile("coin.txt");
		if (outFile.is_open())
		{
			outFile << " YOUR Final Game COINS is Abdul Basit!! :   " << coin;
			outFile.close();
		}
		else
		{
			cout << "Error: Unable to open file coin.txt for writing.\n";
		}
	}
}





void coinsDown02(int size, char arr[][40])
{
	static int speed = 0;
	speed++;	// coins k niche jane ki speed 

	if (speed == 2)
	{
		speed = 0;
		int collect = 0;

		for (int i = 39; i >= 0; i--)
		{
			for (int j = 39; j >= 0; j--)
			{
				if (arr[i][j] == 'o' && arr[i + 1][j] == 'H')
				{
					arr[i][j] = ' ';
					break;
				}
				if (arr[i][j] == 'o' && i == 38)
				{
					break;
				}

				if (arr[i][j] == 'o' && arr[i + 1][j] != 'O')
				{
					arr[i][j] = ' ';
					arr[i + 1][j] = 'o';
				}
				if (arr[i][j] == 'o' && arr[i + 1][j] == 'O')
				{
					arr[i][j] = ' ';
					collect++;
				}

			}
		}
		coin += collect; // update the global coin count


		// save the coin count to file
		ofstream outFile("coin.txt");
		if (outFile.is_open())
		{
			outFile << " YOUR Final Game COINS is Abdul Basit!! :   " << coin;
			outFile.close();
		}
		else
		{
			cout << "Error: Unable to open file coin.txt for writing.\n";
		}
	}

}




void distance()
{
	meters = coin / 2;
}

int main()
{
	srand(time(0));
	int size = 40;
	int coin;
	arrPopulation(size, arr);
	showRunner(size, arr);
	showBoard(size, arr, coin);
     Sleep(100);



	while (1)
	{

		//moveUp(size, arr);

		MoveRunner(size, arr);

		coins(size, arr);

		coinsDown(size, arr);

		distance();

		Hurdle(size, arr);

		HurdleDown(size, arr);

		RunnerHealth(size, arr);

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{

				if (arr[i][j] == 'H')
				{
					if (arr[i + 1][j] == '$')
					{
						GameOver(size, health, arr, coin);
					}
				}
			}
		}
		system("CLS");

		showBoard(size, arr, coin);


		if (meters >= 5)
		{
			while (1)
			{
				//moveUp(size, arr);

				MoveRunner(size, arr);

				coins02(size, arr);

				coinsDown02(size, arr);

				distance();

				Hurdle02(size, arr);

				HurdleDown02(size, arr);

				RunnerHealth(size, arr);

				for (int i = 0; i < size; i++)
				{
					for (int j = 0; j < size; j++)
					{

						if (arr[i][j] == 'H')
						{
							if (arr[i + 1][j] == '$')
							{
								GameOver(size, health, arr, coin);
							}
						}
					}
				}
				system("CLS");

				showBoard(size, arr, coin);
			}

		}

	}
	system("pause");
	return 0;
}

