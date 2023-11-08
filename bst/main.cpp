// C++ Program for BST Traversal and Dynamic Methods
#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;

    Node* insert(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        if (value < node -> data) {
            node -> left = insert(node -> left, value);
        } else if (value > node -> data) {
            node -> right = insert(node -> right, value);
        }
        return node;
    }


    // Search Method
    Node* search(Node* node, int value) {
        if (node == nullptr || node -> data == value) {
            return node;
        }
        if (value < node -> data) {
            return search(node -> left, value);
        } else {
            return search(node -> right, value);
        }
    }

    // DELETE METHOD
    Node* deleteNode(Node* node, int value) {
        if (node == nullptr) return node;   // return null if tree is empty
        
        // Traverse through tree to find int value to delete
        if (value < node -> data) {
            node -> left = deleteNode(node -> left, value);

        } else if (value > node -> data) {
            node -> right = deleteNode(node -> right, value);
        } else {
            if (node->left == nullptr) {
                Node* temp = node -> right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node -> left;
                delete node;
                return temp;
            }

            Node* temp = minValueNode(node -> right);
            node->data = temp -> data;
            node->right = deleteNode(node -> right, temp -> data);
        }
        return node;
    }

    
    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current -> left != nullptr) {
            current = current -> left;
        }
        return current;
    }

    void inOrder(Node* node) {
        if (node != nullptr) {
            inOrder(node->left);
            cout << node -> data << " ";
            inOrder(node -> right);
        }
    }

    void preOrder(Node* node) {
        if (node != nullptr) {
            cout << node -> data << " ";
            preOrder(node -> left);
            preOrder(node -> right);
        }
    }

    void postOrder(Node* node) {
        if (node != nullptr) {
            postOrder(node -> left);
            postOrder(node -> right);
            cout << node->data << " ";
        }
    }

    void levelOrder(Node* node) {
        if (node == nullptr) return;

        queue<Node*> q;
        q.push(node);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            cout << current->data << " ";
            if (current->left != nullptr) q.push(current->left);
            if (current->right != nullptr) q.push(current->right);
        }
    }


public:
    BST() : root(nullptr) {}

    void insert(int value) {
        root = insert(root, value);
    }

    void deleteValue(int value) {
        root = deleteNode(root, value);
    }

    bool search(int value) {
        return search(root, value) != nullptr;
    }

    void inOrder() {
        inOrder(root);
        cout << endl;
    }

    void preOrder() {
        preOrder(root);
        cout << endl;
    }

    void postOrder() {
        postOrder(root);
        cout << endl;
    }

    void levelOrder() {
        levelOrder(root);
        cout << endl;
    }
};

// Main Method
int main() {
    BST bst;
    int number_of_queries;
    cin >> number_of_queries;   // 1st input line is number of queries to be process

    string command; // User Command
    int value;

    // Process BST for _number_of_queries
    for (int i = 0; i < number_of_queries; i++) {
        cin >> command;
        if (command == "INSERT") {
            cin >> value;
            bst.insert(value);

        } else if (command == "DELETE") {
            cin >> value;
            bst.deleteValue(value);
            
        //SEARCH for int
        // Return 'True' if found -> 'False' if not
        } else if (command == "SEARCH") {
            cin >> value;
            cout << (bst.search(value) ? "True" : "False") << endl;

        } else if (command == "INORDER") {
            bst.inOrder();

        } else if (command == "PREORDER") {
            bst.preOrder();

        } else if (command == "POSTORDER") {
            bst.postOrder();

        } else if (command == "LEVELORDER") {
            bst.levelOrder();
        }
    }

    return 0;
}
