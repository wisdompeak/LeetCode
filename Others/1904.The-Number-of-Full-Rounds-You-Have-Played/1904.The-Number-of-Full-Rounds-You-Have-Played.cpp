class Solution {
public:
    int numberOfRounds(string startTime, string finishTime) 
    {
        vector<int>start = {stoi(startTime.substr(0,2)), stoi(startTime.substr(3))};
        vector<int>end = {stoi(finishTime.substr(0,2)), stoi(finishTime.substr(3))};

        start[1] = (start[1]+14) / 15 * 15;
        end[1] = end[1] / 15 * 15;

        int a = start[0]*60+start[1];
        int b = end[0]*60+end[1];

        if (a > b)
            b += 24*60;

        return (b-a)/15;
    }
};
