class Solution {
    struct cmp
    {
        bool operator()(pair<int,int>a,pair<int,int>b)
        {
            return a.second<b.second;
        }        
    };
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) 
    {        
        vector<pair<int,int>>Proj;
        for (int i=0; i<Profits.size(); i++)
            Proj.push_back({Capital[i],Profits[i]});
        sort(Proj.begin(),Proj.end());
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>pq;
        
        int count=0;
        int i=0;
        while (count<k)
        {
            while (i<Proj.size() && W>=Proj[i].first)
            {
                pq.push(Proj[i]);
                i++;
            }
            if (pq.size()!=0)
            {
                W+=pq.top().second;
                count++;
                pq.pop();            
            }
            else
                break;
        }
        
        return W;
    }
};
