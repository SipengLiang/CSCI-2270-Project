#include <iostream>

#include "hangman.hpp"

using namespace std;

void initializeGame(); // builds the library and gets the random word (Calls Guess)

void guess(int wordlength, string randWord); //main game mechanic (Calls findMatch, hangman2D)

void hangman2D(int numIncorrectGuesses); //2D hangman print (called by guess)


int main(){
  initializeGame();
  return 0;
}

void initializeGame(){
  Tree game;
  int input;
  int wordLength;
  bool newGame = true;

  cout << "Hello, welcome to hangman super deluxe edition(tm)" << endl;

  game.buildLibrary();

  while(newGame == true){

    cout << "Please enter a length for the word: ";
    cin >> wordLength;

    string randWord = game.getRandomWord(wordLength);

    cout << "A random word has been chosen, now try to guess it!" << endl;
    cout << randWord << endl;

    guess(wordLength, randWord);


    cout << "1. NEW GAME" << endl;
    cout << "2. CHOOSE NEW DICTIONARY AND PLAY NEW GAME" << endl;
    cout << "3. EXIT" << endl;
    cin >> input;

    if(input == 2){
      game.buildLibrary();
      cout << endl;
      cout << "New Dictionary Added!" << endl;
    }
    else if (input == 3){
      newGame = false;
      cout << "Goodbye!" << endl;
    }
  }
}


void guess(int wordLength, string randWord){
  int index; //figure out match position
  int numIncorrectGuesses = 0; //count the number of wrong guesses
  int numCorrectGuesses = 0; //count the number of correct guesses
  int size = (randWord.length()); // get size of word
  int guessed = 0;
  
  char letter; //user input
  string strletter; //user input as string
  
  bool gameOver = false; //state of the game
  bool found = false; //check to see if a letter matches

  char guessed[100];
  char underscore[size]; //an array of underscores
  char arr[size]; //the array we are storing the correct guess in

  
  for(int j = 0; j < size; j++){ //store underscores in array
    underscore[j] = '_';
  }
  for(int j = 0; j < size; j++){
    arr[j] = ' ';
  }
  

  while(gameOver == false){
    cout << endl;
    cout << "Please enter a letter to guess" << endl;
    cout << "Your Guess: ";
    do{
      getline(cin, strletter);
    } while(strletter == "");
    letter = strletter[0];

    for(int i = 0; i<size; i++){
      if(randWord[i] == letter){
        arr[i] = letter;
        found = true;
        numCorrectGuesses++;
      }
    }

    if(found == false){ //Incorrect guess
      cout << "Incorrect!" << endl;
      numIncorrectGuesses++;
      hangman2D(numIncorrectGuesses);
      if(numIncorrectGuesses == 6){
	gameOver = true;
      }
    }
    else{ //Correct Guess
      cout << endl;
      for(int k = 0; k < size; k++){
        cout << arr[k] << " ";
      }
      cout << endl;
      for(int b = 0; b < size; b++){
        cout << underscore[b] << " ";
      }
      cout << endl;
    }

    if(numCorrectGuesses == (size)){ //check if player has guessed all correct letters
      cout << "You Win!" << endl;
      cout << endl;
      break;
    }
    found = false; //reset found
  }
}


void hangman2D(int numIncorrectGuesses){

  switch (numIncorrectGuesses) {
  case 0:
    cout << "    _________" << endl;
    cout << "    |       |" << endl;
    cout << "            |" << endl;
    cout << "            |" << endl;
    cout << "            |" << endl;
    cout << "            |" << endl;
    cout << "         - - - - " << endl;
    cout << endl;
    break;
  case 1:
    cout << "    _________" << endl;
    cout << "    |       |" << endl;
    cout << "    O       |" << endl;
    cout << "            |" << endl;
    cout << "            |" << endl;
    cout << "            |" << endl;
    cout << "         - - - - " << endl;
    cout << endl;
    break;
  case 2:
    cout << "    _________" << endl;
    cout << "    |       |" << endl;
    cout << "    O       |" << endl;
    cout << "    |       |" << endl;
    cout << "            |" << endl;
    cout << "            |" << endl;
    cout << "         - - - - " << endl;
    cout << endl;
    break;
  case 3:
    cout << "    _________" << endl;
    cout << "    |       |" << endl;
    cout << "    O       |" << endl;
    cout << "   /|       |" << endl;
    cout << "            |" << endl;
    cout << "            |" << endl;
    cout << "         - - - - " << endl;
    cout << endl;
    break;
  case 4:
    cout << "    _________" << endl;
    cout << "    |       |" << endl;
    cout << "    O       |" << endl;
    cout << "   /|l      |" << endl;
    cout << "            |" << endl;
    cout << "            |" << endl;
    cout << "         - - - - " << endl;
    cout << endl;
    break;
  case 5:
    cout << "    _________" << endl;
    cout << "    |       |" << endl;
    cout << "    O       |" << endl;
    cout << "   /|l      |" << endl;
    cout << "   /        |" << endl;
    cout << "            |" << endl;
    cout << "         - - - - " << endl;
    cout << endl;
    break;
  case 6:
    cout << "    _________" << endl;
    cout << "    |       |" << endl;
    cout << "    O       |" << endl;
    cout << "   /|l      |" << endl;
    cout << "   / l      |" << endl;
    cout << "            |" << endl;
    cout << "         - - - - " << endl;
    cout << endl;
    cout << " G A M E O V E R" << endl;
    cout << endl;
    break;
  }
}
