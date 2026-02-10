#include <bits/stdc++.h>
using namespace std;
int main() {
    int s[] = {1, 3, 0, 5, 8, 5};
    int f[] = {2, 4, 6, 7, 9, 9};
    int n = 6;

    vector<pair<int,int>> act(n);
    for (int i = 0; i < n; i++)
        act[i] = make_pair(f[i], s[i]);

    sort(act.begin(), act.end());

    cout << "Activities :" << endl;
    for (int i = 0; i < n; i++)
        cout << "Start: " << act[i].second << ", Finish: " << act[i].first << endl;

    cout << "\nSelected Activities:" << endl;
    int count = 1;
    int lastFinish = act[0].first;
    cout << "Start: " << act[0].second << ", Finish: " << act[0].first << endl;

    for (int i = 1; i < n; i++) {
        if (act[i].second >= lastFinish) {
            cout << "Start: " << act[i].second << ", Finish: " << act[i].first << endl;
            lastFinish = act[i].first;
            count++;
        }
    }

    cout << "\nMaximum number of activities = " << count << endl;
    return 0;
}
