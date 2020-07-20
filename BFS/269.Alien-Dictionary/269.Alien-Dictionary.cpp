class Solution {
public:
    string alienOrder(vector<string>& words) 
    {
        unordered_map<char,unordered_set<char>>Next;
        unordered_map<char,int>inDegree;
        
        for (int i=0; i<words.size(); i++)
            for (int j=0; j<words[i].size(); j++)
                inDegree[words[i][j]] = 0;
        
        for (int i=1; i<words.size(); i++)
        {
            string word1 = words[i-1];
            string word2 = words[i];
            
            if (word1.size()>word2.size() && word1.substr(0, word2.size())==word2) return "";
            
            for (int i=0; i<min(word1.size(),word2.size()); i++)
            {
                if (word1[i]==word2[i]) continue;                
                if (Next[word1[i]].find(word2[i])==Next[word1[i]].end())
                {
                    Next[word1[i]].insert(word2[i]);
                    inDegree[word2[i]]++;
                }
                break;
            }            
        }
                        
        queue<char>q;
        for (auto a:inDegree) 
            if (a.second==0) q.push(a.first);
        string result;
        
        while (!q.empty())
        {
            char current = q.front();
            q.pop();
            result+=current;
            
            for (auto a: Next[current])
            {
                inDegree[a]--;
                if (inDegree[a]==0)                
                    q.push(a);                
            }            
        }
               
        if (result.size()==inDegree.size())
            return result;
        else
            return "";
    }
};
