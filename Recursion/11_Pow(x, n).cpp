// THis is the Probelm of the LeetCode

class Solution {
public:

    double ans(double x, long long n){
        if (n == 0){
            return 1;
        }

        double helf = ans(x , n /2);
        if (n % 2 ==0){
            return helf * helf ;
        }else {
            return helf * helf * x ;
        }

    }
    double myPow(double x, int n) {
        if (x == 1 && n != 0){
            return 1;
        }
        long long N = n ;
        if (n < 0){
            N = -(N);
            x = 1/x;
        }
        return ans(x,N);
    }   
};