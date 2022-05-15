class Solution {
    vector<int>presum;
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) 
    {
        sort(tiles.begin(), tiles.end());
        int n = tiles.size(); 
        presum.resize(n);
        for (int i=0; i<n; i++)
            presum[i] = (i==0?0:presum[i-1]) + (tiles[i][1]-tiles[i][0]+1);        
        int ret = 0;
        
        int j = 0;
        for (int i=0; i<n; i++)
        {
            while (j<n && tiles[i][0]+carpetLen-1 >= tiles[j][1])
                j++;
            int len = presum[j-1] - (i==0?0:presum[i-1]);
            if (j<n)
                len += max(0, tiles[i][0]+carpetLen-1 - tiles[j][0] + 1);
            ret = max(ret, len);
        }
        
        return ret;
    }
};
