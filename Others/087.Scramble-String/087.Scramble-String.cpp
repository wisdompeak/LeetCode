class Solution {
public:
    bool isScramble(string s1, string s2) 
    {
        int n=s1.size();
        if (n==1) return (s1==s2);
        
        string temp1=s1;
        sort(temp1.begin(),temp1.end());
        string temp2=s2;
        sort(temp2.begin(),temp2.end());
        if (temp1!=temp2)
            return false;
        
        for (int i=1; i<n; i++)
        {
            if (isScramble(s1.substr(0,i),s2.substr(0,i)) && isScramble(s1.substr(i),s2.substr(i)))
                return true;
            
            if (isScramble(s1.substr(0,i),s2.substr(n-i)) && isScramble(s1.substr(i),s2.substr(0,n-i)))
                return true;
        }
        return false;
    }
};
