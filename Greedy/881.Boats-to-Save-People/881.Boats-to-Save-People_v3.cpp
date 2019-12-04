class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) 
    {
        vector<int>p(limit+1,0);
        for (int w: people)
            p[w]++;
        
        int count = 0;
        int y = 1;
        for (int x = limit; x>0; x--)
        {
            for (int i = p[x]; i>0; i--)
            {
                count++;
                p[x]--;
                                
                while (y+x<=limit && p[y]==0) y++;
                if (y+x<=limit && p[y]>0)
                {
                    p[y]--;                
                    if (x==y) i--;
                }
                
            }
        }
        return count;
    }
};
