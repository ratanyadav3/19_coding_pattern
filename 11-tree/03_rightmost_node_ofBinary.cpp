#include <iostream>
#include <vector>
using namespace std;

// Node Structure
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};

vector<int> rightView(Node* root) {
    
    vector<int> res;  
   
    int level = 0;     

    while (root) {
        
        // If the node has a right child,
        // find the inorder predecessor
        if (root->right) {
            Node *pred = root->right; 
            int backDepth = 1; 
            
            // Find the leftmost node in the right subtree
            while (pred->left != nullptr && 
                                  pred->left != root) {
                pred = pred->left;
                backDepth++;
            }
            
            // If threading is not yet established
            if (pred->left == nullptr) {
              
                // Add the current node to the view if 
                // visiting the level for the first time
                if (res.size() == level) {
                    res.push_back(root->data);
                }
                
                // Establish the thread and move 
                // to the right subtree
                pred->left = root;
                root = root->right;
                level++;  
            }
            else {  
              
                // Threading was already done
                //(second visit) remove the thread and 
                // go to the left subtree
                pred->left = nullptr;
                root = root->left;
                level -= backDepth;  
            }
        }
        else {
          
            // If no right child, process the current 
            // node and move to the left child
            if (res.size() == level) {
                res.push_back(root->data);
            }
            
            root = root->left;
            level++;  
        }
    }
 
    return res;
}


int main() {
    
    // Representation of the input tree:
    //         1
    //        / \
    //       2   3
    //          / \   
    //         4   5 
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);

    vector<int> result = rightView(root);
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}