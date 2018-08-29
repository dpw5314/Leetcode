#include<cstdlib>
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<string>
#include<sstream>
#include<math.h>
#include<climits>
#include <sstream>


using namespace std;
const int size =9;

struct Interval {
   int start;
   int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
 };

void PrintItvectorInterval(vector<Interval> & a){
	for(int i = 0; i < a.size(); i++){
		cout<<a[i].start<<" "<<a[i].end<<endl;
	}
}

template<typename T>
void PrintItvector(vector<vector<T> >& a){
	for(int i = 0; i < a.size(); i++){
		for(int j=0; j<a[i].size(); j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

template<typename T>
void PrintItvector(vector<T>& a){
	for(int i = 0; i < a.size(); i++){
			cout<<a[i]<<" ";
	}
	cout<<endl;
}

template<typename T>
void PrintIt(T (&a)[size][size], int size){
	for(int i = 0; i < size; i++){
		for(int j=0; j<size; j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}


int factorial(int n){
	return (n==1 || n==0)? 1:factorial(n-1)*n;
}


int choose(int n, int k){
    int max = n+k-1;
    int a, b;
    int start = 1;
    a = (n-1 > k) ? n-1 : k;
    b = (n-1 < k) ? n-1 : k;
    //cout<<a<<b<<max;
    for(int i = a+1; i<= max; i++){
        start*=i;
        //cout<<i;
    }
    //cout<<start<<" "<<factorial(b)<<endl;
    return start/factorial(b);
}


int climbStairs(int n) {
    int num1 = n, num2 = 0;
    int ans = 0, temans;
    if(n>0) ans++;
    else return ans;
    num1 -= 2;
    while(num1 > 0){
        num2++;
        temans = choose(num1+1, num2); 
        //if (num2 > num1) temans =  choose(num2+1, num1);
        //else     temans = choose(num1+1, num2); 
        //cout<<temans<<endl;
        ans += temans;
        num1 -= 2;
    }
    if(num1 == 0) ans++;
    return ans;
}




int main(){
	int n = 35;
	int ans;
	ans = climbStairs(n);
	cout<<ans;
	//PrintItvectorInterval(ans);
    return EXIT_SUCCESS;
}
