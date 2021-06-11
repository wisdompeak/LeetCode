class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) 
    {
        vector<pair<int,int>>proj;
        for (int i=0; i<Profits.size(); i++)
            proj.push_back({Capital[i],Profits[i]});
        sort(proj.begin(),proj.end());
        
        priority_queue<int>pq;
        
        int count = 0;
        int i=0;
        while (count<k)
        {
            while (i<proj.size() && proj[i].first<=W)
            {
                pq.push(proj[i].second);
                i++;
            }
            if (pq.size()!=0)
            {
                W+=pq.top();
                count++;
                pq.pop();
            }
            else
                break;
        }        
        return W;
    }
};
