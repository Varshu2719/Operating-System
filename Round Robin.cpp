# include <iostream>
using namespace std;
int main()
{
	int n;
	cout<<" enter the no. of process";
	cin>>n;
	int bt[n],f,rem_bt[n], wt[n], i ,t=0, tq,tat[n];
	
	
	cout<<" enter the time quantum";
	cin>>tq;
	cout<<" enter the burst time";
	for(i=0; i<n;i++)
	cin>>bt[i];
    
		for(i=0; i<n;i++)
		rem_bt[i]=bt[i];
	
while(true)
{
  f=true;
	for(i=0;i<n;i++)
	{
	if(rem_bt[i]>0)
	{
		f= false;
	
	 	if(rem_bt[i]> tq)
	 	{
	 	
		  t=t+tq;
		  rem_bt[i]= rem_bt[i]- tq;
        }
	    else
	    {
		  t=t+rem_bt[i];
	    
	    wt[i]=t-bt[i];
	    rem_bt[i]=0;
       tat[i]=bt[i]+wt[i];

         }
	} 
}
	if(f==true)
	break;
}

cout<<"the time around time of processes are: \n";
for(i=0;i<n;i++)
cout<<tat[i]<<"\n";

cout<<"the waiting time of processes are: \n";
for(i=0;i<n;i++)
cout<<wt[i]<<"\n";

float sum=0;

  for(i=0;i<n;i++)
  sum=sum+wt[i];
  
  float avgw=sum/n ;

sum=0;
for(i=0;i<n;i++)
  sum=sum+tat[i];
  
  float avgt=sum/n;
  
  cout<<" \n the  average waiting time "<<avgw;
  cout<<" \n the  average turn around time "<<avgt;
  
return 0;
}
