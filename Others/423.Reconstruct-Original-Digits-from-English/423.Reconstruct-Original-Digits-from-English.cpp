class Solution {
public:
    string originalDigits(string s) 
    {
        vector<string>words={"zero","two","four","six","eight","five","seven","one","three","nine"};
        vector<int>nums={0,2,4,6,8,5,7,1,3,9};
        vector<int>distinct={'z','w','u','x','g','f','v','o','h','i'};
        vector<int>str(26,0);
        string result;
        
        for (auto ch:s) str[ch-'a']++;
        for (int i=0; i<10; i++)
        {
            int k = str[distinct[i]-'a'];            
            for (int j=0; j<k; j++)
                result+=to_string(nums[i]);
            for (auto ch: words[i])            
                str[ch-'a']-=k;
        }
        
        sort(result.begin(),result.end());
        
        return result;
    }
};
