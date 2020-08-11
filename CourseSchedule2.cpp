class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        map<int,vector<int>>m;
        for(int i=0;i<prerequisites.size();i++)
            m[prerequisites[i][1]].push_back(prerequisites[i][0]);
        
        vector<int>complete(numCourses,0);
        for(auto &x:m)
        {
            for(auto &el:x.second)
            {
                complete[el]++;
            }
        }
        
        queue<int>q;
        for(int i=0;i<numCourses;i++)
        {
            if(complete[i]==0)
                q.push(i);
        }
        
        vector<int>ans;
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            ans.push_back(x);
            for(auto &i:m[x])
            {
                complete[i]--;
                if(complete[i]==0)
                    q.push(i);
            }
        }
        if(ans.size()!=numCourses)
            return {};
        
        return ans;
    }
};
