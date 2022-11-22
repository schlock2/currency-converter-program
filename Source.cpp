//Program written 22/11/22
#include <iostream>
using namespace std;

class CurrencyConverter {
private:
	//values against the dollar
	double dollarValue=1;
	double poundValue=1.18;
	double euroValue=1.02;
	double japyenValue=0.0070;
public:
	double convertToX(double choice[2][1], double currAmount) {
		translateChoice(choice);
		double exchRate = choice[0][0] / choice[1][0];
		double conversion = currAmount * exchRate;
		return conversion;
	}

	void translateChoice(double choice[2][1]) {
		for (int i = 0; i < 2; i++) {
			if (choice[i][0] == 0) {
				choice[i][0] = dollarValue;
			}
			else if (choice[i][0] == 1) {
				choice[i][0] = poundValue;
			}
			else if (choice[i][0] == 2) {
				choice[i][0] = euroValue;
			}
			else if (choice[i][0] == 3) {
				choice[i][0] = japyenValue;
			}
		}
	}
};

class MenuScreen {
private:
	//Flags for user choice
	int choiceFrom = 0;
	int choiceTo = 0;
	//Converter objects
	int moneyAmount = 0;
	CurrencyConverter moneyprinter;
public:
	void displayStartMenu() {
		cout << "WELCOME TO THE CURRENCY CONVERTER" << endl;
		cout << "===================================================================================" << endl;
		cout << "Enter the number of the currency you wish to convert FROM." << endl;
		cout << "1.DOLLAR, 2.POUND, 3.EURO, 4.YEN 5.EXIT" << endl;
		this->startMenuControl();
	}

	void displaySecondOption() {
		cout << "Now enter which currency you wish to convert TO." << endl;
		cout << "1.DOLLAR, 2.POUND, 3.EURO, 4.YEN 5.EXIT" << endl;
		this->secondOptionControl();
	}

	void displayThirdOption() {
		cout << "Finally, enter the amount of money you wish to convert." << endl;
		this->thirdOptionControl();
	}

	void resultsDisplay() {
		double passing[2][1];
		passing[0][0] = choiceFrom;
		passing[1][0] = choiceTo;
		cout << "Your money is worth: " << moneyprinter.convertToX(passing, moneyAmount) <<endl;
		cout << "Do you want to convert another amount?" << endl;
		cout << "1.YES 2.NO" << endl;
		
		this->resultsControl();
	}
	
	void startMenuControl() {
		int userChoice = this->receiveIntInput();
		while (userChoice > 5 || userChoice < 1) {
			cout << "You entered a number with no option provided. Please re-enter a valid choice." << endl;
			userChoice = this->receiveIntInput();
		}
		switch (userChoice) {
		case 1:
			choiceFrom = 0;
			break;
		case 2:
			choiceFrom = 1;
			break;
		case 3:
			choiceFrom = 2;
			break;
		case 4:
			choiceFrom = 3;
			break;
		case 5:
			cout << "Goodbye." << endl;
			exit;
			break;
		}
		this->displaySecondOption();
	}

	void secondOptionControl() {
		int userChoice = this->receiveIntInput();
		while (userChoice > 5 || userChoice < 1) {
			cout << "You entered a number with no option provided. Please re-enter a valid choice." << endl;
			userChoice = this->receiveIntInput();
		}
		switch (userChoice) {
		case 1:
			choiceTo = 0;
			break;
		case 2:
			choiceTo = 1;
			break;
		case 3:
			choiceTo = 2;
			break;
		case 4:
			choiceTo = 3;
			break;
		case 5:
			cout << "Goodbye." << endl;
			exit;
			break;
		}
		this->displayThirdOption();
	}

	void thirdOptionControl() {
		int userChoice = this->receiveIntInput();
		while (userChoice < 0) {
			cout << "The amount you entered must be greater than zero." << endl;
			userChoice = this->receiveIntInput();
		}
		moneyAmount = userChoice;

		this->resultsDisplay();
	}

	void resultsControl() {
		int userChoice = this->receiveIntInput();
		while (userChoice > 2 || userChoice < 1) {
			cout << "Value entered must be between 1 and 2";
			int userChoice = this->receiveIntInput();
		}
		switch (userChoice) {
		case 1:
			system("cls");
			this->displayStartMenu();
			break;
		case 2:
			cout << "Goodbye." << endl;
			exit;
			break;
		}
	}

	int receiveIntInput() {
		int input;
		while (!(cin >> input)) {
			cout << "You did not enter a number! Try again." << endl;
			cin.clear();
			cin.ignore(123, '\n');
		}
		return input;
	} 
};

int main() {
	MenuScreen menu;
	menu.displayStartMenu();
	return 0;
}