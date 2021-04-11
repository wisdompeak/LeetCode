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
    
    void shiftRight(multiset<int>&A, multiset<int>&B)
    {
        B.insert(*A.rbegin());
        A.erase(--A.end());
    }

    void shiftLeft(multiset<int>&A, multiset<int>&B)
    {
        A.insert(*B.begin());
        B.erase(B.begin());
    }

    void addElement(int num) 
    {                
        if (q.size() < m)
        {                        
            q.push(num);
            Set2.insert(num);
            sum += num;

            if (q.size()==m)
            {
                while (Set1.size()<k)
                {
                    sum -= *Set2.begin();
                    shiftLeft(Set1, Set2);
                }                    
                while (Set3.size()<k)
                {
                    sum -= *Set2.rbegin();
                    shiftRight(Set2, Set3);
                }                    
            }
        }            
        else if (q.size() == m)
        {
            // add the new element
            q.push(num);
            if (!Set1.empty() && num <= *Set1.rbegin())
                Set1.insert(num);
            else if (!Set3.empty() && num >= *Set3.begin())
                Set3.insert(num);
            else
            {
                Set2.insert(num);
                sum += num;
            }

            if (Set1.size() > k)
            {   
                sum += *Set1.rbegin();                             
                shiftRight(Set1, Set2);
            }            
            if (Set3.size() > k)
            {
                sum += *Set3.begin();
                shiftLeft(Set2, Set3);
            }
            
            // delete the old element
            int x = q.front();
            q.pop();
            if (Set1.find(x)!=Set1.end())
                Set1.erase(Set1.find(x));
            else if (Set3.find(x)!=Set3.end())
                Set3.erase(Set3.find(x));
            else
            {
                sum -= x;
                Set2.erase(Set2.find(x));                
            }                
                        
            if (Set1.size() < k)
            {
                sum -= *Set2.begin();
                shiftLeft(Set1, Set2);                
            }            
            if (Set3.size() < k)
            {
                sum -= *Set2.rbegin();
                shiftRight(Set2, Set3);
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

