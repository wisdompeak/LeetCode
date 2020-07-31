class Solution {
public:
    string strWithout3a3b(int A, int B) 
    {
        string ret;
        
        if (A>B)
        {
            int diff = A-B;
            for (int i=0; i<B; i++)
            {
                ret.push_back('a');
                if (diff>0)
                {
                    ret.push_back('a');
                    diff--;
                }
                ret.push_back('b');
            }
            for (int i=0; i<diff; i++)
                ret.push_back('a');
        }
        else
        {
            int diff = B-A;
            for (int i=0; i<A; i++)
            {
                ret.push_back('b');
                if (diff>0)
                {
                    ret.push_back('b');
                    diff--;
                }
                ret.push_back('a');
            }
            for (int i=0; i<diff; i++)
                ret.push_back('b');
        }
        
        return ret;
        
    }
};
