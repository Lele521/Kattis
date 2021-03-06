// Michael Pfeifer
// Version 03, 2018/01/17

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;

const ld  pi   = 4.0*atanl(1.0);
const int iinf = 1e9 + 10;
const ll  inf  = 1e18 + 10;
const int mod  = 1000000007;
const ld  prec = .000001;

#define enld endl
#define endl '\n'
#define pb push_back
#define debug(x) cout<<#x<<" -> "<<x<<'\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); ++i)
#define umap unordered_map
#define uset unordered_set

template<class TIn>
using indexed_set = tree<
        TIn, null_type, less<TIn>,
        rb_tree_tag, tree_order_statistics_node_update>;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

void file() {
    auto a = freopen("a.in",  "r", stdin);
    auto b = freopen("a.out", "w", stdout);
    if(!a || !b) cout << "uh oh" << endl;
}




ll calc(ll hi, ll lo) {
    return hi*hi - lo*lo;
}

int main() {
    //file();
    //fast();

    ll n;
    cin >> n;

    bool printed = false;
    for(ll i = 1; i < 125000; i++) {
        ll lo = 0;
        ll hi = i;

        while(hi - lo > 1) {
            ll mid = (hi + lo) / 2;
            if(calc(i, mid) < n) {
                hi = mid-1;
            }
            else {
                lo = mid;
            }
        }

        if(calc(i,lo) == n) {
            printed = true;
            cout << lo << " " << i << endl;
            break;
        }
    }

    if(!printed) {
        cout << "impossible" << endl;
    }

    return 0;
}
