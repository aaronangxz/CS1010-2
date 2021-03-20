#include <iostream>
#include <vector>
#include <map> 
 
using namespace std;

struct NUSModule 
{
    string code;
    int credits;
    string grade;
    bool su;
};

void make_module(NUSModule &module, string code, int credits, string grade) 
{
    module.code = code;
    module.credits = credits;
    module.grade = grade;
    module.su = false;
    //module = {code, credits, grade, false}; //Works too
}

void set_su(NUSModule &module, bool su) 
{
    if(su == true) 
    {
        if(module.grade == "D" || module.grade == "D+" || module.grade == "F") module.grade = "U";
        else module.grade = "S";
    }
}

int credits_obtained(const vector<NUSModule> &modules) 
{
    int credits = 0;
    for(int i = 0; i < modules.size(); i++)
    {
        if(modules[i].grade != "F" && modules[i].grade != "U") credits += modules[i].credits;
    }
    return credits;
}

double calculate_cap(const vector<NUSModule> &modules, const map<string, double> &points) 
{
    double cap = 0;
    int credit = 0;

    for(int i = 0; i < modules.size(); i++)
    {
        string grade = modules[i].grade;
        int credits = modules[i].credits;

        if(grade != "S" && grade != "U")
        {
            cap += credits * points.at(grade); 
            credit += credits;
        }
    }
    return cap / credit ;
}

int main(void)
{
    NUSModule tic1001, tic1101, tba2102, tic2301, tic1231;
    //vector<NUSModule> modules ={{"tic1001",5,"F",true}};
    vector<NUSModule> modules;
    map<string, double> grade2points;

    grade2points.insert(pair<string, double>("A+", 5.0)); 
    grade2points.insert(pair<string, double>("A", 5.0)); 
    grade2points.insert(pair<string, double>("A-", 4.5)); 
    grade2points.insert(pair<string, double>("B+", 4.0)); 
    grade2points.insert(pair<string, double>("B", 3.5)); 
    grade2points.insert(pair<string, double>("B-", 3.0)); 
    grade2points.insert(pair<string, double>("C+", 2.5)); 
    grade2points.insert(pair<string, double>("C", 2.0)); 
    grade2points.insert(pair<string, double>("D+", 1.5)); 
    grade2points.insert(pair<string, double>("D", 1.0)); 
    grade2points.insert(pair<string, double>("F", 0.0)); 

    make_module(tic1231, "TIC1231", 2, "F");
    modules.push_back(tic1231);

    make_module(tic1001, "TIC1001", 4, "A");	
    modules.push_back(tic1001);	

    make_module(tic1101, "TIC1101", 4, "B-");	
    modules.push_back(tic1101);	

    make_module(tba2102, "TBA2102", 3, "C"); set_su(tba2102, true);	
    modules.push_back(tba2102);	

    make_module(tic2301, "TIC2301", 4, "D"); set_su(tic2301, true);
    modules.push_back(tic2301);

    int ans = credits_obtained(modules);
    cout << "Total Credit is: " << ans << endl;
    cout << "CAP: " << calculate_cap(modules, grade2points);
}