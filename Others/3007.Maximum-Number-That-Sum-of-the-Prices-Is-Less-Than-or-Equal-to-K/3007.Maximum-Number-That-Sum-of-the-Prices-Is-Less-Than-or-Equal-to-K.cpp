using LL = long long;
class Solution {
public:
    long long findMaximumNumber(long long k, int x) 
    {
        LL left = 1, right = 1e15;
        
        while (left < right)
        {
            LL mid = right-(right-left)/2;
            if (checkOK(mid, k, x))
                left = mid;
            else
                right = mid-1;
        }
        return left;
    }
    
    bool checkOK(LL A, LL k, int x)
    {
        LL ret = 0;
        for (int i=x-1; (1LL<<i) <= A; i+=x)
        {
            LL a = A;
            vector<int>arr;
            while (a>0)
            {
                arr.push_back(a%2);
                a/=2;
            }
            if (arr[i]==1)
            {
                LL b = 0;
                for (int j=arr.size()-1; j>i; j--)
                    b = b*2+arr[j];                
                ret += b * pow(2, i);
                b = 0;
                for (int j=i-1; j>=0; j--)
                    b = b*2+arr[j];
                ret += b+1;                
            }
            else
            {
                LL b = 0;
                for (int j=arr.size()-1; j>i; j--)
                    b = b*2+arr[j];
                ret += b * pow(2, i);
            }            
            
            if (ret > k) return false;
        }

        return true;
    }
};
