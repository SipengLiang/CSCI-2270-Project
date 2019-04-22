#ifndef HANGMAN_HPP
#define HANGMAN_HPP

#include <string>

using namespace std;


//Word Container
struct WordNode{
  string word;
  struct WordNode *next;

  WordNode(){}; //Default constructor
};



//Tree Nodes. Will organize based on wordlength
struct TreeNode{
  int wordlength;
  int llength;
  WordNode *head = nullptr;
  TreeNode *left = nullptr;
  TreeNode *right = nullptr;
};



//Class for library
class Tree{
private:
  TreeNode *root;

  //Helper function for buildLibrary to add word to BST and LL
  void addWord(string word);
  void insertLLNode(TreeNode *treenode, WordNode *wordnode);
  TreeNode *searchTreeNode(int wordlength, TreeNode *root); // Helper function to search for the tree node with corresponding word length

public:
  Tree();
  ~Tree();

  //Asks for filename and builds BST by adding TreeNodes and WordNodes
  void buildLibrary();

  //Gets random word based on desired wordlength from library
  string getRandomWord(int wordlength);
};

#endif
