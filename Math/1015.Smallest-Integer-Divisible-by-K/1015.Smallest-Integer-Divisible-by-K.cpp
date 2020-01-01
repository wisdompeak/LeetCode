class Solution {
public:
    int smallestRepunitDivByK(int K) 
    {
        int N = 1;
        int count = 1;
        unordered_set<int>Set;
        
        while (1)
        {
            int r = N%K;
            if (r==0)
                return count;
            if (Set.find(r)!=Set.end())
                return -1;
            
            Set.insert(r);
            N = r*10+1;
            count++;
        }
        
        return -1;        
    }
};
