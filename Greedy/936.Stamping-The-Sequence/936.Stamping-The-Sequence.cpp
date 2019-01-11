class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) 
    {
        bool changed = 1;
        vector<int>results;
        
        while (changed==1)
        {
            changed = 0;
            for (int i=0; i<target.size(); i++)
            {
                if (check(stamp,target,i))
                {                    
                    for (int k=0; k<stamp.size(); k++)
                        target[i+k] = '*';       
                    results.push_back(i);
                    changed = 1;
                    break;
                }
            }
        }
        
        for (int i=0; i<target.size(); i++)        
            if (target[i]!='*') return {};
                            
        reverse(results.begin(),results.end());
        return results;
        
    }
    
    bool check(string&stamp, string&target, int pos)
    {
        int flag = 0;
        for (int i=0; i<stamp.size(); i++)
        {
            if (pos+i>=target.size()) return false;
            if (target[pos+i]=='*') continue;
            if (target[pos+i]!=stamp[i]) return false;
            flag = 1;
        }
        return flag;
    }
};
