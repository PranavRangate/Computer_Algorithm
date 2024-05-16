#include<iostream>
using namespace std;

void merge(int arr[],int left,int mid,int right){
    int n1=mid - left +1;
    int n2=right -mid;    

    int L[n1],R[n2]; // array to store left and right subarrays
   // copy elements to temporary arrays
   for (int i = 0; i < n1; i++) 
   {
    L[i]=arr[left +i];
   }
    for (int j= 0; j < n2; j++)
   {
    R[j]=arr[mid +1 +j];
   }
   int i=0;
   int j=0;
   int k=left;
// merging elements
   while (i<n1 && j<n2)
   {
    if (L[i]<=R[j])
    {
        arr[k]=L[i];
        i++;
    }
    else{
        arr[k]=R[j];
        j++;
    }
     k++;
   }
  // coping remaining elements of left subarray

  while (i<n1)
  {
    arr[k]=L[i];
    i++;
    k++;
  }
  // coping remaining elements of right subarray
   while (j<n2)
  {
    arr[k]=R[j];
    j++;
    k++;
  }

}
void mergesort(int arr[],int left,int right){
    if (left<right)
    {
        int mid=(left + right)/2;
        mergesort(arr,left,mid);   // Sort left sub-array
        mergesort(arr,mid + 1,right);  // Sort right sub-array

        merge(arr,left,mid,right);
    }
    
}
int main()
{ 
    int n;
    cout<<"enter the no elements of array :"<<endl;
    cin>>n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    mergesort(arr,0,n-1);
    cout<<"the sorted array elements are :"<<endl;
    for (int i = 0; i <n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}