class Solution {
public:
    bool isIntervalOverlap(int l1,int r1,int l2,int r2)
    {
        return max(l1,l2)<min(r1,r2);
    }

    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) 
    {
        return isIntervalOverlap(rec1[0],rec1[2],rec2[0],rec2[2])&&
                isIntervalOverlap(rec1[1],rec1[3],rec2[1],rec2[3]);
    }
};