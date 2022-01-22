using LL = long long;
LL M = 1e9+7;
class Solution {
public:
    int numberOfWays(string corridor) 
    {
        int n = corridor.size();
        
        vector<int>seats;
        for (int i=0; i<n; i++)
        {
            if (corridor[i]=='S')
                seats.push_back(i);
        }
        
        if (seats.size() == 0) return 0;
        if (seats.size() == 2) return 1;
        if (seats.size() % 2 !=0) return 0;    
        
        LL ret = 1;
        for (int i=2; i+2<=seats.size(); i+=2)
        {            
            int a = seats[i]-seats[i-1];            
            ret *= (LL)a;
            ret %= M;
        }
        return ret;
    }
};
