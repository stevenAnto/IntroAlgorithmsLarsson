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

void merge(int *v,int p,int q,int r){
  cout<<"entro merge"<<merge<<endl;
  cout<<"p-"<<p<<"q-"<<q<<"r-"<<r<<endl;
  int n1=q-p+1;
  int n2=r-q;
  cout<<"n1:"<<n1<<" n2:"<<n2<<endl;
  int l[n1+1];
  int ri[n2+1];
  for(int i=0;i<n1;i++){
   // cout<<"primerfor"<<endl;
    //cout<<"vpi"<<p+i<<endl;
    l[i]=*(v+p+i);
  }
  mostrar(l,n1);
  //cout<<"salioprimerofor"<<endl;
  for(int i=0;i<n2;i++){
    //cout<<"segundoFopr"<<endl;
    ri[i]=*(v+q+i+1);
  }
  mostrar(ri,n2);
  cout<<"salidasegundor"<<endl;
  int a=numeric_limits<int>::max();
  cout<<"a"<<a<<endl;
  //sirve para indicar que ya esta vacio y continu con los cilos
  l[n1+1]=numeric_limits<int>::max();
  ri[n2+1]=numeric_limits<int>::max();
  //mostrar(l,n1+1);
  cout<<"entreVectore"<<endl;
  //mostrar(ri,n2+1);
  int i=0;
  int j=0;
  for(int k=p;k<=r;k++){
    cout<<"uniendo"<<endl;
    if(l[i]<=ri[j]){
      v[k]=l[i];
      i++;
    }
    else{
      v[k]=ri[j];
      j++;
    }
  }
  //mostrar(v,r);

}
void mergeSort(int *v,int p,int r){
  cout<<"p:"<<p<<"r:"<<r<<endl;
  if (p<r){
    cout<<"entromergeSort"<<endl;
    int q=(p+r)/2;
    cout<<"q:"<<q<<endl;
    mergeSort(v,p,q);
    mergeSort(v,q+1,r);
    merge(v,p,q,r);
  }
  cout<<"noEntrore"<<endl;
}

int iterativeBS(int *v,int k,int n){
  //cout<<" k "<<k<< " n "<<n<<endl;
  int low =0 ;
  int high = n-1;
  //cout<<"low "<<low<<" high "<<high<<endl;
  while (low<=high){
    int mid = (low+high)/2;
    //cout<<"mid:"<<mid<<"low"<<low<<"high"<<high<<endl;
    if(k==*(v+mid)){
      return mid;
    }
    else if (k>*(v+mid)){
      low=mid+1;
    }
    else{
      high = mid-1;
    }
  }
  return -1;
}

bool sumSearch(int *S,int x,int length){
  for(int i=0;i<length;i++){
    int index = iterativeBS(S,x-S[i],length);
    if (index!=-1&&index!=i){
      return true;
    }
  }
  return false;
}

int main(){
  int vector[]={104,124,53,23,90,78,56,11};
  int x = 177;
  int n=sizeof(vector)/sizeof(int);
  mostrar(vector,n);
  mergeSort(vector,0,n-1);
  cout<<"ordenado"<<endl;
  mostrar(vector,n);
  //el valor de limite esta cambiando, no es estatico
  cout<<"result"<<iterativeBS(vector,x,n);
  bool encontro=sumSearch(vector,x,n);
  cout<<"se encontro"<<encontro<<endl;
  //cout<<"Se encontre "<<sumSearch(vector,x,n);
}


