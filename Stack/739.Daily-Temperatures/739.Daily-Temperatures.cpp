class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        int N = temperatures.size();
        vector<int>results(N,0);
        
        for (int i=N-2; i>=0; i--)
        {
            int j = i+1;
            while (results[j]!=0 && temperatures[j]<=temperatures[i])
                j = j+results[j];
            if (temperatures[j]>temperatures[i])
                results[i] = j-i;
            else
                results[i] = 0;
        }
        return results;
    }
};
