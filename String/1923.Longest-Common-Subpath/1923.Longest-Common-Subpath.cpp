typedef uint64_t ULL;
class Solution {
    ULL base = 1e5+7;
public:
    int longestCommonSubpath(int n, vector<vector<int>>& paths) 
    {       
        int left = 0, right = 100000;
        while (left < right)
        {
            int mid = right-(right-left)/2;
            if (checkOK(paths, mid))
                left = mid;
            else
                right = mid-1;
        }
        return left;
    }

    bool checkOK(vector<vector<int>>& paths, int len)
    {

        ULL head = 1;
        for (int i = 0; i < len-1; i++)
            head = head * base;
        
        ULL hash = 0;
        unordered_set<ULL>HashSet;
        unordered_map<ULL,int>HashCount;        

        for (int k = 0; k < paths.size(); k++)
        {
            ULL hash = 0;
            unordered_set<ULL>HashSet;
            for (int i=0; i<paths[k].size(); i++)
            {
                if (i>=len)
                    hash -= paths[k][i-len] * head;
                hash = hash * base + paths[k][i];
                if (i>=len-1 && HashSet.find(hash)==HashSet.end())
                {
                    HashSet.insert(hash);
                    HashCount[hash] += 1;
                }
            }
        }

        for (auto x: HashCount)
        {
            if (x.second >= paths.size())
                return true;
        }
        return false;
    }
};
