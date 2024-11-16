#include <iostream>
using namespace std;
struct sparsematrix{
int row;
int column;
int value;
};
int main(){
cout<<"enter number of rows of matrix"<<endl;
int rows,columns;
cin>>rows;
cout<<"enter number of columns of matrix"<<endl;
cin>>columns;
int arr[rows][columns];
cout<<"enter elements of matrix"<<endl;
for (int i=0;i<rows;i++){
for (int j=0;j<columns;j++){
cout<<"enter "<<i<<"|"<<j<<endl;
cin>>arr[i][j];
}
}
int count=0;
sparsematrix sparse[rows*columns];
for (int i=0;i<rows;i++){
for (int j=0;j<columns;j++){
if(arr[i][j]!=0){
sparse[count].row=i;
sparse[count].column=j;
sparse[count].value=arr[i][j];
count++;  
}
}
}
cout<<"sparse matrix -"<<endl;
cout<<"rows"<<"\t"<<"|column"<<"\t"<<"|value"<<endl;
for(int i=0;i<count;i++){
cout<<sparse[i].row<<"\t  "<<sparse[i].column<<"\t  "<<sparse[i].value<<endl;
}
return 0;
}
