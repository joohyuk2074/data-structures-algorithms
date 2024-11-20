#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void Bubble(int A[], int n) {
    int i,j,flag=0;
    
    for (i=0; i<n-1; i++) {
        flag = 0;
        for (j=0; j<n-1-i; j++) {
            if (A[j] > A[j+1]) {
                swap(&A[j], &A[j+1]);
                flag = 1;
            }
        }
        if (flag == 0) {
            break;
        }
    }
}

void Insertion(int A[], int n) {
    int i,j,x;
    
    for (i=1; i<n; i++) {
        j = i - 1;
        x = A[j];
        while (j > -1 && A[j] > x) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = x;
    }
}

void SelectionSort(int A[], int n) {
    int i, j, k;
    
    for(i=0; i<n-1; i++) {
        for(j=k=i; j<n; j++) {
            if (A[j] < A[k]) {
                k = j;
            }
        }
        swap(&A[i], &A[k]);
    }
}

int partition(int A[], int l, int h) {
    int pivot = A[l];
    int i=l,j=h;
    
    do {
        do {
            i++;
        } while (A[i] <= pivot);
        
        do {
            j--;
        } while (A[j] > pivot);
        
        if (i < j) {
            swap(&A[i], &A[j]);
        }
        
    } while (i < j);
    
    swap(&A[l], &A[j]);
    
    return j;
}

void Merge(int A[], int l, int mid, int h) {
    int i = l;
    int j = mid + 1;
    int k = l;
    int B[100];
    
    while (i <= mid && j <= h) {
        if (A[i] < A[j]) {
            B[k++] = A[i++];
        } else {
            B[k++] = A[j++];
        }
    }
    
    while (i <= mid) {
        B[k++] = A[i++];
    }
    
    while (j <= h) {
        B[k++] = A[j++];
    }
    
    for (int i=l; i<=h; i++) {
        A[i] = B[i];
    }
}

void IMergeSort(int A[], int n) {
    int p,l,h,mid,i;
    
    for (p=2; p<=n; p=p*2) {
        for (i=0; i+p-1<n; i=i+p) {
            l=i;
            h=i+p-1;
            mid=(l+h)/2;
            Merge(A, l, mid, h);
        }
    }
    
    if (p/2 < n) {
        Merge(A, 0, p/2 - 1, n);
    }
}

void MergeSort(int A[], int l, int h) {
    int mid;
    
    if (l < h) {
        mid = (l + h) / 2;
        MergeSort(A, l, mid);
        MergeSort(A, mid+1, h);
        Merge(A, l, mid, h);
    }
}

void QuickSort(int A[], int l, int h) {
    int j;
    
    if (l<h) {
        j = partition(A, l, h);
        QuickSort(A, l, j);
        QuickSort(A, j+1, h);
    }
}

int findMax(int A[], int n) {
    int max = INT32_MIN;
    int i;
    
    for (i = 0; i < n; i++) {
        if (A[i] > max) {
            max = A[i];
        }
    }
    
    return max;
}

void CountSort(int A[], int n) {
    int i,j,max,*C;
    
    max = findMax(A, n);
    C = (int *)malloc(sizeof(int)*max + 1);
    for (i=0; i<max+1; i++) {
        C[i] = 0;
    }
    
    for (i=0; i<n; i++) {
        C[A[i]]++;
    }
    
    i=0;
    j=0;
    while (j<max+1) {
        if (C[j] > 0) {
            A[i++] = j;
            C[j]--;
        } else {
            j++;
        }
    }
}

int main(int argc, const char * argv[]) {
    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3, 1000000};
    int n = 11;
    int i;
    
//    QuickSort(A, 0, 10);
//    IMergeSort(A, n);
//    MergeSort(A, 0, n-1);
    CountSort(A, n);
    
    for (i=0; i<n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    
    return 0;
}
