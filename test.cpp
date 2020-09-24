#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
int main(){
    ifstream fin("config.cfg");
    string line;
    istringstream sin;
    string ipName, iptask, congratulations;
    int ti = 0;
     int gen[] = {0, 0, 0};

    while (getline(fin, line)) {
        sin.str(line.substr(line.find("=")+1));
        if (line.find("TYPE_I") != string::npos) {
            sin >> ti;
            cout << "num "<<  ti << endl;
        }
        if(ti){
            if (line.find("ELEM_COUNT") != string::npos) {
                sin >> gen[0];
                cout << gen[0] << endl;
            }
            else if (line.find("DZ_COUNT") != string::npos) {
                sin >> gen[1];
                cout << gen[2] << endl;
            }
            else if (line.find("SHIFT_COUNT") != string::npos) {
                sin >> gen[2];
                cout << gen[2] << endl;
            }
        }
        else{
            if (line.find("queue_manual") != string::npos) {
                int i, j;
                while(1){
                    sin >> i;
                    if(i == j) break;
                    cout << i << endl;
                    j = i;
                }
            }
        }
    }
}