using LL =long long;
class Solution {    
public:
    int comb[5001][2501];  

    int getComb(int m, int n)
    {
        if (m<n) return 0;
        if (n<=(m+1)/2)
            return comb[m][n];
        else
            return comb[m][m-n];
    }

    void precompute(int n)
    {        
        for (int i = 0; i <= n; ++i) 
        {
            comb[i][0] = 1;
            if (i==0) continue;
            for (int j = 1; j <= (i+1)/2; ++j) 
            {
                comb[i][j] = getComb(i-1, j-1) + getComb(i-1,j);
                comb[i][j] = min(comb[i][j], INT_MAX/2);
            }
        }
    }
    
    LL countPermutations(const vector<int>& nums) {
        
        int total = accumulate(nums.begin(), nums.end(), 0);        

        LL ret = 1;
        for (int i=0; i<26; i++)
        {
            if (nums[i]!=0)
            {
                ret *= getComb(total, nums[i]);
                if (ret >= INT_MAX/2) return INT_MAX/2;
                total -= nums[i];                
            }
        }
        return ret;
    }
    
    string smallestPalindrome(string s, int k) 
    {
        int n = s.size();
        vector<int>nums(26);
        for (int i=0; i<n/2; i++)
            nums[s[i]-'a']+=1;
        
        precompute(n/2);
         
        string ret;
        LL curCount = 0;
        dfs(k, nums, ret, curCount);     
                
        if (curCount != k || ret.size() != n/2) return "";
                
        string tt=ret;         
        reverse(tt.begin(), tt.end());
        if (n%2==1)
            ret.push_back(s[n/2]);
        ret += tt;
        
        return ret;
            
    }
    
    void dfs(LL k, vector<int>&nums, string& ret, LL& curCount)
    {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total == 0) {
            curCount+=1;
            return;
        }
        
        for (int i=0; i<26; i++)
        {
            if (nums[i]==0) continue;
            nums[i]-=1;
            LL temp = countPermutations(nums);
            
            if (curCount + temp < k)
            {
                curCount += temp;
                nums[i]++;
            }
            else
            {
                ret.push_back('a'+i);
                dfs(k, nums, ret, curCount);
                break;
            }
        }
    }
};
