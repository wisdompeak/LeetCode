class Solution {
public:
    vector<int> pathInZigZagTree(int label) 
    {
        vector<int>results;
        while (label>0)
        {
            results.push_back(label);
            int n = log2(label);
            label = pow(2,n-1)+pow(2,n)-1-label/2;            
        }
        reverse(results.begin(),results.end());
        return results;
    }
};
