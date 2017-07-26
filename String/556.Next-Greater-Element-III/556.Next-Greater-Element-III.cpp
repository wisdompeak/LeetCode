class Solution {
public:
    int nextGreaterElement(int n) 
    {
        if (n==0) return -1;
        
        vector<int>num;
        while (n>0)
        {
            num.push_back(n%10);
            n=n/10;
        }
        
        vector<int>p;
        p.push_back(num[0]);
        int i=1;
        while (i<num.size() && num[i]>=num[i-1])
        {
            p.push_back(num[i]);
            i++;
        }
        if (i==num.size()) return -1; // all the digits are descending
        
        int j=0;
        while (p[j]<=num[i]) j++;
        swap(num[i],p[j]);
        
        sort(p.begin(),p.end());
        reverse(p.begin(),p.end());
        
        for (int k=0; k<p.size(); k++)
            num[k]=p[k];
        
        long long result=0;
        for (int i=num.size()-1; i>=0; i--)        
            result = result*10+num[i];
        
        if (result>INT_MAX) 
            return -1;
        else
            return result;                
    }
};
