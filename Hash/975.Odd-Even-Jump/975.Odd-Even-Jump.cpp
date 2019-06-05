class Solution {
public:
    int oddEvenJumps(vector<int>& A) 
    {
        int n = A.size();
        vector<bool>odd(n,0);
        vector<bool>even(n,0);
        odd[n-1] = true;
        even[n-1] = true;
                
        map<int,int>Map;        
        Map[A.back()] = n-1;
        
        for (int i=n-2; i>=0; i--)
        {            
            auto iter1 = Map.lower_bound(A[i]);   
            if (iter1!=Map.end())
            {                
                if (even[iter1->second]) odd[i] = true;
            }
            
            auto iter2 = Map.upper_bound(A[i]);
            if (iter2!=Map.begin())
            {
                iter2 = prev(iter2,1);                
                if (odd[iter2->second]) even[i] = true;
            }
            
            Map[A[i]] = i;
        }
        
        int count = 0;
        for (int i=0; i<n; i++)
            if (odd[i]) count++;
        return count;
    }
};
