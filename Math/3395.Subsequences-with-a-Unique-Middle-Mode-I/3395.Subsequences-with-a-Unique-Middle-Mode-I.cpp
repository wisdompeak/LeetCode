using LL = long long;
LL M = 1e9+7;
class Solution {    
    long long comb[1005][6];  
public:
    LL getComb(int m, int n)
    {
        if (m<n) return 0;
        return comb[m][n];
    }

    int subsequencesWithMiddleMode(vector<int>& nums) 
    {
        int n = nums.size();
        for (int i = 0; i <= n; ++i) 
        {
            comb[i][0] = 1;            
            if (i==0) continue;
            for (int j = 1; j <= 5; ++j) 
            {
                comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
                comb[i][j] %= M;
            }
        }  
        unordered_set<int>Set(nums.begin(), nums.end());

        LL ret = 0;               

        unordered_map<int,int>left;
        unordered_map<int,int>right;
        for (int x: nums) right[x]++;

        for (int i=0; i<n; i++)
        {                        
            int a = nums[i];
            right[a]--;
            if (i>=1) left[nums[i-1]]++;

            ret += getComb(i - left[a], 2) * getComb(n-i-1-right[a], 2) %M;   
            ret %= M;         

            for (int b: Set)
            {                
                if (a==b) continue;                                
                ret += getComb(left[b],2) * getComb(right[a], 1) * getComb(n-i-1-right[a]-right[b], 1) %M;                
                ret += getComb(right[b],2) * getComb(left[a], 1) * getComb(i-left[a]-left[b], 1) %M;                
                ret %= M;
            }

            for (int b: Set)
            {             
                if (a==b) continue;                                
                ret += getComb(left[b],1) * getComb(i-left[b]-left[a], 1) * getComb(right[a], 1) * getComb(right[b], 1) %M;            
                ret += getComb(right[b],1) * getComb(n-i-1-right[b]-right[a], 1) * getComb(left[a], 1) * getComb(left[b], 1) %M;
                ret %= M;
            }

            for (int b: Set)
            {                
                if (a==b) continue;                                
                ret += getComb(left[b],2) * getComb(right[a], 1) * getComb(right[b], 1) %M;                
                ret += getComb(right[b],2) * getComb(left[a], 1) * getComb(left[b], 1) %M;
                ret %= M;
            }
        }

        return (getComb(n, 5) - ret + M) % M;
    }
};
