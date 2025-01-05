class Solution {
public:
    double f(double x, long long n){
        if(!n)return 1;
        if(n==1) return x;
        double ret = f(x,n/2);
        ret*=ret;
        if(n%2)ret*=x;
        return ret;
    }

    double myPow(double x, int n) {
        double val = f(x,abs((long long)n));
        if(n<0)val = 1.0/val;
        return val;
    }
};
