//constant space approach
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pre=1,suff=1;
        int ans=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            if(pre==0) pre=1;
            if(suff==0) suff=1;

            pre=pre*nums[i];
            suff=suff*nums[nums.size()-i-1];
            ans=max(ans,max(pre,suff));
        }
        return ans;
    }
};

//Dynamic Programming approach
int maxProduct(vector<int>& nums) {
        int cur_min=1,cur_max=1;
        int ans=max(nums);
        for(int i=0;i<nums.size();i++)
        {
            if(cur_min==0) cur_min=1;
            if(cur_max==0) cur_max=1;

            int temp=cur_max*n;
            cur_max=max(n*cur_max,n*cur_min,n);
            cur_min=min(tmp,n*cur_min,n);
            ans=max(ans,max(cur_min,cur_max));
        }
        return ans;
    }
