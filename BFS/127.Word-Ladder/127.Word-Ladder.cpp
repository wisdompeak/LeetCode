class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        unordered_map<string,vector<string>>Map;
        unordered_map<string,int>visited;
        unordered_set<string>Set;
        for (int i=0; i<wordList.size(); i++)
        {
            Set.insert(wordList[i]);
            visited[wordList[i]]=0;
        }
        
        wordList.push_back(beginWord);
        for (int i=0; i<wordList.size(); i++)
        {
            string s=wordList[i];
            for (int j=0; j<s.size(); j++)
            {
                string t=s;
                for (char ch='a'; ch<='z'; ch++)
                {
                    if (ch==s[j]) continue;
                    t[j]=ch;
                    if (Set.find(t)!=Set.end())
                        Map[s].push_back(t);
                }
            }
        }
        
        queue<string>q;
        q.push(beginWord);
        int step = 1;
        
        while (!q.empty())
        {
            int len = q.size();
            while (len--)            
            {
                string s = q.front();                
                q.pop();
                for (auto t:Map[s])
                {
                    if (visited[t]==1) continue;
                    if (t==endWord) return step+1;                    
                    visited[t]=1;
                    q.push(t);                    
                }                
            }      
            step++;
        }        
        return 0;        
    }
};
