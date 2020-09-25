class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) 
    {
        int n = warehouse.size();        
        sort(boxes.begin(), boxes.end());
        reverse(boxes.begin(), boxes.end());
        
        int count = 0;
        int i = 0, j = warehouse.size()-1;
        for (auto box: boxes)
        {
            if (i>j) break;
            if (box > max(warehouse[i], warehouse[j])) continue;
            if (warehouse[j] < box || (warehouse[i] >=box && warehouse[i] < warehouse[j]))
                i++;
            else
                j--;
            count++;  
        }
                
        return count;        
    }
};
