class Solution {
    static bool cmp(string&a, string&b)
    {
        return (a+b)>(b+a);
    }
public:
    string largestNumber(vector<int>& nums) 
    {
        vector<string>strs;
        for (int i=0; i<nums.size(); i++)
            strs.push_back(to_string(nums[i]));

        sort(strs.begin(), strs.end(), cmp);

        string result;
        for (int i=0; i<strs.size(); i++)
            result+=strs[i];

        int i=0;
        while (result[i]=='0') i++;
        if (i==result.size())
            return "0";
        else
            return result.substr(i);
            
        return result;
    }
};
