class Solution {
public:
    bool canBeValid(string s, string locked) 
    {
        int n = s.size();
        if (n%2!=0) return false;
        
        if (!checkRight(s, locked)) return false;
        if (!checkLeft(s, locked)) return false;
        return true;
        
    }

    bool checkRight(string s, string locked)
    {
        int unmatched = 0;
        int count = 0;
        
        for (int i = 0; i<s.size(); i++)
        {
            if (s[i]=='(')
                unmatched++;
            else
                unmatched--;

            if (locked[i]=='0' && s[i]==')')            
                count++;
            
            if (unmatched < 0)
            {
                if (count==0) return false;
                unmatched += 2;
                count--;
            }
        }
        return true;
    }
    
    bool checkLeft(string s, string locked)
    {
        int unmatched = 0;
        int count = 0;
        
        for (int i = s.size()-1; i>=0; i--)
        {
            if (s[i]==')')
                unmatched++;
            else
                unmatched--;

            if (locked[i]=='0' && s[i]=='(')            
                count++;
            
            if (unmatched < 0)
            {
                if (count==0) return false;
                unmatched += 2;
                count--;
            }
        }
        return true;
    }
};
