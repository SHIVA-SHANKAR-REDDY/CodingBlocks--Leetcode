class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int start=0,end=n-1;
        //find Transpose of a matrix
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
      //Inverse the matrix
        while(start<end)
        {
            for(int j=0;j<n;j++)
            {
                swap(matrix[j][start],matrix[j][end]);
            }
            start++;
            end--;
        }
    }
};
