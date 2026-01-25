
#include <iostream>
using namespace std;

// Class representing a Node in the Binary Tree
class Node {
public:
    int data;      // Stores the value of the node
    Node* left;    // Pointer to the left child node
    Node* right;   // Pointer to the right child node

    // Constructor to initialize a node with a given key
    Node(int key) {
        data = key;
        left = nullptr;
        right = nullptr;
    }
};

// Class containing the logic for Binary Tree creation
class Solution {
public:
    Node* createBinaryTree() {
        // Creates the root node with key value 1
        Node* root = new Node(1);

        // Creates a left child node for the root with key value 2
        root->left = new Node(2);

        // Creates a right child node for the root with key value 3
        root->right = new Node(3);

        // Creates a left child node for the right child of root with key value 5
        root->right->left = new Node(5);

        return root;
    }
};

// Driver code
int main() {
    Solution solution;
    Node* root = solution.createBinaryTree();

    // Tree created, can be used for further operations
    return 0;
}
