class Solution {
public:
    string minWindow(string s, string t) 
    {
        vector<int>Table(256,0);
        for (int i=0; i<t.size(); i++)
            Table[t[i]]++;
        int COUNT=t.size();
            
        vector<int>Map(256,0);

        int i=0;
        int j=0;
        int count=0;
        
        string result;
        int len=INT_MAX;
        
        for (int j=0; j<s.size(); j++)
        {
            if (Table[s[j]]==0)
                Map[s[j]]++;
            else 
            {
                Map[s[j]]++;
                if (Map[s[j]]<=Table[s[j]])
                    count++;
                
                if (count==COUNT)
                {
                    while (i<j && Map[s[i]]>Table[s[i]])
                    {
                        Map[s[i]]--;
                        i++;
                    }
                    if (len>j-i+1)
                    {
                        cout<<i<<" "<<j<<endl;
                        len=j-i+1;
                        result = s.substr(i,len);
                    }
                    Map[s[i]]--;
                    i++;
                    count--;
                }
            }
        }
        
        return result;
        
    }
};
