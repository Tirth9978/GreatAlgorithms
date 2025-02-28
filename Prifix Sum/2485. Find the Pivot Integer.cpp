class Solution {
public:
    int pivotInteger(int n) {
        if (n==1)return 1;
        int sumLeft =1;
        int sumRight =0;
        for (int i=1;i<=n;i++)sumRight+=i;

        for (int i=2;i<=n;i++){
            sumLeft+=i;
            sumRight-=i-1;
            if (sumLeft==sumRight)return i;
        }        
        return -1;
    }
};
