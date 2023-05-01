class Solution {
public:
    vector<vector<int>> colorRed(int n) 
    {    
        vector<vector<int>>rets;
        vector<vector<int>>val(n+1, vector<int>(2*n+2));        
        
        for (int j=1; j<=2*n-1; j+=2)
        {
            val[n][j] = 1;
            rets.push_back({n,j});            
        }

        bool forward = 1;
        for (int i=n-1; i>=2; i--)
        {
            int j, end, delta;
            if (forward) {
                j = 1; end = 2*i; delta = 1;
            } else {
                j = 2*i-1; end = 0; delta = -1;
            }

            while (j != end) 
            {
                if (val[i][j]==0){
                    if (j%2 == 1) {  // a normal triangle cell. Its bottom neighbour must have been filled.
                        if (val[i][j-delta]==0) {
                            // Noramlly, the previous row neighbour must have been filled. The exception is the case when (i,j) is already the edge.
                            val[i][j+delta] = 1;
                            rets.push_back({i, j+delta});
                        }
                    } else { // a up-side-down triangle cell. Its up neighbour must have not been filled.                        
                        if (val[i][j+delta]==0) {
                            // Noramlly, the next row neighbour must have not been filled. 
                            // The exception is the case when the next row neighbour is filled by the previous row.
                            // Favor upper cell, as its next neighbour must be filled in the next round.
                            val[i-1][j-1] = 1;
                            rets.push_back({i-1, j-1});
                        }
                    }
                    val[i][j] = 1;
                }
                
                j+= delta;
            }
                        
            forward = !forward;
        }

        if (rets.back()[0]!=1 && rets.back()[1]!=1) {
            rets.push_back({1,1});
        }

        return rets;        
    }
};
