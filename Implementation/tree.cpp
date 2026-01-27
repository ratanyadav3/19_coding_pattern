//Tree Data Structure .
//A tree is a hierarchical data structure consisting of nodes, where each node contains a value and references to its child nodes.
//The topmost node is called the root, and nodes without children are called leaves.  
//Trees are widely used in computer science for various applications, including representing hierarchical data, searching, and sorting.
//On the basis of problem we define a lot of type of trees like binary tree, binary search tree, AVL tree, red-black tree, segment tree, trie etc.
// Each one has its own properties and use cases.
//And we use tree according to our needs. So that problem can be solved efficiently.

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


// Tree traversal - Depth First Search (DFS) and Breadth First Search (BFS) .

//Depth First Search (DFS) Traversal 
//1. inorder (Left, Root, Right)
//2. preorder (Root, Left, Right)
//3. postorder (Left, Right, Root)


//Breadth First Search (BFS) Traversal
//1. level order traversal (visit nodes level by level from left to right)
//2. reverse level order traversal (visit nodes level by level from right to left)
//3. zigzag level order traversal (alternate between left to right and right to left at each level)


// Most of the tree problems can be solved using either DFS or BFS traversal techniques.