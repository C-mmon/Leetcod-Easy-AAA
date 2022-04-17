class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) 
    {
        unordered_map <string,int> u_map;
        for(auto i:arr)
        {
            u_map[i]++;
        }
        for(auto i:arr)
        {
            if(u_map[i]==1 && --k ==0)
            {
                return i;
            }
        }
        return "";
    }
};