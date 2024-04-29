using LL = long long;
class Solution {
public:
    int medianOfUniquenessArray(vector<int>& nums) 
    {
        LL n = nums.size();
        LL total = n*(n-1)/2+n;
        LL half = (total+1)/2;
        int left = 1, right = n;
        while (left < right)
        {
            int mid = left + (right-left)/2;
            if (atMostK(nums, mid)>=half)
                right = mid;
            else
                left = mid+1;
        }
        return left;        
    }
    
    LL atMostK(vector<int>& A, int K)
    {
        unordered_map<int,LL>Map;
        LL count=0;
        LL i = 0;
        
        for (LL j=0; j<A.size(); j++)
        {
            Map[A[j]]++;
            
            while (Map.size()>K)
            {
                Map[A[i]]--;
                if (Map[A[i]]==0)
                    Map.erase(A[i]);
                i++;
            }            
            count+= j-i+1;
        }        
        return count;            
    }
};
