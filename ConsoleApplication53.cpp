#include<iostream>
#include<ctime>
#include<cstdlib>
 
unsigned rollDice();
int main() {
	enum class Status{Continue, Won, Lost};
	srand(static_cast<unsigned int>(time(0)));
	unsigned int myPoint{ 0 };
	Status gameStatus;
	unsigned int sumOfDice{ rollDice() };
	switch (sumOfDice) {
	case 11:
	case 7:
		gameStatus = Status::Won;
		break;
	case 2:
	case 3:
	case 12:
		gameStatus = Status::Lost;
		break;
	default: gameStatus = Status::Continue;
		myPoint = sumOfDice;
		std::cout << "Point is " << myPoint << std::endl;
		break;
	}
		while (Status::Continue == gameStatus) {
			sumOfDice = rollDice();
		
		if (sumOfDice == myPoint) {
			gameStatus = Status::Won;
		}
		else {
			if (sumOfDice == 7){
				gameStatus = Status::Lost;
		  }
		}
	  }
	if (Status::Won == gameStatus) {
		std::cout << "Player wins" << std::endl;
	}
	else{ 
		std::cout << "Player loses" << std::endl;
	}
    system("pause");
	return 0;
}

unsigned rollDice() {
	int die1{ 1 + rand() % 6 };
	int die2{ 1 + rand() % 6 };
	int sum{ die1 + die2 };
	std::cout << "Player rolled " << die1 << " + " << die2 << " = " << sum << std::endl;
	return sum;
}