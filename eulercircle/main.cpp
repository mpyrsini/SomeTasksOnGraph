#include <iostream>

using namespace std;
int const N=7;
int euler(int * circle,int ** matrix, int nout, int k,int nv)
{
    for (int i=0;i<nv;i++)
    {
        if (matrix[k][i]>0)
        {
            matrix[k][i]--;
            matrix[i][k]--;
            //euler(circle,matrix,nout,i,nv);
        }
        euler(circle,matrix,nout,i,nv);
    }
    nout++;
    circle[nout]=k;

}
int main()
{
    int ** matrix= new int *[N];
    for (int i=0;i<N;i++)
        matrix[i] = new int[N];
    int * circle= new int[2*N];
    for (int i=0;i<N; i++)
    {
        for (int j=0;j<N; j++)
            matrix[i][j]=0;
    }
    for (int i=0;i<(2*N); i++)
    {
        circle[i]=-1;
    }
    int a,b=0;
    while (true)
    {
        cout<<"to end inputting, input -1, -1"<<endl;
        cout << "input value 1"<<endl;
        cin>>a;
        cout << "input value 2"<<endl;
        cin>>b;
        if (a==-1 && b==-1) break;
        matrix[a][b]+=1;
        matrix[b][a]+=1;
    }
    int countable=0;
    for (int i=0;i<N;i++)
        for (int j=0;j<N;j++)
            countable+=matrix[i][j];
    countable=countable/2;
    cout<<countable;
    //for (int j=0;j<N;j++)
    euler(circle,matrix,0,0,N);
    int i=0;
    while (circle[i]!=-1)
    {
        cout<<circle[i]<<"--";
        i++;
    }
}

