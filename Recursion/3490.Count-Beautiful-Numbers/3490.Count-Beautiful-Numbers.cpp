using State = tuple<int, int, int, bool, bool>;

class Solution {    
public:
    map<State, int> memo;
    vector<int> digits;
    
    int dfs(int pos, int sum, int product, bool tight, bool leading_zero)
    {
        if (pos == digits.size()) {
            return (sum > 0) && (product % sum == 0);
        }

        State key = {pos, sum, product, tight, leading_zero};
        if (memo.find(key) != memo.end()) return memo[key];

        int limit = (tight ? digits[pos] : 9);
        int res = 0;

        for (int d = 0; d <= limit; d++) 
        {            
            res += dfs(pos + 1, sum + d, (leading_zero && d == 0) ? 1 : product * d, tight && (d == limit), leading_zero && (d == 0));
        }

        return memo[key] = res;
    }
    
    int count(int T) 
    {
        if (T <= 0) return 0;
        digits.clear();
        memo.clear();

        while (T > 0) 
        {
            digits.push_back(T % 10);
            T /= 10;
        }
        reverse(digits.begin(), digits.end());
        return dfs(0, 0, 1, true, true);
    }
    
    int beautifulNumbers(int l, int r) 
    {
        return count(r) - count(l-1);
    }
};
