class Solution {
public:
    long long numOfSubsequences(string s) {
        int n = s.size();
        s = "#"+s;
        vector<long long>leftL(n+2);
        vector<long long>rightT(n+2);        
        for (int i=1; i<=n; i++)
            leftL[i] = leftL[i-1]+(s[i-1]=='L');            
        for (int i=n; i>=1; i--)
            rightT[i] = rightT[i+1]+(s[i+1]=='T');

        long long count = 0;
        for (int i=1; i<=n; i++) {
            if (s[i]=='C')
                count += leftL[i]*rightT[i];
        }
        
        long long ret = 0;

        long long CT = 0;
        long long T = 0;
        for (int i=n; i>=1; i--) {
            T += s[i]=='T';
            if (s[i]=='C') CT += T;
            ret = max(ret, count+CT);
        }
  
        long long LC = 0;
        long long L= 0;
        for (int i=1; i<=n; i++) {
            L += s[i]=='L';
            if (s[i]=='C') LC += L;
            ret = max(ret, count+LC);
        }
  
        for (int i=1; i<=n-1; i++) {
            ret = max(ret, count+leftL[i+1]*rightT[i]);
        }
  
        return ret;
    }
};
