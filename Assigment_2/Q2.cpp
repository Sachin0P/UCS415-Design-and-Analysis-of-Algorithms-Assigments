#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {900, 940, 950, 1100, 1500, 1800};
    int dep[] = {910, 1200, 1120, 1130, 1900, 2000};
    int n = 6;

    

    sort(arr, arr + n);
    sort(dep, dep + n);

    int platforms = 1, maxPlatforms = 1;
    int i = 1, j = 0;

    while (i < n && j < n) {
        if (arr[i] <= dep[j]) {
            platforms++;
            i++;
        } else {
            platforms--;
            j++;
        }
        if (platforms > maxPlatforms)
            maxPlatforms = platforms;
    }

    cout << "\nMinimum platforms required = " << maxPlatforms << endl;
    return 0;
}