#include <cstdlib>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <math.h>
#include <climits>
#include <sstream>
#include <set>


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




//double List
struct dlist{
        int val;
        dlist *prev;
        dlist *next;
        dlist(int num){
            val = num;
            prev = next = nullptr;
        }
    };


class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        size = 0;
    }
    
    void addNum(int num) {
        if(size == 0)
            mean = new dlist(num);
        else{
            if(num >= mean->val){
                dlist *right = mean;
                while(right->next != nullptr && num >= right->next->val){
                    right = right->next;
                }
                
                
                if(right->next == nullptr){
                    right->next = new dlist(num);
                    right->next->prev = right;
                }
                else{
                    dlist *temp = new dlist(num);
                    temp->next = right->next;
                    right->next->prev = temp;
                    temp->prev = right;
                    right->next = temp;
                }      
                
                if(size%2 == 0)
                    mean = mean->next;
            }
            else{
                dlist *left = mean;
                while(left->prev != nullptr && num < left->prev->val){
                    left = left->prev;
                }
                if(left->prev == nullptr){
                    left->prev = new dlist(num);
                    left->prev->next = left;
                }
                else{
                    dlist *temp = new dlist(num);
                    left->prev->next = temp;
                    temp->prev = left->prev;
                    temp->next = left;
                    left->prev = temp;
                }
                
                if(size%2 == 1)
                    mean = mean->prev;
            }
        }
        size++;
    }
    
    double findMedian() {
        double sum = 0;
        /*
        cout<<size<<"->";
        //cout<<mean->val<<endl;
        dlist *temp = mean;
        while(temp->prev != nullptr)
            temp = temp->prev;
        while(temp->next != nullptr){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<temp->val;
        cout<<endl;*/
        if(size%2 == 0)
            sum += mean->val + mean->next->val;
        else
            return mean->val;
        
        return sum/2;
    }
    
    dlist *mean;
    int size;
    
};


//87.92 PQ
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(left.size() == right.size()){
            if(left.size() == 0)
                left.push(num);
            else{
                if(num > right.top())
                    right.push(num);
                else
                    left.push(num);
            }
        }
        else if(left.size() > right.size()){
            if(num < left.top()){
                left.push(num);
                num = left.top();
                left.pop();
            }
            right.push(num);
        }
        else if(right.size() > left.size()){
            if(num > right.top()){
                right.push(num);
                num = right.top();
                right.pop();
            }
            left.push(num);
        }
        return;
    }
    
    double findMedian() {
        if(left.size() > right.size())
            return left.top();
        else if(right.size() > left.size())
            return right.top();
        else{
            double sum = left.top() + right.top();
            return sum/2;
        }
    }
    
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
int main(){
	Solution a;
	vector<pair<int, int>> vec = {{0, 5}, {15,20}, {5,10}};

	int ans = a.meetingroom(vec);

	cout<<ans<<endl; 

	return EXIT_SUCCESS;
}