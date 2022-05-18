#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <istream>
#include <fstream>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <deque>
#include <queue>

using namespace std;

const int MAXN = 200000;
long long rsq[MAXN * 4];
long long a[MAXN];
int INF = numeric_limits<int>::max();

void build(int in_Vertex, int in_Left, int in_Right) {
    if (in_Left + 1 == in_Right) {
        rsq[in_Vertex] = a[in_Left];
    }
    else {
        int m = (in_Left + in_Right) / 2;
        build(in_Vertex * 2 + 1, in_Left, m);
        build(in_Vertex * 2 + 2, m, in_Right);
        rsq[in_Vertex] = min(rsq[2 * in_Vertex + 1], rsq[2 * in_Vertex + 2]);
    }
}
void set(int in_Vertex, int in_Left, int in_Right, int in_IndChange, long long in_ValueChange) {
    if (in_Left + 1 == in_Right) {
        rsq[in_Vertex] = in_ValueChange;
    }
    else {
        int avg = (in_Left + in_Right) / 2;
        if (in_IndChange < avg)
            set(in_Vertex * 2 + 1, in_Left, avg, in_IndChange, in_ValueChange);
        else
            set(in_Vertex * 2 + 2, avg, in_Right, in_IndChange, in_ValueChange);

        rsq[in_Vertex] = min(rsq[2 * in_Vertex + 1], rsq[2 * in_Vertex + 2]);
    }
}
long long get(int in_Vertex, int in_Left, int in_Right, int in_LeftPos, int in_RightPos) {
    if (in_RightPos <= in_Left || in_Right <= in_LeftPos)
        return INF;

    if (in_LeftPos <= in_Left && in_Right <= in_RightPos)
        return rsq[in_Vertex];
    int avg = (in_Left + in_Right) / 2;
    return min(get(2 * in_Vertex + 1, in_Left, avg, in_LeftPos, in_RightPos),
        get(2 * in_Vertex + 2, avg, in_Right, in_LeftPos, in_RightPos));
}

int main() {
    long long n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    build(0, 0, n);

    for (int i = 0; i <= n - m; ++i)
        cout << get(0, 0, n, i, i + m) << "\n";

    return 0;
}