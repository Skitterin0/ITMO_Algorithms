#include <fstream>
#include <queue>

struct SValue {
    char value;
    bool isVisited;
    int distance;
};

struct SPos {
    int y;
    int x;
};

int main() {
    std::ifstream fin ("input.txt");
    std::ofstream fout ("output.txt");

    int n, m, startX, startY, finishX, finishY;
    fin >> n >> m;
    SValue matrix[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            SValue tmp;
            fin >> tmp.value;
            tmp.isVisited = false;
            tmp.distance = 10000000;
            matrix[i][j] = tmp;
            if (matrix[i][j].value == 'S') {
                startX = j;
                startY = i;
            }
            if (matrix[i][j].value == 'T') {
                finishX = j;
                finishY = i;
            }
        }
    }
    std::queue<SPos> Q;
    SPos parents [n*m];
    parents[startX+startY*m] = {-1, -1};
    int myX = startX;
    int myY = startY;
    Q.push({startY,startX});
    matrix[startY][startX].distance = 0;
    matrix[startY][startX].isVisited = true;
    while ((myX != finishX || myY != finishY) && !Q.empty()) {
        myX = Q.front().x;
        myY = Q.front().y;
        if ((matrix[myY][myX-1].value != '#') && (myX > 0) && (matrix[myY][myX-1].isVisited == false)) {
            Q.push({myY, myX - 1});
            matrix[myY][myX-1].distance = matrix[myY][myX].distance+1;
            matrix[myY][myX-1].isVisited = true;
            parents[myX-1 + myY*m] = {myY, myX};
        }
        if ((matrix[myY-1][myX].value != '#') && (myY > 0) && (matrix[myY-1][myX].isVisited == false)) {
            Q.push({myY - 1, myX});
            matrix[myY-1][myX].distance = matrix[myY][myX].distance+1;
            matrix[myY-1][myX].isVisited = true;
            parents[myX + (myY-1)*m] = {myY, myX};
        }
        if ((matrix[myY][myX+1].value != '#') && (myX < (m-1)) && (matrix[myY][myX+1].isVisited == false)) {
            Q.push({myY, myX+1});
            matrix[myY][myX+1].distance = matrix[myY][myX].distance+1;
            matrix[myY][myX+1].isVisited = true;
            parents[myX+1 + myY*m] = {myY, myX};
        }
        if ((matrix[myY+1][myX].value != '#') && (myY < (n-1)) && (!matrix[myY+1][myX].isVisited)) {
            Q.push({myY+1, myX});
            matrix[myY+1][myX].distance = matrix[myY][myX].distance+1;
            matrix[myY+1][myX].isVisited = true;
            parents[myX + (myY+1)*m] = {myY, myX};
        }
        Q.pop();
    }

    if (Q.empty() && myX != finishX || myY != finishY) {
        fout << -1;
        return 0;
    }

    std::vector<char> path;
    while (myX != startX || myY != startY) {
        if (parents[myX + myY*m].x > myX) {
            path.push_back('L');
            myX++;
        }
        else if (parents[myX + myY*m].x < myX) {
            path.push_back('R');
            myX--;
        }
        else if (parents[myX + myY*m].y > myY) {
            path.push_back('U');
            myY++;
        }
        else if (parents[myX + myY*m].y < myY) {
            path.push_back('D');
            myY--;
        }
    }
    fout << matrix[finishY][finishX].distance << '\n';
    for (int i = path.size()-1; i >= 0; i--) {
        fout << path[i];
    }

    fin.close();
    fout.close();
    return 0;
}
