using PIS = pair<int,string>;
class SORTracker {
    priority_queue<PIS>pq1;
    priority_queue<PIS,vector<PIS>,greater<>>pq2;
    PIS cur;
public:
    SORTracker() 
    {        
        pq1.push({INT_MIN, "#"});
    }
    
    void add(string name, int score) 
    {
        PIS temp = make_pair(-score, name);
        if (temp > pq1.top())
            pq2.push(temp);
        else
        {
            pq2.push(pq1.top());
            pq1.pop();
            pq1.push(temp);            
        }
    }
    
    string get() 
    {
        auto temp = pq2.top();
        pq1.push(temp);
        pq2.pop();
        return temp.second;
    }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */
