class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) 
    {
               int total = accumulate(arr.begin() , arr.end() , 0);

        cout<<total<<endl;
        if(total%3!=0)
        {
            return false;
        }
        int count=0;
        int sum=0;
        int target=total/3;
        //if we can find sum thrice in the array that means it can be divided
        for(int i=0;i<arr.size();i++)
        {
            sum+=arr[i];
            if(sum==target)
            {
                count++;
                sum=0;
            }
        }
          return count>=3;

    }
};