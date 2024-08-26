#include <iostream>
#include <vector>

using namespace std;

// Function to count inversions using Merge Sort
int merge_and_count(vector<int>& arr, vector<int>& temp_arr, int left, int mid, int right) {
    int i = left;    // Starting index for left subarray
    int j = mid + 1; // Starting index for right subarray
    int k = left;    // Starting index to be sorted
    int inv_count = 0;

    // Conditions are checked to ensure that i doesn't exceed mid and j doesn't exceed right
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp_arr[k++] = arr[i++];
        } else {
            temp_arr[k++] = arr[j++];
            inv_count += (mid - i + 1);
        }
    }

    // Copy the remaining elements of left subarray, if any
    while (i <= mid) {
        temp_arr[k++] = arr[i++];
    }

    // Copy the remaining elements of right subarray, if any
    while (j <= right) {
        temp_arr[k++] = arr[j++];
    }

    // Copy the sorted subarray into Original array
    for (i = left; i <= right; i++) {
        arr[i] = temp_arr[i];
    }

    return inv_count;
}

// Function to count the number of inversions in the array using merge sort
int merge_sort_and_count(vector<int>& arr, vector<int>& temp_arr, int left, int right) {
    int inv_count = 0;
    if (left < right) {
        int mid = (left + right) / 2;

        inv_count += merge_sort_and_count(arr, temp_arr, left, mid);
        inv_count += merge_sort_and_count(arr, temp_arr, mid + 1, right);
        inv_count += merge_and_count(arr, temp_arr, left, mid, right);
    }
    return inv_count;
}

// Function to count inversions in an array
int count_inversions(vector<int>& arr) {
    vector<int> temp_arr(arr.size());
    return merge_sort_and_count(arr, temp_arr, 0, arr.size() - 1);
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int L;
        cin >> L;
        
        if (L == 0) {
            cout << "Optimal train swapping takes 0 swaps." << endl;
            continue;
        }
        
        vector<int> carriages(L);
        for (int i = 0; i < L; ++i) {
            cin >> carriages[i];
        }

        int swaps = count_inversions(carriages);
        cout << "Optimal train swapping takes " << swaps << " swaps." << endl;
    }

    return 0;
}
