class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        unordered_map<char,int>Map;
        for (auto ch: tasks)
            Map[ch]++;
        
        int maxFreq = 0;
        for (auto a:Map)
            maxFreq = max(maxFreq, a.second);
        
        int result = (maxFreq-1)*(n+1);
        int count = 0;
        for (auto a:Map)
        {
            if (a.second == maxFreq)
                count++;
        }
        return max(result+count, (int)tasks.size());
    }
};
