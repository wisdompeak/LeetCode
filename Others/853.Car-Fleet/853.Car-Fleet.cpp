class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) 
    {                
        int N= position.size();
        
        vector<pair<int,int>>q;
        for (int i=0; i<N; i++)
            q.push_back({position[i],speed[i]});
        sort(q.begin(),q.end());        

        int count=0;
        for (int i=N-1; i>=0; i--)
        {
            double T = (target-q[i].first)*1.0/q[i].second;
            int j = i-1;
            while (j>=0 && (target-q[j].first)*1.0/q[j].second <= T)            
                j--;
            count++;
            i = j+1;
        }        
        return count;
    }
};
