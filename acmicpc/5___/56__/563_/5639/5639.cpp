#include <iostream>
#include <algorithm>

using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    
    Node* insert(Node* root , int data){ // returns new maded node's iter
        if(root == NULL){ // 없는에임 (this == NULL은 안된데 , 어케해야되지)
            root = new Node(); // 세로 만들으삼
            root->data = data;
            root->left = root->right = NULL;
        }
        else if (data <= root->data) {
            root->left = insert(root->left, data);
        }else{
            root->right = insert(root->right, data);
        }
        
        return root;
    }
};

void print_(Node* root) {
    if (root->left != NULL)
        print_(root->left);
    if (root->right != NULL)
        print_(root->right);
    cout << root->data << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    Node* root = nullptr;
    int data;
    while(cin >> data){
        root = root->insert(root, data);
    }
    
    print_(root);
}
