class Solution {
public:
    
    int kadane_algo(vector <int> & nums)
    {
        int max_so_far=nums[0];
        int store_max=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(max_so_far<0)
            {
                max_so_far=0;
            }
            max_so_far+=nums[i];
            store_max=max(max_so_far,store_max);
        }
        return store_max;
    }
    int maxSubarraySumCircular(vector <int>& A)
    {
        auto total=accumulate(A.begin(),A.end(),0);
        //find the max sum of subarray using kadane 
        int non_circular_sum=kadane_algo(A);
        
        cout<<non_circular_sum<<endl;
        //find min sub array sum
        for(int i=0;i<A.size();i++)
        {
            A[i]=-A[i];
        }
        int circular_sum=total+kadane_algo(A);
        cout<<circular_sum<<endl; 
        
        //as you can see in the case of [-3,-2,-3] ans should be -2 but our non circular kadane will give 0 as the answer
        if(circular_sum==0)
        {
            return non_circular_sum;
        }
        return max(circular_sum,non_circular_sum);
    }
};