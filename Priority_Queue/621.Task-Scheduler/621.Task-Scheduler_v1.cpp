class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        unordered_map<char,int>Map;
        for (auto ch: tasks)
            Map[ch]++;
        priority_queue<int>pq;
        for (auto a:Map) pq.push(a.second);
        
        n++;
        int count = 0;
        while (pq.size()>0)
        {                            
            int k = min(n, (int)pq.size());            
            
            vector<int>temp;
            for (int i=0; i<k; i++)
            {
                int f = pq.top();
                pq.pop();
                f--;
                if (f!=0) temp.push_back(f);
            }
            if (temp.size()>0)
                count+=n;
            else
                count+=k;
            
            for (auto x: temp)
                pq.push(x);
        }
        return count;        
    }
};
