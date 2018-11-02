#include<bits/stdc++.h>
using namespace std;
struct sjf{
 int brust,tat,wt;
 string pid;
};
vector <sjf> v;
void swap(int i,int j)
{
	int tb;string tpid;
	tb=v[i].brust;
	tpid=v[i].pid;
	v[i].brust=v[j].brust;
	v[i].pid=v[j].pid;
	v[j].brust=tb;
	v[j].pid=tpid;
}
int main()
{
	cout<<" \t\t Program For Shortest Job First Scheduling.";
	cout<<"\n Number Of process:";
	int np;
	cin>>np;
	for(int i=0;i<np;i++)
	{
		int bt;string pid;
		cin>>pid>>bt;
		v.push_back({bt,0,0,pid});
	}
	
	for(int i=0;i<np;i++)
	{
		for(int j=0;j<np;j++)
		{
			if(v[j].brust > v[j+1].brust)
			{
				swap(j,j+1);
			}
		}
	}
	v[0].tat=v[0].brust;
	v[0].wt=0;
	for(int i=1;i<np;i++)
	{
		v[i].tat=v[i].brust+v[i-1].tat;
		v[i].wt=v[i].tat-v[i].brust;
	}
	cout<<"\nPid\tBT\tTAT\tWT\n";
	int sumtat=0,sumwt=0;
	for(int i=0;i<np;i++)
	{   sumtat+=v[i].tat;
	    sumwt+=v[i].wt;
		cout<<v[i].pid<<"\t"<<v[i].brust<<"\t"<<v[i].tat<<"\t"<<v[i].wt<<endl;
	}
	cout<<"Average Tat:"<<sumtat/np;
	cout<<"\nAverage Wt:"<<sumwt/np;
	return 0;	
}
