class Solution {
    vector<string>output;
public:
    vector<string> addOperators(string num, int target) 
    {
        DFS(num,(long long)target,0,0,"");
        return output;
    }
    
    void DFS(string num, long long target, long long curRes, long long product, string expression)
    {
        //cout<<expression<<" "<<curRes<<endl;

        if (num.size()==0 && curRes==target)
        {
            output.push_back(expression);
            return;
        }
        
        for (int i=1; i<=num.size(); i++)
        {            
            string curString=num.substr(0,i);
            string nextString=num.substr(i);
            if (curString.size()>1 && curString[0]=='0') return;
            
            if (expression.size()==0)
                DFS(nextString,target,stoll(curString),stoll(curString),curString);
            else
            {
                DFS(nextString,target,curRes+stoll(curString),stoll(curString),expression+'+'+curString);
                DFS(nextString,target,curRes-stoll(curString),-stoll(curString),expression+'-'+curString);
                DFS(nextString,target,curRes-product+product*stoll(curString),product*stoll(curString),expression+'*'+curString);
            }
        }        
    }
};
