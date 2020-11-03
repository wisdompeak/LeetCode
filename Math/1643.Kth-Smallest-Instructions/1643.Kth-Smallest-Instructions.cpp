class Solution {
public:
    string kthSmallestPath(vector<int>& destination, int k) 
    {
        int V = destination[0];
        int H = destination[1];
        int n = H+V;
       
        string ret;
        for (int i=0; i<n; i++)
        {
            if (H==0)
            {
                ret.push_back('V');
                V--;
                continue;
            }
            else if (V==0)
            {
                ret.push_back('H');
                H--;
                continue;
            }
            
            int sum = comb(H-1+V, H-1);
            if (k <= sum)
            {
                ret.push_back('H');
                H--;
            }
            else
            {
                k -= sum;
                ret.push_back('V');
                V--;
            }            
        }
        
        return ret;        
    }
    
    long long comb(int n, int m)
    {        
        long long cnt = 1;
        for(int i = 0; i < m; i++){
            cnt *= n - i;
            cnt /= i + 1;
        }
        return cnt;
    }
};
