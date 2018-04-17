
#include<conio.h>
#include<stdlib.h>
#include<time.h>
int current_time,lower=1,upper=100;
int current_process=-1;
int prevProcess;
int prevArrTime=-1,n;
//one who is having more candies will have more priority.
int randint()
{
	int candies;
	candies= (rand()%(upper-lower))+lower;
	return candies;
}
struct Students
{
	char studentName[5];
	int priority;
	int arrTime;
	int burstTime;
	int waitTime;
	int turnAroundTime;
	
}obj[10];
				//if any one of the process is arriving before the completion of the running process;
				//also we change the priority to 0 if the process completes.

int min_arr_time()
{
	int i;
	
	int min=100000;
	for(i=0;i<n;i++)
	{
		if(min>obj[i].arrTime && obj[i].priority!=0)
		{
			min=obj[i].arrTime;
			current_process=i;
		}
		else if(min==obj[i].arrTime && obj[i].priority!=0)
		{
			if(obj[current_process].priority<obj[i].priority)
			{
				current_process=i;
			}
			else if(obj[current_process].priority==obj[i].priority)
			{
				if(obj[i].burstTime<obj[current_process].burstTime)
				current_process=i;
			}
		}
	}
	return min;
}
int main()
{
	int i,j,maxPriority=0,x,sum_wait,sum_turn_around;
	printf("\nEnter the number of students(process): ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\n\nEnter the %d student name: ",i+1);
		scanf("%s",obj[i].studentName);
		printf("\nEnter its arrival time: ");
		scanf("%d",&obj[i].arrTime);
		printf("\nEnter its burst time: ");
		scanf("%d",&obj[i].burstTime);
		obj[i].priority=randint();
	}
	
	printf("\n\tHere (-)sign in the priority shows that the process has not arrived yet\n\tHere '0' Priority shows that the process has already executed\n");
	current_time=min_arr_time();
	for(i=0;i<n;i++)
	{
			
			
			maxPriority=0;
			printf("\n\n\n\t\t\tcurrent time= %d",current_time);
			printf("\n\t\t\t%s executes\n\n\n",obj[current_process].studentName);
			printf("\t\t\t\t\tAFTER EXECUTION OF %s current time=%d\n",obj[current_process].studentName,current_time+obj[current_process].burstTime);
			obj[current_process].priority=0;
			current_time=current_time+obj[current_process].burstTime;
			obj[current_process].turnAroundTime=current_time-obj[current_process].arrTime;
			prevArrTime=obj[current_process].arrTime;
			obj[current_process].waitTime=obj[current_process].turnAroundTime-obj[current_process].burstTime;
			
		
