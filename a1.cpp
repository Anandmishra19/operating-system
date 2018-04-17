#include<stdio.h>
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

