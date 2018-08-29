#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;



int main() {
vector<int> a = {1,2,3,4,5};

vector<int>::iterator it = find(a.begin(), a.begin()+1, 1);
cout<<a[it];
return EXIT_SUCCESS;
}
