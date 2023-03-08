#include<iostream>
using namespace std;
void modificar(int *vector,int n){
  for(int i=0;i<n;i++){
    *(vector+i)=*(vector+i)*2;
    cout<<"esto"<<*(vector+i)<<endl;
  }
}
void mostrar(int *vector,int n){
  for(int i=0;i<n;i++){
    cout<<*(vector+i);
    cout<<"\n";
  }
}
void insert(int *v ,int k){
  int key = v[k];
  int index = k-1;
  while (index >=0 && v[index]>key){
    v[index+1]=v[index];
    index--;
  }
  v[index+1]=key;
}
void recursiveInsertion(int *v,int k){
  if(k>0){
    recursiveInsertion(v,k-1);
    insert(v,k);
  }
}

int main(){
  int vector[]= {49,41,52,38,57,9,3};
  int n=sizeof(vector)/sizeof(int);
  cout <<"length of v"<< n<<endl;
  mostrar(vector,n);
  recursiveInsertion(vector,n);
  cout<<"ordenando"<<endl;
  mostrar(vector,n);
}

