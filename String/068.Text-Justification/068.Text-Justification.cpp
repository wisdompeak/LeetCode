class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) 
    {
        vector<string>rets;
        
        for (int i=0; i<words.size(); i++)
        {
            int j = i, count = 0;
            while (j<words.size() && count <= maxWidth)
            {
                if (count==0)
                    count += words[j].size();
                else
                    count += 1 + words[j].size();\
                j++;
            }
            j--;
                        
            if (count > maxWidth)
            {
                count -= 1 + words[j].size();
                j--;
            }
            
            if (j==words.size()-1)
            {
                string temp;
                for (int k=i; k<=j; k++)
                    temp += words[k]+" ";
                temp.pop_back();
                temp += addspace(maxWidth - temp.size());
                rets.push_back(temp);
            }                
            else
            {
                rets.push_back(printline(words, i, j, maxWidth));
            }
                
            i = j;                        
        }
        return rets;
    }
    
    string printline(vector<string>&words, int a, int b, int maxWidth)
    {
        if (a==b)
        {
            return words[a] + addspace(maxWidth-words[a].size());
        }
        
        int total = 0;
        for (int i=a; i<=b; i++) total += words[i].size();
        int space = (maxWidth - total)/max(1, b-a);
        int extra = maxWidth - total - space * (b-a);
        
        string ret;
        for (int i=a; i<a+extra; i++)    
            ret += words[i] + addspace(space+1);        
        for (int i=a+extra; i<b; i++)        
            ret += words[i] + addspace(space);
        
        ret+=words[b];              
        return ret;        
    }
    
    string addspace(int k)
    {
        string ret;
        for (int i=0; i<k; i++)
            ret+=" ";
        return ret;
    }
};
