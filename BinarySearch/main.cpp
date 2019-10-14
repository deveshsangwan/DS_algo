#include <iostream>
using namespace std;
// arr - input array
// n - size of array
// val - element to be searched
int BinarySearch(int arr[], int n, int val){	
    int start=0,end=n-1,mid=(start+end)/2;
    while(val!=arr[mid]){
        
        if(arr[mid]<val){
            start=mid+1;
        }
        else if(arr[mid]>val){
            end=mid-1;
        }
        mid=(start+end)/2;
    
        if(start>end){
            break;
        }
    }
    if(val!=arr[mid]){
        return -1;
    }
    return mid;
}

int main(){
    int size,val;
	cin>>size;
	int *input=new int[1+size];
	
	for(int i=0;i<size;i++)
		cin>>input[i];

	cin>>val;
	cout<<BinarySearch(input,size,val) << endl;
	return 0;
}