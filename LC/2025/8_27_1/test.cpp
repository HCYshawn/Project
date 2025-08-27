class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) 
    {
        pair<int,int> mx{};
        for(auto &d : dimensions)
        {
            int x = d[0],y = d[1];
            mx = max(mx,pair(x*x+y*y,x*y));
        }
        return mx.second;
    }
};