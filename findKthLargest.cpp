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

/// 98%
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        PrintItvector(nums);
        return nums[nums.size()-k];
    }
};


//QuickSort with quickSelection 99%
class Solution {
public:   

    const int& med(vector<int>& nums, int left, int right){
        int center = (left+right)/2;
        if(nums[center]<nums[left])
            std::swap(nums[center], nums[left]);
        if(nums[right]<nums[left])
            std::swap(nums[right], nums[left]);
        if(nums[right]<nums[center])
            std::swap(nums[right], nums[center]);
        
        std::swap(nums[center], nums[right-1]);
        //cout<<nums[right-1]<<endl;
        return nums[right-1];
    }
    
    void QuickSort(vector<int>& nums, int left, int right, int k){
        if(right <= left)
            return;
        else if(right == left+1){
            if(nums[left]>nums[right])
                std::swap(nums[left],nums[right]);
            return;
        }
        const int& pivot = med(nums,left,right);
        int i = left, j = right-1;
        while(1){
            while(nums[++i] < pivot){}
            while(nums[--j] > pivot){}
            if(i<j)
                std::swap(nums[i], nums[j]);
            else{
                break;
            }
        }
        std::swap(nums[i], nums[right-1]);
        if(k < i)
            QuickSort(nums, left, i-1, k);
        else if (k == i)
            return;
        else
            QuickSort(nums, i+1, right, k);
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> tem(nums.size());
        QuickSort(nums, 0, nums.size()-1, nums.size() - k);
        //MergeSort(nums, tem, 0, nums.size()-1);

        return nums[nums.size()-k];
    }
};

//84 QuickSort
class Solution {
public:
    const int& med(vector<int>& nums, int left, int right){
        int center = (left+right)/2;
        if(nums[center]<nums[left])
            std::swap(nums[center], nums[left]);
        if(nums[right]<nums[left])
            std::swap(nums[right], nums[left]);
        if(nums[right]<nums[center])
            std::swap(nums[right], nums[center]);
        
        std::swap(nums[center], nums[right-1]);
        //cout<<nums[right-1]<<endl;
        return nums[right-1];
    }
    
    void QuickSort(vector<int>& nums, int left, int right){
        if(right <= left)
            return;
        else if(right == left+1){
            if(nums[left]>nums[right])
                std::swap(nums[left],nums[right]);
            return;
        }
        const int& pivot = med(nums,left,right);
        int i = left, j = right-1;
        while(1){
            while(nums[++i] < pivot){}
            while(nums[--j] > pivot){}
            if(i<j)
                std::swap(nums[i], nums[j]);
            else{
                std::swap(nums[i], nums[right-1]);
                break;
            }
        }
        QuickSort(nums, left, i-1);
        QuickSort(nums, i+1, right);
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        QuickSort(nums, 0, nums.size()-1);

        return nums[nums.size()-k];
    }
};

/// 54
class Solution {
public:
    void merge(vector<int>& nums, vector<int>& temp, int leftStart, int rightStart, int rightEnd){
        if(rightStart == leftStart+1){
            if(nums[leftStart] > nums[rightStart])
                std::swap(nums[leftStart], nums[rightStart]);
            return;
        }
        int StartPos = leftStart;
        int leftEnd = rightStart - 1;
        int tempPos = leftStart;
        while(leftStart <= leftEnd && rightStart <= rightEnd){
            if(nums[leftStart] < nums[rightStart])
                temp[tempPos++] = std::move(nums[leftStart++]);
            else
                temp[tempPos++] = std::move(nums[rightStart++]);
        }
        while(leftStart <= leftEnd)
            temp[tempPos++] = std::move(nums[leftStart++]);
        while(rightStart <= rightEnd)
            temp[tempPos++] = std::move(nums[rightStart++]);
        
        for(int j = rightEnd; j>=StartPos; j--)
            nums[j] = std::move(temp[j]);
    }
    void MergeSort(vector<int>& nums, vector<int>& temp, int left, int right){
        if(left<right){
            int center = (left+right)/2;
            MergeSort(nums, temp, left, center);
            MergeSort(nums, temp, center+1, right);
            merge(nums, temp, left, center+1, right);
        }
        
    }    
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> tem(nums.size());
        //QuickSort(nums, 0, nums.size()-1);
        MergeSort(nums, tem, 0, nums.size()-1);

        return nums[nums.size()-k];
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