class Solution {
public:
    bool makeStringsEqual(string s, string target) 
    {
        if (s==target) return true;
        return containOne(s) && containOne(target);
    }
    
    bool containOne(string& s)
    {        
        for (auto ch: s)
        {
            if (ch=='1')
                return true;
        }
        return false;
    }
};
