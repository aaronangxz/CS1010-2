#include <iostream>

using namespace std;

struct LandPlot{
    int length, width;
};


void sortLandPlot(LandPlot a[], int n)
{

}


int uniqueLandPlot(LandPlot a[], int n)
{
    return n;   //remember to change!
}

void printLandPlot(LandPlot landArray[], int n)
{
    int i;

    for (i = 0; i < n; i++){
        cout << "(" << landArray[i].length << " x ";
        cout << landArray[i].width << ": ";
        cout << (landArray[i].length * landArray[i].width);
        cout << ") " << endl;
    }
}

int main()
{
    LandPlot landArray[] = {
                            {10,2}, {8,2}, {1,3}, {4,5},
                            {4, 4}, {1, 16}, {16,1}, {1, 1}
                            };
    int nLandPlot = 8;

    cout << "** Original **\n";
    printLandPlot(landArray, nLandPlot);

    cout << "** After Sorting **\n";
    sortLandPlot(landArray, nLandPlot);
    printLandPlot(landArray, nLandPlot);


    cout << "** After Uniqueness Filter **\n";
    nLandPlot = uniqueLandPlot(landArray, nLandPlot);
    cout << nLandPlot << " unique land plot(s).\n";
    printLandPlot(landArray, nLandPlot);


    return 0;
}

/*

//Sample implementation for the sorting algorithms


//Swap, Needed for any of the following sorting functions
void swap(int a[], int i, int j) {
    int temp;

    temp = a[i] ; 
    a[i] = a[j] ; 
    a[j] = temp ;
}


//Selection Sort
void selectionSort(int a[], int n) {
    int i, j, maxIdx;

    for (i = n-1; i >= 1; i--) {
        maxIdx = i;
        for (j = 0; j < i; j++) {
            if (a[j] >= a[maxIdx]){
                maxIdx = j;
            }
        }
        swap(a, maxIdx, i);
    }
}

//Bubble Sort, with early termination
void bubbleSort2(int a[], int n) {
    int i, j;
    bool sorted;
    for (i = n-1; i >= 1; i--) {
        sorted = true;
        for (j = 1; j <= i; j++) {
              if (a[j-1] > a[j]) {
                swap(a, j, j-1);
                sorted = false;
            }
        } //end of inner loop 
        if (sorted)
            return;
    } 
}


//Insertion Sort
void insertionSort(int a[], int n)
{
    int i, j, next;
    for (i=1; i<n; i++) {
        next = a[i];
    
        for (j=i-1; j>=0 && a[j]>next; j--){
             a[j+1] = a[j];
        }            
        a[j+1] = next;
    } 
}

*/
