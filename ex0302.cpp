#include <iostream>
#include <stdlib.h>

using namespace std;

// We declare here a record type called "field"
struct field {
    int x;
    int y;
    bool isWall;
    char symbol;
};

struct current_position {
    int x;
    int y;
};

int current_x;
int current_y;
const int height = 12;
const int width = 16;
field playground[height][width];

void plotMaze(int x, int y) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            playground[i][j].x = i;
            playground[i][j].y = j;
            playground[i][j].isWall = (i == 0 || i == (height - 1) || j == 0 || j == (width - 1));
            if (playground[i][j].isWall)
                playground[i][j].symbol = '*';
            else
                playground[i][j].symbol = ' ';
        }
    }
    playground[0][3].symbol = ' ';

    if (!playground[x][y].isWall || (x == 0 && y == 3)) {
        playground[x][y].symbol = 'O';
        current_x = x;
        current_y = y;
    } else {
        playground[current_x][current_y].symbol = 'O';
    }

//    cout << current_x << " x " << current_y << endl;

    // printing the playground
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cout << playground[i][j].symbol;
        }
        cout << endl;
    }
}

void parseMove(char move) {
//    cout << move;
    switch (move) {
        case 'l':
            plotMaze(current_x, current_y - 1);
            break;
        case 'u':
            plotMaze(current_x - 1, current_y);
            break;
        case 'r':
            plotMaze(current_x, current_y + 1);
            break;
        case 'd':
            plotMaze(current_x + 1, current_y);
            break;
        case 'q':
            break;
        default:
            cout << "Command not supported. Please only use lowercase l, u, r, d or q.";
    }
}

int main() {
    int x = 5, y = 5;
    string moves;

    plotMaze(x, y);

    cin >> moves;
    for (int i = 0; i < moves.size(); i++) {
        parseMove(moves[i]);
    }

    return 0;
}
