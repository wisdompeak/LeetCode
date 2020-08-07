/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     // Compares 4 different elements in the array
 *     // return 4 if the values of the 4 elements are the same (0 or 1).
 *     // return 2 if three elements have a value equal to 0 and one element has value equal to 1 or vice versa.
 *     // return 0 : if two element have a value equal to 0 and two elements have a value equal to 1.
 *     int query(int a, int b, int c, int d);
 *
 *     // Returns the length of the array
 *     int length();
 * };
 */

class Solution {
public:
    int guessMajority(ArrayReader &reader) 
    {
        int n = reader.length();
        int base = reader.query(0,1,2,3);        
        int count0 = 1, count1 = 0;
        int idxDiff = -1;
        for (int i=4; i<n; i++) // check arr[i] == arr[0] ?
        {
            if (base == reader.query(1,2,3,i))
                count0 += 1;
            else
            {
                count1 += 1;
                idxDiff = i;
            }
                
        }
        
        if (reader.query(0,2,3,4) == reader.query(1,2,3,4)) // check arr[1] == arr[0]
            count0 += 1;
        else
        {
            count1 += 1;
            idxDiff = 1;
        }
            
        
        if (reader.query(0,1,3,4) == reader.query(1,2,3,4)) // check arr[2] == arr[0]
            count0 += 1;
        else
        {
            count1 += 1;
            idxDiff = 2;
        }
            
        
        if (reader.query(0,1,2,4) == reader.query(1,2,3,4)) // check arr[3] == arr[0]
            count0 += 1;
        else
        {
            count1 += 1;
            idxDiff = 3;
        }
            
        if (count0>count1) return 0;
        else if (count0<count1) return idxDiff;
        else return -1;                
        
    }
};
