class Solution {
    static bool cmp(string a, string b)
    {
        string c=a+b;
        string d=b+a;
        return stoll(c)>stoll(d);
    }
public:
    string largestNumber(vector<int>& nums) 
    {
        vector<string>Nums;
        for (int i=0; i<nums.size(); i++)
            Nums.push_back(to_string(nums[i]));
            
        sort(Nums.begin(),Nums.end(),cmp);
        
        string result;
        for (int i=0; i<Nums.size(); i++)
            result+=Nums[i];
            
        int i=0;
        while (result[i]=='0') i++;
        if (i==result.size())
            return "0";
        else
            return result.substr(i);
            
        return result;
    }
};
