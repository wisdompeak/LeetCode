class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) 
    {
        sort(boxes.begin(), boxes.end());
        reverse(boxes.begin(), boxes.end());
        
        int count = 0;
        int j = 0;
        for (int box: boxes)
        {
            if (j==warehouse.size()) break;
            if (box <= warehouse[j])
            {
                j++;
                count++;
            }                
        }
        return count;
    }
};
