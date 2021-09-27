class Solution {
    vector<int>nums;
    vector<char>ops;    
    unordered_set<int> dp[20][20];
public:
    int scoreOfStudents(string s, vector<int>& answers) 
    {
        for (int i=0; i<s.size(); i++)
        {
            int j = i;
            while (j<s.size() && isdigit(s[j]))
                j++;
            nums.push_back(stoi(s.substr(i,j-i)));
            ops.push_back(s[j]);
            i = j;
        }

        int n = nums.size();
        
        helper(0, n-1);

        int rightAns = calculate(s);
        int ret = 0;
        for (auto ans: answers)
        {
            if (ans==rightAns)
                ret+=5;
            else if (dp[0][n-1].find(ans)!=dp[0][n-1].end())
                ret+=2;
        }
        return ret;
    }

    void helper(int a, int b)
    {
        if (!dp[a][b].empty())
            return;
        if (a==b)
        {
            dp[a][b] = {nums[a]};
            return;
        }
        
        for (int i=a; i<b; i++)
        {
            helper(a, i);
            helper(i+1, b);
            for (auto x: dp[a][i])
                for (auto y: dp[i+1][b])
                {
                    if (ops[i]=='+' && x+y<=1000)
                        dp[a][b].insert(x+y);
                    else if (ops[i]=='*' && x*y<=1000)
                        dp[a][b].insert(x*y);
                }
        }
    }

    int calculate(string s) 
    {
        string S = "+";
        for (auto ch:s)
        {
            if (ch==' ') continue;
            S.push_back(ch);
            if (ch=='(')
                S+="+";
        }
        s = S;

        vector<int>nums;

        for (int i=0; i<s.size(); i++)
        {
            if (s[i]=='+' || s[i]=='-')
            {
                int j = i+1;
                while (j<s.size() && isdigit(s[j]))
                    j++;
                int num = stoi(s.substr(i+1,j-i-1));
                if (s[i]=='+') nums.push_back(num);
                else if (s[i]=='-') nums.push_back(-num);
                i = j-1;
            }
            else if (s[i]=='*' || s[i]=='/')
            {
                int j = i+1;
                while (j<s.size() && isdigit(s[j]))
                    j++;
                int num = stoi(s.substr(i+1,j-i-1));                
                if (s[i]=='*') nums.back() *= num;
                else if (s[i]=='/') nums.back() /= num;
                i = j-1;
            }
        }

        int ret = 0;
        for (int i=0; i<nums.size(); i++)
            ret+=nums[i];
        return ret;
   }
};
