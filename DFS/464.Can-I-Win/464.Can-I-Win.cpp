class Solution {
    unordered_map<int,bool>Map;
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) 
    {
        if (desiredTotal<=maxChoosableInteger) return true;
        if ((1+maxChoosableInteger)*maxChoosableInteger/2<desiredTotal) return false;
        
        int status=0;
        return DFS(maxChoosableInteger, desiredTotal, status);
    }
    
    bool DFS(int& maxChoosableInteger, int desiredTotal, int status) 
    {
        if (desiredTotal<=0) return false;
        if (Map.find(status)!=Map.end()) return Map[status];
        
        for (int i=1; i<=maxChoosableInteger; i++)
        {
            if (((status>>i)&1)==1) continue;
            if (DFS(maxChoosableInteger,desiredTotal-i, status|(1<<i)))
                Map[status]=false;
            else
            {
                Map[status]=true;
                return true;
            }
        }
        return false;
    }
};
