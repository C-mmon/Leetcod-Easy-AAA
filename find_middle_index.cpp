class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        if(nums.size()==1)
        {
            return 0;
        }
        int n=nums.size();
        vector <int> prefix (n,0);
        vector <int> suffix (n,0);
        
        prefix[0]=nums[0];
        suffix[n-1]=nums[n-1];
        
        for(int i=1;i<n;i++)
        {
            prefix[i]=prefix[i-1]+nums[i];
        }
        for(int i=n-2;i>=0;i--)
        {
            suffix[i]=suffix[i+1]+nums[i];

        }
        for(int i=0;i<n;i++)
        {
            if(i==0 && suffix[i+1]==0)
            {
                return i;
            }
            if(i==n-1 && prefix[n-2]==0)
            {
                return i;
            }
            if(suffix[i]==prefix[i])
            {
                return i;
            }
        }
        return -1;
    }
};