class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        vector<vector<int>>visit;
        vector<int>temp(8,0);
        while(N--)
        {
            for(int i=1;i<cells.size()-1;i++)
            {
                if(cells[i+1]==cells[i-1])
                    temp[i]=1;
                else
                    temp[i]=0;
            }
            if(visit.size()!=0 && visit.front()==temp)
            {
                return visit[N%visit.size()];
            }
            visit.push_back(temp);
            cells=temp;
        }
        return cells;
    }
};
