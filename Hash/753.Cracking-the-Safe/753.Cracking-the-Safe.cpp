class Solution {
public:
    string crackSafe(int n, int k) 
    {
        string ans;
        ans.assign(n-1,'0');
        unordered_map<string,int>record;
        
        int total = pow(k,n);
        
        for (int i=0; i<total; i++)
        {
            string temp = ans.substr(ans.size()-(n-1),(n-1));
            record[temp] = (record[temp]+1)%k;;
            ans+= '0'+record[temp];
        }
        return ans;        
    }
};
