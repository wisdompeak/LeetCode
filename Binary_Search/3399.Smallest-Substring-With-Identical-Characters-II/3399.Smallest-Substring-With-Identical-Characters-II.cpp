class Solution {
public:
    int minLength(string s, int numOps) 
    {
        vector<int>arr;
        vector<int>nums;
        for (auto ch: s) nums.push_back(ch-'0');
        
        int n = s.size();
        for (int i=0; i<n;)
        {
            int j = i;
            while (j<n && s[j]==s[i])
                j++;
            arr.push_back(j-i);
            i = j;
        }
        
        int left = 1, right = n;
        while (left < right)
        {
            int mid = left + (right-left)/2;            
            if (isOK(arr, nums, mid, numOps))
                right = mid;
            else
                left = mid+1;
        }
        return left;
    }
    
    bool isOK(vector<int>arr, vector<int>&nums, int len, int numOps)
    {
        if (len==1)
        {
            int count = 0;
            for (int i=0; i<nums.size(); i++)
                count += (nums[i]==(i%2));
            if (count <= numOps)
                return true;
            
            count = 0;
            for (int i=0; i<nums.size(); i++)
                count += (nums[i]!=(i%2));
            if (count <= numOps)
                return true;
            
            return false;
        }
        
        int count = 0;
                
        for (int i=0; i<arr.size(); i++)
        {
            int x = arr[i];
            count += ceil((x-len)*1.0/(len+1));
            if (count>numOps)
                return false;                
        }
        return true;
    }
};
