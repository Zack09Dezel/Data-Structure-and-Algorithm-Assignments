#include <iostream>
using namespace std;

class Tree {
public:
    int val;
    Tree* left;
    Tree* right;

    Tree(int value) {
        val = value;
        left = right = nullptr;
    }
};

class BinarySearchTree {
private:
    Tree* root;

    Tree* insertRecursive(Tree* root, int value) {
        if (root == nullptr) {
            root = new Tree(value);
            return root;
        }

        if (value < root->val) {
            root->left = insertRecursive(root->left, value);
        } else if (value > root->val) {
            root->right = insertRecursive(root->right, value);
        }

        return root;
    }

    void inOrderRecursive(Tree* root) {
        if (root != nullptr) {
            inOrderRecursive(root->left);
            cout << root->val << " ";
            inOrderRecursive(root->right);
        }
    }

public:
    BinarySearchTree() {
        root = nullptr;
    }

    void insert(int value) {
        root = insertRecursive(root, value);
    }

    void inOrderTraversal() {
        cout << "Inorder traversal:" << endl;
        inOrderRecursive(root);
        cout << endl;
    }

    bool search(int value) {
        Tree* current = root;
        while (current != nullptr) {
            if (current->val == value) {
                return true;
            } else if (value < current->val) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        return false;
    }
};

int main() {
    BinarySearchTree bst;

    bst.insert(5);
    bst.insert(3);
    bst.insert(8);
    bst.insert(2);
    bst.insert(4);
    bst.insert(7);
    bst.insert(9);

    bst.inOrderTraversal();

    cout << "Search for 7: " << (bst.search(7) ? "Found" : "Not Found") << endl;
    cout << "Search for 10: " << (bst.search(10) ? "Found" : "Not Found") << endl;

    return 0;
}
