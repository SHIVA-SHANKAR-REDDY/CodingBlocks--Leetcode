class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) 
    {
        int n=cardPoints.size();
        int totalSum=0;
        for(int i=0;i<n;i++)
        {
            totalSum+=cardPoints[i];
        }
        int currSum=0;
        int windowSize=n-k;
        for(int i=0;i<windowSize;i++)
        {
            currSum+=cardPoints[i];
        }
        int minSum=currSum;
        for(int i=windowSize;i<n;i++)
        {
            currSum=currSum-cardPoints[i-windowSize]+cardPoints[i];
            minSum=min(currSum,minSum);
        }
        return totalSum-minSum;  
    }
};
