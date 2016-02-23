//graph without home-(version 1)
#include <iostream>
using namespace std;
bool moveSlave (int **InitialMatrix,int ** MatrixOfSlave,int ** MatrixOfPredator,int dimension, int slave, int predator)
{
    int max=-1;
    if (MatrixOfSlave[predator][slave]==INT_MAX )
    {
        for (int j=0; j<dimension; j++)
        {
            if (InitialMatrix[j][slave]==1)
            {
                if (MatrixOfPredator[predator][j]>max) //&& InitialMatrix[predator][j]==1)
                {
                    max=MatrixOfPredator[predator][j];
                }
                else if (predator==j && max<1)
                {
                    max=1;
                }
            }
        }
        if (max==-1 || max==INT_MAX) return false;
        else
        {
            MatrixOfSlave[predator][slave]=max+1;
            return true;
        }
    }
    return false;
}
bool movePredator (int **InitialMatrix,int ** MatrixOfSlave,int ** MatrixOfPredator,int dimension, int slave, int predator)
{
    int min=INT_MAX;
    if (MatrixOfPredator[predator][slave]==INT_MAX)
    {
        for (int j=0; j<dimension; j++)
        {
            if (InitialMatrix[j][predator]==1)
            {
                if (MatrixOfSlave[j][slave]<min) //&& InitialMatrix[j][slave]==1)
                {
                    min=MatrixOfSlave[j][slave];
                }
                else if (slave==j && min>1)
                {
                    min=1;
                }
            }
        }
        if (min==INT_MAX) return false;
        else
        {
            MatrixOfPredator[predator][slave]=min+1;
            return true;
        }
    }
    return false;
}

void Game(int **InitialMatrix,int ** MatrixOfSlave,int ** MatrixOfPredator,int dimension)
{
    for (int i=0; i<dimension; i++)
    {
        for (int j=0; j<dimension; j++)
        {
            if (InitialMatrix[i][j]==1)
            {
                MatrixOfPredator[i][j]=1;
            }
            if (i==j)
            {
                MatrixOfPredator[i][j]=0;
                MatrixOfSlave[i][j]=0;
            }
        }
    }
    bool existChange=true;
    while (existChange)
    {
        existChange=false;
        bool FlagMovingSlave=false;
        bool FlagMovingPredator=false;
        for (int i=0; i<dimension; i++)
        {
            for (int j=0; j<dimension; j++)
            {
                    FlagMovingSlave=moveSlave(InitialMatrix,MatrixOfSlave,MatrixOfPredator,dimension,i,j);
                    if (FlagMovingSlave) existChange=true;
            }
        }
        for (int i=0; i<dimension; i++)
        {
            for (int j=0; j<dimension; j++)
            {
                    FlagMovingPredator=movePredator(InitialMatrix,MatrixOfSlave,MatrixOfPredator,dimension,i,j);
                    if (FlagMovingPredator) existChange=true;
            }
        }
    }
}
void input(int ** matrix,int dimension)
{
    for (int i=0; i<dimension; i++)
    {
        for (int j=0; j<dimension; j++)
        {
            cout<<i<<" "<<j<<endl;
            cin>>matrix[i][j];
        }
    }
}
void output(int ** matrix, int dimension)
{
    for (int i=0; i<dimension; i++)
    {
        for (int j=0; j<dimension; j++)
        {
            cout<<" "<<matrix[i][j];
        }
        cout<<endl;
    }
}
void initialization(int ** matrix,int dimension)
{
    for (int i=0; i<dimension; i++)
    {
        for (int j=0; j<dimension; j++)
        {
            matrix[i][j]=INT_MAX;
        }
    }
}
int main()
{
    int N;
    cout<<"input N"<<endl;
    cin>>N;
    int ** matrix= new int *[N];
    int ** MatrixOfSlave = new int *[N];
    int ** MatrixOfPredator = new int * [N];
    for (int i=0; i<N; i++)
    {
        matrix[i] = new int[N];
        MatrixOfSlave[i] = new int [N];
        MatrixOfPredator[i] = new int [N];
    }

    input(matrix,N);
    initialization(MatrixOfPredator,N);
    initialization(MatrixOfSlave,N);
    Game(matrix,MatrixOfSlave,MatrixOfPredator,N);
    cout<<"MatrixOfSlave"<<endl;
    output(MatrixOfSlave,N);
    cout<<"MatrixOfPredator"<<endl;
    output(MatrixOfPredator,N);
    return 0;
}
