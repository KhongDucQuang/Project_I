// Description
// Mỗi nút trên cây có trường id (identifier) là một số nguyên (id của các nút trên cây đôi một khác nhau)
// Thực hiện 1 chuỗi các hành động sau đây bao gồm các thao tác liên quan đến xây dựng cây và duyệt cây
// · MakeRoot u: Tạo ra nút gốc u của cây
// · Insert u v: tạo mới 1 nút u và chèn vào cuối danh sách nút con của nút v (nếu nút có id bằng v không tồn tại hoặc nút có id bằng u đã tồn tại thì không chèn thêm mới)
// · PreOrder: in ra thứ tự các nút trong phép duyệt cây theo thứ tự trước
// · InOrder: in ra thứ tự các nút trong phép duyệt cây theo thứ tự giữa
// · PostOrder: in ra thứ tự các nút trong phép duyệt cây theo thứ tự sau
// Dữ liệu: bao gồm các dòng, mỗi dòng là 1 trong số các hành động được mô tả ở trên, dòng cuối dùng là * (đánh dấu sự kết thúc của dữ liệu).
// Kết quả: ghi ra trên mỗi dòng, thứ tự các nút được thăm trong phép duyệt theo thứ tự trước, giữa, sau của các hành động PreOrder, InOrder, PostOrder tương ứng đọc được từ dữ liệu đầu vào
#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* leftMostChild;
    Node* rightSibling;
};
Node* makeNode(int k){
    Node* p = new Node;
    p->data = k;
    p->leftMostChild = NULL;
    p->rightSibling = NULL;
    return p;
}
Node* find(Node* root, int k){
    if(root == NULL) return NULL;
    if(root->data == k) return root;
    Node* p = root->leftMostChild;
    while(p != NULL){
        Node* h = find(p, k);
        if(h != NULL) return h;
        p = p->rightSibling;
    }
    return NULL;
}
Node* insert(Node* root, int u, int v){
    if(find(root, v) && !find(root, u)){
        Node* thisNode = find(root, v);
        Node* new_Node = makeNode(u);
        if(thisNode->leftMostChild == NULL){
            thisNode->leftMostChild = new_Node;
        } else {
            Node* tmp = thisNode->leftMostChild;
            while(tmp->rightSibling != NULL){
                tmp = tmp->rightSibling;
            }
            tmp->rightSibling = new_Node;
        }
    }
    return root;
}

void preOrder(Node* root){
    if(root == NULL) return;
    cout << root->data << " ";
    Node* p = root->leftMostChild;
    while(p != NULL){
        preOrder(p);
        p = p->rightSibling;
    }
}

void inOrder(Node* root){
    if(root == NULL) return;
    Node* p = root->leftMostChild;
    inOrder(p);
    cout << root->data << " ";
    if(p != NULL){
        p = p->rightSibling;
    }
    while (p != NULL)
    {
        inOrder(p);
        p = p->rightSibling;
    }
}

void postOrder(Node* root){
    if(root == NULL) return;
    Node* p = root->leftMostChild;
    while(p != NULL){
        postOrder(p);
        p = p->rightSibling;
    }
    cout << root->data << " ";
}

int main(){
    Node* root = NULL;
    string s;
    while(true){
        cin >> s;
        if(s == "*") break;
        if(s == "MakeRoot"){
            int k; cin >> k;
            root = makeNode(k);
        } else if(s == "Insert"){
            int u, v; cin >> u >> v;
            root = insert(root, u, v);
        } else if(s == "PreOrder"){
            preOrder(root);
            cout << endl;
        } else if(s == "InOrder"){
            inOrder(root);
            cout << endl;
        } else if(s == "PostOrder"){
            postOrder(root);
            cout << endl;
        }
    }
    return 0;
}
