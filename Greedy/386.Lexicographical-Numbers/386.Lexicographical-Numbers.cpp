class Solution {
public:
    vector<int> lexicalOrder(int n) 
    {
        int current=1;
        vector<int>results(n);
        
        for (int i=0; i<n; i++)
        {
            results[i]=current;
            
            if (current*10<=n)
                current=current*10;
            else
            {
                if (current+1>n) 
                    current=current/10;
                current++;
                while (current % 10==0)
                    current/=10;
            }
        }
        return results;
    }
};
