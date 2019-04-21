#include <iostream>

#include "hangman.hpp"
#include "hangman.cpp"

using namespace std;

void initializeGame(); // builds the library and gets the random word (Calls Guess)

void guess(int wordlength, string randWord); //main game mechanic (Calls findMatch, hangman2D)

int findMatch(string randWord, char letter, int size); //checks to see if guess is in the word (called by guess)

void hangman2D(int numIncorrectGuesses); //2D hangman print (called by guess)


int main(){
  initializeGame();
}

void initializeGame(){
  Tree game;
  int wordLength;

  cout << "Hello, welcome to hangman super deluxe edition(tm)" << endl;
  game.buildLibrary();

  cout << "Please enter a length for the word: ";
  cin >> wordLength;

  string randWord = game.getRandomWord(wordLength);

  cout << "A random word has been chosen, now try to guess it!" << endl;
  cout << randWord << endl;

  randWord.erase(randWord.length() - 1);

  guess(wordLength, randWord);



}


void guess(int wordLength, string randWord){
  int index; //figure out match position
  int numIncorrectGuesses = 0; //count the number of wrong guesses
  int size = (randWord.length()); // get size of word
  char letter; //user input
  bool gameOver = false; //state of the game
  char underscore[size]; //an array of underscores
  char arr[size]; //the array we are storing the correct guess in

  for(int j = 0; j < size; j++){ //store underscores in array
      underscore[j] = '_';
  }

  while(gameOver == false){
    cout << "Please enter a letter to guess" << endl;
    cout << "Your Guess: ";
    cin >> letter;
    index = findMatch(randWord, letter, size); //find where in the string the letter occurs

    if(index == -1){ //Incorrect guess
      cout << "Incorrect!" << endl;
      numIncorrectGuesses++;
      hangman2D(numIncorrectGuesses);
        if(numIncorrectGuesses == 6){
          break;
        }
    }
    else{ //Correct Guess
      arr[index] = letter;
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
  }
}


int findMatch(string randWord, char letter, int size){
  int i;
  for (i = 0; i < size; i++ ){
    if(randWord[i] == letter){
      return i;
    }
  }
  return -1;
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
