class Solution {
public:
    bool isPowerOfFour(int num) 
    {
        if (num==1)
            return true;
        else if (num>0 && (num&(num-1))==0 && (num-1)%3==0)
            return true;
        else
            return false;
    }
};
