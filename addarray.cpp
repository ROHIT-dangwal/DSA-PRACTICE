#include<iostream>
using namespace std;
int main(){
    int arr[5]={7,48,2,89,6};
    int i = 0;
    int sum = 0;
    while(i<5){
        sum = sum + arr[i];
        i++;
    }
    cout<<sum;
}