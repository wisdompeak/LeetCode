class Solution {
    int next[1001][26];
public:
    int shortestWay(string source, string target) 
    {
        int n = source.size();
        source = "#" + source;
        
        for (int k=0; k<26; k++)
            next[n][k] = -1;
        
        for (int i=n-1; i>=0; i--)      
        {
            for (int k=0; k<26; k++)
                next[i][k] = next[i+1][k];
            next[i][source[i+1]-'a'] = i+1;
            
        }
        
        int j = 0;
        int count = 1;
        for (int i=0; i<target.size(); i++)
        {               
            if (next[j][target[i]-'a'] != -1)
            {
                j =  next[j][target[i]-'a'];
            }
            else
            {
                if (j==0) return -1;
                j = 0;
                count++;
                i--;
            }                
        }
        return count;        
    }
};
