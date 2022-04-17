class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        int count=0;
        //intialise an array with 0 and size of intial array 
        vector <int> temp (nums.size(),0);
        
        
        temp[0]=nums[0];
        //storing the previous value of the array
        for(int i=1;i<nums.size();i++)
        {
            temp[i]=temp[i-1]+nums[i];
        }
        unordered_map <int,int> u_map;
        for(int i=0;i<nums.size();i++)
        {
            if(temp[i]==k)
            {
                count++;
            }
            if(u_map.find(temp[i]-k)!=u_map.end())
            {
                count+=u_map[temp[i]-k];
            }
            u_map[temp[i]]++;
        }
        return count;
    }
};