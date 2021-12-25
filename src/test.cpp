#include "btree.hpp"
#include "Integer.hpp"
#include "Date.hpp"
#include <ctime>

int main() {
    // srand(0);
    // Btree *bt = new Btree; 
    // object *in = new Integer;
    // time_t start, end;
    // // insert
    // start = clock();
    // for (int i = 0; i < 2000000; i++) {
    //     bt->add(new Integer(rand()%2000000));
    // }
    // end = clock();
    // cout << "Inserting: " << double (end-start) / 1000 << endl;
    // // write bin
    // start = clock();
    // bt->wrBin();
    // end = clock();
    // cout << "Writing in bin: " << double (end-start) / 1000 << endl;
    // // deleting
    // start = clock();
    // for (int i = 0; i < 2000000; i++) {
    //     bt->deleteObj(new Integer(rand()%2000000));
    // }
    // end = clock();
    // cout << "Deleting: " << double (end-start) / 1000 << endl;
    object* o1 = new Integer;
    object* o2 = new Date;
    cin >> *(Integer*)o1;
    cin >> *(Date*)o2;
    cout << equal(o1, o2);
    return 0;
}