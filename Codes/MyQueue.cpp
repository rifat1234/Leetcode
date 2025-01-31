// Online C++ compiler to run C++ program online
#include <iostream>


struct Node { 
    int val;
    Node *next;
    
    Node(int x){
        val = x;
    }
};

class MyQueue {
private:
    Node *head, *tail;
public:
    MyQueue(){
        head = nullptr;
        tail = nullptr;
    }
    
    void push(int val){
        auto nd = new Node(val);
        if(tail != nullptr) tail->next = nd;
        tail = nd;
        if(head == nullptr){
            head = tail;
        }
    }
    
    int front(){
        if(head == nullptr)throw "Queue empty";
        return head->val;
    }
    
    void pop(){
        if(head == nullptr)throw "Queue empty";
        head = head->next;
    }
    
};

using namespace std;

int main() {
    // Write C++ code here
    MyQueue q;
    q.push(1);
    q.push(2);
    cout<<q.front()<<endl;
    q.pop();
    cout<<q.front()<<endl;
    q.pop();
    q.push(3);
    cout<<q.front()<<endl;
    
    return 0;
}
