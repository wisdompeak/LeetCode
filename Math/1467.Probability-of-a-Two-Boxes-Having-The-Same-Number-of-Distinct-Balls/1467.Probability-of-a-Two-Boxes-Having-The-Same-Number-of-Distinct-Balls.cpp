class Solution {
    int C[10][10];
    vector<int>balls;
    long long all = 0;
    long long good = 0;
public:
    double getProbability(vector<int>& balls) 
    {
        int n = balls.size();
        this->balls = balls;
        
        for (int i = 0; i <= 8; ++i) {
            C[i][i] = C[i][0] = 1;            
            for (int j = 1; j < i; ++j) {
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            }
        }        
        
        vector<int>set1(n);
        vector<int>set2(n);
        dfs(0,set1,set2);
        
        return good*1.0/all;
    }
    
    void dfs(int k, vector<int>&set1, vector<int>&set2)
    {
        if (k == balls.size())
        {          
            if (accumulate(set1.begin(), set1.end(), 0) != accumulate(set2.begin(), set2.end(), 0))
                return;
            
            long long p = 1;
            for (int i=0; i<balls.size(); i++)
                p *= C[balls[i]][set1[i]];
            
            all += p;
            
            int cnt1 = 0, cnt2 = 0;
            for (auto x: set1) if (x>0) cnt1+=1;
            for (auto x: set2) if (x>0) cnt2+=1;
            
            if (cnt1 == cnt2)
                good += p;
            
            return ;
        }
        
        for (int i=0; i<=balls[k]; i++)
        {
            set1[k] += i;
            set2[k] += balls[k]-i;
            dfs(k+1, set1, set2);
            set1[k] -= i;
            set2[k] -= balls[k]-i;
        }
    }
};
