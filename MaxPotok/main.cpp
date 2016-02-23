#include <iostream>
const int N=5;
const int I=0;
const int S=4;
using namespace std;
struct vertex
{
    bool visited=false;
    int ComeFrom=0;
    int CurrentValue=0;
};
void MaxPotok(int MainMatrix[][N],int ** matrix, vertex **Inform)
{
    int index=1;
    while (index==1)
    {
        for (int i=0; i<N; i++)
        {
            (*Inform)[i].visited=false;
            (*Inform)[i].ComeFrom=0;
            (*Inform)[i].CurrentValue=0;
        }
        (*Inform)[I].CurrentValue=INT_MAX;
        int  localthread=1;
        while (localthread==1)
        {
            int MaxValue=-1;
            int start=-1;
            for (int k=0; k<N; k++)
            {
                if ( ((*Inform)[k].visited==false) && ((*Inform)[k].CurrentValue>MaxValue) )
                {
                    start=k;
                    MaxValue=(*Inform)[k].CurrentValue;
                }

            }
            if (start==-1) localthread=0;
            if (start!=-1)
            {
                for (int j=0; j<N; j++)
                {
                    if (MainMatrix[start][j]>0 && (*Inform)[j].visited==false)
                    {
                        if ((MainMatrix[start][j]-matrix[start][j])>(*Inform)[start].CurrentValue)
                        {
                            if ((*Inform)[j].CurrentValue<(*Inform)[start].CurrentValue)
                            {
                                (*Inform)[j].ComeFrom=start;
                                (*Inform)[j].CurrentValue=(*Inform)[start].CurrentValue;
                            }
                            else;
                        }
                        else
                        {
                            if ((*Inform)[j].CurrentValue<MainMatrix[start][j]-matrix[start][j])
                            {
                                (*Inform)[j].ComeFrom=start;
                                (*Inform)[j].CurrentValue=MainMatrix[start][j]-matrix[start][j];
                            }
                            else;
                        }
                    }
                    if (MainMatrix[start][j]<0 && (*Inform)[j].visited==false)
                    {
                        if (-matrix[start][j]>(*Inform)[start].CurrentValue)
                        {
                            if ((*Inform)[j].CurrentValue<(*Inform)[start].CurrentValue)
                            {
                                (*Inform)[j].ComeFrom=start;
                                (*Inform)[j].CurrentValue=(*Inform)[start].CurrentValue;
                            }
                            else;
                        }
                        else
                        {
                            if ((*Inform)[j].CurrentValue<-matrix[start][j])
                            {
                                (*Inform)[j].ComeFrom=start;
                                (*Inform)[j].CurrentValue=-matrix[start][j];
                            }
                            else;
                        }
                    }
                    (*Inform)[start].visited=true;
                }
            }
        }
        int counter=S;
        int Thread=(*Inform)[S].CurrentValue;
        while (counter!=I)
        {
            matrix[counter][(*Inform)[counter].ComeFrom]=-Thread+matrix[counter][(*Inform)[counter].ComeFrom];
            matrix[(*Inform)[counter].ComeFrom][counter]=Thread+matrix[(*Inform)[counter].ComeFrom][counter];
            counter=(*Inform)[counter].ComeFrom;
        }
        if (Thread==0) index=0;
    }
}


int main()
{
    vertex *VertexInformation = new vertex[N];
    int MainMatrix[N][N];
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
        {
            cout<<i<<j<<endl;
            cin>>MainMatrix[i][j];
        }
    int ** matrix= new int *[N];
    for (int i=0; i<N; i++)
        matrix[i] = new int[N];
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
        {

            matrix[i][j]=0;
        }
    MaxPotok(MainMatrix,matrix, &VertexInformation);
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}
