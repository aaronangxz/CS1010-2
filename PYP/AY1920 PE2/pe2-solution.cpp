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
// Create custom ADT to record time + position
struct Log {
    long time;
    GPS position;
};

struct Person {
    // Just need to maintain a history of Logs
    vector<Log> log;
};


/* Part B */
void log(Person &person, long time, GPS position) {
    // We want the log to be in chronological order
    int i;                 
    // linear search through the vector to find where to insert
    for (i = 0; i < person.log.size(); i++) {
        if (person.log[i].time > time)
            break;
    }
    person.log.insert(person.log.begin() + i, {time, position}); 
}


/* Part C */
bool has_contact(Person &person, long time, GPS position) {
    // Linear search through the vector    
    // ---a---b---  looking for a time between two logs
    //      ^
    vector<Log> &log = person.log;
    for (int i = 0; i < log.size(); i++) {        
        if (close_contact(log[i].position, position) // if position is close
              and log[i].time <= time // a <= t
              and (i == log.size()-1  // a is the last log
                   or time <= log[i+1].time) // t <= b
            ) {          
            return true;
        }        
    }
    return false;
}


/* Part D */
bool has_contact(Person &p, Person &q) {
    // reuse Part C.
    // Check for every log in P, was Q close to it
    for (Log l : p.log) {        
        if (has_contact(q, l.time, l.position))
            return true;        
    }              
    // Do the same for the reverse
    for (Log l : q.log) {
        if (has_contact(p, l.time, l.position))
            return true;        
    }
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