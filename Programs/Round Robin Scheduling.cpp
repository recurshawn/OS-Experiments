#include<iostream>
using namespace std;
#define quantum 4

float avgWaitTime=0;
int waitTime=0;

class process
{
    public:
        string name;
        int burstTime;

};

void timeCalc(process * p, int n)
{
    int rem=0;
    int pr=0;
    cout<<"*********** GANTT Chart ***********"<<endl;
    while(true)
    {
        for(int i=0;i<n;i++)
        {
            if(p[i].burstTime!=0)
            {
                rem++;
                avgWaitTime += waitTime;
                pr++;
                cout<<" |"<<waitTime<<"| "<<p[i].name<<" ";
                if(p[i].burstTime>quantum)
                {
                    p[i].burstTime -= quantum;
                    waitTime += quantum;
                }
                else
                {
                    waitTime+= p[i].burstTime;
                    p[i].burstTime = 0;
                }

            }

        }
        if(rem==0)
        {
            break;
        }
        rem=0;
    }
    avgWaitTime = avgWaitTime/pr;
    cout<<endl;
    cout<<"***********************************"<<endl;
    cout<<"Average Waiting Time is: "<<avgWaitTime<<endl;
}

void insertProcess(process * p, int n)
{
    cout<<"Enter the process name and burst time of each of the "<<n<<" processes: ";

    for(int i=0;i<n;i++)
    {
        cin>>p[i].name;
        cin>>p[i].burstTime;

    }
}
int main()
{
    int n;

    cout<<"Enter the number of processes: ";
    cin>>n;
    process p[n];

    insertProcess(p, n);
    timeCalc(p, n);

}
