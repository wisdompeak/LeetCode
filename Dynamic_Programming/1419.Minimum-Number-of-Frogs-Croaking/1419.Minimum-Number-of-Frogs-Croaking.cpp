class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) 
    {
        int c=0, r=0, o=0, a=0;
        int ret = 0;
        for (auto ch: croakOfFrogs)
        {
            if (ch=='c')
                c++;
            else if (ch=='r')
            {
                c--;
                r++;
                if (c<0) return -1;
            }
            else if (ch=='o')
            {
                r--;
                o++;
                if (r<0) return -1;
            }
            else if (ch=='a')
            {
                o--;
                a++;
                if (o<0) return -1;
            }
            else if (ch=='k')
            {
                a--;
                if (a<0) return -1;
            }
            ret = max(ret, c+r+o+a);
        }
        
        if (c+r+o+a>0) return -1;
        
        return ret;
    }
};

// c-- r++
