#include<stdio.h>
/*
  Write a menu driven C program to implement linear Search and Binary Search
*/

int linearSearch(int a[], int key,int n){
  int i=0;
  for(i=0; i<n; i++){
    if(a[i]==key){
      return i;
    }
  }
  return -1;
}

void bubbleSort(int a[], int n){
  for(int i=0; i<n-1; i++){
    for(int j=0; j<n-i-1;j++){
      if(a[j]>a[j+1]){
        int temp = a[j];
        a[j] = a[j+1];
        a[j+1] = temp; 
      }
    }
  }
}

int binarySearch(int a[], int key, int n){
  int low=0, high=n-1;

  while(low<=high){
    int mid = ((high+low)/2);

    if(a[mid]==key){
      return mid;
    }else if(key<a[mid]){
      high = mid-1;
    }else{
      low=mid+1;
    }
  }
  return -1;
}

int main(){

  int choice, n , key, index;
  int a[100];

  //Array
  printf("Enter the size of the array: ");
  scanf("%d",&n);
  printf("Enter the elements:\n");
  for(int i=0; i<n;i++){
    scanf("%d",&a[i]);
  }

  //menu driven
  do{

    printf("\nMenu\n");
    printf("1. Linear Search\n2. Binary Search\n3. Exit");
    printf("Enter your choice: ");
    scanf("%d",&choice);

    if(choice==1||choice==2){
      printf("Enter the key to search: ");
      scanf("%d",&key);
    }

    switch(choice){

      case 1:
        index = linearSearch(a,key,n);
        if(index!=-1){
          printf("The element %d is found in the array index %d",key,index);
        }else{
          printf("Element not found");
        }
        break;
      case 2:
        bubbleSort(a,n);
        index = binarySearch(a,key,n);
        if(index!=-1){
          printf("The element %d is found in the array index %d",key,index);
        }else{
          printf("Element not found");
        }
        break;

      case 3:
        printf("exiting from the program");

    }

  }while(choice!=3);

  return 0;
}
