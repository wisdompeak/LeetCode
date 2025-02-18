class Solution {
public:
    bool maxSubstringLength(string s, int k) 
    {
        int n = s.size();        
        vector<vector<int>>pos(26);
        for (int i=0; i<n; i++)
            pos[s[i]-'a'].push_back(i);
        
        vector<pair<int, int>>intervals;
        for (int letter=0; letter<26; letter++)
        {
            if (pos[letter].empty()) continue;
            int start = pos[letter][0];
            int i = start;
            int far = pos[letter].back();
            
            bool flag = true;
            while (i<=far)
            {
                far = max(far, pos[s[i]-'a'].back());
                if (pos[s[i]-'a'][0]<start)
                {
                    flag = false;
                    break;
                }
                i++;
            }
            if (far-start+1==n) continue;
            if (flag==false) continue;
            intervals.push_back({start, far});            
        }
        
        return helper(intervals)>=k;
    }

    bool contains(pair<int,int>a, pair<int,int>b)
    {
        return a.first<b.first && a.second>b.second;
    }    
    
    int helper(vector<pair<int, int>> &intervals) {        
        int n = intervals.size();
        vector<int>check(n, 1);
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
            {
                if (i==j) continue;
                if (contains(intervals[i],intervals[j]))
                    check[i] = 0;
                if (contains(intervals[j],intervals[i]))
                    check[j] = 0;
            }
        int ret = 0;
        for (int i=0; i<n; i++) ret += check[i];
        return ret;
    }


};
