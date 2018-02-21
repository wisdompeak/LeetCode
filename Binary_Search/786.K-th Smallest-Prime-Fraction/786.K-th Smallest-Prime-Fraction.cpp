class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) 
    {
        double left=A[0]*1.0/A.back();
        double right = 0;
        for (int i=1; i<A.size(); i++)
            right = max(right,A[i-1]*1.0/A[i]);
        double mid;
        
        while (left<right)
        {
            mid = left+(right-left)/2.0;
            int count=0;
            
            for (int i=0; i<A.size(); i++)
            {
                auto pos = lower_bound(A.begin(),A.end(),A[i]*1.0/mid);
                count+= A.end()-pos;
            }
            
            if (count==K)
                break;
            else if (count<K)
                left = mid;
            else
                right = mid;
        }
                
        double diff=1;
        int p,q;
        for (int i=0; i<A.size(); i++)
        {
            auto pos = lower_bound(A.begin(),A.end(),A[i]*1.0/mid);        
            if (pos>A.begin()+i && pos!=A.end())
            {
                int x = *pos;
                if (diff > mid-A[i]*1.0/x )
                {
                    diff = mid-A[i]*1.0/x;
                    p = A[i];
                    q = x;
                }
            }
        }
        
        return {p,q};
    }
};
