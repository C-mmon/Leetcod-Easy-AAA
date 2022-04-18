class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid)
    {
        //declaring the size of n and m 
        //how to know that
        int n=grid[0].size(); //breadth of a vector which is number of col
        int m=grid.size(); //number of rows 
        
        //declare m*n vector for both hor and ver
        vector <vector <int>> hor (m,vector <int> (n,0)); //we need m number of rows and and inside that row there will be element n such that is filled with 0 n times
        vector <vector <int>> ver (m,vector <int> (n,0));
        
        //create horizontal array and vertical
       for(int i=0;i<m;i++)
       {
           for(int j=0;j<n;j++)
           {
               if(grid[i][j])
               {
                   hor[i][j] =(j==0)?1:hor[i][j-1]+1;
                   ver[i][j] =(i==0)?1:ver[i-1][j]+1;
               }
           }
       }
        
        
        
        //returning the answer why are we iterating from the bottom right ?
        int max=0;
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                int small=min(ver[i][j],hor[i][j]);
                //core logic
            //why writing the if condition without while loop will fail 
                while(small>max)
                {
                    if(ver[i][j-small+1]>=small && hor[i-small+1][j]>=small)
                    {
                        max=small;
                    }
                small--;
                }
            }
        }
        
        
        //return the value
        return max*max;
                    

    }
};