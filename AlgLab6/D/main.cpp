#include <fstream>
#include <queue>
#include <vector>
using namespace std;

struct Label {
    string value;
    int line;
};


int main() {
    ifstream fin("quack.in");
    ofstream fout("quack.out");

    string line;
    string labelName;

    queue <unsigned short> quackQueue;
    vector <string> quackLine;
    vector <Label*> label;

    unsigned short reg[26] = {0};
    unsigned short x, y;
    int lineNum = 0;

    while (fin >> line) {
        quackLine.push_back(line);
        if (line[0] == ':') {
            Label* newElem = new Label();
            newElem->value = quackLine[lineNum].substr(1, quackLine[lineNum].length());
            newElem->line = lineNum;
            label.push_back(newElem);
        }
        lineNum++;
    }
    for (int i = 0; i < quackLine.size(); i++) {
        switch (quackLine[i][0]) {
            case '+':
                x = quackQueue.front();
                quackQueue.pop();
                y = quackQueue.front();
                quackQueue.pop();
                quackQueue.push((x + y) % 65536);
                break;

            case '-':
                x = quackQueue.front();
                quackQueue.pop();
                y = quackQueue.front();
                quackQueue.pop();
                quackQueue.push((x - y) % 65536);
                break;

            case '*':
                x = quackQueue.front();
                quackQueue.pop();
                y = quackQueue.front();
                quackQueue.pop();
                quackQueue.push((x * y) % 65536);
                break;

            case '/':
                x = quackQueue.front();
                quackQueue.pop();
                y = quackQueue.front();
                quackQueue.pop();
                if (y == 0) {
                    quackQueue.push(0);
                }
                else {
                    quackQueue.push(x / y);
                }
                break;

            case '%':
                x = quackQueue.front();
                quackQueue.pop();
                y = quackQueue.front();
                quackQueue.pop();
                if (y == 0) {
                    quackQueue.push(0);
                }
                else {
                    quackQueue.push(x % y);
                }
                break;

            case '>':
                x = quackQueue.front();
                quackQueue.pop();
                reg[quackLine[i][1] - 'a'] = x;
                break;

            case '<':
                quackQueue.push(reg[quackLine[i][1] - 'a']);
                break;

            case 'P':
                if (quackLine[i].length() == 1) {
                    fout << quackQueue.front() << '\n';
                    quackQueue.pop();
                }
                else {
                    fout << reg[quackLine[i][1] - 'a'] << '\n';
                }
                break;

            case 'C':
                if (quackLine[i].length() == 1) {
                    x = quackQueue.front();
                    quackQueue.pop();
                    fout << char(x % 256);
                }
                else {
                    fout << char(reg[quackLine[i][1] - 'a'] % 256);
                }
                break;

            case ':':
                break;

            case 'J':
                labelName = quackLine[i].substr(1, quackLine[i].length());
                for (int j = 0; j < label.size(); j++) {
                    if (label[j]->value == labelName) {
                        i = label[j]->line;
                        break;
                    }
                }
                break;

            case 'Z':
                if (reg[quackLine[i][1] - 'a'] == 0) {
                    labelName = quackLine[i].substr(2, quackLine[i].length());
                    for (int j = 0; j < label.size(); j++) {
                        if (label[j]->value == labelName) {
                            i = label[j]->line;
                            break;
                        }
                    }
                }
                break;

            case 'E':
                if (reg[quackLine[i][1] - 'a'] == reg[quackLine[i][2] - 'a']) {
                    labelName = quackLine[i].substr(3, quackLine[i].length());
                    for (int j = 0; j < label.size(); j++) {
                        if (label[j]->value == labelName) {
                            i = label[j]->line;
                            break;
                        }
                    }
                }
                break;

            case 'G':
                if (reg[quackLine[i][1] - 'a'] > reg[quackLine[i][2] - 'a']) {
                    labelName = quackLine[i].substr(3, quackLine[i].length());
                    for (int j = 0; j < label.size(); j++) {
                        if (label[j]->value == labelName) {
                            i = label[j]->line;
                            break;
                        }
                    }
                }
                break;

            case 'Q':
                return 0;

            default:
                quackQueue.push(stoi(quackLine[i]));
                break;
        }
    }
    fin.close();
    fout.close();
    return 0;
}