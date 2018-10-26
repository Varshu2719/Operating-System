#include<iostream>

using namespace std;

int main()

{

int p;

cout<<"Enter the no of processes: \n";

cin>>p;



int a[p],b[p],c[p],t[p],w[p],i;



for(i=0;i<p;i++)

{

cout<<"\n Enter the arrival time of process "<<i+1<<"is: ";

cin>>a[i];

cout<<"\n Enter the burst time of process "<<i+1<<"is: ";

cin>>b[i];

}



c[0]=b[0];



for(i=0;i<p;i++)

c[i]=c[i-1]+b[i];



for(i=0;i<p;i++)

cout<<"\n \n Completion time of process "<<i+1<<"is: "<<c[i];



for(i=0;i<p;i++)

t[i]=c[i]-a[i];



for(i=0;i<p;i++)

cout<<"\n \n Turn around time of process "<<i+1<<"is: "<<t[i];



for(i=0;i<p;i++)

w[i]=t[i]-b[i];



for(i=0;i<p;i++)

cout<<"\n \n Waiting time of process "<<i+1<<"is: "<<w[i];



float avgt=0,avgw=0;



for(i=0;i<p;i++)

{

avgt=avgt+t[i];

avgw=avgw+w[i];

}



cout<<"\n \n Average turn around time  is: "<<avgt;

cout<<"\n \n Average waiting time  is: "<<avgw;



return 0;

}
