#include <iostream>
#include <string>

#ifndef _binTree_H_
#define _binTree_H_


class binTree
{
private:
  struct Node
  {
    char data;
    Node* left;
    Node* right;
    Node* previous;
  };
  Node* head;
  Node* current;
  char alphabet[26]  = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
  'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
  'U', 'V', 'W', 'X', 'Y', 'Z'};
  int index = 0;
  int size;
public:
  binTree(int s);
  void advance_index();
  void build_tree(int size);
  void set_tree();
  void print_tree();
  int get_size();
  ~binTree();
};

binTree :: binTree(int s)
:size(s)
{
  head = NULL;
  current = NULL;
  build_tree(size);
}

void binTree:: advance_index()
{
  index++;
}

void binTree:: build_tree(int size)
{
  Node* first = new Node;
  first->previous = nullptr;
  head = first;
  current = head;
  bool alternator = true;
  int counter = 0;
  while(size)
    {
      Node* foo = new Node;
      foo->left = nullptr;
      foo->right = nullptr;
      if(alternator)
      {
        current -> left = foo;
        current->left->previous = current;
        alternator = false;
        counter++;
      }
      else
      {
        current ->right = foo;
        current->right->previous = current;
        alternator = true;
        counter++;
        if(counter%4 == 0 && counter > 3)
        {
           current = current->previous->right;
           continue;
        }
        if (counter%2 == 0)
        {
           current = current->left;
        }
      }
      size--;

    }

}

void binTree:: set_tree()
{
  int size = get_size();
  current = head;
  while (current->left) current = current->left;
  current->data = alphabet[index];
  std:: cout << "Current letter: " << alphabet[index] << std:: endl;
  advance_index();
  size--;
  bool leftHalf = true;
  while (size)
  {
    if (leftHalf)
    {
    current = current->previous;
    current->data = alphabet[index];
    std:: cout << "Current letter: " << alphabet[index] << std:: endl;
    advance_index();
      size--;
    if (current->previous == nullptr)
    {
       leftHalf = false;
       current = current->right;
       while(current->left) current = current->left;
       current->data = alphabet[index];
       std:: cout << "Current letter: " << alphabet[index] << std:: endl;
       advance_index();
       size--;
       continue;
    }
    current->right->data = alphabet[index];
    std:: cout << "Current letter: " << alphabet[index] << std:: endl;
    advance_index();
    size--;
    }

    else
    {
      current = current->previous;
      current->data = alphabet[index];
      std:: cout << "Current letter: " << alphabet[index] << std:: endl;
      advance_index();
      size--;
      current->right->data = alphabet[index];
      std:: cout << "Current letter: " << alphabet[index] << std:: endl;
      advance_index();
      size--;
    }

  }

}

int binTree:: get_size()
{return size;}

void binTree:: print_tree()
{
  //now we are at furthest left Node
  //trying to build this binary tree from left
  //to right with the letters, like in the notes
  //so just go up one set the letter , incrament,
  // go to the right, set letter ,incrament,
  //go back up, make sure to keep doing size--
  //rinse and repeat
  //printing works similarly
}

binTree:: ~binTree(){};


#endif
