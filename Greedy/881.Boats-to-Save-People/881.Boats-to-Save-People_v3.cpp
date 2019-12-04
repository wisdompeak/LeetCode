class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) 
    {
        vector<int>p(limit+1,0);
        for (int w: people)
            p[w]++;
        
        int count = 0;
        int x = limit;
        int y = 1;
        
        while (x>0)
        {
            while (x>0 && p[x]==0)
                x--;
            if (x==0) break;
            count++;
            p[x]--;
            
            while (y+x<=limit && p[y]==0) 
                y++;
            if (y+x<=limit && p[y]>0) 
                p[y]--;
        }
                
        return count;
    }
};
