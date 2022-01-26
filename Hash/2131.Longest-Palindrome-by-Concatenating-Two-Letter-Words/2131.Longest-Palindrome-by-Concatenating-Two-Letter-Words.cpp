class Solution {
public:
    int longestPalindrome(vector<string>& words) 
    {
        unordered_map<string,int>count1;
        unordered_map<string,int>count2;
        unordered_map<string,int>count3;
                
        for (auto str: words)
        {
            string str2 = str;
            reverse(str2.begin(), str2.end());
            
            if (str2==str)
                count3[str]++;
            else
            {
                string key = min(str2, str);
                if (key==str)
                    count1[key]++;
                else
                    count2[key]++;
            }
        }
        
        int ret = 0;
        for (auto& [key, val]: count1)
        {            
            int a = count1[key];
            int b = count2[key];
            ret += min(a,b)*2*2;
        }
        int flag = 0;
        for (auto& [key, val]: count3)
        {
            ret += val/2*2*2;
            if (val%2==1)
                flag = 1;
        }
        
        return ret+flag*2;
    }
};
