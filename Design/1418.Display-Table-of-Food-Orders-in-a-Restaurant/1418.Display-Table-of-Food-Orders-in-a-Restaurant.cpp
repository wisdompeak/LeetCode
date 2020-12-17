class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) 
    {
        map<int, unordered_map<string, int>>table2Order;
        set<string>foodNames;
        for (auto order:orders)
        {
            table2Order[stoi(order[1])][order[2]]++;
            foodNames.insert(order[2]);
        }
        
        int i = 1;
        unordered_map<string,int>food2index;
        for (auto food: foodNames)        
        {
            food2index[food] = i;
            i++;
        }
        
        vector<vector<string>>rets;

        vector<string>header({"Table"});
        for (auto x:foodNames) header.push_back(x);        
        rets.push_back(header);
        
        for (auto x:table2Order)
        {            
            int id = x.first;
            auto order = x.second;

            vector<string>row(foodNames.size()+1, "0");
            row[0] = to_string(id);
            
            for (auto y: order)
            {
                int col = food2index[y.first];
                int num = y.second;
                row[col] = to_string(num);
            }            
            rets.push_back(row);            
        }
        
        return rets;
    }
};
