#include <bits/stdc++.h>
#include<deque>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'knightlOnAChessboard' function below.
 *
 * The function is expected to return a 2D_INTEGER_ARRAY.
 * The function accepts INTEGER n as parameter.
 */

vector<pair<int, int>> check_pairs(int x, int y, int a, int b, int n) {
    vector<pair<int, int>> possible_pairs = {
        {x + a, y+b}, {x+a, y-b},
        {x-a, y+b}, {x-a, y-b},
        {x + b, y+a}, {x+b, y-a},
        {x-b, y+a}, {x-b, y-a}
    };
    vector<pair<int, int>> moves = {};
    for (int i = 0; i < possible_pairs.size(); i++) {
        pair<int, int> p = possible_pairs[i];

        if (0 <= p.first && 0 <= p.second && p.first < n && p.second < n) {
            moves.push_back(p);
        }
    }
    return moves;
}

int BFS(int a, int b, int n) {
    deque<vector<int>> q = {};
    q.push_back({0, 0, 0});
    vector<pair<int, int>> visited = {pair<int, int>(0,0)};
    int x = 0; int y = 0; int count = 0;

    while (!(q.empty())) {
        vector<int> front = q.front();
        x = front[0];
        y = front[1];
        count = front[2];

        q.pop_front();

        vector<pair<int, int>> pos_pairs = check_pairs(x, y, a, b, n);


        for (int i = 0; i < pos_pairs.size(); i++) {
            pair<int, int> p = pos_pairs[i];

            if (p.first == n-1 && p.second == n-1) {
                count++;
                return count;
            }
            
            bool isFound = false;
            for (int k = 0; k < visited.size(); k++) {
                if (visited[k].first == p.first && visited[k].second == p.second) {
                    isFound = true;
                    break;
                }
            }
            if (!isFound) {
                visited.push_back(p);
                count++;
                q.push_back({p.first, p.second, count});
            }            
        }
    }
    return -1;
}


vector<vector<int>> knightlOnAChessboard(int n) {
    vector<vector<int>> result;
    for (int i = 1; i < n; i++) {
        vector<int> row;
        for (int j = 1; j < n; j++) {
            row.push_back(BFS(i, j, n));
        }
        result.push_back(row);
    }
    int cpt = 0;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-1; j++) {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<int>> result = knightlOnAChessboard(n);

    for (size_t i = 0; i < result.size(); i++) {
        for (size_t j = 0; j < result[i].size(); j++) {
            fout << result[i][j];

            if (j != result[i].size() - 1) {
                fout << " ";
            }
        }

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
