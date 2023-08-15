class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp(n+1,0);
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            if(temp[nums[i]]==1)
            {
                ans.push_back(nums[i]);
            }
            temp[nums[i]]++;
        }
        return ans;
    }
};
