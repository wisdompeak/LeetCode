// Find all primes <= n.
vector<int>Eratosthenes(int n)
{
    auto q=vector<int>(n+1,0);
    for (int i=2; i<=sqrt(n); i++)
    {
        if (q[i]==0)
        {
            int j=i*2;
            while (j<=n)
            {
                q[j]=1;
                j+=i;
            }
        }
    }
    vector<int>primes;
    for (int i=2; i<=n; i++)
    {
        if (q[i]==0)
            primes.push_back(i);                
    }
    return primes;
}
