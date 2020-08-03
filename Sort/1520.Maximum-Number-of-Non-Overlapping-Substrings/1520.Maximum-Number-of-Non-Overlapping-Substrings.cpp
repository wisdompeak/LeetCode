class Solution {
    static bool cmp(vector<int>&a, vector<int>&b)
    {
        return a[1]-a[0] < b[1]-b[0];
    }
public:
    vector<string> maxNumOfSubstrings(string s) 
    {
        vector<int>start(26,-1);
        vector<int>end(26,-1);
        for (int i=0; i<s.size(); i++) 
            if (start[s[i]-'a']==-1) start[s[i]-'a'] = i;
        for (int i=s.size()-1; i>=0; i--) 
            if (end[s[i]-'a']==-1) end[s[i]-'a'] = i;
        
        vector<vector<int>>intervals;
        for (int i=0; i<26; i++)
        {
            if (start[i]==-1) continue;
            int left = start[i], right = end[i];
            bool valid = true;
            for (int k=left; k<=right; k++)
            {
                if (start[s[k]-'a']==-1) continue;
                if (start[s[k]-'a'] < left)
                {
                    valid = false;
                    break;
                }
                right = max(right, end[s[k]-'a']);
            }
            if (valid) intervals.push_back({left, right});
        }
        
        sort(intervals.begin(), intervals.end(), cmp); 
        vector<int>flags(intervals.size(),1);

        for (int i=0; i<intervals.size(); i++)
        {
            if (flags[i]==0) continue;
            for (int j=i+1; j<intervals.size(); j++)
            {                
                if (flags[j]!=0 && intervals[i][0]>intervals[j][0] && intervals[i][1]<intervals[j][1])                
                    flags[j] = 0;                
            }
        }

        vector<string> ret ;
        for (int i=0; i<intervals.size(); i++)
            if (flags[i]) ret.push_back(s.substr(intervals[i][0], intervals[i][1]-intervals[i][0]+1));

        return ret;
    }
};
