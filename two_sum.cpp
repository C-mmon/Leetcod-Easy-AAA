class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        //value and its index
        unordered_map <int,int> ump;
        
        for(int i=0;i<nums.size();i++)
        {
            if(ump.find(target-(nums[i])) != ump.end())
            {
                return {i,ump.at(target-(nums[i]))};
            }
            else
            {
                ump.insert({nums[i],i});
            }
        }
                
      return {};
   }
               
};