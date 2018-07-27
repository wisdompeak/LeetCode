class Solution {
public:
    vector<int> diffWaysToCompute(string input) 
    {
        vector<int>results;
        vector<int>vals1;
        vector<int>vals2;
        for (int i=0; i<input.size(); i++)
        {
            if (input[i]!='+' && input[i]!='-' && input[i]!='*')
                continue;
            vals1 = diffWaysToCompute(input.substr(0,i));
            vals2 = diffWaysToCompute(input.substr(i+1));
            for (int a : vals1)
                for (int b: vals2)
                {
                    if (input[i]=='+') results.push_back(a+b);
                    else if (input[i]=='-') results.push_back(a-b);
                    else if (input[i]=='*') results.push_back(a*b);
                }
        }
        if (results.empty())
            results.push_back(stoi(input));
        return results;
    }
};
