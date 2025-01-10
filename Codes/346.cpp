//sz = 3
// 1->2->2->3
//sum = 7, q=2-2-3

class MovingAverage {
private:
int sz;
double sum=0;
queue<int> q;
public:
    MovingAverage(int size) {
        sz = size;
    }
    
    double next(int val) {
        q.push(val);
        sum+=val;
        
        if(q.size()>sz){
            sum-=q.front();
            q.pop();
        }
        
        return sum/q.size();
        
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
