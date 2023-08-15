class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        sort(nums.begin(),nums.end());
        int closeSum=100000;
        for(int i=0;i<nums.size()-2;i++)
        {
            int j=i+1;
            int k=nums.size()-1;
            while(j<k)
            {
                int sum=nums[i]+nums[j]+nums[k];
                if(sum==target)
                {
                    return sum;
                }
                if(abs(target-sum)<abs(target-closeSum))
                {
                    closeSum=sum;
                }
                else if(sum>target)
                {
                    k--;
                }
                else
                {
                    j++;
                }
            }
        }
        return closeSum;
    }
};
