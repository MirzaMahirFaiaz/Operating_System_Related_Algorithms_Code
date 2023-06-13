//@author MIRZA MAHIR FAIAZ, Dept. of CSE, AUST
#include<stdio.h>
#include<bits/stdc++.h>
#define ll long long
#define PI acos(-1)
using namespace std;

int main()
{


    ll i, limit, total = 0, x, counter = 0, time_quantum;
    ll wt = 0, tt = 0, arrival_time[10], burst_time[10], temp[10];
    double average_wt, average_tt;
    cout<<"\nEnter Total Number of Processes: ";
    cin>>limit;
    x = limit;
    for(i = 0; i < limit; i++)
    {
        cout<<"\nEnter Arrival time & Burst Time of Process["<<i+1<<"]"<<endl;
        cin>>arrival_time[i]>>burst_time[i];
        temp[i] = burst_time[i];
    }

    cout<<"\nEnter Time Quantum: ";
    cin>>time_quantum;
    cout<<"\nProcess \t\t Burst Time \t\t Turnaround Time \t\t Waiting Time"<<endl;
    for(total = 0, i = 0; x != 0;)
    {
        if(temp[i] <= time_quantum && temp[i] > 0)
        {
            total = total + temp[i];
            temp[i] = 0;
            counter = 1;
        }
        else if(temp[i] > 0)
        {
            temp[i] = temp[i] - time_quantum;
            total = total + time_quantum;
        }
        if(temp[i] == 0 && counter == 1)
        {
            x--;
            cout<<"\nProcess["<<i+1<<"]\t\t"<<burst_time[i]<<"\t\t"<<total - arrival_time[i]<<"\t\t"<<total - arrival_time[i] - burst_time[i];
            wt = wt + total - arrival_time[i] - burst_time[i];
            tt = tt + total - arrival_time[i];
            counter = 0;
        }
        if(i == limit-1)
        {
            i = 0;
        }
        else if(arrival_time[i + 1] <= total)
        {
            i++;
        }
        else
        {
            i = 0;
        }
    }

    average_wt = (wt * 1.0) / limit;
    average_tt = (tt * 1.0) / limit;
    cout<<"\nAverage Waiting Time: "<<average_wt<<endl;
    cout<<"\nAvg Turnaround Time: "<<average_tt<<endl;



    return 0;
}
