class Solution {
public:
    string smallestGoodBase(string n) 
    {
        long long N=0;
        for (int i=0; i<n.size(); i++)
            N=N*10+n[i]-'0';
        
        if (N==1) return "2";
        
        long long m_max = log(N+1)/log(2)+1;
        
        for (long long m=m_max; m>=2; m--)
        {
            long long left = 2;
            long long right = pow(N,1.0/(m-1));
            long long mid;
            
            // cout<<"m="<<m<<" "<<left<<" "<<right<<" "<<endl;
                
            while (left<=right)  // 两个边界都需要探查
            {
                
                mid = left+(right-left)/2;
                long long k=mid;
                long long sum=1;
                for (int i=1; i<m; i++)
                {
                    sum=sum*k+1;
                }
                if (sum==N)
                    return to_string(k);
                else if (sum<N)
                    left = mid+1;
                else
                    right = mid-1;  // 注意，因为mid已经排除，所以right的更新值不应该包括mid本身，否则死循环。
                    
                //cout<<sum<<" "<<k<<" "<<m<<" "<<endl;
                    
            }
        }
        
        return to_string(N-1);
        
    }
};
