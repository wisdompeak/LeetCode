class Solution {
    int count = 0;
public:
    int numDupDigitsAtMostN(int N) 
    {
        
        vector<int>num;
        int n = N;
        while (n>0)
        {
            num.push_back(n%10);
            n=n/10;
        }
        reverse(num.begin(),num.end());
        
        for (int k=1; k<num.size(); k++)
        {
            count+= 9*permu(9,num.size()-(1+k));
        }
        
        cout<<count<<endl;
        
        vector<int>digits(10,0);
        DFS(num,digits,0);
        
        return N-count;
    }
    
    void DFS(vector<int>&num, vector<int>&digits, int k)
    {
        if (k==num.size())
        {
            count++;
            return;
        }
        
        for (int i=0; i<=9; i++)
        {
            if (k==0 && i==0) continue;
            
            if (i<num[k])
            {
                if (digits[i]==1) continue;
                count+= permu(10-(k+1),num.size()-(k+1));
            }
            else if (i==num[k])
            {
                if (digits[i]==1) continue;
                digits[i] = 1;
                DFS(num, digits, k+1);
                digits[i] = 0;                
            }
            
        }
    }

    int permu(int M, int N)
    {
        int ans =1 ;
        for (int i=0; i<N; i++)
            ans*=(M-i);
        return ans;
    }
        
};
