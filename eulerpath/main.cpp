#include <iostream>
const int N=7;
using namespace std;
void serch_euler (int v, int ** matrix, int * circle,int & k)
{
    for (int i=0;i<N;++i)
        if (matrix[v][i])
    {
        matrix[v][i]=0;
        matrix[i][v]=0;
        serch_euler(i,matrix,circle,k);
    }
    circle[k]=v;
    k++;
}
bool euler (int ** matrix, int * cir)
{
    int degree[N];
    for (int j=0;j<N;j++)
        degree[j]=0;
    for (int i=0;i<N;i++)
        for (int k=0;k<N;k++)
            if (matrix[i][k] && i!=k)  {degree[i]++;}
    int count=0;
   int j=0;// beginning
    for (int i=0;i<N;i++)
        if (degree[i]%2!=0)
        {
            ++count;
            if (count>2) return false;
            j=i;
        }
        int  a=0;
        serch_euler(j,matrix,cir,a);
        return true;

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
        matrix[a][b]=1;
        matrix[b][a]=1;
    }
    bool flag=euler(matrix,circle);
    if (flag)
    for (int i=0;i<(2*N);i++)
        if (circle [i]==-1) cout<<""; else cout<<circle[i]<<" ";
    else cout<<"impossible"<<endl;
}
