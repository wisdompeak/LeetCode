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
    
    
    int helper(vector<pair<int, int>> &intervals) {        
        sort(intervals.begin(), intervals.end(), [](pair<int, int> a, pair<int, int> b) {
            return a.second < b.second;
        });

        int count = 0;
        int far = INT_MIN;
        
        for (auto &interval : intervals) 
        {
            if (interval.first > far) { 
                count++;
                far = interval.second;  
            }
        }
        return count;
    }
};
