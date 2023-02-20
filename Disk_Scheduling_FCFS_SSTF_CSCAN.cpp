//@author MIRZA MAHIR FAIAZ, Dept. of CSE, AUST
#include<stdio.h>
#include<bits/stdc++.h>
#define ll long long
#define PI acos(-1)
using namespace std;
vector<int>vec;
int n,in,nmboh,sp;

void cscan(){
    cout<<"\nCSCAN:"<<endl;
    vector<int> vecs;
    vecs=vec;
    sort(vecs.begin(),vecs.end());

    auto low = lower_bound(vecs.begin(),vecs.end(),sp);
     int sum=0;
     int pos= sp;
     cout<<"Cylinder Serving Order: "<<sp;
     vector<int>::iterator it;
     for(it=low; it!=vecs.end();it++){
        sum+=((*it)-pos);
        cout<<"=>"<<*it;
        pos=*it;
     }
     it--;

    sum+=(nmboh-(*it));
    if(nmboh!=*it)
        cout<<"=>"<<nmboh;
    pos=0;
    if(vecs[0]!=0)
        cout<<"=>0";

    for(auto it=vecs.begin(); it!=low;it++){
        sum+=((*it)-pos);
        cout<<"=>"<<*it;
        pos=*it;
     }

cout<<endl;
cout<<"Total Cylinder movement: "<<sum<<endl;
}

void sstf(){
    int i,j;
    cout<<"\nSSTF: "<<endl;
    int mark[10000]={0};
    vector<int>veci;
    int pos=sp,    sum=0;
    for(i=0;i<n;i++){
       int mini=-1;
       int mind=99999;

       for(j=0;j<n;j++){
        if(mind>abs(pos-vec[j]) && mark[j]!=1)
        {
            mind=abs(pos-vec[j]);
            mini=j;
        }
       }
       sum+=mind;
       veci.push_back(vec[mini]);
       mark[mini]=1;
       pos=vec[mini];

    }
    cout<<"Cylinder Serving Order: "<<sp;
    for(auto it= veci.begin();it!= veci.end();it++){
       cout<<"=>"<<*it<<" ";
    }
    cout<<endl;
    cout<<"Total Cylinder movement: "<<sum<<endl;
}

void fcfs(){
    cout<<"\n FCFS: "<<endl;
    int sum=0,dif;
    int pos=sp;
    for(int i=0;i<n;i++){
        dif= abs(vec[i]-pos);
        sum+=dif;
        pos=vec[i];
    }
    cout<<"=>"<<sp;
    for(int i=0;i<n;i++){
        cout<<"=>"<<vec[i];
    }
    cout<<"\nTotal Cylinder movement: "<<sum<<endl;
}
int main(){

    cout<<"Enter Number of heads : ";
    cin>>nmboh;
    nmboh--;

    cout<<"Enter Number of Request : ";
    cin>>n;

    cout<<"Enter Cylinder Requests : ";
    for(int i=0;i<n;i++){
            cin>>in;
        vec.push_back(in);
    }

    cout<<"Enter Start Point : ";
    cin>>sp;

    fcfs();
    sstf();
    cscan();
    return 0;
}
/**
A Simple Test Case
200
8
98 183 37 122 14 124 65 67
53
*/
