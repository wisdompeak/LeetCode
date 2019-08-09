class StockSpanner {
    vector<int>arr;
    stack<int>Stack;
    int i;
public:
    StockSpanner() {
        i = 0;
    }
    
    int next(int price) 
    {
        arr.push_back(price);
        int ret;
        
        if (Stack.empty() || arr[Stack.top()] > arr[i])
        {
            ret = 1;
            Stack.push(i);
        }
        else
        {
            while (!Stack.empty() && arr[Stack.top()] <= arr[i])
                Stack.pop();
            if (!Stack.empty())
                ret = i - Stack.top();
            else
                ret = i+1;
            Stack.push(i);
        }
        
        i++;
        
        return ret;           
    }
};
