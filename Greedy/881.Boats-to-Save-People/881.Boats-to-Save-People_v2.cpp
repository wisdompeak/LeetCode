class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) 
    {
        vector<int>p(limit+1,0);
        for (int w: people)
            p[w]++;
        
        int count = 0;
        for (int x = limit; x>0; x--)   // weight of the heaviest guy up to now
        {
            for (int i = p[x]; i>0; i--)
            {
                count++;
                p[x]--;
                
                int y = limit-x;
                while (y>0 && p[y]==0) y--;
                if (y>0) p[y]--;
                if (x==y) i--;
            }
        }
        return count;
    }
};
