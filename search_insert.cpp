class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        int low=0;
        int high=nums.size()-1;
        while(high>=low)
        {
            int mid=(low+high)/2;
            if(target==nums[mid])
                return mid;
            else if(target>nums[mid])
                low=mid+1;
            else
                high=mid-1;
        }
        return low;
    }
};


//question to ask
//why are we returning low 

        // (1) At this point, low > high. That is, low >= high+1
        // (2) From the invariant, we know that the index is between [low, high+1], so low <= high+1. Follwing from (1), now we know low == high+1.
        // (3) Following from (2), the index is between [low, high+1] = [low, low], which means that low is the desired index
        //     Therefore, we return low as the answer. You can also return high+1 as the result, since low == high+1