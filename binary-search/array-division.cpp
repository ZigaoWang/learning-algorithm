//
// Created by Zigao Wang on 12/24/24.
//

// https://cses.fi/problemset/task/1085

#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

bool check(vector<ll>& a, ll max_sum, int k) {
    int groups = 1;
    ll curr_sum = 0;
    for (ll x : a) {
        if (x > max_sum) return false;
        if (curr_sum + x > max_sum) {
            groups++;
            curr_sum = x;
        } else {
            curr_sum += x;
        }
    }
    return groups <= k;
}

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<ll> a(n);
    ll left = 0, right = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        left = max(left, a[i]);
        right += a[i];
    }
    
    while (left < right) {
        ll mid = left + (right - left) / 2;
        if (check(a, mid, k)) right = mid;
        else left = mid + 1;
    }
    
    cout << left << endl;
    return 0;
}
