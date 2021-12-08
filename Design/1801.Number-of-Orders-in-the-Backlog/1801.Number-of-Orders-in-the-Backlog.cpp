typedef pair<long,long> PII; //{price,amount}

class Solution {    
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) 
    {
        priority_queue<PII>buy;
        priority_queue<PII, vector<PII>, greater<>>sell;
        
        long ret = 0;
        long M = 1e9+7;
        
        for (auto order: orders)
        {
            ret = (ret+order[1]) % M;
            
            if (order[2]==0)
            {
                while (order[1]>0 && !sell.empty() && sell.top().first <= order[0])
                {
                    auto [price, amount] = sell.top();
                    sell.pop();
                    long num = min(amount, (long)order[1]);
                    amount-=num;
                    order[1]-=num;
                    ret = (ret - num*2 + M) % M;
                    if (amount > 0)
                        sell.push({price, amount});                    
                }
                if (order[1] > 0)
                    buy.push({order[0], order[1]});
            } 
            else
            {
                while (order[1]>0 && !buy.empty() && buy.top().first >= order[0])
                {
                    auto [price, amount] = buy.top();
                    buy.pop();
                    long num = min(amount, (long)order[1]);
                    amount-=num;
                    order[1]-=num;
                    ret = (ret - num*2 + M) % M;
                    if (amount > 0)
                        buy.push({price, amount});                    
                }
                if (order[1] > 0)
                    sell.push({order[0], order[1]});
            }
        }
        
        return ret;
    }
};
