class Solution {
public:
    int removeAlmostEqualCharacters(string word) 
    {
        int n = word.size();
        int ret = 0;
        for (int i=0; i<n; )
        {
            int j = i+1;
            while (j<n && abs(word[j]-word[j-1])<=1)
                j++;
            ret += (j-i)/2;
            i = j;
        }
        return ret;
        
    }
};
