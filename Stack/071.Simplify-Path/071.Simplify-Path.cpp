class Solution {
public:
    string simplifyPath(string path) 
    {
        int i = 0;
        vector<string>q;
        while (i+1<path.size())
        {
            int j = path.find("/", i+1);
            if (j==-1) 
            {
                q.push_back(path.substr(i+1));
                break;
            }
            else
            {
                q.push_back(path.substr(i+1, j-i-1));
                i = j;
            }
        }

        vector<string>p;
        for (auto s: q)
        {
            if (s=="." || s=="") continue;
            else if (s=="..") 
            {
                if (p.size()>0) p.pop_back();
            }
            else p.push_back(s);
        }

        string ret;
        for (auto s:p)
            ret+='/'+s;
        return ret == ""? "/":ret;
        
    }
};
