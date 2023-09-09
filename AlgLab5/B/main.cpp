#include <fstream>
#include <vector>

using namespace std;

struct Node {
    string key;
    string value;
    bool isDeleted;
};

int keyIntoNumber (string key) {

    int number = 0;

    for (int i = key.size() - 1; i >= 0; i--) {
        number += (int) key[i] * (i+1);
    }

    return number;
}

void Put (string key, string value, vector <vector <Node>> &hash) {
    int a = keyIntoNumber(key) % 9901;
    Node newElem = {key, value, false};

    for (int i = 0; i < hash[a].size(); i++) {
        if (hash[a][i].key == key) {
            hash[a][i] = newElem;
            return;
        }
    }

    hash[a].push_back(newElem);
}

void Delete (string key, vector <vector <Node>> &hash) {

    int a = keyIntoNumber(key) % 9901;

    for (int i = 0; i < hash[a].size(); i++) {
        if (hash[a][i].key == key) {
            hash[a][i].isDeleted = true;
        }
    }
}

string Get (string key, vector <vector <Node>> &hash) {

    int a = keyIntoNumber(key) % 9901;

    for (int i = 0; i < hash[a].size(); i++) {
        if (hash[a][i].key == key && hash[a][i].isDeleted == false) {
            return hash[a][i].value;
        }
    }

    return "none";
}

int main() {

    ifstream fin("map.in");
    ofstream fout("map.out");

    string command;
    vector <vector<Node>> hash(10000);
    string key, value;

    while (fin >> command) {
        switch (command[0]) {
            case 'p':
                fin >> key >> value;
                Put(key, value, hash);
                break;
            case 'd':
                fin >> key;
                Delete(key, hash);
                break;
            case 'g':
                fin >> key;
                fout << Get(key, hash) << '\n';
                break;
        }
    }

    fin.close();
    fout.close();
    return 0;
}
