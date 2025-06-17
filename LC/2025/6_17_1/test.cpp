class Solution {
public:
    int findClosestNumber(vector<int>& nums) 
    {
        int ret = INT_MAX;
        for(int i = 0;i<nums.size();i++)
        {
            if(abs(nums[i])<abs(ret)||abs(nums[i])==abs(ret)&&nums[i] > 0)
                ret = nums[i];
        }    
        return ret;
    }
};