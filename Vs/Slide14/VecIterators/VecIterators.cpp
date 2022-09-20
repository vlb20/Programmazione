#include <vector>
using std::vector;

int vectorSum1(vector<int> V){
    vector<int>::iterator p;//iterator per accedere ad un elemento di vector V
    int sum{0};
    for(p=V.begin(); p != V.end(); ++p){
        sum += *p;
    }
    return sum;
}

int vectorSum2(const vector<int>& V){
    vector<int>::const_iterator p;
    int sum{0};
    for(p=V.begin(); p != V.end(); ++p){
        sum += *p;
    }
    return sum;
}