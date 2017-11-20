class Solution {
public:
    string countOfAtoms(string formula) 
    {
        stack<map<string,int>>Stack;
        map<string,int>current;
        Stack.push(current);
        
        for (int i=0; i<formula.size(); i++)
        {
            if (formula[i]=='(')
            {
                Stack.push(current);
                current.clear();
            }
            else if (formula[i]==')')
            {
                map<string,int>temp = current;
                
                int j=i+1;
                while (j<formula.size() && isdigit(formula[j]))
                    j++;
                string s = formula.substr(i+1,j-i-1);
                int num;
                if (s.size()!=0)
                    num = stoi(s);
                else
                    num = 1;                
                
                current = Stack.top();
                Stack.pop();
                for (auto a:temp)                
                    current[a.first]+=a.second*num;                
                
                i=j-1;
            }
            else if (formula[i]>='A' && formula[i]<='Z' )
            {
                int j=i+1;
                while (j<formula.size() && formula[j]>='a' && formula[j]<='z')
                    j++;
                string element = formula.substr(i,j-i);
                i=j;
                while (j<formula.size() && isdigit(formula[j]))
                    j++;
                string s = formula.substr(i,j-i);
                int num;
                if (s.size()!=0)
                    num = stoi(s);
                else
                    num = 1;
                current[element]+=num; 
                i=j-1;
            }
        }
        
        string result;
        for (auto a:current)
        {
            result+=a.first;
            if (a.second>1)
                result+=to_string(a.second);
        }
        return result;
            
    }
};
