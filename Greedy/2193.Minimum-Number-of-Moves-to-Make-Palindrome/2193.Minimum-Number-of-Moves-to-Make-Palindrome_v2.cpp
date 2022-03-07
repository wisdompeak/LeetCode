class Solution {
    int temp[50001];
public:
    int minMovesToMakePalindrome(string s) 
    {
        int n = s.size();
        int count = 0; // how many left-pair characters have been processed
        int ret = 0;
        
        unordered_map<char, deque<int>>dq;
        for (int i=0; i<n; i++)
            dq[s[i]].push_back(i);
        
        vector<int>arr;
        for (int i=0; i<n; i++)
        {
            if (dq[s[i]].empty())
                continue;
            else if (dq[s[i]].size()==1)
            {
                ret += i + (n/2-count) - n/2;
                dq[s[i]].pop_back();
            }
            else
            {
                arr.push_back(dq[s[i]].back());
                dq[s[i]].pop_front();
                dq[s[i]].pop_back();
                ret += i-count;
                count++;                
            }
        }
        
        reverse(arr.begin(), arr.end());
        return ret + reversePairs(arr);
    }
    
    int reversePairs(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int>sorted = nums;        
        return helper(nums, sorted, 0, n-1);        
    }

    int helper(vector<int>& nums, vector<int>& sorted, int a, int b)
    {
        if (a>=b) return 0;
        int ret = 0;
        int mid = a+(b-a)/2;
        ret += helper(nums, sorted, a, mid);
        ret += helper(nums, sorted, mid+1, b);

        for (int j=mid+1; j<=b; j++)
        {
            auto iter = upper_bound(sorted.begin()+a, sorted.begin()+mid+1, (long)nums[j]);
            ret += sorted.begin()+mid+1 - iter;
        }
        sort(sorted.begin()+a, sorted.begin()+b+1);
        return ret;
    }
};
