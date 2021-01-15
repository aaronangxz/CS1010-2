#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;


/******************************************
Part A. Date Related Functions
******************************************/
struct Date 
{
    int year;
    int month;
    int day;
};

void make_date(Date& newDate, int year, int month, int day)
{
    newDate = {year, month, day};
}

int compare_date( Date& dateA, Date& dateB )
{
	if (dateA.year == dateB.year)
    {
        if (dateA.month == dateB.month)
        {
            if (dateA.day > dateB.day) return 1;
            else if (dateA.day == dateB.day )return 0;
            else return -1;
        }
        else if (dateA.month > dateB.month) return 1;
        else return -1;
    }
    else if (dateA.year > dateB.year) return 1;
    else return -1;
}

/******************************************
Part B. Time Related Functions
******************************************/
struct Time 
{
    int hour;
    int minutes;
};

void make_time( Time& newTime, int hour, int minute )
{
    newTime = {hour, minute};
}
 
int compare_time( Time& timeA, Time& timeB )
{
	if (timeA.hour == timeB.hour)
    {
        if (timeA.minutes == timeB.minutes)return 0;
        else if (timeA.minutes > timeB.minutes) return 1;
        else return -1;
    }
    else if (timeA.hour > timeB.hour) return 1;
    else return -1;
}


/******************************************
Part C. Appointmnet Related Functions
******************************************/

struct Appointment 
{
    string description;
    int year;
    int month;
    int day;
    int startHour;
    int startMinute;
    int endHour;
    int endMinute;
};

void make_appointment( Appointment& newApt,
             string description, 
             int year, int month, int day,
             int startHour, int startMinute,
             int endHour, int endMinute ) 
{
    newApt = {description,year,month,day,startHour,startMinute,endHour,endMinute};
}


bool has_conflict( Appointment& aptA, Appointment& aptB )
{
    Date aptAdate, aptBdate;
    make_date(aptAdate,aptA.year,aptA.month,aptA.day);
    make_date(aptBdate,aptB.year,aptB.month,aptB.day);
    Time aptAstart, aptBstart, aptAend, aptBend;
    make_time(aptAstart,aptA.startHour,aptA.startMinute);
    make_time(aptBstart,aptB.startHour,aptB.startMinute);
    make_time(aptAend,aptA.endHour,aptA.endMinute);
    make_time(aptBend,aptB.endHour,aptB.endMinute);

    if (compare_date(aptAdate,aptBdate)== 0)
    {
        if (compare_time(aptAend,aptBstart) == 0 || compare_time(aptAend,aptBstart) == -1) return false;
        else if (compare_time(aptBend,aptAstart) == 0 || compare_time(aptBend,aptAstart) == -1) return false;
        else return true;
    }
    else return false;
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

    Date dateOne, dateTwo;
    make_date(dateOne, 2018, 1, 23);
    make_date(dateTwo, 2018, 1, 23);

    //Should be 0 for the sample test values above
    cout << "Date compare result = " 
        << compare_date(dateOne, dateTwo) << endl;


    /*****************
     *Testing Part B.*
     *****************/

    Time timeOne, timeTwo;
    make_time(timeOne, 11, 30);
    make_time(timeTwo,13, 45);

    //Should be -1 for the sample test values above
    cout << "Time compare result = " 
        << compare_time(timeOne, timeTwo) << endl;

    /*****************
     *Testing Part C.*
     *****************/
    Appointment aptOne, aptTwo;
    make_appointment(aptOne, "Appointment One",
    				2018, 1, 23, 11, 30, 12, 45);

    make_appointment(aptTwo, "Appointment Two",
    				2018, 1, 23, 12, 45, 13, 15);

    // //Should be Fine for the sample test values above
    // //Make sure you test all possibilities
    if (has_conflict( aptOne, aptTwo)){
    		cout << "Appointments CLASH!\n";
    } else {
    		cout << "Appointments are FINE!\n";
    }
	return 0;
}
