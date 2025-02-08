#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int count=0;//globally declared 
//formula of mergeSort(merged array)
void mergeSort(int arr[],int start,int end)
{
    //selecting accending order
    if(start>=end)
    {
        return;
    }
    int mid=(start+end)/2 ;//index 0 to end index
    //for left
    mergeSort(arr,start,mid);
    // for right 
    mergeSort(arr,mid+1,end); //mid+1=next element of mid
    // merged left and merged right
    merge(arr,start,mid,end);
}
//copy the unsorted array to left and right side here left elements counts > right 
void merge(int arr[],int start,int mid,int end)
{
int left=(mid-start)+1 ;//left array is greater thn right(total 5 then right=2 and left=2+1=3)
int right=(end-mid);
int leftarr[left] ,rightarr[right];
int i,j;
//index=pos-1
//left
for(i=0;i<left ;i++)
{
    leftarr[i]=arr[start+i];
}
//right
for(j=0;j<right;j++)
{
    rightarr[j]=arr[mid+1+j];
}
//selecting conditions for ascending or descending
int k=start;
while(i<left && j<right)
{
    count++;//start counting
    if(leftarr[i]<=rightarr[j]) //ascending
    {
        arr[k]=leftarr[i];
        i++;
    }
    else //descending
    {
        arr[k]=rightarr[j];
        j++;
    }
    k++;
}
//copy and merge
while(i<left) //left
{
    arr[k]=leftarr[i];
    i++;
    k++;
}
while(j<right) //left
{
    arr[k]=rightarr[j];
    j++;
    k++;
}
}
//read from file(read,file handling)
int readfromFile(int arr[],int maxsize,const char *filename) //maxsize=the max size of an array can contain
{
    FILE *file=fopen(filename,"r"); //r for read the file
     //FILE is a data type in c and file is a pointer in file stream
    if(!file)
    {
        printf("Error :File not found %s\n",filename);
        return 0;
    }
    int size=0;
    while(size<maxsize &&  fscanf(file,"%d",&arr[size])==1)
    {
        size++;
    }
    fclose(file);
    return size;
}
//print the final merged array
void printarr(int arr[],int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        printf("%d\n",arr[i]);
    }
}
//main function
int main()
{
    int arr[1000]; //maxsize=1000
int size=readfromFile(arr,1000,"input.txt") ;//file name=input.text
if(size==0) //there is no element in array
{
    printf("Empty");
    return 1; 
}
printf("Unsorted Array:\n");
printarr(arr,size);

mergeSort(arr,0,size-1); //start=0 index,end=[index=pos-1]=size-1 

printf("Sorted Array:\n");
printarr(arr,size);

    return 0;
}

