class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        if (n==0) return tasks.size();
            
        unordered_map<char,int>Map;
        for (int i=0; i<tasks.size(); i++)
            Map[tasks[i]]++;
        
        n++;
        
        priority_queue<pair<int,char>>pq;
        for (auto a:Map)
            pq.push({a.second,a.first});
        
        int result=0;
        while (pq.size()>0)
        {
            vector<pair<int,char>>temp;
            for (int i=0; i<n; i++)
            {
                if (pq.empty() && temp.size()>0) 
                {
                    result++;
                    continue;
                }
                else if (pq.empty() && temp.size()==0) 
                {
                    break;
                }
                
                int num=pq.top().first;
                char job=pq.top().second;
                if (num>=2)                
                    temp.push_back({num-1,job});
                pq.pop();
                result++;
            }
            for (int i=0; i<temp.size(); i++)
                pq.push(temp[i]);
        }
        
        return result;
        
    }
};
