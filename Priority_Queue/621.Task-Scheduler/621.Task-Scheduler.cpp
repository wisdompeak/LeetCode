class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        if (n==0) return tasks.size();
        
        n++;
        
        unordered_map<char,int>Map;
        for (int i=0; i<tasks.size(); i++)
            Map[tasks[i]]++;
        
        priority_queue<pair<int,char>>pq;
        for (auto a:Map)
            pq.push({a.second,a.first});
                
        int count=0;
        while (pq.size()>0)
        {
            vector<pair<int,char>>temp;
            int num = pq.size();            

            for (int i=0; i<min(num,n); i++)
            {                
                if (pq.top().first>1)
                    temp.push_back({pq.top().first-1,pq.top().second});
                pq.pop();
            }
            
            for (int i=0; i<temp.size(); i++)
                pq.push(temp[i]);  
            
            if (pq.size()==0)
                count+=num;
            else
                count+=n;
            
          
        }
        
        return count;
    }
};
