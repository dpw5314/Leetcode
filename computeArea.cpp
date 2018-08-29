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


//73.48
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        pair<int, int> Aw, Ah, Bw, Bh, Ow, Oh;
        Aw = make_pair(A, C);      Ah = make_pair(B, D);
        Bw = make_pair(E, G);      Bh = make_pair(F, H);
        int Area = (Aw.second - Aw.first) *(Ah.second - Ah.first) + (Bw.second - Bw.first)* (Bh.second - Bh.first);
        
        if(Bw.first <= Aw.second && Bw.first >= Aw.first){
            int max = Aw.second < Bw.second? Aw.second:Bw.second;
            Ow = make_pair(Bw.first, max);
        }
        else if(Aw.first <= Bw.second  && Aw.first >= Bw.first){
            int max = Aw.second < Bw.second? Aw.second:Bw.second;
            Ow = make_pair(Aw.first, max);
        }
        else Ow = make_pair(0,0);
        
        if(Bh.first <= Ah.second && Bh.first >= Ah.first){
            int max = Ah.second < Bh.second? Ah.second:Bh.second;
            Oh = make_pair(Bh.first, max);
        }
        else if(Ah.first <= Bh.second && Ah.first >= Bh.first ){
            int max = Ah.second < Bh.second? Ah.second:Bh.second;
            Oh = make_pair(Ah.first, max);
        }
        else Oh = make_pair(0,0);
        int Overlap = (Ow.second - Ow.first) *(Oh.second - Oh.first);
        //cout<<Ow.first<<" "<<Ow.second<<endl;
        //cout<<Oh.first<<" "<<Oh.second;
        return Area - Overlap;
    }
};


int main(){
	vector<int> vec = {2,1,1,2};
	//{3,5,7,0,1,2};
	//{3,1};
	Solution* a = new Solution();
	int ans = a->rob(vec);
    cout<<ans;
    delete a;
	return EXIT_SUCCESS;
}