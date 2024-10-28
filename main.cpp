// COMSC-210 | Lab 25 | Dan Pokhrel
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <vector>
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

    cout << vecRead << " " << lisRead << " " << setRead;

    // read

    start = high_resolution_clock::now();
    for (int i = 0; i < CODES_SZ; i++)
        vec.push_back(codes[i]);
    end = high_resolution_clock::now();
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

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/