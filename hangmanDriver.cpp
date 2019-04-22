#include <iostream>
#include <vector>

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
  Tree game; //instantiate an object
  int input; //user input variable

  int wordLength; //integer length of the word
  string strWordLength; //string input from the user
  bool wordLengthGood = true; //check to make sure user input is a valid number

  bool newGame = true; //used to start new game or exit

  cout << "Hello, welcome to hangman super deluxe edition(tm)" << endl;
  game.buildLibrary();

  while(newGame == true){

    cout << "Please enter a length for the word: ";
    //get number and validate input
    do{
      getline(cin, strWordLength);

      //check if the input was a number
      for(int i = 0; i < strWordLength.size(); i++){
        if(!isdigit(strWordLength[i])){
          cout << "Invalid input. Enter new word length" << endl;
          wordLengthGood = false;
          break;
        }
        else{
          wordLengthGood = true;
        }
      }
    } while(strWordLength == "" || !wordLengthGood); //redo if it isn't

    //convert string to  number
    wordLength = stoi(strWordLength);

    //get a random word
    string randWord = game.getRandomWord(wordLength);




    //word length not found in the case the user enters a very large number
    while(randWord == "null"){
      cout << endl;
      cout << "Please enter a new length: ";

      do{
        getline(cin, strWordLength);

        //check if the input was a number
        for(int i = 0; i < strWordLength.size(); i++){
          if(!isdigit(strWordLength[i])){
            cout << "Invalid input. Enter new word length" << endl;
            wordLengthGood = false;
            break;
          }
          else{
            wordLengthGood = true;
          }
        }
      } while(strWordLength == "" || !wordLengthGood); //redo if it isn't

      //conver string to int
      wordLength = stoi(strWordLength);
      //get random word
      randWord = game.getRandomWord(wordLength);
    }


    cout << "A random word has been chosen, now try to guess it!" << endl;

    guess(wordLength, randWord); //function that controls the flow of the game

    //menu
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

  char letter; //user input
  string strletter; //user input as string

  bool gameOver = false; //state of the game
  bool found = false; //check to see if a letter matches
  bool guessed = false;

  vector <char> guessedarr; //vector to record all the gussed letters
  char underscore[size]; //an array of underscores
  char arr[size]; //the array we are storing the correct guess in


  for(int j = 0; j < size; j++){ //store underscores in array
    underscore[j] = '_';
  }
  for(int j = 0; j < size; j++){ //store empty spaces
    arr[j] = ' ';
  }


  while(gameOver == false){

    //get letter
    cout << endl;
    cout << "Please enter a letter to guess" << endl;
    cout << "Your Guess: ";
    do{
      getline(cin, strletter);
    } while(strletter == "");
    letter = strletter[0];



    //check if input was already guessed by searching through vector
    for(int i = 0; i < guessedarr.size(); i++){
      if(guessedarr[i] == letter){
        guessed = true;
        break;
      }
      else{
        guessed = false;
      }
    }



    //if letter has not been guessed
    if(!guessed){

      //push guessed letter into vector
      guessedarr.push_back(letter);

      //check if the new letter they have guessed is in the word
      for(int i = 0; i < size; i++){
        if(randWord[i] == letter){
          arr[i] = letter; //place the letters in the correct position
          found = true;
          numCorrectGuesses++;
        }
      }

      //Incorrect guess
      if(found == false){
        cout << "Incorrect!" << endl;
        numIncorrectGuesses++; //increment number of incorrect guesses
        hangman2D(numIncorrectGuesses); //display the hangman model
        if(numIncorrectGuesses == 6){ //check if the user has guessed incorrectly too many times
          gameOver = true; //game is over, player loses
          cout << "The word was: " << randWord << endl;
        }
      }
      //Correct Guess -> output current string with the correct letters they have guessed
      else{
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

      //check if player has guessed all correct letters
      if(numCorrectGuesses == (size)){
        cout << "You Win!" << endl;
        cout << endl;
        break;
      }
    }
    //if the letter was already guessed
    else{
      cout << endl << "Letter was already guessed" << endl;
      cout << "Letters Guessed:" << endl;
      for(int i = 0; i < guessedarr.size(); i++){
        cout << guessedarr[i] << " ";
      }
      cout << endl;
    }

    found = false; //reset found
    guessed = false; //reset guessed
  }
}

//This function just outputs a 2D visualization of the hangman model whenever an incorrect word is guessed
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
