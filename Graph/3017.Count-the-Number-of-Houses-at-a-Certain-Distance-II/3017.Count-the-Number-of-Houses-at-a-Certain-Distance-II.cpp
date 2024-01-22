using LL = long long;
class Solution {
    LL count[100005];
    int n;
public:
    vector<long long> countOfPairs(int n, int x, int y) 
    {
        if (x>y) return countOfPairs(n, y, x);
        this->n = n;

        vector<LL>rets;

        if (abs(x-y)<=1)
        {
            for (int t=1; t<=n; t++)
                rets.push_back((n-t)*2);
            return rets;            
        }

        f1(x-1);
        f1(n-y);

        cout<<"OK"<<endl;

        f2(x-1, n-y);
        cout<<"OK"<<endl;

        int d = y-x+1;
        f3(x-1, (d-1)/2, (d-1)-(d-1)/2);
        f3(n-y, (d-1)/2, (d-1)-(d-1)/2);
        cout<<"OK"<<endl;

        for (int t=1; t<=n; t++)
            count[t] *= 2;
        cout<<"OK1"<<endl;

        f4(d);
        cout<<"OK2"<<endl;
        
        for (int t=1; t<=n; t++)
            rets.push_back(count[t]);

        return rets;
    }

    void f1(LL a)
    {
        for (int t=1; t<=n; t++)
        {
            LL lower = 1;
            LL upper = a-t;
            count[t] += max(0LL, upper-lower+1);
        }             
    }

    void f2(LL a, LL b)
    {
        for (int t=1; t<=n; t++)
        {
            LL lower = max(1LL, a+3-t);
            LL upper = min(a, a+2+b-t);
            count[t] += max(0LL, upper-lower+1);
        }             
    }

    void f3(LL a, LL p, LL q)
    {
        for (int t=1; t<=n; t++)
        {
            LL lower = max(1LL, a+2-t);
            LL upper = min(a, a+1+p-t);
            count[t] += max(0LL, upper-lower+1);
        } 
        for (int t=1; t<=n; t++)
        {
            LL lower = max(1LL, a+2-t);
            LL upper = min(a, a+1+q-t);
            count[t] += max(0LL, upper-lower+1);
        }  
        for (int t=1; t<=n; t++)
        {
            if (a>=t) count[t] += 1;
        }    
    }

    void f4(LL d)
    {
        for (int t=1; t<=n; t++)
        {
            if (t < d-t)
                count[t] += d*2;
            else if (t == d-t)
                count[t] += d;
        }
    }
};
