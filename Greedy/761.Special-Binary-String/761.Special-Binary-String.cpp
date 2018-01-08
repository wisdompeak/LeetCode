class Solution {
public:
    string makeLargestSpecial(string S) 
    {
        if (S.size()==2) return S;

        vector<string>strs;
        
        for (int i=0; i<S.size(); i++)
        {
            int i0=i;
            int count=0;
            while (i<S.size())
            {
                if (S[i]=='1')
                    count++;
                else
                    count--;                
                if (count==0)
                    break;   
                i++;
            }
            strs.push_back("1"+makeLargestSpecial(S.substr(i0+1,i-i0-1))+"0");
        }
        
        sort(strs.begin(),strs.end(),greater<string>());
        string result;
        for (auto a:strs) result+=a;
        return result;
        
    }
};
