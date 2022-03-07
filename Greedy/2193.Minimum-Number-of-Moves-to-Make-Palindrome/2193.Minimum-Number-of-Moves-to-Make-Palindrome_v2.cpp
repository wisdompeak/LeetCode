class Solution {
public:
    int minMovesToMakePalindrome(string s) 
    {
        int n = s.size();
        int ret = 0;
        
        unordered_map<char, deque<int>>dq;
        for (int i=0; i<s.size(); i++)
            dq[s[i]].push_back(i);
        
        vector<int>arr;
        int count = 0;  // how many left-pair characters have been processed
        
        for (int i=0; i<n; i++)
        {            
            if (dq[s[i]].empty()) 
                continue;
            else if (dq[s[i]].size()==1)
            {
                ret += abs(i+(n/2-count)-n/2);
                dq[s[i]].pop_back();
            }                
            else
            {
                dq[s[i]].pop_front();
                arr.push_back(dq[s[i]].back());
                dq[s[i]].pop_back();
                ret += i-count;
                count++;
            }
        }
        
        reverse(arr.begin(), arr.end());
                
        vector<int> temp = countSmaller(arr);        
        ret += accumulate(temp.begin(), temp.end(), 0);
        
        return ret;
    }
    
    vector<int> countSmaller(vector<int> nums) 
    {        
        int N = nums.size();
        if (N==0) return {};
        
        vector<int>sortedNums = nums;        
        vector<int>counts(N,0);
        DivideConque(nums,sortedNums, counts, 0, nums.size()-1);  // 0表示起点，N-1表示终点
        return counts;
    }
    
    void DivideConque(vector<int>&nums, vector<int>&sortedNums, vector<int>&counts, int start, int end)
    {
        if (start==end) return;
        
        int mid = start+(end-start)/2;
        DivideConque(nums, sortedNums, counts, start,mid);
        DivideConque(nums, sortedNums, counts, mid+1, end);
        
        for (int i=start; i<=mid; i++)
        {
            int val = nums[i];
            auto pos = lower_bound(sortedNums.begin()+mid+1, sortedNums.begin()+end+1,val);            
            counts[i] += pos-(sortedNums.begin()+mid+1);
        }
       
        sort(sortedNums.begin()+start,sortedNums.begin()+end+1);        
    }
};
