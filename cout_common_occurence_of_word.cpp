class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) \
    {
                unordered_map<string, int> freq1, freq2; 
        for (auto& s : words1) ++freq1[s]; 
        for (auto& s : words2) ++freq2[s]; 
        int ans = 0; 
        for (auto i : freq1) 
            if (i.second == 1 && freq2[i.first] == 1) 
            {
                ++ans; 
            }
        return ans; 
        
    }
};