class Solution {
    int m;
public:
    string minAbbreviation(string target, vector<string>& dictionary) 
    {
        if (dictionary.size()==0)
            return to_string(target.size());
        this->m = target.size();
        
        unordered_set<string>Set;
        for (auto word: dictionary)
        {
            if (word.size()==m)
                Set.insert(word);
        }
        
        vector<pair<int,int>>masks;
        for (int state = 0; state < (1<<m); state++)        
            masks.push_back({len(state), state});
        sort(masks.begin(), masks.end());
        
        for (auto x: masks)
        {
            int mask = x.second;
            string abbr = getAbbr(target, mask);
            int flag = 1;
            
            for (auto word: Set)
            {
                string s = getAbbr(word, mask);
                if (s==abbr)
                {
                    flag = 0;
                    break;
                }                
            }
            if (flag==1) return abbr;            
        }
        
        return "";        
    }
    
    string getAbbr(string& word, int mask)
    {
        string ret;
        for (int i=0; i<m; i++)
        {
            if ((mask>>i)&1)
                ret.push_back(word[i]);
            else
            {
                int j = i;
                while (j<m && ((mask>>j)&1)==0)
                    j++;
                ret  += to_string(j-i);
                i = j-1;
            }
        }
        return ret;
    }
    
    int len(int mask)
    {
        int count = 0;
        for (int i=0; i<m; i++)
        {
            if ((mask>>i)&1)
                count++;
            else
            {
                int j = i;
                while (j<m && ((mask>>j)&1)==0)
                    j++;
                count += 1;
                i = j-1;
            }
        }
        return count;
        
    }
};
