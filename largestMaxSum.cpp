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
int* findMaxCross(int *vector,int low, int mid, int high){
  cout <<"low"<<low<<"mid"<<mid<<"high"<<high<<endl;
  int *vectorR = new int[3];
  mostrar(vectorR,3);
  int maxLeft;
  int maxRight;
  int leftSum=-100000;
  int sum =0;
  for (int i= mid;i>=low;i--){
    cout<<"primerfor"<<endl;
    sum =sum + vector[i];
    if(sum>leftSum){
      leftSum =sum;
      vectorR[0]=i;
    }
  }
  int rightSum=-100000;
  sum = 0 ;
  for (int i= mid+1;i<=high;i++){
    cout<<"segundor"<<endl;
    sum =sum + vector[i];
    if(sum>rightSum){
      rightSum =sum;
      vectorR[1]=i;
    }
  }
  vectorR[2]=leftSum+rightSum;
  return vectorR;
}
int * findMaxSumS(int *vector,int low, int high){
  cout<<"entrofinSummax"<<low<<high<<endl;
  int *vectorRe = new int[3];
  int *vectorL = new int[3];
  int *vectorR = new int[3];
  int *vectorC = new int[3];
  if (high==low){
    vectorRe[0]=low;
    vectorRe[1]=high;
    vectorRe[2]=vector[low];
    return vectorRe;
  }
  else{
    int mid =(low+high)/2;
    vectorL= findMaxSumS(vector,low, mid);
    vectorR= findMaxSumS(vector,mid+1, high);
    vectorC= findMaxCross(vector,low, mid,high);

    if(vectorL[2]>=vectorR[2]&&vectorL[2]>=vectorC[2]){
      return vectorL;
    }
    else if(vectorR[2]>=vectorL[2]&&vectorR[2]>=vectorC[2]){
      return vectorR;
    }
    else{
      return vectorC;
    }
  }
}




int main(){
  int vector[]={13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
  int n=sizeof(vector)/sizeof(int);
  cout<<"sizeof"<<n<<endl;
  mostrar(findMaxCross(vector,0,4,n-1),3);
  cout<<"respuesta"<<endl;
  mostrar(findMaxSumS(vector,0,n-1),3);

}


