class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        priority_queue<pair<int,int>>pq;
        vector<int>ans;
        for(auto &it:m)
        {
            //ans.push_back(it.first);
            pq.push(make_pair(it.second,it.first));
        }
        
        for(int i=0;i<k;i++)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};
