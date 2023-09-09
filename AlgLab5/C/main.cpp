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

    return number % 9901;
}

void Put (string key, string value, vector <vector <Node>> &hash) {

    int a = keyIntoNumber(key);
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

    int a = keyIntoNumber(key);

    for (int i = 0; i < hash[a].size(); i++) {
        if (hash[a][i].key == key) {
            hash[a][i].isDeleted = true;
        }
    }
}

string Get (string key, vector <vector <Node>> &hash) {

    int a = keyIntoNumber(key);

    for (int i = 0; i < hash[a].size(); i++) {
        if (hash[a][i].key == key && hash[a][i].isDeleted == false) {
            return hash[a][i].value;
        }
    }

    return "none";
}

string Prev (string key, vector <string> queue, vector <vector <Node>> &hash) {

    string prevKey;
    string tmpValue = "none";

    for (int i = 0; i < queue.size(); i++) {
        if (queue[i] == key) {
            bool found = false;

            while (!found) {
                if (i - 1 == -1) {
                    return "none";
                }

                prevKey = queue[--i];
                int a = keyIntoNumber(prevKey);

                for (int j = 0; j < hash[a].size(); j++) {
                    if (hash[a][j].key == prevKey && hash[a][j].isDeleted == false) {
                        tmpValue = hash[a][j].value;
                        found = true;
                    }
                }
            }

            break;
        }
    }

    return tmpValue;
}

string Next (string key, vector <string> queue, vector <vector <Node>> &hash) {

    string nextKey;
    string tmpValue = "none";

    for (int i = 0; i < queue.size(); i++) {
        if (queue[i] == key) {
            bool found = false;

            while (!found) {
                if (i + 1 == queue.size()) {
                    return "none";
                }

                nextKey = queue[++i];
                int a = keyIntoNumber(nextKey);

                for (int j = 0; j < hash[a].size(); j++) {
                    if (hash[a][j].key == nextKey && hash[a][j].isDeleted == false) {
                        tmpValue = hash[a][j].value;
                        found = true;
                    }
                }
            }

            break;
        }
    }

    return tmpValue;
}

int main() {

    ifstream fin("linkedmap.in");
    ofstream fout("linkedmap.out");

    vector <string> queue;
    vector <vector<Node>> hash(10000);

    string command;
    string key, value;
    bool isAdded;

    while (fin >> command) {
        switch (command[0]) {
            case 'p':
                switch (command[1]) {
                    case 'u':
                        fin >> key >> value;
                        isAdded = false;
                        for (int i = 0; i < queue.size(); i++) {
                            if (queue[i] == key) {
                                isAdded == true;
                                break;
                            }
                        }
                        if (!isAdded) {
                            queue.push_back(key);
                        }
                        Put(key, value, hash);
                        break;
                    case 'r':
                        fin >> key;
                        fout << Prev(key, queue, hash) << '\n';
                        break;
                }
                break;
            case 'd':
                fin >> key;
                Delete(key, hash);
                break;
            case 'g':
                fin >> key;
                fout << Get(key, hash) << '\n';
                break;
            case 'n':
                fin >> key;
                fout << Next(key, queue, hash) << '\n';
                break;

        }
    }

    fin.close();
    fout.close();
    return 0;
}
