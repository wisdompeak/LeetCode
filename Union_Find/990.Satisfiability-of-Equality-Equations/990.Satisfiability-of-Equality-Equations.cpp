class Solution {
    vector<int>Father;
public:
    bool equationsPossible(vector<string>& equations) 
    {
        Father.resize(26);
        for (int i=0; i<26; i++)
            Father[i] = i;

        for (auto & eq: equations)
        {            
            if (eq[1]=='=')
            {
                int a = eq[0]-'a';
                int b = eq[3]-'a';
                if (FindFather(a)!=FindFather(b))
                    Union(a,b);
            }
        }

        for (auto & eq: equations)
        {            
            if (eq[1]=='!')
            {
                int a = eq[0]-'a';
                int b = eq[3]-'a';
                if (FindFather(a)==FindFather(b))
                    return false;
            }
        }

        return true;
    }
    int FindFather(int x)
    {
        if (Father[x]!=x)
            Father[x] = FindFather(Father[x]);
        return Father[x];
    }
    
    void Union(int x, int y)
    {
        x = Father[x];
        y = Father[y];
        if (x<y)
            Father[y] = x;
        else
            Father[x] = y;
    }    
};
