#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'maximizingXor' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER l
 *  2. INTEGER r
 */

int maximizingXor(int l, int r) {
    int max = 0;
    if (l < r) {
        for (int a=l; a<=r; a++) {
            for (int b=l; b<=r; b++) {
                if ((a^b) > max) max = (a^b);
            }
        } 
        return max;
    }
    else return (l ^ r);
}

// O(n) solution :
int maximizingXorOptimized(int l, int r) {
    int LxorR = l ^ r;
    int msbPos = 0;
    while (LxorR) {
        msbPos++;
        LxorR >>= 1;
    }
    return (pos(2, msbPos)-1);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string l_temp;
    getline(cin, l_temp);

    int l = stoi(ltrim(rtrim(l_temp)));

    string r_temp;
    getline(cin, r_temp);

    int r = stoi(ltrim(rtrim(r_temp)));

    int result = maximizingXor(l, r);

    fout << result << "\n";
    cout << result << "\n";


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
