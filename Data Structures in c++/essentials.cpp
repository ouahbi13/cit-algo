// Pointers
// References
// classes, structs
// Stacks/ Queues
// Linked Lists
// Hash tables



#include <iostream>

using namespace std;

#define print(s) cout << s << endl;

// struct Vector {
//     int x;
//     int y;
//     int z;
// }


// class Player {
//     public:
//         int X;
//         int Y;
//         int speed;

//     Player(int x, int y) {
//         X = x;
//         Y = y;
//     }


//     void Move() {
//         x += 1;
//     }

// };

// class NPC : public Player {
//     string dialog;
//     NPC(string d) {
//         dialog = d;
//     }
//     void Move() {
//         x += 0;
//     }
// }


int main() {
    char s[] = "algo";
    int n = sizeof(s)/sizeof(s[0]);
    for (int i = 0; i < n; i++) {
        print(s[i]);
    }
    // cout << "n = " << n << endl;
    return 0;

}