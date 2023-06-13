//@author MIRZA MAHIR FAIAZ, Dept. of CSE, AUST
#include<stdio.h>
#include<bits/stdc++.h>
#define ll long long
#define PI acos(-1)
using namespace std;

int main()
{

    ll t,i,j,art[10],bt[10],rt[10],shesht,smallest;

    ll remain=0,n,time,total_wt=0,total_tt=0;

    cout<<"Enter no of Processes : ";
    cin>>n;

    for(i=0; i<n; i++)
    {

       cout<<"Enter Arrival time & Burst time for Process P"<<i+1<<" : ";

        cin>>art[i];
        cin>>bt[i];

        rt[i]=bt[i];

    }

    cout<<"\n\nProcess\t|Turnaround Time| Waiting Time\n\n";

    rt[9]=999999;

    for(time=0; remain!=n; time++)
    {

        smallest=9;

        for(i=0; i<n; i++)
        {
            if(art[i]<=time && rt[i]<rt[smallest] && rt[i]>0)
            {
                smallest=i;
            }
        }

        rt[smallest]--;

        if(rt[smallest]==0)
        {
            remain++;

            shesht=time+1;

            cout<<"\nP["<<smallest+1 <<"]\t|\t"<<shesht-art[smallest]<<"\t|\t"<<shesht-bt[smallest]-art[smallest];

            total_wt+=shesht-bt[smallest]-art[smallest];

            total_tt+=shesht-art[smallest];

        }

    }

    cout<<"\n\nAverage waiting time = "<<(total_wt*1.0)/n<<endl;
    cout<<"Average Turnaround time = "<<(total_tt*1.0)/n<<endl;


    return 0;
}
