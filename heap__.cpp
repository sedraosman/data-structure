#include <stdio.h>
#include<time.h>
#include<stdlib.h>

void shuffle(int arr[],int _size){
	srand(time(NULL));
	for(int i = 0;i < _size;i++){
		int swap_index = rand() % _size;
		int temp = arr[i];
		arr[i] = arr[swap_index];
		arr[swap_index] = temp;
		
		
	}
	
}


//swap islemi icin swap fonkisyonu;
void swap(int* x,int* y){
	int temp ;
	temp = *x;
	*x = *y;
	*y = temp;
	
}
// arr arreyi temsil eder
// size temsil eder
//x :pzisini temsil eder

void ekle(int arr[] ,int _size,int x) {

	int left = 2*x+1;
	int right = 2*x+2;
	int root = x;
	if(left < _size &&arr[left] > arr[root]){
	root = left;
}
	if(right<_size&&arr[right] > arr[root]){

root = right;}


	if (root != x)
{
	swap(&arr[x],&arr[root]);
	ekle(arr,_size,root);
}

}
void heap(int arr[] ,int _size ){

	for(int x=_size/2-1;x>=0;x--){
		ekle(arr,_size,x);
	}
}
void heapSort(int arr[], int _size)
{

	heap(arr, _size);
	for (int i = _size-1; i >=0; i--)
	{
		swap(&arr[0],&arr[i]);
		ekle(arr, i, 0);
	}

}
void print(int arr[], int n){
	
	for (int i = 0;i<n; i++){
		printf("%d\n",arr[i]);
	}
}
int main(){
	int _size=10000 ;
	int arr [_size];
	//random sayilarla arraye kurumu
	for(int i = 0;i < _size; i++)
	arr[i] = rand() % 100;
	//random txt
	FILE *file;
	file = fopen("random_number","w");
	for(int x = 0;x  <_size; x++){
	fprintf(file,"arr[%d]=%d",x,arr[x])	;
	}
	//shuffle fonkisyonu cagirildi
	shuffle(arr,_size);
	//shuffle txt 
	FILE *shuffle;
	shuffle = fopen("shuffle_arr","w");
	//print islemi
	for(int j = 0; j < _size; j++){
	fprintf(shuffle,"arr[%d]=%d",j,arr[j])	;
//	printf("arr[%d]=%d\n",j,arr[j]);
     
}

	heapSort(arr,_size);
	print(arr,_size);
	
	return 0;
}
