#include<iostream>
using namespace std;

int add(int a, int b){
	int result=a+b;
	cout<<"the sum of two numbers is "<<result<<endl;
}

int divide(int x,int y){
	int w=x/y;
		if(y==0){
		cout<<" invalide inputs "<<endl;
	}
	cout<<"the devisoin of x by y is "<<w<<endl;
}

int subtrct(int n,int m){
	int f=n-m;
	cout<<" The subtraction of n and m is "<<f<<endl;
}

int multpl(int num1, int num2){
	int d=num1*num2;
	cout<<"The multiplication of num1 and num2 is "<<d<<endl;	
}

int main(){
	int k, z; 
	cout<<"enter value for first";
		cin>>k;
	cout<<"enter value for first";
	cin>>z;	

  char operatr;
 cout<<" enter your choice fo opeation ('*','/','-','+') ";
 cin>>operatr;
  switch(operatr){
  	case '+':
  		cout<<add(k,z);
  		break;
  	case '/':
	  cout<< divide(k,z);
	  break;
	case '-':
	cout<<subtrct(k,z);  
 	 break;	
  	case '*':
	  cout<< multpl(k,z);
	  break;
	  default:
	  cout<<"invalide operator "<<endl;	
  }	         
     return 0;
}


