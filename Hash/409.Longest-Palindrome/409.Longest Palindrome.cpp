class Solution {
public:
    int longestPalindrome(string s) 
    {
        vector<int>Map(256,0);
        for (int i=0; i<s.size(); i++)
            Map[s[i]]++;
        
        int sum=0;
        int flag=0;
        for (auto a:Map)
        {
            if ((a % 2) ==1)
            {
                sum+=a-1;
                flag=1;
            }
            else
                sum+=a;
        }
        
        return sum+flag;
        
    }
};
