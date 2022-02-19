// Finding the minimum for all subarrays of fixed length using a modified version of queues and stacks
// Explanation: https://cp-algorithms.com/data_structures/stack_queue_modification.html

#include<stdio.h>
#include <bits/stdc++.h>
#include <iostream>
#include<stdlib.h>
#include <stack>

using namespace std;

int findMinimum(stack<pair<int, int>> &s1, stack<pair<int, int>> &s2){
    int minimum = 0;
    if (s1.empty() || s2.empty()) minimum = s1.empty() ? s2.top().second : s1.top().second;
    else minimum = min(s1.top().second, s2.top().second);
    return minimum;
}

void addElement(stack<pair<int, int>> &s1, int new_element) {
    int minimum = s1.empty() ? new_element : min(new_element, s1.top().second);
    s1.push({new_element, minimum});
}

void removeElement(stack<pair<int, int>> &s1, stack<pair<int, int>> &s2) {
    if (s2.empty()) {
        while (!s1.empty()) {
            int element = s1.top().first;
            s1.pop();
            int minimum = s2.empty() ? element : min(element, s2.top().second);
            s2.push({element, minimum});
        }
    }
    int remove_element = s2.top().first;
    s2.pop();
}

int main() {
    int array[] = {2, 3, 4, 5, 7, 8, 6};
    int m = 2;
    int n = sizeof(array)/sizeof(*array);
    stack<pair<int, int>> s1, s2;
    int j;
    for (j = 0; j < m; j++) {
        addElement(s1, array[j]);
    }
    
    while (j<=n) {
        cout << findMinimum(s1, s2) << endl;
        addElement(s1, array[j++]);
        removeElement(s1, s2);
    }
    return 0;
}