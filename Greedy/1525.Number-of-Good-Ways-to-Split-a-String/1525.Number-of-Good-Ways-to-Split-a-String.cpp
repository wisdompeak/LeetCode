class Solution {
public:
    int numSplits(string s) 
    {
        int n = s.size();
        vector<int>left(n,0);
        vector<int>right(n,0);
        
        vector<int>count(26,0);
        int sum = 0;
        for (int i=0; i<s.size(); i++)
        {
            count[s[i]-'a']+=1;
            if (count[s[i]-'a']==1)
                sum+=1;
            left[i] = sum;
        }
        
        count.assign(26,0);
        sum = 0;
        for (int i=s.size()-1; i>=0; i--)
        {
            count[s[i]-'a']+=1;
            if (count[s[i]-'a']==1)
                sum+=1;
            right[i] = sum;
        }
        
        int ret = 0;
        for (int i=0; i<s.size()-1; i++)
        {
            if (left[i]==right[i+1])
                ret+=1;
        }
        return ret;
        

    }
};
