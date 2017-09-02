class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) 
    {
        int N=s.size();
        vector<int>p(N,0);
        
        for (int i=0; i<dict.size(); i++)
        {
            int len=dict[i].size();
            string str=dict[i];
            for (int j=0; j<=N-len; j++)
            {
                if (s.substr(j,len)==str)
                {
                    for (int k=j; k<j+len; k++)
                        p[k]=1;
                }
            }
        }
        
        /*
        for (int i=0; i<p.size(); i++)
            cout<<p[i];
        */
        
        string result;
        int i=0;
        while (i<N)
        {
            while (i<N && p[i]==0)
            {
                result+=s[i];
                i++;
            }                
            
            if (i==N)            
                return result;
            else
            {
                result+="<b>";
                int i0=i;
                while (i<N && p[i]==1)
                    i++;
                result+=s.substr(i0,i-i0);
                result+="</b>";
            }
        }
        
        return result;
    }
};
