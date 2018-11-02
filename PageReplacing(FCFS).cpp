#include<iostream>
using namespace std;
int main()
{
	int frame;
	cout<<"Input Page frame:";
	cin>>frame;
	int ref[10];
	for(int i=0;i<10;i++)cin>>ref[i];
	int pg[frame],hit=0,miss=0,k=0;
	for(int i=0;i<10;i++)
	{ int av=0;                                                                                            
		for(int j=0;j<frame;j++)
		{
			if(pg[j]==ref[i])
			{  
				av=1;
				hit++;
			}
		}
		if(av==0)
		{   
			pg[k]=ref[i];
			miss++;
			k=(k+1)%frame;
		}
	}
	float hr=hit/10,mr=miss/10;
	cout<<"hit ratio:"<<hit;
	cout<<endl<<"page fault ratio:"<<miss;
	return 0;
}
