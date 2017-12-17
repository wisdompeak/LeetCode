class Solution {
public:
    string predictPartyVictory(string senate) 
    {
        string str=senate;
        int len=0;
        int count=0;
        while (senate.size()!=len)
        {
            len=senate.size();
            string s;
            for (int i=0; i<senate.size(); i++)
            {
                if (senate[i]=='R')
                {                    
                    if (count>=0) s.push_back('R');
                    count++;
                }
                else
                {                    
                    if (count<=0) s.push_back('D');
                    count--;
                }
            }
            senate = s;
        }
        
        if (senate[0]=='R')
            return "Radiant";
        else
            return "Dire";
    }
};
