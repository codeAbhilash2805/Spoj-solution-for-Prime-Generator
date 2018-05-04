 #include<iostream>
#include<math.h>
#include<vector>

using namespace std;

void primee(int m, int n);

int main()
{


	int t,i,m,n,min=0,max=0;
	cin>>t;
    for(i=0;i<t;i++)
    {
        //Generating Primes for all test cases
        cin>>m>>n;
        if((m==1||m==0) && n==1)
        {
            cout<<endl;
            continue;
        }

	    primee(m,n);
	    cout<<endl;
    }

    return 0;

}

void primee(int m, int n)
{

    vector<int> vec;
    int i=m,val=1,j,var,t,sum,tmp,buc;

    //If m and n have same values the check if m is a prime or not
    if(m==n)
    {
        val=1;

		for(j=2;j<=int(sqrt(n));j++)
		{
			if(i%j==0)
			{
				val=0;
				break;
			}

		}
		if(val==1)
        {

            cout<<m<<endl;
            return;

        }
    }


    //1 and 0 are not primes anyway and the sieve starts with 2
    if(m==1 || m==0)
    {
        m=2;

    }
    int a[100000]={0};
    buc=n-m+1;


    //Constructing an array having numbers from m to n
    for(i=0;i<(buc);i++)
        a[i]=m+i;




    //Generating a vector of primes till square root n
    for(i=2;i<=sqrt(n);i++)
	{
		val=1;

		for(j=2;j<=int(sqrt(i));j++)
		{
			if(i%j==0)
			{
				val=0;
				break;
			}

		}
		if(val==1)
        {

            vec.push_back(i);

        }

	}


    i=0;
    t=a[0];
    //changed from 2 back to its original value
    m=t;

    //using the vector eliminate the non primes in the array
     while(i<vec.size())
    {
        var=vec[i];

            tmp=t%var;
         if(tmp==0)
             sum=0;
         else
            sum=var-tmp;

        if(sum<=(n-m))
        {
            if((a[sum]/var)==1)
                sum+=var;
        }

        while(sum<=(n-m))
        {

            a[sum]=0;
            sum+=var;
            if(sum>(n-m))
                break;
        }
        i++;

    }


    //Printing the output
    for(i=0;i<(buc);i++)
    {
       if(a[i])
        cout<<a[i]<<endl;
    }





}
