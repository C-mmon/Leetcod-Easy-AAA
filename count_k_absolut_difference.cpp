class Solution {
public:
    int countKDifference(vector<int>& nums, int k) 
    {
        
        //counting sort
        vector <int> store (101,0);
        for(int i=0;i<nums.size();i++)
        {
            store[nums[i]]++;
        }
        int ans=0;
        
        for (int i = 0; i + k < 101; i++) {
            ans += store[i] * store[i + k];
        }
        return ans;

        
    }
};