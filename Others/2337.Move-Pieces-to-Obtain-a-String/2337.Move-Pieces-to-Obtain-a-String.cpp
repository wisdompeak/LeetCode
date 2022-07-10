class Solution {
public:
    bool canChange(string start, string target) 
    {
        int j = 0;
        for (int i=0; i<start.size(); i++)
        {
            if (start[i]=='_') continue;
            while (j<target.size() && target[j]=='_')
                j++;
            if (j==target.size()) return false;
            
            
            if (start[i]!=target[j])
                return false;            
            if (start[i]=='L' && i<j)
                return false;            
            if (start[i]=='R' && i>j)
                return false;
            
            j++;
        }
        
        for (int k=j; k<target.size(); k++)
            if (target[k]!='_')
                return false;
        
        return true;
    }
};
