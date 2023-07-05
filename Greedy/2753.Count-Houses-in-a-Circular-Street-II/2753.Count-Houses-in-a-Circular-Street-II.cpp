/**
 * Definition for a street.
 * class Street {
 * public:
 *     Street(vector<int> doors);
 *     void closeDoor();
 *     bool isDoorOpen();
 *     void moveRight();
 * };
 */
class Solution {
public:
    int houseCount(Street* street, int k) 
    {
        while (!street->isDoorOpen())
            street->moveRight();
        street->moveRight();

        int step = 1;
        int lastOpen = 0;
        for (int i=0; i<k; i++)
        {
            if (street->isDoorOpen())
            {
                lastOpen = step;
                street->closeDoor();                
            }            
            step++;
            street->moveRight();
       }
       return lastOpen;
    }
};
