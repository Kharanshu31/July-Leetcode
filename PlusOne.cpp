class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i=digits.size()-1;
        while(i>=0)
        {
            if(digits[i]!=9)
            {
                digits[i]+=1;
                return digits;
            }
            digits[i]=0;
            i--;
        }
        
        vector<int>res(digits.size()+1,0);
        res[0]=1;
        return res;
    }
};
