#include <bits/stdc++.h>
using namespace std;
struct segment
{
    int n;
    vector<int> tree;
    segment(vector<int> &arr)
    {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 1, 0, n - 1);
    }
    void build(vector<int> &arr, int node, int start, int end)
    {
        if (start == end)
        {
            tree[node] = arr[start];
        }
        else
        {
            int mid = (start + end) / 2;
            build(arr, 2 * node, start, mid);
            build(arr, 2 * node + 1, mid + 1, end);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
            tree[node] = min(tree[2 * node], tree[2 * node + 1]);
            tree[node] = max(tree[2 * node], tree[2 * node + 1]);
        }
    }
    int sum(int node, int start, int end, int l, int r)
    {
        if (r < start || l > end)
            return 0;
        if (l <= start && r >= end)
            return tree[node];
        int mid = (start + end) / 2;
        return sum(2 * node, start, mid, l, r) + sum(2 * node + 1, mid + 1, end, l, r);
    }

    int minr(int node, int start, int end, int l, int r)
    {
        if (r < start || l > end)
            return INT_MAX;
        if (l <= start && r >= end)
            return tree[node];
        int mid = (start + end) / 2;
        return min(minr(2 * node, start, mid, l, r), minr(2 * node + 1, mid + 1, end, l, r));
    }
    int maxr(int node, int start, int end, int l, int r)
    {
        if (r < start || l > end)
            return INT_MIN;
        if (l <= start && r >= end)
            return tree[node];
        int mid = (start + end) / 2;
        return max(maxr(2 * node, start, mid, l, r), maxr(2 * node + 1, mid + 1, end, l, r));
    }
};
int main()
{
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    segment st(arr);
    cout << st.sum(1, 0, arr.size() - 1, 0, 5) << endl;
    cout << st.minr(1, 0, arr.size() - 1, 0, 5) << endl;
    cout << st.maxr(1, 0, arr.size() - 1, 0, 5) << endl;
}