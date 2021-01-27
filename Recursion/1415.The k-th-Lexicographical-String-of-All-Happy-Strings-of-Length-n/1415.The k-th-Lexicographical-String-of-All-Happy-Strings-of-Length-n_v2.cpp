class Solution {
    string ret;
public:
    string getHappyString(int n, int k) 
    {      
        int total = pow(2,n-1)*3;
        if (k > total) return "";
        dfs(n, k-1);
        return ret;        
    }

    void dfs(int n, long k)
    {
        if (n==0) return;

        int t = k / pow(2,n-1);
        char ch = 'a'+t;
        if (ret.size()>0 && ch>=ret.back())
            ch++;
        ret.push_back(ch);

        dfs(n-1, k - t*pow(2,n-1));
    }
};
