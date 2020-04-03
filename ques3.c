#include<stdio.h>
#include<math.h>
#include<unistd.h>
#include<pthread.h>
int checkP(long int num3)
{
	long int sq=sqrt(num3);
	for(long int i=2;i<=sq;i++)
	{
		if(num3%i==0)
			return 1;
	}
	return 0;
}
void* calcP(void *num)
{
	long num2=*(int*)num;
	int arr[num2+1];
	for(long int i=0;i<=num2;i++)
	{
		arr[i]=1;
	}
	arr[0]=0;
	arr[1]=0;
	int val;
	for(long int i=2;i<=num2;i++)
	{
		if(arr[i]==1)
		{
			val=checkP(i);
			if(val==1)
				arr[i]=0;
			else
			{
				for(long int j=2;i*j<=num2;j++)
				{
					arr[i*j]=0;
				}
			}
		}
		
	}
	printf("All the prime numbers less than or equal to %ld\n",num2);
	for(long int i=0;i<=num2;i++)
	{
		if(arr[i]==1)
			printf("%ld ",i);
	}
}
int main()
{
	pthread_t t1;
	long int num;
	scanf("%ld",&num);
	pthread_create(&t1,NULL,calcP,(void*)&num);
	pthread_join(t1,NULL);
}
