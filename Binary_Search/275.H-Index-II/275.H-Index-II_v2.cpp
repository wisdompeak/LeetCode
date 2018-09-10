class Solution {
public:
    int hIndex(vector<int>& citations) 
    {            
        int N = citations.size();
        int i = N-1;
        while (i>=0 && N-i<=citations[i])
            i--;
        return N-(i+1);
    }
};
