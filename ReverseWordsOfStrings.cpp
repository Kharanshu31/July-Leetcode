class Solution {
public:
    string reverseWords(string s) {
//         int pos=0;
//         vector<string>res;
//         for(int i=1;i<s.length()-1;i++)
//         {
//             if(s[i]==' ' && s[i-1]!=' ' && s[i+1]!=' ')
//             {
//                 // reverse(s.begin()+pos,s.begin()+i);
//                 string temp=s.substr(pos,i-1);
//                 res.insert(res.begin(),temp);
//                 pos=i+1;
//             }
//         }
//         string ans="";
//         for(int i=0;i<res.size()-1;i++)
//             ans+=res[i];
        
//         return ans;
        
    string ans="";
    int n=s.size();

    for(int i=n-1;i>=0;i--)
    {
        if(s[i]==' ')
            continue;

        else
        {
            string reserve="";
            int j=i;

            while(i>=0 && s[i]!=' ')
                i--;

            if(ans.size())
                ans.append(" ");

            reserve=s.substr(i+1,j-i);
            ans.append(reserve);
        }
    }

    return ans;
        
    }
};
