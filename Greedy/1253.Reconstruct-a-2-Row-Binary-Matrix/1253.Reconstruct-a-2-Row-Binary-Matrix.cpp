class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) 
    {
        vector<int>a;
        vector<int>b;
        
        for (auto x: colsum)
        {
            if (x==2)
            {
                if (upper==0 || lower==0)
                    return {};
                a.push_back(1);
                b.push_back(1);
                upper--;
                lower--;
            }
            else if (x==0)
            {
                a.push_back(0);
                b.push_back(0);
            }
            else
            {
                if (upper>=lower && upper>0)
                {
                    a.push_back(1);
                    b.push_back(0);
                    upper--;
                }
                else if (lower>=upper && lower>0)
                {
                    a.push_back(0);
                    b.push_back(1);
                    lower--;
                }
                else
                    return {};
            }
        }
        
        if (upper!=0 || lower!=0)
            return {};
        else
            return {a,b};
    }
};
