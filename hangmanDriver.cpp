#include <iostream>

#include "hangman.hpp"

using namespace std;

void play();

int main(){
  Tree t;
  t.buildLibrary();
  string word;
  word = t.getRandomWord(3);
  cout << word << endl;
  return 0;
}

void play(){

}
