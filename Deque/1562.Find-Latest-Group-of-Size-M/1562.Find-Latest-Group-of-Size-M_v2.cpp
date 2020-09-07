
class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) 
    {
        const int n = arr.size();        
        vector<pair<int, int>> ranges(n, make_pair(-1, -1));
        
        int countsForM = 0;
        int ans = -1;
        for (int i = 0; i < n; ++i) 
        {
            int flipIndex = arr[i] - 1;
            
            pair<int, int> newRange{flipIndex, flipIndex};
            
            if (flipIndex < n - 1) 
            {
                auto nextRange = ranges[flipIndex + 1];
                if (nextRange.first != -1) 
                {
                    newRange.second = nextRange.second;                    
                    if (nextRange.second - nextRange.first + 1 == m) 
                        --countsForM;
                }
            }
            
            if (flipIndex > 0) 
            {
                auto prevRange = ranges[flipIndex - 1];
                if (prevRange.first != -1) 
                {
                    newRange.first = prevRange.first;                
                    if (prevRange.second - prevRange.first + 1 == m) 
                        --countsForM;
                }
            }
            
            if (newRange.second - newRange.first + 1 == m) 
                ++countsForM;
            
            if (countsForM > 0) 
                ans = i + 1;
            
            ranges[newRange.first] = newRange;
            ranges[newRange.second] = newRange;
            
        }
        
        return ans;
    }
};
