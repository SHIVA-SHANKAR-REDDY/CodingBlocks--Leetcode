class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++)
        {
            //use only if statment dcoz we want to skip for loop each time not while loop.
            //using while can lead to infinite loop.
            if(i>0 && nums[i]==nums[i-1])
            {
                continue;
            }
            int sum=nums[i];
            int j=i+1;
            int k=nums.size()-1;
            while(j<k)
            {
                if(sum+nums[j]+nums[k]==0)
                {
                    vector<int> temp({nums[i],nums[j],nums[k]});
                    result.push_back(temp);
                    while(j<k && nums[j]==nums[j+1]) j++;
                    while(k>j && nums[k]==nums[k-1]) k--;
                    j++;
                    k--;
                }
                else if(sum+nums[j]+nums[k] < 0)
                {
                    j++;
                }
                else
                {
                    k--;
                }
            } 
        }
        return result; 
    }
};
