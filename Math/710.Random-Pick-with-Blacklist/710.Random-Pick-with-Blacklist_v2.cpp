class Solution {
    int N;
    vector<int>blacklist;
public:
    Solution(int N, vector<int>& blacklist) 
    {        
        sort(blacklist.begin(),blacklist.end());
        this->N = N;
        this->blacklist = blacklist;
        
    }
    
    int pick() 
    {
        int k = rand()%(N-blacklist.size())+1;
        
        int left = 0;
        int right = N-1;
        while (left<right)
        {
            int mid = left+(right-left)/2;
            if (count(mid) >= k)
                right = mid;
            else
                left = mid+1;            
        }
        return left;        
    }
    
    int count(int t)
    {
        auto iter = upper_bound(blacklist.begin(),blacklist.end(),t);
        return (t+1)-(iter-blacklist.begin());
    }
};
