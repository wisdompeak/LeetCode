class Solution {
    int maxChoosableInteger;
    int desiredTotal;
    unordered_map<int,bool>Map;
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) 
    {
        if (desiredTotal==0) return true;
        if (desiredTotal > (1+maxChoosableInteger)*maxChoosableInteger/2)
            return false;
        
        this->maxChoosableInteger = maxChoosableInteger;
        this->desiredTotal = desiredTotal;        
        return DFS(0);
    }
    
    bool DFS(int status)
    {
        if (Map.find(status)!=Map.end()) return Map[status];
        
        int sum = 0;
        for (int i=1; i<=maxChoosableInteger; i++)
        {
            if (((status>>i)&1)==1)
                sum+=(i);
        }        
        if (sum>=desiredTotal) 
        {
            Map[status] = false;
            return false;
        }
        
        for (int i=1; i<=maxChoosableInteger; i++)
        {
            if (((status>>i)&1)==1) continue;
            int newStatus = status | (1<<i);
            if (DFS(newStatus)==false)
            {
                Map[status] = true;
                return true;            
            }
        }
        
        Map[status] = false;
        return false;
    }
};
