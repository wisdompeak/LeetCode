class Solution {
public:
    string minAbbreviation(string target, vector<string>& dictionary) 
    {
        if (dictionary.size()==0)
            return to_string(target.size());        
                
        unordered_set<string>Set;                
        int N = target.size();
        
        for (auto str:dictionary)
        {
            if (str.size()==N)
                Set.insert(str);
        }               
                
        vector<pair<int,int>>masks;        
        for (int i=0; i<(1<<N); i++)        
            masks.push_back({len(i,N),i});             
        sort(masks.begin(),masks.end());
        
        for (int i=0; i<masks.size(); i++)
        {
            int mask = masks[i].second;
            string a = abbr(target,mask);
            int flag = 1;
            
            for (auto word:Set)
            {
                string b = abbr(word, mask);
                if (a==b)
                {
                    flag = 0;
                    break;
                }
            }            
            if (flag == 1) return a;
        }
    }
    
    
    int len(int mask, int N)
    {
        int count = 0;
        for (int i=0; i<N; i++)
        {
            if (((mask>>(N-1-i))&1)==1)        
                count++;
            else
            {
                int j = i+1;
                while (j<N && ((mask>>(N-1-j))&1)==0)
                    j++;
                count++;
                i = j-1;
            }
        }        
        return count;
    }
    
    string abbr(string A, int mask)
    {       
        string result;
        int N = A.size();
        
        for (int i=0; i<N; i++)
        {
            if (((mask>>(N-1-i))&1)==1)
                result.push_back(A[i]);
            else
            {
                int j = i+1;
                while (j<N && ((mask>>(N-1-j))&1)==0)
                    j++;
                result += to_string(j-i);
                i = j-1;
            }
        }
        return result;
    }
    
};
