#include "btree.hpp"
#include "Integer.hpp"
#include "Date.hpp"
#include <ctime>

int main() {
    srand(0);
    Btree *bt = new Btree; 
    object *in = new Integer;
    time_t start, end;
    // insert
    start = clock();
    for (int i = 0; i < 2000000; i++) {
        bt->add(new Integer(rand()%2000000));
    }
    end = clock();
    cout << "Inserting: " << double (end-start) / 1000 << endl;
    // write bin
    start = clock();
    bt->wrBin();
    end = clock();
    cout << "Writing in bin: " << double (end-start) / 1000 << endl;
    // deleting
    start = clock();
    for (int i = 0; i < 2000000; i++) {
        bt->deleteObj(new Integer(rand()%2000000));
    }
    end = clock();
    cout << "Deleting: " << double (end-start) / 1000 << endl;
    
    return 0;
}