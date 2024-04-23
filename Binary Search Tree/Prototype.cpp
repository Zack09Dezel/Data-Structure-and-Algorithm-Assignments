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

        //Traversal recursive functions
        Node *preOrderRecursive(Node* currentRoot){
            if (currentRoot != NULL){
                cout << currentRoot->key << " ";
                preOrderRecursive(root->left);
                preOrderRecursive(root->right);
            }
        }


        Node *inOrderRecursive(Node* currentRoot){
            if (currentRoot != NULL){
                inOrderRecursive(root->left);
                cout << currentRoot->key << " ";
                inOrderRecursive(root->right);
            }
        }

        Node *postOrderRecursive(Node* currentRoot){
            if (currentRoot != NULL){
                postOrderRecursive(root->left);
                postOrderRecursive(root->right);
                cout << currentRoot->key << " ";
            }
        }

        void preOrderRecursive(){
            preOrderRecursive(root);
        }

        void inOrderRecursive(){
            inOrderRecursive(root);
        }

        void postOrderRecursive(){
            postOrderRecursive(root);
        }

};

int main(int argc, char** argv) {
    BST *bin1 = new BST();

    bin1->insert(1);
    bin1->insert(5);
    bin1->insert(2);
    bin1->insert(4);
    bin1->insert(7);
    bin1->insert(9);

    bin1->preOrderRecursive();

    return 0;
}

