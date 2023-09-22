#include <iostream>
using namespace std;
int n;
unsigned long commandRunIDX = 0;
string commands;

bool board[1025][1025];

char getCommand() {
    return commands[commandRunIDX++];
}

void run(int stx, int sty, int size) {
    int edx = stx + size - 1, edy = sty + size - 1;
    char command = getCommand();
    
    if(command == 'X') {
        // run
        // LT
        int newSize = size / 2;
        run(stx, sty, newSize);
        run(stx, sty + newSize, newSize);
        
        run(stx + newSize, sty, newSize);
        run(stx + newSize, sty + newSize, newSize);
    }
    if(command == '1') {
        for(int i = stx; i <= edx; i++)
            for(int j = sty; j <= edy; j++)
                board[i][j] = true;
    }
}

int main() {
    cin >> n >> commands;
    
    run(1, 1, n);
    
    cout << n << "\n";
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++)
            cout << (board[i][j] ? "1" : "0") << " ";
        cout << "\n";
    }
}
