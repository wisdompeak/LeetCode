class MKAverage {
    int m,k;
    multiset<int>Set1;
    multiset<int>Set2;
    multiset<int>Set3;    
    long sum = 0;
    queue<int>q;
    vector<int>temp;
public:
    MKAverage(int m, int k) 
    {
        this->m = m;
        this->k = k;        
    }
    
    void addElement(int num) 
    {                
        q.push(num);
        temp.push_back(num);
        
        if (q.size() == m)
        {                        
            sort(temp.begin(), temp.end());
            for (int i=0; i<k; i++)
                Set1.insert(temp[i]);
            for (int i=k; i<m-k; i++)
            {
                Set2.insert(temp[i]);
                sum += temp[i];
            }                
            for (int i=m-k; i<m; i++)
                Set3.insert(temp[i]);
        }            
        else if (q.size() == m+1)
        {
            int x = q.front();
            q.pop();
            
            // delete the old element
            if (Set1.find(x)!=Set1.end())
                Set1.erase(Set1.lower_bound(x));
            else if (Set3.find(x)!=Set3.end())
                Set3.erase(Set3.lower_bound(x));
            else
            {
                Set2.erase(Set2.lower_bound(x));
                sum -= x;
            }                
            
            // add the new element
            if (!Set1.empty() && num <= *Set1.rbegin())
                Set1.insert(num);
            else if (!Set3.empty() && num >= *Set3.begin())
                Set3.insert(num);
            else
            {
                Set2.insert(num);
                sum += num;
            }
                          
            // adjust the three sets
            while (Set1.size() > k)
            {
                int y = *Set1.rbegin();
                Set1.erase(Set1.lower_bound(y));
                Set2.insert(y);
                sum += y;
            }            
            while (Set3.size() > k)
            {
                int y = *Set3.begin();
                Set3.erase(Set3.lower_bound(y));
                Set2.insert(y);
                sum += y;
            }
            
            while (Set1.size() < k)
            {
                int y = *Set2.begin();
                Set2.erase(Set2.lower_bound(y));
                Set1.insert(y);
                sum -= y;
            }            
            while (Set3.size() < k)
            {
                int y = *Set2.rbegin();
                Set2.erase(Set2.lower_bound(y));
                Set3.insert(y);
                sum -= y;
            }                        
        }
    }
    
    int calculateMKAverage() 
    {
        if (q.size() < m)
            return -1;
        else
            return sum / (m-2*k);        
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */

