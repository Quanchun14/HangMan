#include<iostream>
#include<string>
#include<fstream>
#include<time.h>
#include<stdlib.h>
#include<windows.h>
using namespace std;

bool win = false;
//Define functions
string RandomWord(int);
int RandomNumber(int);
void Design(int);
void PrintWord(string, string);
int main(){
	int  live = 7;
	int choice;
	int num;
	string letter;
	string word;
	string guessedLetters = "";

	cout << "Chosse yout level: \n1)Easy\n2)Medium\n3)Hard\n-->";
	cin >> choice;

	//valid input
	while(choice < 1 || choice > 3){
		system("cls");
		cout << "You have entered a wrong number, renter your level..\n";
		cout << "Chosse yout level: \n1)Easy\n2)Medium\n3)Hard\n-->";
		cin >> choice;
	}

	word = RandomWord(choice);
	system("cls"); //Clear the screen
	bool help = false;
	while(live > 0){
		win = true;
		Design(live);
		PrintWord(word, guessedLetters);
		if(help){
			win = false;
			help = false;
		}
		if(win)
			break;
		cout << "\n\nIf you want to know the first letter write 'help' (Your lives will decrease!)" <<endl;
		cout << "\n\nLetter guesses: " << guessedLetters <<endl;
		cout << "\n\nEnter a letter: ";
		cin >> letter;

		int b = 0;

		while(letter[b] != '\0')
			b++;
		
		//catch those cheatty persons who write more than a letter
		if(b > 2){
			if(letter == "help"|| letter == "Help"){ // need a help to know the first letter
				help = true;
				live--;
				cout <<"-->\""<< word[0] << "\"<--" << endl;
				letter = word[0];
				system("pause");//stop the screen
			}
			else{
				system("cls");
				for(;;){ //infinity loop
				 cout <<"You are CHEATING!"<<endl;
				}
			}
		}
		guessedLetters += letter[0];
		if(word.find(letter) != -1 || help){
			system("cls");
			continue;
		}else{
			system("cls");
			live--;
		}
	}
	if(live == 0) //IF we have finished game
		cout << "\n\n\n\t\t\t >>>You Lose!<<<\n\n";
		cout << "The word was: " << word << endl;
	if(live > 0){
		cout << "\n\n\n\t\t\t >>>You Win!<<<\n\n";
		cout << "The word was: " << word << endl;
	}
	return 0;
}

// Get a random word from the wordlist depending on the level chosen
string RandomWord(int choice){
	int randomNum = RandomNumber(choice);
	int counter = 1;
	string line, word;
	ifstream file("wordlist.txt");
	while(getline(file, line)){
		if(randomNum == counter){
			word = line;
			break;
		}
		counter++;
	}
	return word;
}

//Get a random number to get the word, it depends on the chosen level
int RandomNumber(int choice){
	int random;
	srand(time(NULL));
	if(choice == 1)
		random = (rand() % (158 + 1 - 1)) + 1;
	if(choice == 2)
		random = (rand() % (456 + 1 - 159)) +159;
	if(choice == 3)
		random = (rand() % (669 + 1 - 457)) + 457;

	return random;
}

//Design the hangman depending on lives
void Design(int live){
switch(live){
	case 0:
	cout << "\t\t\t|---------|" << endl;
	cout << "\t\t\t|         0" << endl;
	cout << "\t\t\t|        /|\\" << endl;
	cout << "\t\t\t|         |" << endl;
	cout << "\t\t\t|        / \\" << endl;
	cout << "\t\t\t|" << endl;
	cout << "\t\t\t|_" << endl;
	break;
	case 1:
	cout << "\t\t\t|---------|" << endl;
	cout << "\t\t\t|         0" << endl;
	cout << "\t\t\t|        /|\\" << endl;
	cout << "\t\t\t|         |" << endl;
	cout << "\t\t\t|          \\" << endl;
	cout << "\t\t\t|" << endl;
	cout << "\t\t\t|_" << endl;
	break;
	case 2:
	cout << "\t\t\t|---------|" << endl;
	cout << "\t\t\t|         0" << endl;
	cout << "\t\t\t|        /|\\" << endl;
	cout << "\t\t\t|         |" << endl;
	cout << "\t\t\t|            " << endl;
	cout << "\t\t\t|" << endl;
	cout << "\t\t\t|_" << endl;
	break;
	case 3:
	cout << "\t\t\t|---------|" << endl;
	cout << "\t\t\t|         0" << endl;
	cout << "\t\t\t|        /|\\" << endl;
	cout << "\t\t\t|          " << endl;
	cout << "\t\t\t|            " << endl;
	cout << "\t\t\t|" << endl;
	cout << "\t\t\t|_" << endl;
	break;
	case 4:
	cout << "\t\t\t|---------|" << endl;
	cout << "\t\t\t|         0" << endl;
	cout << "\t\t\t|         |\\" << endl;
	cout << "\t\t\t|          " << endl;
	cout << "\t\t\t|            " << endl;
	cout << "\t\t\t|" << endl;
	cout << "\t\t\t|_" << endl;
	break;
	case 5:
	cout << "\t\t\t|---------|" << endl;
	cout << "\t\t\t|         0" << endl;
	cout << "\t\t\t|         |  " << endl;
	cout << "\t\t\t|          " << endl;
	cout << "\t\t\t|            " << endl;
	cout << "\t\t\t|" << endl;
	cout << "\t\t\t|_" << endl;
	break;
	case 6:
	cout << "\t\t\t|---------|" << endl;
	cout << "\t\t\t|         0" << endl;
	cout << "\t\t\t|            " << endl;
	cout << "\t\t\t|          " << endl;
	cout << "\t\t\t|            " << endl;
	cout << "\t\t\t|" << endl;
	cout << "\t\t\t|_" << endl;
	break;
	case 7:
	cout << "\t\t\t|---------|" << endl;
	cout << "\t\t\t|          " << endl;
	cout << "\t\t\t|            " << endl;
	cout << "\t\t\t|          " << endl;
	cout << "\t\t\t|            " << endl;
	cout << "\t\t\t|" << endl;
	cout << "\t\t\t|_" << endl;
	break;
	default:
		break;
}
}

//Print chosen right letter or '_'
void PrintWord(string word, string letter){
	for(int i = 0; i<word.size();i++){
		if(letter.find(word.at(i)) != -1)
			cout << word.at(i) << " ";
		else{
			cout << "_ ";
			win = false;
		}
	}	
}