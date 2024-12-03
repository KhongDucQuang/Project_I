// Description
// Given a BST initialized by NULL. Perform a sequence of operations on a BST including:
// insert k: insert a key k into the BST (do not insert if the key k exists)
// Input
// •Each line contains command under the form: “insert k”
// •The input is terminated by a line containing #
// Output
// •Write the sequence of keys of nodes visited by the pre-order traversal (separated by a SPACE character)

#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* leftChild;
    Node* rightChild;
};

Node* makeNode(int k){
    Node* p = new Node;
    p->data = k;
    p->leftChild = NULL;
    p->rightChild = NULL;
    return p;
}

Node* insert(Node* r, int k){
    if(r == NULL){
        r = makeNode(k);
    } else if(r->data > k){
        r->leftChild = insert(r->leftChild, k);
    } else if(r->data < k){
        r->rightChild = insert(r->rightChild, k);
    }
    return r;
}
void preOrder(Node* r){
    if(r == NULL) return;
    cout << r->data << " ";
    preOrder(r->leftChild);
    preOrder(r->rightChild);
}
int main(){
    Node* root = NULL;
    string s;
    int k;
    while(true){
        cin >> s;
        if(s == "#") break;
        cin >> k;
        root = insert(root, k);
    }
    preOrder(root);
    return 0;
}
