class Solution {
public:
    string robotWithString(string s) 
    {
        int n = s.size();
        vector<char>nextSmallest(n,INT_MAX);
        char smallest = 'z'+1;        
        for (int i=n-1; i>=0; i--)
        {
            smallest = min(smallest, s[i]);
            nextSmallest[i] = smallest;
        }
                
        stack<char>st;
        string ret;
        int i = 0;
        while (i<n)
        {
            if (st.empty() || nextSmallest[i] < st.top())
            {
                st.push(s[i]);                
                i++;
            }
            else
            {
                ret.push_back(st.top());
                st.pop();                
            }            
        }
        
        while (!st.empty())
        {
            ret.push_back(st.top());
            st.pop();
        }
        
        return ret;
    }
};
