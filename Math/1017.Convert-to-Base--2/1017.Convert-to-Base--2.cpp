class Solution {
public:
    string baseNeg2(int N) 
    {
        string ret;
        while (N!=-0)
        {
            int r = N%(-2);
            int d = (N-r)/(-2);
            
            if (r<0)
            {
                d += 1;
                r += 2;
            }
            
            ret.push_back('0'+r);
            N = d;
        }
        reverse(ret.begin(), ret.end());
        if (ret=="") return "0";
        else return ret;
    }
    
};
