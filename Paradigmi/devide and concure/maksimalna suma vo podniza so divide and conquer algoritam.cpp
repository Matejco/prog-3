#include <bits/stdc++.h>
using namespace std;

int maxSuma(vector<int>& a, int l, int mid, int r) {
    int sum = 0;
    int leftMax = INT_MIN;

    // od levo do mid
    for (int i = mid; i >= l; i--) {
        sum += a[i];
        leftMax = max(leftMax, sum);
    }

    sum = 0;
    int rightMax = INT_MIN;

    // od desno do mid
    for (int i = mid + 1; i <= r; i++) {
        sum += a[i];
        rightMax = max(rightMax, sum);
    }

    return leftMax + rightMax;
}

int maxSuma_p(vector<int>& a, int l, int r) {
    if (l == r)
        return a[l];

    int mid = (l + r) / 2;

    return max({maxSuma_p(a, l, mid), maxSuma_p(a, mid + 1, r), maxSuma(a, l, mid, r)});
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << maxSuma_p(a, 0, n - 1) << endl;
    return 0;
}