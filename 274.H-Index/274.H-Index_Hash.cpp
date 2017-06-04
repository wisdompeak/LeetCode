class Solution {
public:
    int hIndex(vector<int>& citations) 
    {
        if (citations.size()==0) return 0;
        
        map<int,int>Map;
        for (int i=0; i<citations.size(); i++)
            Map[citations[i]]++;
        auto q = vector<pair<int,int>>(Map.begin(),Map.end());
        
        int sum=0;
        
        for (int i=q.size()-1; i>=0; i--)
        {
            if (q[i].first>sum+q[i].second)
                sum+=q[i].second;
            else if (q[i].first==sum+q[i].second)
                return q[i].first;
            else
                return max(q[i].first,sum);
        }
        
        return sum;        
    }
};
