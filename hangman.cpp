#include <iostream>
#include <string>
#include <srand.h>
#include <time.h>

#include "handman.hpp"

using namespace std;

Tree::Tree(){
  root = nullptr;
}

Tree::~Tree(){
}

void Tree::insertLLNode(TreeNode *treenode, WordNode *wordnode){

  //no head
  if(!treenode->head){
    treenode->head = wordnode;
  }

  //comes before the head
  else if(){

  }

  //comes after the head
  else{
  }
}

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
    else if(traverse->wordlength < wordlength){
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
  else if(previous->wordlength < wordlength){
    previous->left = treenode;
    insertLLNode(treenode, movienode);
  }

  //new wordlength is greater than parent node
  else{
    previous->right = treenode;
    insertLLNode(treenode, movienode);
  }
}

void Tree::buildLibrary(){
  string filename;

  cout << "Enter name of dictionary: " << endl;
  cin >> filename << endl;

  a;lsdkjfs;ld
}

string Tree::getRandomWord(int wordlength){

  cout << "random" << endl;
  cout << "dog" << endl;

  asdffdsadf
}
