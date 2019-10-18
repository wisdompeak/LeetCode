class Solution {
public:
    int kSimilarity(string A, string B) 
    {
        if (A==B) return 0;
        
        queue<string>q;
        q.push(A);
        
        int step = -1;
        unordered_set<string>visited;
        visited.insert(A);
        
        while (!q.empty())
        {
            int len = q.size();
            step++;
            
            while (len--)
            {
                string str = q.front();
                q.pop();
                
                int i = 0;
                while (str[i]==B[i])
                    i++;
                
                for (int j=i+1; j<str.size(); j++)
                {
                    if (str[j]!=B[i])
                        continue;
                    
                    string newStr = str;
                    swap(newStr[i], newStr[j]);
                    
                    if (newStr==B)
                        return step+1;
                    
                    if (visited.find(newStr)==visited.end())
                    {
                        q.push(newStr);
                        visited.insert(newStr);
                    }
                    
                    //cout<<str<<": "<<newStr<<endl;
                }
            }
            
        }
        
        return -1;
        
    }
};
