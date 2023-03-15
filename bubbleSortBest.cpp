#include<iostream>
#include<limits>
using namespace std;

void mostrar(int *vector,int n){
  cout<<"{";
  for(int i=0;i<n;i++){
    cout<<*(vector+i);
    cout<<";";
  }
  cout<<"}\n";
}
void bubbleSort(int *vector, int n){
  for (int i=0;i<n-1;i++){
    for(int j=n-1;j>i;j--){
      cout<<*(vector+j)<<" "<<*(vector+j-1)<<endl;
      if (*(vector+j)<*(vector+j-1)){
	int temporary = *(vector+j);
	*(vector+j)=*(vector+j-1);
	*(vector+j-1)=temporary;
      }
    }
  }
}

int main(){
  int vector[]={104,124,53,23,90,78,56,11};
  int x = 177;
  int n=sizeof(vector)/sizeof(int);
  mostrar(vector,n);
  cout<<"ordenado"<<endl;
  bubbleSort(vector,n);
  mostrar(vector,n);
}


