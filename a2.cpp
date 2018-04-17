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
