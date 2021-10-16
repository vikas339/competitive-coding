#include <bits/stdc++.h>  
using namespace std;
 
typedef long long ll;


#define flash ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

 

vector<bool> segmentedSieve(long long L, long long R) {      //Generates primes between L,R             
 long long lim = sqrt(R);
 vector<bool> mark(lim + 1, false);
vector<long long> primes;
 for (long long i = 2; i <= lim; ++i) {
 if (!mark[i]) {
 primes.emplace_back(i);
for (long long j = i * i; j <= lim; j += i)
mark[j] = true;
}
}
vector<bool> isPrime(R - L + 1, true);
for (long long i : primes)
for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
isPrime[j - L] = false;
if (L == 1)
isPrime[0] = false;
return isPrime;
}


string decimalToBinary(int n)
{
    string s = bitset<64> (n).to_string();
    const auto loc1 = s.find('1');
      
    if(loc1 != string::npos)
        return s.substr(loc1);
      
    return "0";
}
int isSubstring(string s1, string s2)
{
    int M = s1.length();
    int N = s2.length();
 
    for (int i = 0; i <= N - M; i++) {
        int j;
 
        
        for (j = 0; j < M; j++)
            if (s2[i + j] != s1[j])
                break;
 
        if (j == M)
            return i;
    }
 
    return -1;
}
bool isSubSequence(string str1, string str2)
{
    int m=str1.length();
    int n=str2.length();
    int k = 0; 
    for (int i = 0; i < n && k < m; i++)
        if (str1[k] == str2[i])
            k++;
 
    
    return (k == m);
}
int main()
{
    flash;
    ll t;
    cin >> t;
    while(t--)
    {
        string v;
        cin>>v;
        int i=0;
        while(true)
        {
            string num=decimalToBinary(i);
            if(isSubSequence(num,v)==0)
            {
                cout<<num;
                break;
            }
            i++;
        }
        cout<<"\n";
    }
    return 0;
}