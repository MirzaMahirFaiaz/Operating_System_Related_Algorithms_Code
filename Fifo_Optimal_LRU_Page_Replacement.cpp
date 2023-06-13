//@author MIRZA MAHIR FAIAZ, Dept. of CSE, AUST
#include<bits/stdc++.h>
using namespace std;
const int N=100000;

int n,fs,nmbp;
int pages[N], mark[N];

void LRU(){
     queue<int> Q;
    int pf=0;
    int hit=0;

    ofstream fout;
    fout.open ("output.txt",ios::app);
    fout<<"LRU: \n"<<endl;

    for(int i=0; i<n; i++)
    {
        if(mark[pages[i]]==true)
        {
            hit++;
        }
        else
        {
            Q.push(pages[i]);
            mark[pages[i]]=true;
            if(Q.size()>fs)
            {
                int p= Q.front();
                mark[p]=false;
                Q.pop();
            }
            pf++;
        }

    }
    int getArrayLength = sizeof(mark) / sizeof(int);
    for(int i=0;i<getArrayLength;i++){
        mark[i]=false;
    }
    fout<<"\nTotal Page Faults: "<<pf<<endl;
    fout.close();

    return;
}

void fifo_page_replacement()
{
    queue<int> Q;
    int pf=0;
    int hit=0;
    ofstream fout;
    fout.open ("output.txt",ios::app);
    fout<<"FIFO: \n"<<endl;


    for(int i=0; i<n; i++)
    {
        if(mark[pages[i]]==true)
        {
            hit++;
        }
        else
        {
            Q.push(pages[i]);
            mark[pages[i]]=true;
            if(Q.size()>fs)
            {
                int p= Q.front();
                mark[p]=false;
                Q.pop();
            }
            pf++;
        }

    }
    fout<<"\nTotal Page Faults: "<<pf<<endl;
    fout.close();


     int getArrayLength = sizeof(mark) / sizeof(int);
    for(int i=0;i<getArrayLength;i++){
        mark[i]=false;
    }

    return;
}

void optimal_page_replacement(void)
{
    vector<int> vec;
    int pf=0;
    int hit=0;
    ofstream fout;
    fout.open ("output.txt",ios::app);
    fout<<"Optimal: \n"<<endl;

    for(int i=0; i<n; i++)
    {
        int arr[]={1000,1000,1000,1000};

        if(mark[pages[i]]==true)
        {
            fout<<"Hit happen "<<pages[i]<<endl;
            hit++;
        }
        else
        {
            vec.push_back(pages[i]);
            mark[pages[i]]=true;
            if(vec.size()>fs)
            {
                for(int h = 0;h<3;h++){
                    int p = vec[h];
                    for(int j=i+1;j<n;j++){
                        if(p==pages[j]){
                            arr[h]=j-i;
                            break;
                        }
                    }
                }
                int maxi,maxv=-99999;
                    for(int h=0;h<3;h++){
                        if(maxv<arr[h]){
                            maxv=arr[h];
                            maxi=h;
                        }
                    }

                mark[vec[maxi]]=false;
                vector<int>::iterator it = vec.begin()+maxi;
                vec.erase(it);
            }
            pf++;
            fout<<"Page Fault : "<<pages[i]<<endl;
            vector<int> cvec = vec;
            for(vector<int>::iterator it= cvec.begin();it!=cvec.end();it++){
                fout<<*it<<" ";
            }
            fout<<endl;
        }

    }
    fout<<"\nTotal Page Faults: "<<pf<<endl;
     fout.close();

     int getArrayLength = sizeof(mark) / sizeof(int);
    for(int i=0;i<getArrayLength;i++){
        mark[i]=false;
    }

    return;
}

int main()
{

    int ch;
while(true){
    ifstream myfile;
    myfile.open("input.txt");
    cout<<"Number of Page References: ";
    myfile>>n;

    cout<<"Page Reference String:\n";
    for(int i=0; i<n; i++)
        myfile>>pages[i];

    cout<<"Number of Memory Page Frames: ";
    myfile>>fs;
    myfile.close();

    cout<<"What you want? \n1. FIFO \n2.Optimal \n3.LRU \n4.Exit \n";
    cin>>ch;
    if(ch==1){
    fifo_page_replacement();
    }else if(ch==2){
    optimal_page_replacement();
    }else if(ch==3){
    LRU();
    }else if(ch==4){
        exit(0);
    }
}

    return 0;
}
/**
22
7 0 1 2 0 3 0 4 2 3 0 3 0 3 2 1 2 0 1 7 0 1
4
*/
