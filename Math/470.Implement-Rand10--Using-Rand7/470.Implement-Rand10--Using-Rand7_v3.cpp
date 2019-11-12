// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
    stack<int>Stack;
public:
    int rand10() 
    {
        int n = 7;
        int upper = pow(7,n)/10*10;
        int digits = log(upper)/log(10);     
        
        while (Stack.empty())
        {
            int x = 0;
            for (int i=0; i<n; i++)
                x = x*7+rand7()-1;
                   
            if (x<upper)
            {                
                for (int j=0; j<digits; j++)
                {
                    Stack.push(x%10+1);
                    x = x/10;
                }                
            }            
        }
        int ret = Stack.top();
        Stack.pop();
        return ret;
    }    
};
