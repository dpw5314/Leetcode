  #include <cstdlib>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <math.h>
#include <climits>
#include <queue>
#include <sstream>
#include <unordered_map>

using namespace std;
const int size = 9;


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


string IntToString(int a)
{
    ostringstream temp;
    temp<<a;
    return temp.str();
}



struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };


//Beautiful Solution
 class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){return a.start<b.start;});
        
        vector<Interval> res {intervals[0]};
        for(auto ele:intervals){
            if(res.back().end < ele.start)
                res.push_back(ele);
            else
                res.back().end =(res.back().end > ele.end)? res.back().end : ele.end;
        }
        return res;
    }
        
};

//Mine
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        
        if(intervals.size() == 0){
            intervals.push_back(newInterval);
            return intervals;
        }
        
        int low = 0, high = intervals.size()-1;
        int mid;
        bool ifFind = false;
        
        //find the locations of first interval
        
        while(high >= low){
            mid = (high + low)/2;
            if(intervals[mid].end >= newInterval.start and intervals[mid].start <= newInterval.start){
                ifFind = true;
                break;
            }
            else if(intervals[mid].end < newInterval.start){
                //cout<<mid<<newInterval.start<<" "<<intervals[mid+1].start<<endl;
                mid++;
                if(mid < intervals.size() and newInterval.start < intervals[mid].start)
                    break;
                low = mid;
                //cout<<low<<high<<endl;
            }
            else if(intervals[mid].start > newInterval.start){
                mid--;
                if(mid  >= 0 and newInterval.start > intervals[mid].end){
                    mid++;
                    break;
                }           
                high = mid;
            }
        }
        
        cout<<mid;
        
        if(!ifFind){
            if(mid <0) mid = 0;
            else if(mid > intervals.size()) mid =  intervals.size();
            Interval temp(newInterval.start, newInterval.end);
            intervals.insert(intervals.begin()+mid, temp);
        }
        
        
        int Curr = mid; low = mid+1; high = intervals.size()-1;
        int End = newInterval.end;
        
        while(high >= low){
            mid = (high + low)/2;
            
            if(intervals[mid].end >= End and intervals[mid].start <= End)
                break;
            else if(intervals[mid].end < End){
                mid++;
                if(mid < intervals.size() and End < intervals[mid].start){
                    mid--;
                    break;
                }
                low = mid;
            }
            else if(intervals[mid].start > End){
                mid--;          
                high = mid;
            }
        }
                cout<<mid<<Curr<<endl;
        if(mid < Curr) mid = Curr;
        else if(mid >= intervals.size()) mid = intervals.size()-1;
        intervals[Curr].end = (End > intervals[mid].end)?End:intervals[mid].end;
        

        //cout<<*(intervals.begin()+Curr+1)<<" "<<*(intervals.begin()+mid);
        if(mid > Curr)            
            intervals.erase(intervals.begin()+Curr+1, intervals.begin()+mid+1);
    
        
        return intervals;
    }
        
};
int main(){
	Solution a;
	vector<vector<int>> vec = {
							  {1,   4,  7, 11, 15},
							  {2,   5,  8, 12, 19},
							  {3,   6,  9, 16, 22},
							  {10, 13, 14, 17, 24},
							  {18, 21, 23, 26, 30}};
	int target = 11;
	//{{'1','1','1'},{'0','1','0'},{'1','1','1'}};
							/*	{{'1','1','0','0','0'},
								{'1','1','0','0','0'},
								{'0','0','1','0','0'},
								{'0','0','0','1','1'}};*/
							/*	{{'1','1','1','1','0'},
								{'1','1','0','1','0'},
								{'1','1','0','0','0'},
								{'0','0','0','0','0'}};*/
	//{-2, 3, -4};
	//{-1,-2,-9,-6};

  //{412,392,401,75,38,106,223};
  //{58,92,387,421,194,208,231};
  //{186,419,83,408} ;
  //7802;
  //7798;
  //6249;
	bool ans = a.searchMatrix(vec, target);
	cout<<ans;
	return EXIT_SUCCESS;
}