#include <iostream>
#include<stdlib.h>
#include <stack>


using namespace std;

int findMinimum(stack<pair<int, int>>& st){
    int minimum = st.top().second;
    return minimum;
}

void addElement(stack<pair<int, int>>& st) {
    int new_min = st.empty() ? new_elem : min(new_elem, st.top().second);
    st.push({new_elem, new_min});
}

void removeElement(stack<pair<int, int>>& st) {
    int removed_element = st.top().first;
    st.pop();
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