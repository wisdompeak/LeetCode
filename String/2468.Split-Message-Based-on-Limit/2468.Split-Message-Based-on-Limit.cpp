class Solution {
public:
    vector<string> splitMessage(string message, int limit) 
    {
        for (int len=1; 3+2*len < limit; len++)
        {
            int num = pow(10,len)-1;
            int cost = (3+len) * num;
            for (int i=1; i<=len; i++)
                cost += i * ((pow(10,i)-1) - (pow(10, i-1)-1));
                        
            if (limit*num - cost >= (int)message.size())            
                return get(message, limit, len);            
        }
        
        return {};
    }
    
    vector<string>get(string message, int limit, int len)
    {
        vector<string> rets;
        int count = 0;
        int part = 0;
        while (count < message.size())
        {
            part++;
            int cost = 3+len+to_string(part).size();
            int k = min((int)message.size() - count, limit-cost);
            rets.push_back(message.substr(count, k) + "<" + to_string(part) + "/");
            count += k;
        }
        
        for (string& ret: rets)
            ret += to_string(part) + ">";
        
        return rets;                
    }
    
   
};
