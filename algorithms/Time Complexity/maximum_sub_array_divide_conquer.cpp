#include <limits.h>
#include <stdio.h>
#include <tuple>

int max(int a, int b) { return (a > b) ? a : b; }

int max(int a, int b, int c) { return max(max(a, b), c); }

int maxCrossingSubarray(int arr[], int low, int mid, int high) {
    
    int leftSum = INT_MIN;
    int sum = 0;
    int maxLeft = mid;
    for (int i = mid; i > low; i--) {
        sum += sum + arr[i]
        if sum > leftSum { 
            leftSum = sum;
            maxLeft = i;
        }
    }
    
    int rightSum = INT_MIN;
    sum = 0;
    int maxRight = mid + 1;
    for (int j = mid + 1; j < high; i++) {
        sum += sum + arr[j]
        if sum > rightSum { 
            rightSum = sum;
            maxRight = j;
        }
    }
    tuple<int, int, int> maxCross = make_tuple(maxLeft, maxRight, leftSum + rightSum);
    return maxCross;
}

int findMaximumSubarray(int arr[], int low, int high) {
    if (high == low) return (low, high, arr[low]);
    else {
        int mid = (low + high) / 2;
        tuple<int, int, int> leftTuple = findMaximumSubarray(arr, low, mid);
        int (leftLow, leftHigh, leftSum) = findMaximumSubarray(arr, low, mid);
        int (rightLow, rightHigh, rightSum) = findMaximumSubarray(arr, mid+1, high);
        int (crossLow, crossHigh, crossSum) = maxCrossingSubarray(arr, low, mid, high);
        if (leftSum > rightSum && leftSum > crossSum) return (leftLow, leftHigh, leftSum);
        else if (rightSum > leftSum && rightSum > crossSum) return (rightLow, rightHigh, rightSum);
        else return (crossLow, crossHigh, crossSum);
    }
}