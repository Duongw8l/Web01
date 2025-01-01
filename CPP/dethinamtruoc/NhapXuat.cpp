#include<iostream>
#include<algorithm>
#define SIZE 100
using namespace std;



//hàm tìm max
int Max(int arr[], int n ){
	int i;
   int max = arr[0];
   for (i = 1; i < n; i++)
      if (arr[i] > max)
         max = arr[i];

   return max;
}


//hàm tìm min
int Min(int arr[], int n){
	int i;
   int min = arr[0];
   for (i = 1; i < n; i++)
      if (arr[i] < min)
         min = arr[i];

   return min;
}
int main(){
	int arr[SIZE];
	int n;
	cin>>n;
	for(int i=0; i<n; i++){ //nhập dữ liệu
		cout << "arr[" <<i <<"] = ";
		cin >> arr[i];
	}
	for(int i=0; i<n; i++){ //xuất dữ liệu
		cout << arr[i] << endl;
	}
	
	int maxValue = Max(arr, n);
    cout << "so lon nhat la " << maxValue << endl;
    
    int minValue = Min(arr, n);
    cout <<"so nho nhat: " << minValue << endl;
    
    sort(arr, arr + n); // tăng dần
    cout <<"so nho thu 2: " << arr[1] << endl;
    
    sort(arr, arr + n, greater<int>()); //giảm dần
    cout <<"so lon thu 2: " << arr[1];
    
    
    return 0;
	
	
}


































//
//#include<iostream>
//#define SIZE 100
//using namespace std;
//
//// Function to find the maximum value in the array
//int Max(int arr[], int n){
//    int i;
//    int max = arr[0];
//    for (i = 1; i < n; i++)
//        if (arr[i] > max)
//            max = arr[i];
//
//    return max;
//}
//
//int main(){
//    int arr[SIZE];
//    int n;
//
//    // Input the size of the array
//    cout << "Enter the number of elements: ";
//    cin >> n;
//
//    // Input array elements
//    for(int i = 0; i < n; i++){
//        cout << "arr[" << i << "] = ";
//        cin >> arr[i];
//    }
//
//    // Output array elements
//    cout << "Array elements are:" << endl;
//    for(int i = 0; i < n; i++){
//        cout << arr[i] << " ";
//    }
//    cout << endl;
//
//    // Call the Max function to find the largest element
//    int maxValue = Max(arr, n);
//    cout << "The largest element is: " << maxValue << endl;
//
//    return 0;
//}
