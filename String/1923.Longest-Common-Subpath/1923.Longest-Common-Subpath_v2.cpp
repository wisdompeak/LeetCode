typedef uint64_t ULL;
typedef pair<ULL,ULL> PULL;
class Solution {
    ULL base1 = 1e5;
    ULL base2 = 1e5+7;
public:
    int longestCommonSubpath(int n, vector<vector<int>>& paths) 
    {
        int left = 0, right = 100000;
        while (left < right)
        {
            int k = right-(right-left)/2;
            if (checkOK(paths, k))   // if there is a common subarray of length k 
                left = k;
            else
                right = k-1;                
        }
        return left;
    }
    
    bool checkOK(vector<vector<int>>& paths, int len)
    {        
        map<PULL, int>HashCount;
        
        ULL head1 = 1;
        ULL head2 = 1;
        for (int i=0; i<len-1; i++)
        {
            head1 = head1 * base1;
            head2 = head2 * base2;
        }
            
        
        for (int k=0; k<paths.size(); k++)
        {
            set<PULL>HashSet;
            ULL hash1 = 0;
            ULL hash2 = 0;
            
            for (int i=0; i<paths[k].size(); i++)
            {
                if (i>=len)
                {
                    hash1 -= paths[k][i-len] * head1;
                    hash2 -= paths[k][i-len] * head2;
                }
                    
                hash1 = hash1 * base1 + paths[k][i];
                hash2 = hash2 * base2 + paths[k][i];
                
                if (i>=len-1 && HashSet.find({hash1,hash2})==HashSet.end())
                {
                    HashSet.insert({hash1,hash2});
                    HashCount[{hash1,hash2}]++;
                }                    
            }            
        }
        
        for (auto x: HashCount)
        {
            if (x.second == paths.size())
                return true;
        }
        return false;        
    }
};
