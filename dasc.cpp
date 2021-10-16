#include <bits/stdc++.h>
using namespace std;
#include <string.h>
using namespace std;
#define N 10000000;
int i = 0;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p64>> vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i, e) for (ll i = 0; i < e; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout << #x << " = " << x << ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define flash                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

vector<bool> segmentedSieve(long long L, long long R)
{ //Generates primes between L,R
    long long lim = sqrt(R);
    vector<bool> mark(lim + 1, false);
    vector<long long> primes;
    for (long long i = 2; i <= lim; ++i)
    {
        if (!mark[i])
        {
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

ll power(ll a, ll b)
{
    ll result = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
            result *= a;
        a *= a;
        b /= 2;
    }
    return result;
}

void printSubsequence(string input, string output, string a[1000000])
{
    // Base Case
    // if the input is empty print the output string
    //string a[10000000];
    if (input.empty())
    {
        //cout << output << endl;

        a[i] = output;
        i++;
        return;
    }
    //cout<<a;

    // output is passed with including
    // the Ist characther of
    // Input string
    printSubsequence(input.substr(1), output + input[0], a);

    // output is passed without
    // including the Ist character
    // of Input string
    printSubsequence(input.substr(1), output, a);
}
void decToBinary(int n)
{
    if(n==0){
        cout<<"0";
    }
    // array to store binary number
    int binaryNum[32];

    // counter for binary array
    int i = 0;
    while (n > 0)
    {

        // storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    // printing binary array in reverse order
    for (int j = i - 1; j >= 0; j--)
        cout << binaryNum[j];
    cout << ln;
}
int main()
{
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);                       //Inputs
    //freopen("output.txt", "w", stdout);
    //#endif

    /*const int N=1000001;
bool sieve[N];
memset(sieve,true,sizeof(sieve));                             //Sieve
for(int i=2;i*i<=N;i++)
{
   if(sieve[i])
    {
        for(int j=i*i;j<=N;j+=i)
        {
            sieve[j]=0;
        }
    }
}*/
    // int carry = 0;
    // cin >> val;
    // vector <int> arr(10000, 0);
    // arr[0] = 1; //Initial product = 1
    // int k = 0; //Current size of the number stored in arr
    // for(int i = 1; i <= val; i++) {
    //     for(int j = 0;j <= k; j++) {
    //         arr[j] = arr[j] * i + carry;
    //         carry = arr[j] / 10;
    //         arr[j] = arr[j] % 10;
    //     }
    //     while(carry) { //Propogate the remaining carry to higher order digits
    //         k++;
    //         arr[k] = carry % 10;
    //         carry /= 10;
    //     }
    // }
    // for(int i = k; i >= 0; i--) {
    //     cout << arr[i];
    // }
    flash;
    ll t;
    cin >> t;
    while (t--)
    {
        int z;
        vector<int> b;
        string output = "";
        string input;
        cin >> input;
        string a[1000000];

        printSubsequence(input, output, a);
        for (int j = 0; j <= pow(2, input.length()); j++)
        {
            //cout << a[j] << endl;
        }
        i = 0;
        for (int j = 0; j <= pow(2, input.length()); j++)
        {

            if (a[j].length())
            {
                bitset<sizeof(int) * 8> x(a[j]);
                b.push_back(x.to_ulong());
            }
        }
        sort(b.begin(), b.end());
        b.erase(unique(b.begin(), b.end()), b.end());

        // for (int k = 0; k < b.size(); k++)
        // {
        //     //cout << b[k] << endl;
        // }
        for (int l = 0; l < b.size(); l++)
        {
            if (b[l] != l)
            {
                //cout<< l<<endl;
                z = l;
                int n = z;
                decToBinary(n);
                break;
            }
        }
    }
    return 0;
}