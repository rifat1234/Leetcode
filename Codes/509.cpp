class Solution {
public:
    int fib(int n) {
        vector<int> mem(40,0);
        mem[1] = 1;
        for(int i=2;i<=n;i++)mem[i] = mem[i-1]+mem[i-2];

        return mem[n];
    }
};
