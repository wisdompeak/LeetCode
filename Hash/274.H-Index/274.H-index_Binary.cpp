class Solution {
public:
    int hIndex(vector<int>& citations) 
    {
        int left=0;
        int N=citations.size();
        int right=N-1;
        int mid;
        
        if (N==0) return 0;
        
        while (left<right)
        {
            int mid= left+(right-left)/2;
            
            if (N-mid==citations[mid])
                return citations[mid];
            else if (N-mid<citations[mid])
                right = mid;
            else
                left= mid+1;
        }
        
        return min(N-left,citations[left]);
        
    }
};
