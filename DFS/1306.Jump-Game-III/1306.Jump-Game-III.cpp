class Solution {
    int visited[50001];
public:
    bool canReach(vector<int>& arr, int start) 
    {
        if (start<0 || start>=arr.size()) 
            return false;
        if (arr[start]==0)
            return true;
        if (visited[start]==1) 
            return false;

        visited[start] = 1;
        
        if (canReach(arr, start-arr[start]))
            return true;
        
        if (canReach(arr, start+arr[start]))
            return true;

        return false;
    }
};
