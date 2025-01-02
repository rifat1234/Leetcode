/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
    if (node == nullptr) {
        return node;
    }

      map<int, Node*> mp;
      set<int> st;

      queue<Node*> q;
      q.push(node);
      
      while(!q.empty()){
        Node* nd = q.front();
        q.pop();
        mp[nd->val] = new Node(nd->val);

        for(int i=0;i<nd->neighbors.size();i++){
          if(!mp.count(nd->neighbors[i]->val)){
            q.push(nd->neighbors[i]);
          }
        }
      }

      q.push(node);
      
      while(!q.empty()){
        Node* nd = q.front();
        q.pop();
        st.insert(nd->val);
        Node* newNd = mp[nd->val];
        
        for(int i=0;i<nd->neighbors.size();i++){
          if(!st.count(nd->neighbors[i]->val)){
            st.insert(nd->neighbors[i]->val);
            q.push(nd->neighbors[i]);
          }
          Node *neigh = nd->neighbors[i];
          newNd->neighbors.push_back(mp[neigh->val]);

        }
      }

      return mp[node->val];

    }
};
