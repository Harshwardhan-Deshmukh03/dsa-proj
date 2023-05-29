#include<stdio.h>
#include<stdlib.h>

void swap(int* a, int* b){
    int c=*a;
    *a=*b;
    *b=c;
}

void Splitit(int arr[8][7], int n){
    int pref[2][n];
    for (int i = 0; i < n; i++){
        pref[0][i] = i + 1;
        pref[1][i] = 0;
    }
   
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n; j++){
            int c = arr[j][i];
            pref[c - 1][1] += n - i - 1;
        }
    }
    
    int sorted = 0;
    for (int i = 0; i < n - 1; i++){
        sorted = 1;
        for (int j = 0; j < n - 1 - i; j++){
            if (pref[1][j] > pref[1][j + 1]){
                sorted = 0;
                swap(&(pref[1][j]), &(pref[1][j + 1]));
                swap(&(pref[0][j]), &(pref[0][j + 1]));
            }
        }
        if (sorted){
            break;
        }
    }
    int first[n/2];
   int second[n/2];
   for (int i = 0; i < n/2; i++)
   {
    first[i]=pref[0][2*i];
    second[i]=pref[0][2*i+1];
   }
   for (int i = 0; i < n/2; i++)
   {
    printf("%d ",second[i]);
   }

   int retMatrix1[n/2][n/2+1];
   int retMatrix2[n/2][n/2+1];
   for (int i = 0; i < n/2; i++)
   {
    retMatrix1[i][0]=first[i];
    retMatrix2[i][0]=second[i];
   }
   


   
   
    
    // Rest of the code...
}

int main(){
    int a[8][7] = {
        {3, 6, 7, 8, 2, 4, 5},
        {6, 5, 7, 4, 3, 8, 1},
        {2, 4, 1, 6, 8, 5, 7},
        {5, 7, 2, 8, 3, 6, 1},
        {7, 6, 8, 4, 2, 1, 3},
        {5, 4, 3, 1, 7, 8, 2},
        {8, 1, 4, 5, 6, 3, 2},
        {5, 3, 2, 6, 4, 7, 1}
    };

    Splitit(a, 8);
    
    return 0;
}
