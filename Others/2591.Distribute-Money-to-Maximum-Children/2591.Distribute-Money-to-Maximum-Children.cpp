class Solution {
public:
    int distMoney(int money, int children) 
    {
        if (money < children) return -1;
        if (money==4 && children==1) return -1;
        if (money > children * 8) return children-1;
        
        int d = money - children;
        int k = d / 7;
        int r = d % 7;
        
        if (r==3 && (children-k)==1)
            return k-1;
        else
            return k;
        
    }
};
