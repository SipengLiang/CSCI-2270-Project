#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <sstream>

#include "hangman.hpp"

using namespace std;
/**************************
Constructor
**************************/
Tree::Tree(){
  root = nullptr;
}

/*************************** HELPER FUNCTION *************************/
void deleteAllLLNodes(WordNode *head){
  WordNode* temp;
  while(head != nullptr){ //traverse through linked list deleting all the nodes
    temp = head;
    head = head->next;
    delete temp;
  }
  head = nullptr;
}
/********************* HELPER FUNCTION *********************/
void deleteAllTreeNodes(TreeNode * currNode){
  if(currNode == nullptr){
    return;
  }
  if(currNode!=NULL) //traverse through the tree to delete all the nodes
  {
      deleteAllTreeNodes(currNode->left);
      deleteAllTreeNodes(currNode->right);
      deleteAllLLNodes(currNode->head);
      delete currNode;
      currNode = NULL;
  }
  return;
}

/**************** Deconstructor *************************/
Tree::~Tree(){
  deleteAllTreeNodes(root);
}

/*********************************************
Function: insertLLNode
Goal: Once at the appropiate TreeNode, it will insert a wordNode to a linked list
input: treenode (pointer to TreeNode), wordnode (pointer to wordnode)
output: NA
**********************************************/
void Tree::insertLLNode(TreeNode *treenode, WordNode *wordnode){

  //no head
  if(!treenode->head){ //head is nullptr
    treenode->head = wordnode; // set the head of the LL to wordnode
    wordnode->next = nullptr;
  }

  //comes before the head
  else if(treenode->head){
    wordnode->next = treenode->head;
    treenode->head = wordnode;
  }

  //comes after the head
  else{
   }
}

/***********************************
Function: addWord
Goal: adds a word to the BST, it will call the function insertLLNode
input: word (string)
output: NA
************************************/
void Tree::addWord(string word){
  //Create wordnode
  WordNode *wordnode = new WordNode;
  wordnode->word = word;
  wordnode->next = nullptr;

  //get wordlength for tree traversal
  int wordlength = word.size();

  //traverse
  TreeNode *traverse = root;
  TreeNode *previous = nullptr;


  while(traverse){
    previous = traverse;

    //if wordlength exists, add to LL
    if(traverse->wordlength == wordlength){
      insertLLNode(traverse, wordnode);
      traverse->llength++;
      return;
    }

    //else go left
    else if(wordlength < traverse->wordlength){
      traverse = traverse->left;
    }

    //else go right
    else{
      traverse = traverse->right;
    }
  }


  //wordlength in tree didn't exist, must create and add to LL
  TreeNode *treenode = new TreeNode;
  treenode->wordlength = wordlength;
  treenode->llength = 1;

  //Tree never existed
  if(!previous){
    root = treenode;
    treenode->head = wordnode;
  }

  //new wordlength is less than parent node
  else if(wordlength < previous->wordlength){
    previous->left = treenode;
    insertLLNode(treenode, wordnode);
  }

  //new wordlength is greater than parent node
  else{
    previous->right = treenode;
    insertLLNode(treenode, wordnode);
  }
}

/*******************************************************
Function: searchTreeNode
Goal: Searches for the TreeNode with the given wordLength
Input: wordLength (integer), root (pointer to root)
Output: Pointer to corresponding TreeNode
********************************************************/
TreeNode *Tree::searchTreeNode(int wordLength, TreeNode *root){
  TreeNode *traverse; //create a pointer
  traverse = root; //start at the root

  while(traverse){ //condition: traverse is not nullptr
    if(traverse->wordlength > wordLength){ //if current node is less than wordLength, go left
      traverse = traverse->left;
    }
    else if(traverse->wordlength == wordLength){ // if equal, you're at the correct node, break
      break;
    }
    else if(traverse->wordlength < wordLength){ //if current node is greater than wordLength, go right
      traverse = traverse->right;
    }
  }
  return traverse;
}

/******************************************************
Function: buildLibrary
Goal: Takes user input for the name of the file and starts adding words from the file to the BST to build a library
Input: NA
Output: NA
*****************************************************/
void Tree::buildLibrary(){
  string filename;
  string line;
  bool open = false;
  stringstream linedata;

  while(!open){
    cout << "Enter name of dictionary: " << endl;
    cin >> filename; //user input

    ifstream read(filename); //instantiate object

    if(read.is_open()){
      open = true;
      //check if the file was opened successfully
      while(getline(read, line)){ // condition: there is a line with text
	stringstream linedata(line);
	getline(linedata, line, '\r');
        addWord(line); //add the word to BST
      }
    }
    else{
      cout << "File could not be opened, please try again." << endl; // error handler
    }
  }
}

/*******************************************************
Function: getRandomWord
Goal: Goes through the BST to get a random word of the corresponding wordlength, calls searchNode
Input: wordLength (integer)
Output: string
*******************************************************/
string Tree::getRandomWord(int wordlength){
  TreeNode *search = searchTreeNode(wordlength, root); // pointer to the TreeNode
  if(search == nullptr){
    cout << "Input word length not found" << endl;
    return "null";
  }
  int LLSize = search->llength; //store the amount of words in the linked list
  srand(time(NULL)); // initialize random number generator using seed
  int randNum = rand() % LLSize + 1; //generate random number between 1 to the size of the LL

  WordNode *traverse;
  traverse = search->head; //setting traverse to the head of the LL
  while(randNum && traverse){
    traverse = traverse->next; //traverse through the linked list
    randNum--; //decrement randNum
  }
  return traverse->word; // return the word at the position given by the random number

}
