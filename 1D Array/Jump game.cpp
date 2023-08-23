//recursion approach :
//tc : O(N^N) ~ exponential
//sc : O(N)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        return create(nums, 0); 
    }
private:
    bool create(vector<int>& nums, int idx) {
        if(idx == nums.size() -1) return true;  //if I reach the last index, I should return true;
        if(nums[idx] == 0) return false; //if at any  point I reach an index with jump value = 0
		//,I'll get stuck and hence will return a false.
        
        int reach = idx + nums[idx]; //the max jump that I can make
		//I can make jumps ranging from idx + 1, till reach, and hence will run a loop
		//to cover all those possbile jumps
        for(int jump=idx + 1; jump <= reach; jump++) {
		//if true, it means taking this jump led me to the last index.
            if(jump < nums.size() && create(nums, jump)) 
                return  true; 
        }
			
		//if I reach  here,  it means none of the jumps led  me to the  last index 
		//and hence returning, false.
        return  false;
    }
};
//memoized :
//tc : O(N* N) -> for each index, I can have at max N jumps, hence O(N* N).
//sc : O(N) + O(N) -> stack space plus dp array size.
class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return create(nums, 0, dp);
    }
private:
    bool create(vector<int>& nums, int idx, vector<int>& dp) {
        if(idx == nums.size() -1) return true;
        if(nums[idx] == 0) return false;
        
        if(dp[idx] != -1) return dp[idx]; //overlapping subproblems
        int reach = idx + nums[idx];
        for(int jump=idx + 1; jump <= reach; jump++) {
            if(jump < nums.size() && create(nums, jump, dp)) 
                return dp[idx] = true; //memoizing for particular index.
        }
        
        return dp[idx] = false; //memoizing for particular index.
    }
};
dp(tabulation) solution, so that extra O(N) space can be chucked out.

// tc : O(N* N)
// sc : O(N) -> dp array size
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[n-1] = 1; //base case;
        
        for(int idx = n-2; idx >= 0; idx--) {
            if(nums[idx] == 0) {
                dp[idx] = false;
                continue;   
            }
            
            int flag = 0;
            int reach = idx + nums[idx];
            for(int jump=idx + 1; jump <= reach; jump++) {
                if(jump < nums.size() && dp[jump]) {
                    dp[idx] = true;
                    flag = 1;  
                    break;
                }
            }
            if(flag == 1) 
                continue;
           
            dp[idx] = false;
			
        }
        return dp[0]; 
    }

};
//kadanes approach
//tc : O(N)
//sc : O(1)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        //it shows at max what index can I reach.
        //initially I can only reach index 0, hence reach = 0
        int reach = 0; 
    
        for(int idx = 0; idx < nums.size(); idx++) {
            //at every index I'll check if my reach was atleast able to 
            //reach that particular index.
            
            //reach >= idx -> great, carry on. Otherwise, 
            if(reach < idx) return false;
            
            //now as you can reach this index, it's time to update your reach
            //as at every index, you're getting a new jump length.
            reach = max(reach, idx + nums[idx]);
        }
        
        //this means that you reached till the end of the array, wohooo!! 
        return true;
        
    }
};
