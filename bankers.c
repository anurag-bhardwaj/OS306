/*
paste these values on the terminal.
5
4
0 0 1 2
1 0 0 0
1 3 5 4
0 6 3 2
0 0 1 4
0 0 1 2
1 7 5 0
2 3 5 6
0 6 5 2
0 6 5 6
1 5 2 0

5
3
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2
7 5 3
3 2 2
9 0 2
2 2 2
4 3 3
3 3 2
*/

#include<stdio.h>
void safeOrNot(int pro,int res)
{
	int i,j,k,count=0,Gtry=0;
	int Allocation[pro][res],Max[pro][res],Order[pro];
	int Available[res],RemainingNeed[pro][res];
	for(i=0;i<pro;i++)
	{
		Order[i]=-1;
	}
	for(i=0;i<res;i++)
	{
		Available[i]=-1;
	}
	for(i=0;i<pro;i++)
	{
		for(j=0;j<res;j++)
		{
			RemainingNeed[i][j]=0;
		}
	}
	for(i=0;i<pro;i++)
	{
		printf("Enter the Allocated values for process P%d\t",i);
		for(j=0;j<res;j++)
		{
			scanf("%d",&Allocation[i][j]);
		}
	}
	printf("\n\n");
	for(i=0;i<pro;i++)
	{
		printf("Enter the Max-Need values for process P%d\t",i);
		for(j=0;j<res;j++)
		{
			scanf("%d",&Max[i][j]);
		}
	}
	printf("\n\n");
	printf("Enter the Available Resource values.\t");
	for(i=0;i<res;i++)
	{
		scanf("%d",&Available[i]);
	}
	printf("\n");
//	printf("Calculating Remaining Need for each Process.\n");
//	for(i=0;i<pro;i++)
//	{
//		for(j=0;j<res;j++)
//		{
//			RemainingNeed[i][j]=Max[i][j]-Allocation[i][j];
//		}
//	}
	for(i=0;i<pro;i++)
	{
		for(j=0;j<res;j++)
		{
			printf("%d ",RemainingNeed[i][j]);
		}
		printf("\n");
	}
	while(count<pro)
	{
		int check;
		int processVal=-1;
		for(i=0;i<pro;i++)
		{
			int check2=1;
			check=1;
			for(k=0;k<pro;k++)
			{
				if(Order[k]==i)
				{
					check2=0;
					break;
				}
			}
			if(check2==1)
			{
				for(j=0;j<res;j++)
				{
					if(RemainingNeed[i][j]>Available[j])
					{
						check=0;
						break;
					}
				}
				if(check==1)
				{
					processVal=i;
					break;
				}
			}
		}
		if(check==1)
		{
			Order[count]=processVal;
			count++;
			for(i=0;i<res;i++)
			{
				Available[i]+=Allocation[processVal][i];
			}
			printf("Available Resource.\t");
			for(i=0;i<res;i++)
			{
				printf("%d ",Available[i]);
			}
			printf("\n");
		}
		else if(Gtry<pro)
		{
			Gtry++;
		}
		else
		{
			printf("Not in safe state.\n");
			break;
		}
	}
	if(Order[pro-1]!=-1)
	{
		printf("Safe state.\n");
	}
	printf("Order of Execution.\t");
	for(i=0;i<pro;i++)
	{
		if(Order[i]!=-1)
			printf("P%d ",Order[i]);
	}
}
main()
{
	int pro,res;
	printf("Enter number of processes: ");
	scanf("%d",&pro);
	printf("\nEnter number of Resources: ");
	scanf("%d",&res);
	safeOrNot(pro,res);
}
