1.	#include <stdio.h>
2.	#include <conio.h>
3.	#include <math.h>
4.	void main()
5.	{
6.		int a[10],i,n=5;
7.		float mean,temp,var,sd,sum=0.0;
8.		clrscr();
9.		for(i=0;i<n;i++)
10.	        {
11.			printf("\nENTER NUMBER-%d: ",i+1);
12.			scanf("%d",&a[i]);
13.			sum=sum+a[i];
14.		}
15.		mean=sum/n;
16.		sum=0.0;
17.		for(i=0;i<n;i++)
18.	        {
19.			temp=a[i]-mean;
20.			sum=sum+(temp*temp);
21.		}
22.		var=sum/n;
23.		sd=sqrt(var);
24.		printf("\nMEAN = %0.2f",mean);
25.		printf("\nVARIANCE = %0.2f",var);
26.		printf("\nSTANDARD DAVIATION = %0.2f",sd);
27.		getch();
28.	}
