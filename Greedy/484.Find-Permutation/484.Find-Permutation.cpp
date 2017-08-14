class Solution {
public:
    vector<int> findPermutation(string s) 
    {
        s.insert(s.begin(),s[0]);
        int N=s.size();
        vector<int>results(N,0);
        
        int left=0;
        int right=0;
        
        while (right<s.size())
        {
            while (right+1<s.size() && !(s[right]=='D' && s[right+1]=='I'))
                   right++;
            if (right==s.size()) right--;
            
            int top=left;
            while (s[top+1]=='I') top++;
            for (int i=left; i<top; i++)
                results[i]=i+1;
            for (int i=top; i<=right; i++)
                results[i]=top+1+right-i;
            left=right+1;
            right=right+1;
        }
        
        return results;
            
    }
};
