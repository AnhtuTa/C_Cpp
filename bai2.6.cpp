#include<stdio.h>
#include<conio.h>
#include<math.h>

int ktraSNT(int n) //neu n l� so nguy�n t� th� h�m n�y tra v� kq = 1
{
	int a;
	int k=1;
	
	a=sqrt(n);
	for(int i=2;i<=a;i++) {
		if((n%i)==0) {
			k--;
			break;
		}
	}
	return k;
}
int main()
{
	int n,i;
	printf("nhap so n= ");
	scanf("%d",&n);
	printf("c�c s� nguy�n t� < %d l�:\n",n);
	for(i=2;i<n;i++)  {
		if(ktraSNT(i)==1) {
			printf("%d \n",i);
		}
	}
}
