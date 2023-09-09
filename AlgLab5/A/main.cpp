#include <fstream>
#include <vector>

using namespace std;

struct Node {
    int key;
    bool isDeleted;
};

void Insert (int number, vector <vector <Node>> &hash) {
    Node newElem = {number, false};
    int a = abs(number % 9901);
    for (int i = 0; i < hash[a].size(); i++) {
        if (hash[a][i].key == newElem.key) {
            if (hash[a][i].isDeleted == true) {
                hash[a][i].isDeleted = false;
                return;
            }
            else {
                return;
            }
        }
    }
    hash[a].push_back(newElem);
}

void Delete (int number, vector <vector <Node>> &hash) {
    int a = abs(number % 9901);
    for (int i = 0; i < hash[a].size(); i++) {
        if (hash[a][i].key == number) {
            hash[a][i].isDeleted = true;
        }
    }
}

bool Exists (int number, vector <vector <Node>> &hash) {
    int a = abs(number % 9901);
    for (int i = 0; i < hash[a].size(); i++) {
        if (hash[a][i].key == number && hash[a][i].isDeleted == false) {
            return true;
        }
    }
    return false;
}

int main() {
    ifstream fin("set.in");
    ofstream fout("set.out");

    string command;
    int number;

    vector <vector <Node>> hash(10000);


    while (fin >> command) {
        switch(command[0]) {
            case 'i':
                fin >> number;
                Insert(number, hash);
                break;
            case 'd':
                fin >> number;
                Delete(number, hash);
                break;
            case 'e':
                fin >> number;
                bool isExists = Exists(number, hash);
                if (isExists) {
                    fout << "true\n";
                }
                else {
                    fout << "false\n";
                }
                break;
        }
    }

    fin.close();
    fout.close();
    return 0;
}
