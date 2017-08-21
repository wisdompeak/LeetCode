class Solution {
public:
    int maxProduct(vector<string>& words) 
    {
        vector<int>codes(words.size(),0);
        
        for (int i=0; i<words.size(); i++)
        {
            string s=words[i];
            int code=0;
            for (int j=0; j<s.size(); j++)
            {
                int x=s[j]-'a';
                code = (code|(1<<x));
            }
            codes[i]=code;
        }        
        
        
        int result=0;
        for (int i=0; i<words.size(); i++)
         for (int j=0; j<words.size(); j++)
         {
             if ((codes[i]&codes[j])!=0) continue;
             result=max(result,(int)words[i].size()*(int)words[j].size());
         }
        return result;
    }
};
