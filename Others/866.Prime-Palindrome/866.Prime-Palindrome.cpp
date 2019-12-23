class Solution {
public:
    int primePalindrome(int N) 
    {
        if (N>7 && N<=11) return 11;
        
        string M = to_string(N);
        int n = M.size()/2;
        
        int a = pow(10,n);
        
        for (int i=a; i<=20000; i++)
        {
            string s = to_string(i);
            string s1 = s.substr(0, s.size()-1);
            reverse(s1.begin(),s1.end());
            s = s+s1;
            
            int k = stoi(s);
            if (k>=N && isPrime(k)) return k;
        }
        
        return -1;
    }
    
    bool isPrime(int k)
    {
        if (k==1) return false;
        if (k%2==0) return k==2;
        for (int i=3; i*i<=k; i+=2)
        {
            if (k%i==0) return false;
        }
        return true;
    }
};
