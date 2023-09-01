#include <iostream>

using namespace std;

void merge(int arr[], int l, int mid, int r){

    int n1=mid-l+1;
    int n2=r-mid;

    int a[n1];
    int b[n2]; // temp arrays

    for(int i=0;i<n1;i++){
        a[i]=arr[l+i];
    }
    for(int i=0;i<n2;i++){
        b[i]=arr[mid+1+i];
    }
    int i=0;
    int j=0;
    int k=l;
    while(i<n1 && j<n2){
        if(a[i]>b[j]){
            arr[k]=a[i];
            k++; i++;
        }
        else {
            arr[k]=b[j];
            k++; j++;
        }
    }
    while(i<n1){
        arr[k]=a[i];
        k++; i++;
    }

    while(i<n2){
        arr[k]=b[j];
        k++; j++;
    }
}

void mergeSort(int arr[], int l, int r){
    if(l<r){
        int mid=(l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);

        merge(arr,l,mid,r);
    }
}

int shopaholic(int compras[], int l, int r){
    int res=0;
    mergeSort(compras,l,r);
    for(int i=2;i<=r;i+=3){
        res+=compras[i];
    }
    return res;
}

int main() {
    int tests = 0;
    cin >> tests;

    int outputs[tests];


    for(int i=0;i<tests;i++){
        int largo=0;
        cin >> largo;
        int compras[largo];
        for(int i=0;i<largo;i++){
            int num=0;
            cin >> num;
            compras[i]=num;
        }
        int res = shopaholic(compras,0,largo-1);
        outputs[i]=res;
    }
    for(int res : outputs){
        cout << res << endl;
    }

    return 0;
}
