using LL = long long;
class Solution {
    unordered_set<LL>visited;
public:
    bool possiblyEquals(string s1, string s2) 
    {
        vector<string>t1 = parse(s1);
        vector<string>t2 = parse(s2);
        return dfs(t1, 0, 0, t2, 0, 0);        
    }

    vector<string>parse(string s)
    {
        vector<string>t;
        for (int i=0; i<s.size(); i++)
        {
            if (isalpha(s[i]))
            {
                t.push_back(s.substr(i,1));
            }
            else
            {
                int j = i;
                while (j<s.size() && isdigit(s[j]))
                    j++;
                t.push_back(s.substr(i, j-i));
                i = j-1;
            }
        }
        return t;
    }

    bool dfs(vector<string>&t1, int i, int num1, vector<string>&t2, int j, int num2)
    {        
        if (i==t1.size() && j==t2.size()) 
            return num1==num2;
        
        if (i==t1.size() && num1==0) return false;        
        if (j==t2.size() && num2==0) return false;

        LL hash = i*1e9 + num1*1e6+ j*1e3+ num2;
        if (visited.find(hash)!=visited.end()) return false;

        if (i<t1.size() && isdigit(t1[i][0]))
        {
            unordered_set<int>nums = getNum(t1[i]);
            for (int x: nums)
            {                
                if (dfs(t1, i+1, num1+x, t2, j, num2))
                    return true;
            }
            visited.insert(hash);
            return false;
        }
        else if (j<t2.size() && isdigit(t2[j][0]))
        {
            unordered_set<int>nums = getNum(t2[j]);
            for (int x: nums)
            {                
                if (dfs(t1, i, num1, t2, j+1, num2+x))
                    return true;
            }
            visited.insert(hash);
            return false;                
        }

        if (num1!=0 && num2!=0)
        {
            int common = min(num1, num2);            
            return dfs(t1, i, num1-common, t2, j, num2-common);
        }
        else if (num1!=0 && num2==0)
        {            
            return dfs(t1, i, num1-1, t2, j+1, 0);
        }
        else if (num1==0 && num2!=0)
        {            
            return dfs(t1, i+1, 0, t2, j, num2-1);
        }
        else
        {            
            visited.insert(hash);
            if (t1[i]!=t2[j]) return false;
            return dfs(t1, i+1, 0, t2, j+1, 0);
        }
    }

    unordered_set<int>getNum(string t)
    {
        int d = stoi(t);
        if (t.size()==1)
            return {d};
        else if (t.size()==2)
        {
            int a = d/10;
            int b = d%10;
            return {a+b, d};
        }
        else
        {
            int a = d/100;
            int b = (d/10)%10;
            int c = d%10;
            return {a+b+c, a+b*10+c, a*10+b+c, d};
            
        }
    }
};
