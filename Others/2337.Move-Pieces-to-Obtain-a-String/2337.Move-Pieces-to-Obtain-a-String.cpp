class Solution {
public:
    bool canChange(string start, string target) 
    {
        string s, t;        
        
        vector<int>pos1;
        vector<int>pos2;
        for (int i=0; i<start.size(); i++)
        {
            char ch = start[i];
            if (ch!='_')
            {
                s.push_back(ch);
                pos1.push_back(i);
            }
        }
        
        for (int i=0; i<target.size(); i++)
        {
            char ch = target[i];
            if (ch!='_')
            {
                t.push_back(ch);
                pos2.push_back(i);
            }
        }
               
        if (s!=t) return false;
        
        for (int i=0; i<pos2.size(); i++)
        {
            if (t[i]=='L')
            {
                if (pos1[i] < pos2[i]) return false;
            }
            else if (t[i]=='R')
            {
                if (pos1[i] > pos2[i]) return false;
            }
        }
        
        return true;
    }
};
