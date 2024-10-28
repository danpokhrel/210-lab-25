// COMSC-210 | Lab 25 | Dan Pokhrel
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <chrono>
#include <vector>
#include <algorithm>
#include <list>
#include <set>
using namespace std;
using namespace std::chrono;

const int CODES_SZ = 20000;

// Prototypes
high_resolution_clock::time_point time_start();
int time_end(high_resolution_clock::time_point start);

int main() {
    vector<string> vec;
    list<string> lis;
    set<string> se;

    // read file
    ifstream fin("codes.txt");
    string codes[CODES_SZ];
    int i = 0;
    while (fin.good()){
        string x; getline(fin, x);
        codes[i] = x;
        i++;
    }

    cout << " Operation    Vector      List       Set\n";

    // read

    auto start = time_start();
    // ---------------------------------------------------------------
    for (int i = 0; i < CODES_SZ; i++)
        vec.push_back(codes[i]);
    auto vecRead = time_end(start);
    // ---------------------------------------------------------------

    start = time_start();
    // ---------------------------------------------------------------
    for (int i = 0; i < CODES_SZ; i++)
        lis.push_back(codes[i]);
    // ---------------------------------------------------------------
    auto lisRead = time_end(start);

    start = time_start();
    // ---------------------------------------------------------------
    for (int i = 0; i < CODES_SZ; i++)
        se.insert(codes[i]);
    // ---------------------------------------------------------------
    auto setRead = time_end(start);

    cout << setw(10) << "Read";
    cout << setw(10) << vecRead
        << setw(10) << lisRead
        << setw(10) << setRead << endl;

    // sort

    start = time_start();
    // ---------------------------------------------------------------
    sort(vec.begin(), vec.end());
    // ---------------------------------------------------------------
    vecRead = time_end(start);

    start = time_start();
    // ---------------------------------------------------------------
    lis.sort();
    // ---------------------------------------------------------------
    lisRead = time_end(start);
    
    setRead = -1;

    cout << setw(10) << "Sort";
    cout << setw(10) << vecRead
        << setw(10) << lisRead
        << setw(10) << setRead << endl;

    // insert

    start = time_start();
    // ---------------------------------------------------------------
    vec.insert(vec.begin() + CODES_SZ/2, "TESTCODE");
    // ---------------------------------------------------------------
    vecRead = time_end(start);

    start = time_start();
    // ---------------------------------------------------------------
    list<string>::iterator it = lis.begin(); advance(it, CODES_SZ/2);
    lis.insert(it, "TESTCODE");
    // ---------------------------------------------------------------
    lisRead = time_end(start);

    start = time_start();
    // ---------------------------------------------------------------
    se.insert("TESTCODE");
    // ---------------------------------------------------------------
    setRead = time_end(start);

    cout << setw(10) << "Insert";
    cout << setw(10) << vecRead
        << setw(10) << lisRead
        << setw(10) << setRead << endl;

    // delete

    start = time_start();
    // ---------------------------------------------------------------
    vec.erase(vec.begin() + CODES_SZ/2);
    // ---------------------------------------------------------------
    vecRead = time_end(start);

    start = time_start();
    // ---------------------------------------------------------------
    it = lis.begin(); advance(it, CODES_SZ/2);
    lis.erase(it);
    // ---------------------------------------------------------------
    lisRead = time_end(start);

    start = time_start();
    // ---------------------------------------------------------------
    se.erase("eohGGM1Q");
    // ---------------------------------------------------------------
    setRead = time_end(start);

    cout << setw(10) << "Delete";
    cout << setw(10) << vecRead
        << setw(10) << lisRead
        << setw(10) << setRead << endl;

    return 0;
}

high_resolution_clock::time_point time_start(){
    return high_resolution_clock::now();
}

int time_end(high_resolution_clock::time_point start){
    auto end = high_resolution_clock::now();
    return duration_cast<milliseconds>(end - start).count();
}