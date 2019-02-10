#include<iostream>
using namespace std;



//partition function
int partition(int *a,int startt,int endd){
	//what is pivot
	int pivot=a[endd];
	int partitionindex=startt;
	//we go along array if a[i] is less equal to then put at 1 ,2,3 position as partitionindex place
	for(int i=startt;i<endd;i++){
		if(a[i]<=pivot){
		swap(a[i],a[partitionindex]);
		partitionindex++;
		}
	}
	//after all done
	swap(a[partitionindex],a[endd]);
	return partitionindex;
}

//quickshort function
void qs(int * a,int startt,int endd){
	if(startt<endd){
		//what is pivot==number in array at end and partition ''index'' 	from which we compare
		int pivot=a[endd];
		//call partition function
		int pindex=partition(a,startt,endd);
		//recursive function
		qs(a,startt,pindex-1);
		qs(a,pindex+1,endd);
	}
}


int main(){

//define array
int arr[10]={3,5,6,8,7,0,1,2,9,4};
int end=9;
int start=0;
//calling function
//partition(arr,start,end);
qs(arr,start,end);

//display
for(int i=0;i<=end;i++){
cout<<arr[i]<<endl;
}
return 0;
}
