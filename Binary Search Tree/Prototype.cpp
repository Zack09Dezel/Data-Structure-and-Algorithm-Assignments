#include <iostream>
using namespace std;

class Node {
    public:
        int key;
        Node *left;
        Node *right;

        Node(){
            left = right = NULL;
        }
};

class BST {
    public:
        Node *root;

        BST(){
            root = NULL;
        }

        Node *InsertRecursive(int newKey, Node *currentRoot){

            //Insert the value
            if (root == NULL){
                Node *newNode = new Node();
                newNode->key = newKey;
                return newNode;
            }

            //Traversal to the left and right
            if (newKey < currentRoot->key){
                currentRoot->left = InsertRecursive(newKey, currentRoot->left);
            }else if (newKey > currentRoot->key){
                currentRoot->right = InsertRecursive(newKey, currentRoot->right);
            }
            return currentRoot;
        }

        //Initialize the first root as the current root
        void insert(int newKey){
            root = InsertRecursive(newKey, root);
        }
};

