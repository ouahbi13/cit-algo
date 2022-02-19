//Kill the Monster, Problem Link: https://codeforces.com/contest/1633/problem/C

#include<stdio.h>
#include <bits/stdc++.h>
#include <iostream>


using namespace std;

string wonOrLost(long long hc, long long dc, long long hm, long long dm, long long k, long long w, long long a) {
    long long hc_new, dc_new, c_hits_to_win, m_hits_to_win;
    for (int i = 0; i <= k; i++) {
        hc_new = hc + i*a;
        dc_new = dc + (k-i)*w;
        c_hits_to_win = (hm%dc_new == 0) ? hm/dc_new : (hm/dc_new) + 1;
        m_hits_to_win = (hc_new%dm == 0) ? hc_new/dm : (hc_new/dm) + 1;
        if (m_hits_to_win >= c_hits_to_win) return "YES";
    }
    return "NO";
}



int main(){
    double t = 1;
    cin >> t;
    while (t--) {
        long long hc, dc, hm, dm, k, w, a;
        cin >> hc >> dc;
        cin >> hm >> dm;
        cin >> k >> w >> a;
        cout << wonOrLost(hc, dc, hm, dm, k, w, a) << endl;
    }
    return 0;
}