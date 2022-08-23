#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vector<int>>


int main() {
    int t;
    cin >> t;

    vi results;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vii book;
        // int book[]
        vi understood;
        
        for (int j = 0; j < n; j++) {
            int k;
            cin >> k;
            vi chaps;
            for (int p = 0; p < k; p++) {
                vi chapters;
                int a;
                cin >> a;
                chapters.push_back(a);
                chaps = chapters;
            }
            book.push_back(chaps);
        }


        while (understood.size() != book.size()) {
            for (int a = 0; a < book.size(); a++) {
                for (int b = 0; b < book[a].size(); b++) {
                    if (find(understood.begin(), understood.end(), book[a][b]) == understood.end()) break;
                    understood.push_back(book[a][b]);
                    }
            }
        }

        
    }

    return 0;
}