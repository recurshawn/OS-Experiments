#include<iostream>
using namespace std;
#define quantum 4

float avgWaitTime=0;
int waitTime=0;

class process
{
    public:
        string name;
        int waitTime;
        int totalWait;
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
                p[i].totalWait += (waitTime - p[i].waitTime);
                p[i].waitTime = waitTime;
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
    cout<<endl;
    cout<<"***********************************"<<endl;
    for(int i=0;i<n;i++)
    {
    avgWaitTime += p[i].totalWait;
    }
    avgWaitTime /= n;
    cout<<"Average Waiting Time is: "<<avgWaitTime;
}

void insertProcess(process * p, int n)
{
    cout<<"Enter the process name and burst time of each of the "<<n<<" processes: ";

    for(int i=0;i<n;i++)
    {
        cin>>p[i].name;
        cin>>p[i].burstTime;
        p[i].waitTime=0;
        p[i].totalWait=0;
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
