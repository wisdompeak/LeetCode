class Solution {
public:
    bool checkPalindromeFormation(string a, string b) 
    {
        return check(a,b) || check(b,a);        
    }
    
    bool check(string&a, string& b)
    {
        int i=0, j=b.size()-1;
        while (i<j && a[i]==b[j])
        {
            i++;
            j--;
        }
        if (i>=j) return true;
        return isPalindrome(a.substr(i,j-i+1))||isPalindrome(b.substr(i,j-i+1));
    }
    
    bool isPalindrome(string s)
    {
        int i=0, j = s.size()-1;
        while (i<j && s[i]==s[j])
        {
            i++;
            j--;
        }
        return i>=j;
    }
};
