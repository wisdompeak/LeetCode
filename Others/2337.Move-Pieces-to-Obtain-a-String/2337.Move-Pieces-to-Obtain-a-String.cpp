class Solution {
public:
    bool canChange(string start, string target) 
    {
        int i=0;
        int j=0;
        while (i<start.size() && j<target.size())
        {
            while (i<start.size() && start[i]=='_')
                i++;
            while (j<target.size() && target[j]=='_')
                j++;
            if (start[i]!=target[j])
                return false;
            if (start[i]=='R' && i>j)
                return false;
            if (start[i]=='L' && i<j)
                return false;
            i++;
            j++;
        }
        return true;
    }
};
