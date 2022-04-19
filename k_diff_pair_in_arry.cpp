class Solution {
public:
    int findPairs(vector<int>& nums, int k) 
    {
        set<pair<int,int>>s;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(abs(nums[j]-nums[i])==k)
                {
                    if(s.find(make_pair(nums[i],nums[j]))==s.end()  && s.find(make_pair(nums[j],nums[i]))==s.end() )
                    {
                        s.insert(make_pair(nums[i],nums[j])); 
                    }
                    
                             
                }
            }
        }
        return s.size();
        
    }
};