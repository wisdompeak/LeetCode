using LL = long long;
class Solution {
    LL memo[18][2][2][2];
    int L;
    vector<int>digits;
public:    
    LL dfs(int pos, int carry, int endA, int endB) {
        if (pos==L) {
            if (carry==0 && endA==1 && endB==1)
                return 1;
            else
                return 0;
        }

        if (memo[pos][carry][endA][endB]!=-1)
            return memo[pos][carry][endA][endB];

        LL ret = 0;
        int target = digits[pos];
        for (int i=0; i<=9; i++) {
            if(endA==1 && i!=0) continue;            
            if(endA==0 && i==0) continue;            
            vector<int>A;
            if (endA) A.push_back(1);
            else {
                A.push_back(0);
                if (i!=0) A.push_back(1);
            }

            
            for (int j=0; j<=9; j++) {
                if (endB==1 && j!=0) continue;
                if (endB==0 && j==0) continue;
                int sum = i+j+carry;
                if (sum%10!=target) continue;
                int ncarry = (sum>=10)?1:0;

                vector<int>B;
                if (endB) B.push_back(1);
                else {
                    B.push_back(0);
                    if (j!=0) B.push_back(1);
                }

                for (int nxt_enda: A)
                    for (int nxt_endb: B)                                                    
                        ret += dfs(pos+1, ncarry, nxt_enda, nxt_endb);                                                                    
            }
        }

        memo[pos][carry][endA][endB] = ret;
        return ret;
           
    };
    
    long long countNoZeroPairs(long long n) {

        fill(&memo[0][0][0][0], &memo[0][0][0][0]+18*2*2*2, -1);
                
        LL temp = n;
        while (temp>0) {
            digits.push_back(temp%10);
            temp/=10;
        }
        L = digits.size();
        
        return dfs(0,0,0,0);
    }
};
