class Solution {
public:
    int evaluate(string expression) 
    {
        unordered_map<string,int>data;
        return helper(expression, 1, expression.size()-2, data);
    }
    
    int helper(string &s, int a, int b, unordered_map<string,int> data)
    {       
        if (a+3<=b && s.substr(a,3)=="add")
        {            
            vector<int>nums;
            
            for (int i=a+4; i<=b; i++)
            {
                if (s[i]=='(')
                {
                    int j = getRightParenthsis(s,i);
                    int next = helper(s,i+1, j-1, data);
                    nums.push_back(next);                    
                    i = j;
                }
                else if (isalpha(s[i]))
                {
                    int j = getVar(s,i);
                    string var = s.substr(i,j-i);
                    nums.push_back(data[var]);
                    i = j-1;
                }
                else if (isdigit(s[i])||s[i]=='-')
                {
                    int j= getDigit(s,i);
                    nums.push_back(stoi(s.substr(i,j-i)));
                    i = j-1;
                }
            }
            return nums[0]+nums[1];
        }
        
        else if (a+4<=b && s.substr(a,4)=="mult")
        {            
            vector<int>nums;
            
            for (int i=a+5; i<=b; i++)
            {
                if (s[i]=='(')
                {
                    int j = getRightParenthsis(s,i);
                    int next = helper(s,i+1, j-1, data);
                    nums.push_back(next);                    
                    i = j;
                }
                else if (isalpha(s[i]))
                {
                    int j = getVar(s,i);
                    string var = s.substr(i,j-i);
                    nums.push_back(data[var]);
                    i = j-1;
                }
                else if (isdigit(s[i])||s[i]=='-')
                {
                    int j= getDigit(s,i);
                    nums.push_back(stoi(s.substr(i,j-i)));
                    i = j-1;
                }
            }
            return nums[0]*nums[1];
        }
        
        else if (a+3<=b && s.substr(a,3)=="let")
        {
            int flag = 0;
            string var;
            int val;
            for (int i=a+4; i<=b; i++)
            {
                if (s[i]==' ') continue;
                                
                if (flag==0)
                {
                    if (s[i]=='(')
                    {
                        return helper(s,i+1,b-1,data);
                    }
                    else if (isdigit(s[i])||s[i]=='-')
                    {
                        int j = getDigit(s,i);
                        return stoi(s.substr(i,j-i));
                    }
                    
                    int j = getVar(s, i);
                    var = s.substr(i, j-i);   
                    i = j-1;
                    
                    if (j==b+1)
                        return data[var];                    
                }
                else 
                {
                    if (s[i] == '(')
                    {
                        int j = getRightParenthsis(s,i);
                        val = helper(s,i+1, j-1, data);
                        i = j;
                    }
                    else if (isdigit(s[i])||s[i]=='-')
                    {
                        int j = getDigit(s,i);
                        val = stoi(s.substr(i,j-i));
                        i = j-1;
                    }
                    else if (isalpha(s[i]))
                    {
                        int j = getVar(s,i);
                        val = data[s.substr(i,j-i)];
                        i = j-1;
                    }
                    data[var] = val;
                }
                                                
                flag = 1-flag;
                
            }
        }
        
        return -1;
        
        
    }
    
    int getVar(string &s, int i)
    {
        while (isdigit(s[i])||isalpha(s[i]))
            i++;
        return i;
    }
    
    int getDigit(string &s, int i)
    {
        while (isdigit(s[i])||s[i]=='-')
            i++;
        return i;
    }
    
    int getRightParenthsis(string &s, int i)
    {
        int level = 1;
        i++;
        while (level>0)
        {
                        
            level+=(s[i]=='(');                        
            level-=(s[i]==')');
            if (level==0)
                break;
            i++;
        }        
        return i;
    }
};
