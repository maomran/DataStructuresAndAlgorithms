//
// Created by Mieszko Wawrzyniak on 22/04/2018.
//

#include "BST.h"

#include <utility>
#include <iostream>

using namespace std;

BST::BST() {
  root = nullptr;
}

BST::_Node::_Node(string key) {
  this->key = move(key);
  this->val = 1;
  this->left = nullptr;
  this->right = nullptr;
}

void BST::Add(string word) {
  if (!root) {
    root = new _Node(word);
    return;
  }
  
  _Node *n = root;
  int cmp;
  
  while (true) {
    cmp = strcmp(n->key.c_str(), word.c_str());
    
    if (0 == cmp) {
      ++n->val;
      return;
    }
  
    if (cmp < 0) {
      if (!n->left) {
        n->left = new _Node(word);
        return;
      }
    
      n = n->left;
      continue;
    }
    
    if (cmp > 0) {
      if (!n->right) {
        n->right = new _Node(word);
        return;
      }
    
      n = n->right;
      continue;
    }
  }
}

string BST::MostPopular() {
  string str;
  uint64_t topVal = 0;
  
  walk(root, str, topVal);
  
  return str;
}

void BST::walk(BST::_Node *node, string &topStr, uint64_t &topVal) {
  if (!node) {
    return;
  }
  
  if (node->val > topVal) {
    topStr = node->key;
    topVal = node->val;
  }
  
  walk(node->left, topStr, topVal);
  walk(node->right, topStr, topVal);
}
