class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) 
    {
        int curMin = INT_MAX;
        vector<int>cap(warehouse.size());
        for (int i=0; i<warehouse.size(); i++)
        {
            curMin = min(curMin, warehouse[i]);
            cap[i] = curMin;
        }
        reverse(cap.begin(), cap.end());
        sort(boxes.begin(), boxes.end());
        
        int j = 0, count = 0;
        for (int i=0; i<boxes.size(); i++)
        {
            while (j<cap.size() && boxes[i]>cap[j])
                j++;
            if (j<cap.size())
            {
                count++;
                j++;
            }
        }
        return count;
    }
};
