#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include "Deq_List_One.h"


using namespace std;

int main(){
    string ipName, iptask, congratulations;
    int gen[] = {0, 0, 0}, ti = 0, n = 0, k = 0;
    Deq_List_One q1, *q2;

    ifstream fin("config.cfg");
    string line;
    istringstream sin;

    while (getline(fin, line)) {
        sin.str(line.substr(line.find("=")+1));
        if (line.find("TYPE_INPUT") != string::npos) {
            sin >> ti;
        }
        else if (line.find("AUTHOR") != string::npos) {
            cout << "Автор " << sin.str() << endl << endl;
            ipName = sin.str();
        }
        else if (line.find("TASK") != string::npos) {
            cout << "Задание: " << sin.str() << '.' << endl << endl;
            iptask = sin.str();
        }
        else if (line.find("CONGRATULATIONS") != string::npos) {
            congratulations = sin.str();
        }
        else if (line.find("ELEM_COUNT") != string::npos) {
            sin >> gen[0];
        }
        else if (line.find("DZ_COUNT") != string::npos) {
            sin >> gen[1];
        }
        else if (line.find("SHIFT_COUNT") != string::npos) {
            sin >> gen[2];
        }
        else if (line.find("N_COUNT") != string::npos) {
            sin >> n;
        }
        else if (line.find("K_COUNT") != string::npos) {
            sin >> k;
        }
        else if (line.find("QUEUE_MANUAL") != string::npos) {
            int i, j;
            gen[0] = 0;
            q2 = new Deq_List_One();
            while(1){
                sin >> i;
                if(i == j) break;
                q2->Append(i);
                gen[0]++;
                j = i;
            }
        }
        sin.clear();
    }
    if(!ti) q2 = new Deq_List_One(gen[0], gen[1], gen[2]);

    cout << endl;
    cout << "Сгенерированая очередь:" << endl;
    q2->Print();
    cout << endl << "Удалить " << n << " элемент(а/ов) начиная с " << k << "-го" << endl << endl;
    k--;
    for(int i = 0; i < gen[0]; i++){
        if ((i >= k)&&(n != 0)){
            q2->Pop_Left();
            n--;
        }else q1.Push_Right(q2->Pop_Left()); 
    }
    cout << "Новая очередь:" << endl;
    q1.Print();
    
    cout << endl << congratulations << endl;
    cin.get();
    q2->~Deq_List_One();
}
