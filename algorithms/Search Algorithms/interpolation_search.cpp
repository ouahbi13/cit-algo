#include <iostream>

using namespace std;

int interpolationSearch(int arr[], int n, int x) {
    int low = 0, high = n - 1;

    int pos;

    while (low <= high && x >= arr[low] && x <= arr[high]) {
        if (low == high) {
            if (arr[low] == x) return low;
            return -1;
        }
        
        pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (x - arr[low]));

        if (arr[pos] == x) return pos;
        else if (arr[pos] > x) high = pos - 1;
        else low = pos + 1; 
    }
    return -1;
}

int main() {
    int arr[] = {10, 12, 14, 16, 18, 20};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 1;
    int index = interpolationSearch(arr, n, x);
    string result = (index != -1) ? "Element found at index " + std::to_string(index) : "Element not found !";
    cout << result;
    return 0;
}
