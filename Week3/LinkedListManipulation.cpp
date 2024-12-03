// Description
// Viết chương trình thực hiện công việc sau:
// Xây dựng danh sách liên kết với các khóa được cung cấp ban đầu là dãy a
// 1
// , a
// 2
// , …, a
// n
// , sau đó thực hiện các thao tác trên danh sách bao gồm: thêm 1 phần tử vào đầu, vào cuối danh sách, hoặc vào trước, vào sau 1 phần tử nào đó trong danh sách, hoặc loại bỏ 1 phần tử nào đó trong danh sách

// Input
// Dòng 1: ghi số nguyên dương n (1 <= n <= 1000)
// Dòng 2: ghi các số nguyên dương a
// 1
// , a
// 2
// , …, a
// n
// .
// Các dòng tiếp theo lần lượt là các lệnh để thao tác (kết thúc bởi ký hiệu #) với các loại sau:
// addlast  k: thêm phần tử có key bằng k vào cuối danh sách (nếu k chưa tồn tại)
// addfirst  k: thêm phần tử có key bằng k vào đầu danh sách (nếu k chưa tồn tại)
// addafter  u  v: thêm phần tử có key bằng u vào sau phần tử có key bằng v trên danh sách (nếu v đã tồn tại trên danh sách và u chưa tồn tại)
// addbefore  u  v: thêm phần tử có key bằng  u vào trước phần tử có key bằng v trên danh sách (nếu v đã tồn tại trên danh sách và u của tồn tại)
// remove  k: loại bỏ phần tử có key bằng k khỏi danh sách
// reverse: đảo ngược thứ tự các phần tử của danh sách (không được cấp phát mới các phần tử, chỉ được thay đổi mối nối liên kết)
// Output
// Ghi ra dãy khóa của danh sách thu được sau 1 chuỗi các lệnh thao tác đã cho
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* makeNode(int k){
    Node* p = new Node;
    p->data = k;
    p->next = NULL;
    return p;
}

bool findNode(Node* head, int k){
    Node* cur = head;
    while(cur != NULL){
        if(cur->data == k) return true;
        cur = cur->next;
    }
    return false;
}
Node* addHead(Node* head, int k){
    if(findNode(head, k)) return head;
    Node* tmp = makeNode(k);
    if(head == NULL){
        return tmp;
    }
    tmp->next = head;
    return tmp;
}

Node* addLast(Node* head, int k){
    if(findNode(head, k)) return head;
    Node* tmp = makeNode(k);
    if(head == NULL){
        return tmp;
    }
    Node* cur = head;
    while(cur->next != NULL){
        cur = cur->next;
    }
    cur->next = tmp;
    return head;
}

Node* addAfter(Node* head, int u, int v){
    if(head == NULL) return head;
    if(!findNode(head, v) || findNode(head, u)) return head;
    Node* tmp = makeNode(u);
    Node* cur = head;
    while(cur->data != v){
        cur = cur->next;
    }
    tmp->next = cur->next;
    cur->next = tmp;
    return head;
}

Node* addBefore(Node* head, int u, int v){
    if(head == NULL) return head;
    if(head->data == v){
        Node* tmp = makeNode(u);
        tmp->next = head;
        return tmp;
    }
    if(!findNode(head, v) || findNode(head, u)) return head;
    Node* tmp = makeNode(u);
    Node* cur = head;
    while(cur->next != NULL && cur->next->data != v){
        cur = cur->next;
    }
    if(cur->next != NULL){
        tmp->next = cur->next;
        cur->next = tmp;
    }
    return head;
}
Node* removeK(Node* head, int k){
    if(head == NULL) return head;
    if(head->data == k){
        Node* tmp = head;
        head = head->next;
        free(tmp);
        return head;
    }
    if(!findNode(head, k)) return head;
    Node* cur = head;
    while(cur->next->data != k){
        cur = cur->next;
    }
    if(cur->next->next == NULL){
        cur->next == NULL;
        return head;
    }
    Node* tmp = cur->next;
    cur->next = cur->next->next;
    free(tmp);
    return head;
}

Node* reverseLinkedList(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* newHead = reverseLinkedList(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

void printList(Node* head){
    Node* cur = head;
    while(cur != NULL){
        cout << cur->data << " ";
        cur = cur->next;
    }
}
int main(){
    int n; cin >> n;
    Node* head = NULL;
    for(int i = 0; i < n; i++){
        int k; cin >> k;
        head = addLast(head, k);
    }
    string cmd;
    while(true){
        cin >> cmd;
        if(cmd == "#") break;
        if(cmd == "addlast"){
            int k; cin >> k;
            head = addLast(head, k);
        } else if(cmd == "addfirst"){
            int k; cin >> k;
            head = addHead(head, k);
        } else if(cmd == "addafter"){
            int a, b; cin >> a >> b;
            head = addAfter(head, a, b);
        } else if(cmd == "addbefore"){
            int a, b; cin >> a >> b;
            head = addBefore(head, a, b);
        } else if(cmd == "remove"){
            int k; cin >> k;
            head = removeK(head, k);
        } else if(cmd == "reverse"){
            head = reverseLinkedList(head);
        }
    }
    printList(head);
    return 0;
}


