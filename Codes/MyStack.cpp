// Online C++ compiler to run C++ program online
#include <iostream>


struct Node { 
    int val;
    Node *next;
    
    Node(int x){
        val = x;
    }
};

class MyStack {
private:
    Node *head;
public:
    MyStack(){
        head = nullptr;
    }
    
    void push(int val){
        auto nd = new Node(val);
        auto prevHead = head;
        head = nd;
        head->next = prevHead;
    }
    
    int top(){
        if(head == nullptr)
            throw "Empty struct";
        return head->val;
    }
    
    void pop(){
        if(head == nullptr)
            throw "Empty struct";
        head = head->next;
    }
};

using namespace std;

int main() {
    // Write C++ code here
    MyStack stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    cout<<stk.top()<<endl;
    stk.pop();
    cout<<stk.top()<<endl;
    stk.push(4);
    cout<<stk.top()<<endl;
    stk.pop();
    stk.pop();
    cout<<stk.top()<<endl;
    
    
    return 0;
}
