#include <bits/stdc++.h>
using namespace std;

void countFreq(int arr[]) {
    int n = sizeof(arr) / sizeof(arr[0]);

    unordered_map<int ,int> map;

    for (int i = 0 ; i < n ; i++) {
        map[arr[i]]++;
    }

    for (auto it : map) {
        cout << it.first << " " << it.second <<endl;
    }

}

void minmaxFreq ( int arr[],int n) {

    map<int ,int> freq;

    for (int i = 0 ; i < n ; i++) {
        freq[arr[i]]++;
    }

    int maxFreq = 0 ;
    int minFreq = n;
    int maxEle = 0;
    int minEle = 0;

    for (auto it : freq) {
        int count = it.second ;
        int element = it.first;

        if (count > maxFreq) {
            maxFreq = count;
            maxEle = element;
        }
        if (count < minFreq) {
            minFreq = count;
            minEle = element;
        }
    }

    cout << "The highest frequency element is: " << maxEle << "\n";
    cout << "The lowest frequency element is: " << minEle << "\n";

}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[] = {10,5,10,15,10,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    minmaxFreq(arr,n);

    return 0;
}
