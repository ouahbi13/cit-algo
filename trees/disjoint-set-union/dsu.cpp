#include <bits/stdc++.h>

using namespace std;

// this array stores the immediate ancestor of the element i in the tree, 
// if i is the root then the reference is itself: parent[i] == i

int parent[];

void make_set(int v) {
    parent[v] = v;
}

int find_set(int v) {
    if (v == parent[v]) return v;
    return find_set(parent[v]);
}

// Path compression optimization:
// This optimization is designed for speeding up find_set.

// If we call find_set(v) for some vertex v, 
// we actually find the representative p for all vertices that we visit on the path between v and the actual representative p. 
// The trick is to make the paths for all those nodes shorter, by setting the parent of each visited vertex directly to p.

// Using this technique we optimize our find_set complexity from O(n) to O(logn)

int find_set(int v) {
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) parent[b] = a;
}

// Union by size / rank

// In this optimization we will change the union_set operation.
// In the naive implementation the second tree always got attached to the first one.
// In practice that can lead to trees containing chains of length.
// With this optimization we will avoid this by choosing very carefully which tree gets attached.

// In the first approach we use the size of the trees as rank,
// and in the second one we use the depth of the tree
// (more precisely, the upper bound on the tree depth,
// because the depth will get smaller when applying path compression).

// Union by size:
void make_set(int v) {
    parent[v] = v;
    size[v] = 1;
}
void union_sets(int a, int b) {
    a = find_set(a);
    b= find_set(b);
    if (a != b) {
        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}

// Union by depth (rank):
void make_set(int v) {
    parent[v] = v;
    rank[v] = 0;
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a!=b) {
        if (rank[a] < rank[b]) swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b]) rank[a]++;
    }
}

int main() {

    return 0;
}