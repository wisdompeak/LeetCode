class Solution {
    unordered_map<int,int>pos;  // idx of s -> idx of removable
public:
    int maximumRemovals(string s, string p, vector<int>& removable) 
    {
        for (int i=0; i<removable.size(); i++)
            pos[removable[i]] = i;
        
        int left = 0, right = removable.size();
        while (left < right)
        {
            int mid = right-(right-left)/2;
            if (checkOK(s,p,mid))
                left = mid;
            else
                right = mid-1;
        }
        return left;
    }
    
    bool checkOK(string& s, string& p, int k) 
    {
        int i = 0, j = 0;
        int t = 0;
        while (j<p.size())
        {
            while (i<s.size() && s[i]!=p[j])
                i++;
                        
            if (i>=s.size()) break;
            
            if (pos.find(i)==pos.end() || pos[i]>=k)
                j++;
            
            i++;
        }
        return j==p.size();
    }
};
