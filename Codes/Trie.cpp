// Online C++ compiler to run C++ program online
#include <iostream>

using namespace std;

struct Node {
    Node *ar[26];
    bool endWord;  
    
    Node(){
        endWord = false;
    }
};

class Trie {
private:
    Node *root;
public:
    Trie(){
        root = new Node();
    }
    
    void insert(string word){
        auto *cur = root;
        for(auto ch:word){
            int val = ch - 'a';
            if(cur->ar[val]==nullptr){
                cur->ar[val] = new Node();
            }
            
            cur = cur->ar[val];
        }
        
        cur->endWord = true;
    }
    
    bool search(string word){
        auto *cur = root;
        for(auto ch:word){
            int val = ch - 'a';
            if(cur->ar[val] == nullptr)return false;
            cur = cur->ar[val];
        }
        
        return cur->endWord;
    }
};



int main() {
    Trie trie;
    trie.insert("apple");
    cout<<"Found app: "<<trie.search("app")<<endl;
    cout<<"Found apple: "<<trie.search("apple")<<endl;
    cout<<"Found apples: "<<trie.search("apples")<<endl;
    cout<<"Found balls: "<<trie.search("ball")<<endl;
    return 0;
}
