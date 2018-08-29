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


//94.70
class Solution {
public:
    int Operators(int a, int b, char op){
        //cout<<"Op"<<a<<" "<<b<<endl;
             if(op == '+')
                return a+b;
            else if(op == '-')
                return a-b;
            else if(op == '*')
                return a*b;    
    }

    
    vector<int> diffWaysToCompute(string input) {
        vector<int> ans;

        for(int i = input.size()-1; i>= 0;i--){
            if(input[i] == '+' || input[i] == '-' || input[i] == '*'){
                vector<int> left =  diffWaysToCompute(input.substr(0, i));
                vector<int> right = diffWaysToCompute(input.substr(i+1, input.size()- i - 1));
                for(auto ele : left)
                    for(auto ele1 : right)
                        ans.push_back(Operators(ele, ele1, input[i]));
            }
        }
        if(ans.empty())
            ans.push_back(stoi(input));
        return ans;
    }
};

int main(){
	Solution a;
	vector<int> vec = {3,2,3,1,2,4,5,5,6};
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
	int ans = a.findKthLargest(vec, 4);
	cout<<ans;
	return EXIT_SUCCESS;
}