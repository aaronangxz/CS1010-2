#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

/** BEGIN ADT 
  Example ADT for use for local testing
   Note: actual implementation might be differ **/
struct GPS {
    double point;
};

bool close_contact(GPS g1, GPS g2) {
    return abs(g1.point - g2.point) <= 10.0;
}

/** END OF ADT **/

/* Part A */
struct Person {

};


/* Part B */
void log(Person &person, long time, GPS position) {
    
}


/* Part C */
bool has_contact(Person &person, long time, GPS position) {
    return false;
}


/* Part D */
bool has_contact(Person &p, Person &q) {
    return false;
}

void test_contact() {
    Person p;
    log(p, 100, {100});    
    log(p, 500, {200});  // Note the order of logs need not be
    log(p, 200, {200});  // in increasing time
    log(p, 300, {400});

    Person q;
    log(q, 80,  {300});
    log(q, 150, {210});
    log(q, 240, {500});    

    Person r;
    log(r, 260, {100});
    log(r, 360, {200});
    log(r, 500, {490});    

    Person s;
    log(s, 80, {200});
    log(s, 110, {400});
    log(s, 260, {300});
    log(s, 450, {100});

    cout << std::boolalpha;
    cout << "Task C" << endl;         
    cout << has_contact(p, 250, {190}) << endl;
    cout << has_contact(p, 700, {190}) << endl;
    cout << has_contact(p, 400, {190}) << endl;
    
    cout << "Task D" << endl;
    cout << has_contact(p, q) << endl;
    cout << has_contact(q, p) << endl;
    cout << has_contact(p, r) << endl;
    cout << has_contact(q, r) << endl;
    
    cout << has_contact(s, p) << endl;
    cout << has_contact(s, q) << endl;
    cout << has_contact(s, r) << endl;    
}

int main() {    
    test_contact();
    return 0;
}