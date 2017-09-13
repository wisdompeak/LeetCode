class Solution {
public:
    string nearestPalindromic(string n) 
    {
        int N=n.size();
        string s1,s2,s3;
        
        if (N%2==1)
        {
            string t=n.substr(0,N/2+1);
            long long num=convert(t);
            string t1,t2;
            
            // candidate 1
            t1 = to_string(num);
            t2 = t1;
            reverse(t2.begin(),t2.end());
            s1 = t1.substr(0,N/2)+t2;
            
            // candidate 2
            t1 = to_string(num-1);
            t2=t1;
            reverse(t2.begin(),t2.end());
            s2 = t1.substr(0,N/2)+t2;
            
            // candidate 3
            t1 = to_string(num+1);
            t2=t1;
            reverse(t2.begin(),t2.end());
            s3 = t1.substr(0,N/2)+t2;

            cout<<s1<<" "<<s2<<" "<<s3<<endl;
            
            return pick(n,s1,s2,s3);
        }
        
        if (N%2==0)
        {
            string t=n.substr(0,N/2);
            long long num=convert(t);
            string t1,t2;
            
            //candidate 1
            t1 = n.substr(0,N/2);
            reverse(t1.begin(),t1.end());
            s1 = to_string(num)+t1;
            
            //candidate 2
            t1 = to_string(num-1);
            if (t1=="0")
                s2="9";
            else if (t1.size()==t.size())
            {
                t2=t1;
                reverse(t2.begin(),t2.end());
                s2=t1+t2;
            }
            else if (t1.size()!=t.size())
            {
                t2=t1;
                reverse(t2.begin(),t2.end());
                s2=t1+'9'+t2;
            }
            
            //candidate 3
            t1 = to_string(num+1);
            if (t1.size()==t.size())
            {
                t2=t1;
                reverse(t2.begin(),t2.end());
                s3=t1+t2;
            }
            else if (t1.size()!=t.size())
            {
                t2=t1;
                reverse(t2.begin(),t2.end());
                t1.pop_back();
                s3=t1+t2;
            }
            
            cout<<s1<<" "<<s2<<" "<<s3<<endl;
            
            return pick(n,s1,s2,s3);
        }        
    }
    
    string pick(string n, string s1, string s2, string s3)
    {
        long long m= convert(n);
        long long n1= convert(s1);
        long long n2= convert(s2);
        long long n3= convert(s3);
        
        if (n1==m)
        {
            return abs(n2-m)<=abs(n3-m)?s2:s3;
        }
        else
        {
            long long num_temp = abs(n1-m)<=abs(n3-m)?n1:n3;
            string string_temp = abs(n1-m)<=abs(n3-m)?s1:s3;
            
            return abs(n2-m)<=abs(num_temp-m)?s2:string_temp;
        }        
    }    
    
    long long convert(string s)
    {
        long long result=0;
        for (int i=0; i<s.size(); i++)
        {
            result = result*10 + s[i]-'0';
        }
        return result;
    }    
};
