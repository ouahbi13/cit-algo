// Vanya and Lanterns, Problem Link: https://codeforces.com/problemset/problem/492/B

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

double findMinimumDistance(double arr[], int n, double l) {
    double maximumDiff = 0;
    for (int i = 0; i < n-1; i++) {
        if (arr[i+1] - arr[i] > maximumDiff) {
            maximumDiff = arr[i+1] - arr[i];
        }
    }
    return max(max(arr[0], maximumDiff / 2), l - arr[n-1]);
}



int main() {
    int n; int l;
    cin >> n >> l;

    double positions[n];
    for (int i = 0; i < n; i++) {
        cin >> positions[i];
    }

    sort(positions, positions + n);

    cout << fixed << findMinimumDistance(positions, n, l);

    return 0;
}