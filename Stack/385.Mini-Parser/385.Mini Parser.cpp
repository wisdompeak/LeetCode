/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) 
    {
        if (s[0]!='[') return NestedInteger(stoi(s));
        
        stack<NestedInteger>Stack;
        
        for (int i=0; i<s.size(); i++)
        {
            if (s[i]=='[')
                Stack.push(NestedInteger());
            else 
            {
                int i0=i;
                while (i<s.size() && s[i]!=',' && s[i]!=']')
                    i++;
                if (i>i0)
                {
                    int num = stoi(s.substr(i0,i-i0));
                    Stack.top().add(NestedInteger(num));
                }
                
                if (s[i]==']' && Stack.size()>1)
                {
                    NestedInteger temp=Stack.top();
                    Stack.pop();
                    Stack.top().add(temp);
                }
            }
        }
        
        return Stack.top();
    }
};
