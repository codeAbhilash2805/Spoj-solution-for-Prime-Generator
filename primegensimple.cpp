#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
using namespace std;

void primee(int num1, int num2);

int main()
{
	int n,i,num1,num2;
	cin>>n;

    for(i=0;i<n;i++)
    {
        cin>>num1>>num2;
	    primee(num1,num2);
	    cout<<endl;
    }
    return 0;

}

void primee(int num1, int num2)
{

    int i=num1,val=1,j;
    if(num2==0||num2==1)
    {
        cout<<endl;
        return;
        }
    if(num1==0 || num1==1)
	   i=2;
    else
       i=num1;

    while(i<=num2)
	{
		val=1;
		j=2;
		while(j<=sqrt(i))
		{
			if(i%j==0)
			{
				val=0;
				break;
			}
		j++;
		}
		if(val==1)
			cout<<i<<endl;
		i++;
	}
}
