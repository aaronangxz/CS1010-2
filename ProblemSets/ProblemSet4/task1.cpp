#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/**************************
Point Class
**************************/
class Point {

public:

//Constructor is the make_point() equivalent in OOP approach
Point( double x, double y) {
    p[0] = x;
    p[1] = y;
}

//Minor change to the name, instead of x_of() ==> get_x()
virtual double get_x() const {
    return p[0];
}

//Minor change to the name, instead of y_of() ==> get_y()
virtual double get_y() const {
    return p[1];
}

virtual void set_x( double val) {
    p[0] = val;
}

virtual void set_y( double val) {
    p[1] = val;
}

//Example to show interaction between objects of the same class
virtual double distance_to(const Point& anotherPt ) const {
    double x = p[0] - anotherPt.p[0];   //note that you can access the
                                        // private data of objects of
                                        // the same class
    double y = p[1] - anotherPt.p[1];

    return sqrt(x*x + y*y);
}

//TODO: useful method to the main task
//Return true if p has the same (x,y) as this object
virtual bool equal(const Point& p){
    if(this->get_x() ==  p.get_x() && this->get_y() == p.get_y()) return true;
    return false; //remember to change
}

//Minor change to the name, instead of display_point() ==> print()
virtual void print(ostream &out) {
    out << "(" << get_x() << "," << get_y() << ")";
}

private:
    double p[2];
};

/*****************************
Line Class
*****************************/
class Line {

public:


//Constructor is the make_line() equivalent in OOP approach
Line(const Point &s, const Point &e)
: start(s), end(e) {
}

virtual Point get_start() const {
    return start;
}

virtual Point get_end() const {
    return end;
}


virtual double length() const {
    return start.distance_to( end );
}

//TODO: useful method to the main task
//Return true if l has the same end points as this object
//Note that the end points may be reversed for the two lines
bool equal( const Line& l) {
    if(this->start.equal(l.get_start()) && this->end.equal(l.get_end())) return true;
    else if (this->start.equal(l.get_end()) && this->end.equal(l.get_start())) return true;
    return false; //remember to change
}


private:
    Point start, end;
}; 

/*****************************
Polygon Class
*****************************/

//TODO: Decide the internal representation and complete
//      the methods in this class
class Polygon {

public:

Polygon( const Point& p1, const Point& p2, const Point& p3) 
{
    Points.push_back(p1);
    Points.push_back(p2);
    Points.push_back(p3);

    Lines.push_back(Line(p1,p2));
    Lines.push_back(Line(p2,p3));
    Lines.push_back(Line(p3,p1));
}

virtual bool add(Point& p) 
{
    for(Point point : Points)
    {
        if(point.equal(p)) return false;
    }
    Lines.pop_back();
    Lines.push_back(Line(Points.back(),p));
    Lines.push_back(Line(p,Points.front()));
    Points.push_back(p);
    return true; //remember to change
}

virtual bool add(Line& exist, Point& p) 
{
    int count = 0;
    bool isExist = false;
    for(int i = 0; i < Lines.size(); i++)
    {
        if(Lines[i].equal(exist))
        {
            count = i;
            isExist = true;
            break;
        }
    }

    if(!isExist) return false;

    Point start = exist.get_start();
    Point end = exist.get_end();
    Line to = Line(start,p);
    Line from = Line(p,end);
    Points.push_back(p);
    Lines.erase(Lines.begin() + count);
    Lines.insert(Lines.begin() + count, to);
    Lines.insert(Lines.begin() + count + 1,from);
    return true; //remember to change
}

virtual double perimeter() 
{
    double peri = 0;
    for(Line b: Lines) peri += b.length();
    return peri;
}

virtual void print( ostream& out ) 
{

//Printing format example
//(1,1) -> (2,2) -> (3,3) -> (1,1)
//Notes:
//     No extra space at the end
//     The first point is printed again at the end
    for(Point p: Points)
    {
        p.print(out);
        out << " -> ";
    }
    Points[0].print(out);
    out << endl;
}


private:

//TODO: Decide your internal representation
// e.g. vector of points / lines,
//   linked list of points / lines etc
    vector<Point> Points;
    vector<Line> Lines;
};


int main()
{
    Point p1(2,2), p2(5,2), p3(5,6), p4(5,2);

    //Part 1. Point

    //  Distance test
    cout << "Distance from p1 to p2 is ";
    cout << p1.distance_to( p2 ) << endl;

    //  Same point check: should be true
    cout << "Is p1 the same as p2 =  ";
    cout << p1.equal( p2 ) << endl;

    //  Same point check: should be false
    cout << "Is p2 the same as p4 =  ";
    cout << p2.equal( p4 ) << endl;

    //Part 2. Line 
    Line l1(p1, p2), l2(p2, p1), l3(p1, p3);

    //  l1 is the same as l2, even though the points are reversed
    cout << "Is l1 the same as l2 =  ";
    cout << l1.equal( l2 ) << endl;

    //  l1 is the not the as l3
    cout << "Is l1 the same as l3 =  ";
    cout << l1.equal( l3 ) << endl;


    //Part 3. Polygon

    //  Use of constructor
    Polygon pg(p1, p2, p3);
    
    //  Basic test of print() and perimeter()


    pg.print( cout );
    cout << "Perimeter = " << pg.perimeter() << endl;

    //  Add duplicate point, i.e. should fail to add
    if ( !pg.add(p1)){
        cout << "Add p1 to polygon failed!\n";
    } else {
        cout << "Add p1 to polygon ok!\n";
        pg.print( cout );
        cout << "Perimeter = " << pg.perimeter() << endl;
    }

    //  Add point should be ok in this case
    Point p5(2,6);

    if ( !pg.add(p5)){
        cout << "Add p5 to polygon failed!\n";
    } else {
        cout << "Add p5 to polygon ok!\n";
        pg.print( cout );
        cout << "Perimeter = " << pg.perimeter() << endl;
    }


    //  Use the alternative version of add point


    //  This case should fail as l6 is not an existing line in polygon pg
    Point p7(-1, 2);
    Line l6(p1, p3);

    if (!pg.add(l6, p7)){
        cout << "Remove l6 and add p7 to polygon failed!\n";
    } else {
        cout << "Remove l6 and add p7 to polygon ok!\n";
        pg.print( cout );
        cout << "Perimeter = " << pg.perimeter() << endl;
    }

	//  This case should be ok as l5 is an existing line in polygon pg
    Point p6(-1, 6);
    Line l5(p1, p5);

    if (!pg.add(l5, p6)){
        cout << "Remove l5 and add p6 to polygon failed!\n";
    } else {
        cout << "Remove l5 and add p6 to polygon ok!\n";
        pg.print( cout );
        cout << "Perimeter = " << pg.perimeter() << endl;
    }


    return 0;
}
