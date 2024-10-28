// COMSC-210 | Lab 25 | Dan Pokhrel
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <vector>
#include <list>
#include <set>
using namespace std;

const int CODES_SZ = 20000;



int main() {
    vector<int> vec;
    list<int> lis;
    set<int> se;

    // read file
    ifstream fin("codes.txt");
    string codes[CODES_SZ];
    int i = 0;
    while (fin.good()){
        string x; getline(fin, x);
        codes[i] = x;
        i++;
    }



    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/