#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;


/******************************************
Part A. Date Related Functions
******************************************/
struct Date {
		
};

void make_date(Date& newDate, 
		int year, int month, int day)
{
}

int compare_date( Date& dateA, Date& dateB )
{
	return 0; //remember to change
}

/******************************************
Part B. Time Related Functions
******************************************/
struct Time {
};

void make_time( Time& newTime, int hour, int minute )
{
}
 
int compare_time( Time& timeA, Time& timeB )
{
	return 0; //remember to change
}


/******************************************
Part C. Appointmnet Related Functions
******************************************/

struct Appointment {
};

void make_appointment( Appointment& newApt,
             string description, 
             int year, int month, int day,
             int startHour, int startMinute,
             int endHour, int endMinute ) 
{
}


bool has_conflict( Appointment& aptA, Appointment& aptB )
{
	return false; //remember to change
}

/***********************************************************
   Main function
***********************************************************/

int main()
{
    //Comment / modify the following statements to test
    //Note: you should test beyond these cases
    //Note2: you should consider implement additional useful helper
    //       functions

    /*****************
     *Testing Part A.*
     *****************/

    // Date dateOne, dateTwo;
    // make_date(dateOne, 2018, 1, 23);
    // make_date(dateTwo, 2018, 1, 23);

    // //Should be 0 for the sample test values above
    // cout << "Date compare result = " 
    //     << compare_date(dateOne, dateTwo) << endl;


    /*****************
     *Testing Part B.*
     *****************/

    // Time timeOne, timeTwo;
    // make_time(timeOne, 11, 30);
    // make_time(timeTwo,13, 45);

    // //Should be -1 for the sample test values above
    // cout << "Time compare result = " 
    //     << compare_time(timeOne, timeTwo) << endl;

    /*****************
     *Testing Part C.*
     *****************/
    // Appointment aptOne, aptTwo;
    // make_appointment(aptOne, "Appointment One",
    // 				2018, 1, 23, 11, 30, 12, 45);

    // make_appointment(aptTwo, "Appointment Two",
    // 				2018, 1, 23, 12, 45, 13, 15);

    // //Should be Fine for the sample test values above
    // //Make sure you test all possibilities
    // if (has_conflict( aptOne, aptTwo)){
    // 		cout << "Appointments CLASH!\n";
    // } else {
    // 		cout << "Appointments are FINE!\n";
    // }
	return 0;
}
