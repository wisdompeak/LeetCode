class Solution {
public:
    int countCollisions(string directions) 
    {
        int count = 0;
        int n = directions.size();

        int flag = 0;
        for (int i=0; i<n; i++)
        {
            if (flag == 0 && (directions[i]=='R' || directions[i]=='S'))
                flag = 1;
            if (flag == 1 && directions[i]=='L')
                count++;
        }

        flag = 0;
        for (int i=n-1; i>=0; i--)
        {
            if (flag == 0 && (directions[i]=='L' || directions[i]=='S'))
                flag = 1;
            if (flag == 1 && directions[i]=='R')
                count++;
        }
        return count;
    }
};
