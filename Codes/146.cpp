/*["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
*/

// sz = 2, lst = (4,4)->(3,3)
class LRUCache {
private:
int sz;
unordered_map<int,list<pair<int,int>>::iterator> mp;
list<pair<int,int>> lst;
public:
    LRUCache(int capacity) {
        sz = capacity;  
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())return -1;
        else{
            auto val = *mp[key];
            lst.erase(mp[key]);
            lst.push_front(val);
            mp[key] = lst.begin();
        }
        return mp[key]->second;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            lst.erase(mp[key]);
        }
        lst.push_front(make_pair(key,value));
        mp[key] = lst.begin();
        if(lst.size()>sz){
            mp.erase(lst.back().first);
            lst.pop_back();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
