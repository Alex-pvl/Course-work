#include "btree.hpp"
#include "Integer.hpp"
#include "Date.hpp"
#include <ctime>

void test_rand(int n) {
    Btree bt;
    // массив значений
    int* m = new int[n]; 
    srand(clock());
    int random, pog10 = n + n%10;
    for (int i = 0; i < n; i++) {
        // для уникальности генерируемых значений
        for (;;) {
            bool good = true;
            random = 1 + rand()%n;
            for (int j = 0; j < n; j++) {
                if (random == m[j]) {
                    good = false;
                    break;
                }
            }
            if (good) break;
        }
        m[i] = random;
        // вставка 
        bt.add(new Integer(m[i]));
    }
    cout << "items count: " << bt.size() << endl;
    double S = 0;
    for (int i = 0; i < n/2; i++) {
        S += bt.search2(m[i]);
    }
    cout << "theoretical count: 1.39 * log2(n) = " << 1.39*(log((double) n) / log(2.0)) << endl;
    cout << "practical count: " << S/(n/2) << endl;
    delete[] m;
}

int main() {
    time_t start, end;
    for (int i = 1000; i <= 10000; i+=1000) {
        start = clock();
        test_rand(i);
        end = clock();
        cout << "Elapsed time - " << (double) (end-start) / CLOCKS_PER_SEC << " seconds." << endl;
    }
    return 0;
}