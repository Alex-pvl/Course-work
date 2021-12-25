#include "btree.hpp"
#include "Integer.hpp"
#include "Date.hpp"
#include <ctime>

void test_rand(int n) {
    Btree bt;
    int* m = new int[n];
    srand(0);
    int random;
    for (int i = 0; i < n; i++) {
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
        bt.add(new Integer(m[i]));
    }
    cout << "items count: " << bt.size() << endl;
    double S = 0;
    int pog10 = n;
    for (int i = 0; i < n/2; i++) {
        S += bt.search2(m[i]);
    }
    cout << "theoretical count: 1.39 * log2(n) = " << 1.39*(log((double) n) / log(2.0)) << endl;
    cout << "practical count: " << S/(n/2) << endl;
    delete[] m;

    // time_t start, end;
    // srand(0);
    // for (int i = 0; i < 10000; i++) {
    //     bt->add(new Integer(rand()%11000));
    // }
    
    // int n = bt->size() / 2;
    // int arr[n];
    // start = clock();
    // for (int i = 0; i < n; i++) {
    //     arr[i] = bt->search2(rand()%11000);
    // }
    // end = clock();
    
    // double sum = 0;
    // for (int i = 0; i < n; i++) {
    //     //cout << arr[i] << " ";
    //     if (arr[i] != -1) {
    //         sum += arr[i];
    //     }
        
    // }
    // cout << endl << (double) sum / n << endl;
    // cout << double (end-start) * 1000 << endl;
}

int main() {
    
    for (int i = 1000; i <= 10000; i+=1000) {
        test_rand(i);
        cout << endl;
    }
    
    
    return 0;
}