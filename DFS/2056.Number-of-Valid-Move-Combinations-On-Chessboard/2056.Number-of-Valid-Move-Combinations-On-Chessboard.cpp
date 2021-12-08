class Solution {
    vector<pair<int,int>>dir{{-1,0},{1,0},{0,-1},{0,1},{1,1},{1,-1},{-1,1},{-1,-1}};
    int n;
    unordered_set<long long>rets;
public:
    int countCombinations(vector<string>& pieces, vector<vector<int>>& positions) 
    {
        this->n = pieces.size();
                
        for (int state= 0 ; state<(1<<(3*n)); state++)
        {
            int flag =1;
            vector<int>dirs(n);
            for (int k=0; k<n; k++)
            {
                int d = (state>>(3*k))%8;
                if (pieces[k]=="rook" && d>3) {flag=0; break;}
                if (pieces[k]=="bishop" && d<4) {flag=0; break;}                
                dirs[k] = d;
            }
            if (flag)            
                dfs(positions, dirs, (1<<n)-1);
        }
        
        return rets.size()+1;        
    }
    
    void dfs(vector<vector<int>>& positions, vector<int>& dirs, int state)
    {
        for (int subset=state; subset>0; subset=(subset-1)&state)
        {
            vector<vector<int>>pos2 = positions;            
            int flag = 1;
            for (int i=0; i<n; i++)
            {
               if ((subset>>i)&1)
               {
                   pos2[i][0] += dir[dirs[i]].first;
                   pos2[i][1] += dir[dirs[i]].second;
                   if (pos2[i][0]<1 || pos2[i][0]>8) {flag = 0; break;}                   
                   if (pos2[i][1]<1 || pos2[i][1]>8) {flag = 0; break;}                   
               }
            }
            if (flag==0) continue;
            if (duplicate(pos2)) continue;
            
            long long hash = getHash(pos2);
            if (rets.find(hash)!=rets.end())
                continue;
            rets.insert(hash);  
            dfs(pos2, dirs, subset);
        }
    }
    
    bool duplicate(vector<vector<int>>&pos)
    {
        for (int i=0; i<n; i++)
            for (int j=i+1; j<n; j++)
                if (pos[i]==pos[j])
                    return true;
        return false;
    }
    
    long long getHash(vector<vector<int>>&pos)
    {
        long long ret = 0;
        for (int k=0; k<n; k++)
        {
            ret = ret*10 + pos[k][0];
            ret = ret*10 + pos[k][1];
        }
        return ret;
    }
};
