class Solution {
public:
    int climbStairs(int n) {
        int first=1;
        int second=2;
        if(n<=2)
            return n;
        int ans=0;
        for(int i=3;i<=n;i++)
        {
            ans=first+second;
            first=second;
            second=ans;
        }
        
        return ans;
    }
};
