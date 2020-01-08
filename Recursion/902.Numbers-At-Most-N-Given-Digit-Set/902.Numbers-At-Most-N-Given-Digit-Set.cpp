class Solution {
    int count = 0;
    string num;
    int K;
    
public:
    int atMostNGivenDigitSet(vector<string>& D, int N) 
    {
        num = to_string(N);
        K = num.size();
        
        for (int i=1; i<=K-1; i++)
            count += pow(D.size(), i);
        
        DFS(0, 0, D);
        
        return count;
    }
    
    void DFS(long cur, int pos, vector<string>& D)
    {
        if (pos==K)
        {
            count+=1;
            return;
        }
        
        for (string s: D)
        {
            if ('0'+stoi(s) < num[pos])
                count += pow( D.size(), K-1-pos);
            else if ('0'+stoi(s) == num[pos])
                DFS(cur*10+stoi(s), pos+1, D);            
        }               
    }
};
