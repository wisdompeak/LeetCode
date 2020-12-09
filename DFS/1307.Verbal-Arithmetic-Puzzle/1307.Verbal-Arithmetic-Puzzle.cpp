class Solution {            
    int Map[128];
    int visited[10];
public:
    bool isSolvable(vector<string>& words, string result) 
    {       
        for (int i=0; i<128; i++)
            Map[i] = -1;
        reverse(result.begin(),result.end());
        for (int i=0; i<words.size(); i++)
        {
            reverse(words[i].begin(),words[i].end());
            if (words[i].size()>result.size())
                return false;
        }            
        
        return DFS(words,result,0,0,0);
    }
    
    bool DFS(vector<string>& words, string result, int j, int i, int sum)
    {
        if (j==result.size())
        {
            if (sum!=0)
                return false;
            if (result.size()>1 && Map[result.back()]==0)
                return false;
            return true;
        }

        if (i==words.size())
        {
            if (Map[result[j]]!=-1)
            {
                if (Map[result[j]]!=sum%10)
                    return false;
                else
                    return DFS(words,result,j+1,0,sum/10);
            }
            else
            {
                if (visited[sum%10]==1)
                    return false;
                
                Map[result[j]] = sum%10;
                visited[sum%10] = 1;   
                if  (DFS(words,result,j+1,0,sum/10))
                    return true;
                Map[result[j]] = -1;
                visited[sum%10] = 0;
                return false;                                
            }           
        }             
                    
        if (j>=words[i].size())
        {            
            return DFS(words,result,j,i+1,sum);        
        }   
        
        char ch = words[i][j];
        if (Map[ch]!=-1)
        {
            if (words[i].size()>1 && j==words[i].size()-1 && Map[ch]==0)
                return false;
            return DFS(words,result,j,i+1,sum+Map[ch]);
        }
        else
        {
            for (int d=0; d<=9; d++)
            {
                if (visited[d]==1) 
                    continue;
                if (d==0 && words[i].size()>1 && j==words[i].size()-1)
                    continue;
                Map[ch] = d;
                visited[d] = 1;
                if (DFS(words,result,j,i+1,sum+d))
                    return true;                
                Map[ch] = -1;
                visited[d] = 0;
            }
            return false;
        }
        
        return true;
    }
};
