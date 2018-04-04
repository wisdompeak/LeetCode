class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) 
    {        
        int N=A.size();
        vector<unordered_map<int,int>>counts(N);
        int result=0;
        int temp=0;
        
        for (int i=0; i<N; i++)
        {
            for (int j=0; j<i; j++)
            {                
                if((long)A[i] - (long)A[j] > INT_MAX || (long)A[i] - (long)A[j] < INT_MIN) continue;
                int diff = A[j]-A[i];
                counts[i][diff]+=1;
                if (counts[j].find(diff)!=counts[j].end())
                {
                    counts[i][diff]+=counts[j][diff];
                    result+=counts[j][diff];
                }                    
            }            
        }        
        return result;
    }
};
