#include <bits/stdc++.h>
#define for0(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define forc(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i)
#define forr0(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define forr1(i, n) for (int i = (int)(n); i >= 1; --i)

#define pb push_back
#define fi first
#define se second

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin, (x).rend()

#define tr(c,i) for(__typeof__((c)).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define sz(a) int((a).size())

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    // sort(a.begin(), a.end());
    int e = 0 , b =  0, c = 0, d = 0;
    for(int i = 0; i<n;i++){
        bool ok2 = false;
        for(int j = i + 1; j<n; j++){
            bool ok1 = false;
            for(int k = j+1; k < n; k++){
                // cout<<i<<" "<<j<<" "<<k<<endl;
                vector<int>x;
                // cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<endl;
                x.push_back(a[i]);
                x.push_back(a[j]);
                x.push_back(a[k]);
                // cout<<x[0]<<endl;
                sort(x.begin(), x.end());
                // int res = a[k] - a[i] - a[j];
                int res = -(x[2] - x[1] - x[0]);
                // cout<<res<<endl;
                if(res <= 0 || res > 2500000) continue;
                
                
                int m  = lower_bound(a.begin(), a.end(), res) - a.begin() + 1;  
                // cout<<m<<endl;
                // m >= 0 && m <n && 
                // cout<<(a[m] == res)<<endl;
                if (a[m] == res && m != i && m != j && m != k){
                    // cout<<"adfas"<<endl;
                    e = i ;
                    b = m ;
                    c = k ;
                    d = j ;
                    if(a[e] < a[c]) swap(e,c);
                    if(a[e] < a[d]) swap(e,d);

                    if(a[b] > a[c]) swap(c,b);
                    if(a[b] > a[d]) swap(b,d);

                    // cout<<a[e] <<a[b]<<a[c]<<a[d]<<endl;
                    // cout<<e<<" "<<b<<" "<<c<<" "<<d<<endl;
                    e++;
                    b++;
                    c++;
                    d++;
                    ok1 = true;
                    break;
                }else continue;
            }
            if(ok1){
                ok2 = true;
                break;
            }
        }
        if(ok2){
            break;
        }
    }
    // cout<<e<<" "<<b<<" "<<c<<" "<<d<<endl;
    if(e == 0){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
        cout<<e<<" "<<b<<" "<<c<<" "<<d<<endl;
    }
    return 0;
}