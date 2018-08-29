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




vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ans;
        int start, end, index;
        sort(intervals.begin(), intervals.end(), [](Interval&a, Interval&b){
        	if(a.start == b.start) return a.end<b.end;
        	else   return a.start<b.start;
        });
        for(int i = 0; i < intervals.size(); i++){
            
            index = i;
            end = intervals[i].end;
            while(index+1<intervals.size() and (intervals[index].end >= intervals[index+1].start or end >= intervals[index+1].start)){
                index++;
                end = (end > intervals[index].end) ? end :intervals[index].end;
            }
            
            if(index > i){
                start = intervals[i].start ;
                Interval tem(start,end);
                ans.push_back(tem);
                i = index;
            }
            else ans.push_back(intervals[i]);
        }
        return ans;
    }


int main(){
	vector<vector<int>> start = {{5,5},{1,3},{3,5},{4,6},{1,1},{3,3},{5,6},{3,3},{2,4},{0,0}};
	//{{0,0},{1,2},{5,5},{2,4},{3,3},{5,6},{5,6},{4,6},{0,0},{1,2},{0,2},{4,5}};
	//{{1,3},{0,2},{2,3},{4,6},{4,5},{5,5},{0,2},{3,3}};
	//{{5,5},{1,3},{3,5},{4,6},{1,1},{3,3},{5,6},{3,3},{2,4},{0,0}};
	vector<Interval> start1, ans;
	for(int i = 0; i < start.size(); i++){
		Interval tem(start[i][0], start[i][1]);
		start1.push_back(tem);
	}
	ans = merge(start1);
	PrintItvectorInterval(start1);
	cout<<"Ans:\n";
	PrintItvectorInterval(ans);
    return EXIT_SUCCESS;
}
