class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) 
    {        
        vector<pair<int,int>>q;
        int N= position.size();
        if (N==0) return 0;
        
        for (int i=0; i<N; i++)
            q.push_back({target-position[i],speed[i]});
        sort(q.begin(),q.end());
        
        int i = 0;                
        int count = 0;
        while (i<N)
        {
            double time = q[i].first*1.0/q[i].second;
            int j = i+1;
            while (j<N && q[j].first*1.0/q[j].second<=time)
                j++;
            count++;
            i = j;
        }
        return count;
    }
};
