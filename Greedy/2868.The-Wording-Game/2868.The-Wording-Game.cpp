class Solution {
public:
    bool canAliceWin(vector<string>& a, vector<string>& b) 
    {
        int m = a.size(), n = b.size();
        int i = 0, j = 0;

        while (1)
        {
            while (j<n && b[j]<=a[i])
                j++;
            if (j==n || b[j][0] > a[i][0]+1)
                return true;

            while (i<m && a[i]<=b[j])
                i++;
            if (i==m || a[i][0] > b[j][0]+1)
                return false;
        }

        return false;        
    }
};
