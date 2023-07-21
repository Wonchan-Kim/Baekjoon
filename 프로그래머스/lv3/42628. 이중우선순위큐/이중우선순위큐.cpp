#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Node {
public:
    int key;
    Node* left;
    Node* right;

    Node(int key) {
        this->key = key;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
private:
    Node* root;

    Node* insertRecursive(Node* root, int key) {
        if (root == nullptr) {
            return new Node(key);
        }

        if (key < root->key) {
            root->left = insertRecursive(root->left, key);
        } else if (key > root->key) {
            root->right = insertRecursive(root->right, key);
        }

        return root;
    }

    Node* findMaxNode(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }

        while (root->right != nullptr) {
            root = root->right;
        }

        return root;
    }

    Node* findMinNode(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }

        while (root->left != nullptr) {
            root = root->left;
        }

        return root;
    }

    Node* deleteRecursive(Node* root, int key) {
        if (root == nullptr) {
            return nullptr;
        }

        if (key < root->key) {
            root->left = deleteRecursive(root->left, key);
        } else if (key > root->key) {
            root->right = deleteRecursive(root->right, key);
        } else {
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            Node* successor = findMinNode(root->right);
            root->key = successor->key;
            root->right = deleteRecursive(root->right, successor->key);
        }

        return root;
    }

public:
    BST() {
        root = nullptr;
    }

    void insert(int key) {
        root = insertRecursive(root, key);
    }

    int findMax() {
        Node* maxNode = findMaxNode(root);
        if (maxNode == nullptr) {
            std::cout << "BST is empty." << std::endl;
            return -1; // Or throw an exception, depending on your preference
        }

        return maxNode->key;
    }

    int findMin() {
        Node* minNode = findMinNode(root);
        if (minNode == nullptr) {
            std::cout << "BST is empty." << std::endl;
            return -1; // Or throw an exception, depending on your preference
        }

        return minNode->key;
    }

    void remove(int key) {
        root = deleteRecursive(root, key);
    }
};

vector<int> solution(vector<string> operations) {
    BST bst;
    vector<int> answer = {0, 0};
    int cnt = 0;
    
    for(string op : operations) {
        // 삽입
        if(op[0] == 'I') {
            bst.insert(stoi(op.substr(2)));
            cnt++;
        }
        else {
            // 빈 큐에 데이터를 삭제하라는 연산일 경우 무시
            if(!cnt) continue;
            
            // 최댓값 삭제
            if(op[2] == '1') {
                bst.remove(bst.findMax());
                cnt--;
            }
            else {
                bst.remove(bst.findMin());
                cnt--;
            }
        }
    }
    
    if(cnt) {
        answer[0] = bst.findMax();
        answer[1] = bst.findMin();
    }
    
    return answer;
}