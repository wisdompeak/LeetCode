class Solution {
public:
    int maximumGain(string s, int x, int y) 
    {
        if (x<y) 
        {
            reverse(s.begin(), s.end());
            swap(x,y);
        }
        int ret = 0;
        string t;
        for (auto ch:s)
        {
            t.push_back(ch);
            while (t.size()>=2 && t.substr(t.size()-2)=="ab")
            {
                t.pop_back();
                t.pop_back();
                ret += x;
            }
        }
        string w;
        for (auto ch:t)
        {
            w.push_back(ch);
            while (w.size()>=2 && w.substr(w.size()-2)=="ba")
            {
                w.pop_back();
                w.pop_back();
                ret += y;
            }
        }
        return ret;

    }
};
