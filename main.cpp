// COMSC-210 | Lab 25 | Dan Pokhrel
#include <iostream>
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

    // read

    auto start = high_resolution_clock::now();
    for (int i = 0; i < CODES_SZ; i++)
        vec.push_back(codes[i]);
    auto end = high_resolution_clock::now();
    auto vecRead = duration_cast<milliseconds>(end - start).count();

    start = high_resolution_clock::now();
    for (int i = 0; i < CODES_SZ; i++)
        lis.push_back(codes[i]);
    end = high_resolution_clock::now();
    auto lisRead = duration_cast<milliseconds>(end - start).count();

    start = high_resolution_clock::now();
    for (int i = 0; i < CODES_SZ; i++)
        se.insert(codes[i]);
    end = high_resolution_clock::now();
    auto setRead = duration_cast<milliseconds>(end - start).count();

    cout << vecRead << " " << lisRead << " " << setRead << endl;

    // sort

    start = high_resolution_clock::now();
    sort(vec.begin(), vec.end());
    end = high_resolution_clock::now();
    vecRead = duration_cast<milliseconds>(end - start).count();

    start = high_resolution_clock::now();
    lis.sort();
    end = high_resolution_clock::now();
    lisRead = duration_cast<milliseconds>(end - start).count();

    setRead = -1;

    cout << vecRead << " " << lisRead << " " << setRead << endl;

    // insert

    start = high_resolution_clock::now();
    vec.insert(vec.begin() + CODES_SZ/2, "TESTCODE");
    end = high_resolution_clock::now();
    vecRead = duration_cast<milliseconds>(end - start).count();

    start = high_resolution_clock::now();
    list<string>::iterator it = lis.begin(); advance(it, CODES_SZ/2);
    lis.insert(it, "TESTCODE");
    end = high_resolution_clock::now();
    lisRead = duration_cast<milliseconds>(end - start).count();

    start = high_resolution_clock::now();
    se.insert("TESTCODE");
    end = high_resolution_clock::now();
     setRead = duration_cast<milliseconds>(end - start).count();

    cout << vecRead << " " << lisRead << " " << setRead << endl;

    // delete

    start = high_resolution_clock::now();
    vec.erase(vec.begin() + CODES_SZ/2);
    end = high_resolution_clock::now();
    vecRead = duration_cast<milliseconds>(end - start).count();

    start = high_resolution_clock::now();
    list<string>::iterator it = lis.begin(); advance(it, CODES_SZ/2);
    lis.insert(it, "TESTCODE");
    end = high_resolution_clock::now();
    lisRead = duration_cast<milliseconds>(end - start).count();

    start = high_resolution_clock::now();
    se.insert("TESTCODE");
    end = high_resolution_clock::now();
     setRead = duration_cast<milliseconds>(end - start).count();

    cout << vecRead << " " << lisRead << " " << setRead << endl;

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/