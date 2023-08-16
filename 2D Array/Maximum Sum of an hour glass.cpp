class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int maxSum=INT_MIN;
	    for(int i=0;i<m-2;i++)
	    {
		    for(int j=0;j<n-2;j++)
		    {
			    int curr_sum=0;
			    curr_sum=curr_sum+grid[i][j]+grid[i+2][j];
			    curr_sum=curr_sum+grid[i][j+1]+grid[i+1][j+1]+grid[i+2][j+1];
			    curr_sum=curr_sum+grid[i][j+2]+grid[i+2][j+2];
			    maxSum=max(curr_sum,maxSum);
		    }
	    }
	return maxSum;
    }
};
