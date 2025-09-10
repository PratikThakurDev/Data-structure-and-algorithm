#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n) {
    for ( int i = 0 ; i < n-1 ; i++) {
        int min = arr[i];
        int index = i;
        for (int j = i ; j < n ; j++) {
            if ( min > arr[j]) {
                min = arr[j];
                index = j;
            }
        }
        swap(arr[index],arr[i]);
    }

    for ( int i = 0 ; i < n ; i++) {
        cout<<arr[i]<<" ";
    }
}

void bubbleSort(int arr[], int n) {
    for (int i = 0 ; i < n-1 ; i++) {
        int didSwap = 0;
        for (int j = 0 ; j < n-1-i ; j++) {
            if ( arr[j] > arr[j+1]) {
                swap(arr[j],arr[j+1]);
                didSwap = 1;
            }
        }
        if (didSwap == 0) {
            break;
        }
    }
        for ( int i = 0 ; i < n ; i++) {
        cout<<arr[i]<<" ";
    }

}

void insertionSort(int arr[], int n) {
    for (int i = 0 ; i < n-1 ; i++) {

        for ( int j = i + 1 ; j > 0 ; j--) {
            while (true) {
                if(arr[j-1]<arr[j]) {
                    break;
                }
                swap(arr[j-1],arr[j]);
            }
        }
    }
    for ( int i = 0 ; i < n ; i++) {
        cout<<arr[i]<<" ";
    }
}

void mergeArray(vector <int> &arr , int low , int mid , int high) {
    vector <int> temp ;
    int left = low;
    int right = mid+1;
    while ( left <= mid && right <= high) {
        if (arr[left] <= arr[right] ) {
            temp.push_back(arr[left]);
            left++;
        } 
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while ( left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }
    while ( right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    for ( int i = low ; i <= high ; i++) {
        arr[i] = temp[i - low];

    }

}

void mergeSort (vector <int> &arr , int low , int high) {
    if (low == high) return ;
    int mid =( low + high)/2 ;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1, high) ;
    mergeArray(arr,low,mid,high);
}

int getIndex ( vector <int> &arr , int low , int high) {
    int pivot = low ;
    int i = low ; 
    int j = high ;
    while (i < j) {
        while ( arr [i] <= arr[pivot] && i < high) {
            i++;
        }
        while ( arr[j] > arr[pivot] && j > low) {
            j--;
        }
        if ( i < j ) swap(arr[i] , arr[j] ) ;

    swap( arr[pivot], arr[j]);
    }
    return j;
}

void quickSort ( vector <int> &arr , int low , int high) {

    if ( low < high) {
        int partitionIndex = getIndex( arr ,  low ,  high) ;
        quickSort(arr , low , partitionIndex-1 ) ;
        quickSort(arr , partitionIndex+1 , high) ;
    }
}

int main() {

    vector<int> arr  {5,3,1,8,6};
    int n = arr.size();

    quickSort(arr,0,n-1);

    for (int val : arr) {
        cout << val << " ";
    }

    return 0;
}
