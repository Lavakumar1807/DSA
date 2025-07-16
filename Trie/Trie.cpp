#include<bits/stdc++.h>
using namespace std;

class Node{
public :
    vector<Node*> children;
    bool isEnd;

    Node(){
      isEnd = false;
      children.resize(26,nullptr);
    }
};

class Trie{
private:
    Node* root;
public : 
    Trie(){
      root = new Node();
    }

    void insert(string word){
      Node* node = root;
      int wordSize = word.size();

      for(int i = 0;i < wordSize;i++){
          int index = word[i] - 'a';
          if(node->children[index] == nullptr){
             node->children[index] = new Node();
          }
          node = node->children[index];
      }

      node->isEnd = true;
    }

    bool search(string word){
      Node* node = root;
      int wordSize = word.size();

      for(int i = 0;i < wordSize;i++){
        int index = word[i] - 'a';
        if(node->children[index] == nullptr){
          return false;
        }
        node = node->children[index];
      }

      return node->isEnd;
    }

    bool isPrefix(string word){
      Node* node = root;
      int wordSize = word.size();

      for(int i = 0;i < wordSize;i++){
        int index = word[i] - 'a';
        if(node->children[index] == nullptr){
          return false;
        }
        node = node->children[index];
      }

      return true;
    }

};

int main(){
   Trie test;
   vector<string> words = {"apple","apron","doll","doctor","computer","app"};

   for(string word : words){
     test.insert(word);
   }

   cout << "Search 'doll' : " << test.search("doll") << endl;
   cout << "Search 'computer' : " << test.search("computer") << endl;
   cout << "is 'apr' prefix : "<< test.isPrefix("apr") << endl;
   cout << "is 'computerr' prefix  : " << test.isPrefix("computerr") << endl;
   cout << "Search 'zoo' : " << test.search("zoo") << endl;

   return 0;
}

/*
  The Trie data structure is a tree-like structure used for storing a dynamic set of strings. 
  It allows for efficient retrieval and storage of keys, making it highly effective in handling large datasets. 
  Trie supports operations such as insertion, search, deletion of keys, and prefix searches. 

  The trie data structure, also known as a prefix tree, is a tree-like data structure used for efficient retrieval of key-value pairs. 
  It is commonly used for implementing dictionaries and autocomplete features, making it a fundamental component in many search algorithms.

  Trie data structure follows a property that If two strings have a common prefix then they will have the same ancestor in the trie.
*/