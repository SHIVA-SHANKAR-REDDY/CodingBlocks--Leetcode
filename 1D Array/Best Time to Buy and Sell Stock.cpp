class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=prices[0];
        int m=0;
        for(int i=1;i<prices.size();i++)
          {
           if(buy>prices[i])
           {
               buy=prices[i];
           }
           else if(prices[i]-buy>m)
           {
               m=prices[i]-buy;
           }
        }
        return m;
    }
};
