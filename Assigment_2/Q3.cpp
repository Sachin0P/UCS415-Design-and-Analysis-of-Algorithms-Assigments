// Problem 3: Job Sequencing with Deadlines
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<pair<int, pair<int, char>>> jobs(4);
    jobs[0] = make_pair(20, make_pair(4, 'a'));
    jobs[1] = make_pair(10, make_pair(1, 'b'));
    jobs[2] = make_pair(40, make_pair(1, 'c'));
    jobs[3] = make_pair(30, make_pair(1, 'd'));
    int n = 4;
    sort(jobs.begin(), jobs.end());
    reverse(jobs.begin(), jobs.end());
     cout << "Given Jobs:" << endl;
    cout << "ID\tDeadline\tProfit" << endl;
    for (int i = 0; i < n; i++)
        cout << jobs[i].second.second << "\t" << jobs[i].second.first
             << "\t\t" << jobs[i].first << endl;
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].second.first > maxDeadline)
            maxDeadline = jobs[i].second.first;
    }

    bool slot[100] = {false};
    char result[100];
    int totalProfit = 0;
    int jobCount = 0;

    for (int i = 0; i < n; i++) {
        int deadline = jobs[i].second.first;
        for (int t = deadline; t >= 1; t--) {
            if (slot[t] == false) {
                slot[t] = true;
                result[t] = jobs[i].second.second;
                totalProfit += jobs[i].first;
                jobCount++;
                break;
            }
        }
    }

    cout << "\nScheduled Jobs:" << endl;
    cout << "Slot\tJobID" << endl;
    for (int t = 1; t <= maxDeadline; t++) {
        if (slot[t])
            cout << t << "\t" << result[t] << endl;
    }

    cout << "\nNumber of jobs scheduled = " << jobCount << endl;
    cout << "Maximum Total Profit = " << totalProfit << endl;
    return 0;
}