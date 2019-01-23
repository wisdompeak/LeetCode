// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() 
    {
        int a = rand7();
        int b = rand7();
        int x = (a-1)*7+(b-1);
        if (x>=40) return rand10();
        return x%10+1;
    }
};
