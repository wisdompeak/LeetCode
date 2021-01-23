class Solution {
public:
    vector<int> decode(vector<int>& encoded) 
    {
        int n = encoded.size()+1;
        int sum = 0;
        for (int i=1; i<=n; i++)
            sum ^= i;
        
        int headtail = 0;
        for (int x: encoded)
            headtail ^= x;
        
        int nohead = headtail;
        for (int i=0; i<encoded.size(); i+=2)
            nohead ^= encoded[i];
        int head = sum^nohead;

        vector<int>ret(n);        
        ret[0] = head;        
        for (int i=1; i<n; i++)
            ret[i] = encoded[i-1] ^ ret[i-1];
        
        return ret;
    }
};
