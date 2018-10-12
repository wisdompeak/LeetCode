class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        unordered_map<char,int>Map;
        for (auto ch: tasks)
            Map[ch]++;
        
        vector<int>q;
        for (auto a:Map) q.push_back(a.second);        
        sort(q.begin(),q.end());        
        
        int maxFreq = q.back();
        int idle = (maxFreq-1)*(n+1);
        
        for (int i = q.size()-1; i>=0; i--)
            idle -= min(q[i], maxFreq-1);
                
        return tasks.size()+max(0,idle);
    }
};
