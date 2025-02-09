class Logger {
private:
    unordered_map <string, int> mp;
public:
    Logger() {
        
    }
    
    //["Logger", "shouldPrintMessage", "shouldPrintMessage", "shouldPrintMessage", "shouldPrintMessage", "shouldPrintMessage", "shouldPrintMessage"]
//[[], [1, "foo"], [2, "bar"], [3, "foo"], [8, "bar"], [10, "foo"], [11, "foo"]]
    //mp = {foo:11, bar:2}
    bool shouldPrintMessage(int timestamp, string message) {
        if(mp.find(message)==mp.end()){
            mp[message] = timestamp;
            return true;
        }
        
        if ((timestamp - mp[message]) >= 10){
            mp[message] = timestamp;
            return true;
        }
        
        return false;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
