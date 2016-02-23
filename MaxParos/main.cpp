#include <iostream>
const int N=3;
using namespace std;
void SearchMatching(int ** ResultMatrix, bool * BelongToMatch, int ** CurrentMatch)
{
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
        {
            if (ResultMatrix[i][j]!=0 && i!=j)
            {
                if (!(BelongToMatch[i] || BelongToMatch[j]))
                    {
                        BelongToMatch[i]=true;
                        BelongToMatch[j]=true;
                        CurrentMatch[i][j]=1;
                    }
            }
        }
}
int SearchFreeVertex(bool * BelongToMatch)
{
    for (int i=0; i<N; i++)
    {
        if (!(BelongToMatch[i]))
            return i;
    }
}
int ChooseVertex(int ** ResultMatrix, int start, int OtherVertex)
{
    int result=-1;
    for (int i=0;i<N;i++)
    {
        if (start!=i && ResultMatrix[start][i]!=0)
            {
                if (result!=-1)
                {
                    result=i;
                }
                else
                    OtherVertex=i;
            }
    }
    return result;
}
void Chain(int ** ResultMatrix, bool * BelongToMatch, int ** CurrentMatch, int LengthOfChain)
{
    LengthOfChain=0;
    SearchMatching(ResultMatrix,BelongToMatch);
    int StartVertex=SearchFreeVertex(BelongToMatch);
    int CurrentVertex=-2;
    int OtherWay=-1;
    bool FlagMatch=false;
    bool PreviousFlag=true;
    BelongToMatch[StartVertex]=true;
    while (CurrentVertex!=-1)
    {
        CurrentVertex=ChooseVertex(ResultMatrix,StartVertex,OtherWay)
        if (OtherWay=-1)
        {
            if (!FlagMatch && PreviousFlag )
            {
            PreviousFlag=FlagMatch;
            FlagMatch=true;
            BelongToMatch[CurrentVertex]=true;
            LengthOfChain++;
            }
            else
            {
                if (FlagMatch && !PreviousFlag)
                CurrentMatch[CurrentVertex][StartVertex]=2;
                CurrentMatch[StartVertex][CurrentVertex]=2;
                PreviousFlag=FlagMatch;
                FlagMatch=false;
                BelongToMatch[CurrentVertex]=true;
                LengthOfChain++;
            }
        }
        else
        {
            Chain(ResultMatrix, BelongToMatch);
        }
        StartVertex=CurrentVertex;
        OtherWay=-1;
    }

}
void MaxMatching(int FirstMatrix[][N],int ** ResultMatrix, int ** CurrentMatch)
{
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
        {
             ResultMatrix[i][j]=FirstMatrix[i][j];
        }
    bool *BelongToMatch = new bool[N];
    for (int i=0;i<N;i++)
        BelongToMatch[i]=false;


}
int main()
{
    int InitialMatrix[N][N];
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
        {
            cout<<i<<j<<endl;
            cin>>InitialMatrix[i][j];
        }
    int ** WorkMatrix= new int *[N];
    for (int i=0; i<N; i++)
        WorkMatrix[i] = new int[N];
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            WorkMatrix[i][j]=0;
        MaxMatching(InitialMatrix,WorkMatrix);
}
