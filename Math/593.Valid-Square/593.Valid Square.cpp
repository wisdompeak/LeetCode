class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) 
    {
        unordered_set<int>Set;
        
        Set.insert(distance(p1,p2));
        Set.insert(distance(p1,p3));
        Set.insert(distance(p1,p4));
        Set.insert(distance(p2,p3));
        Set.insert(distance(p2,p4));
        Set.insert(distance(p3,p4));
        
        return (Set.count(0)==0 && Set.size()==2);
    }
    
    int distance(vector<int>a, vector<int>b)
    {
        return (a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]);
    }
};
