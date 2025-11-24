#include <iostream>
using namespace std;

void inputMatrix(int arr[][5], int rows, int cols)
{
    cout << "Enter array elements: " << endl;
    for (int t = 0; t < rows; t++)
    {
        for (int p = 0; p < cols; p++)
        {
            cin >> arr[t][p];
        }
    }
}

void printSparse(int sparse[][3]) {
    int nonZero = sparse[0][2];
    for (int i = 0; i <= nonZero; i++) {
        for (int j = 0; j < 3; j++) {
            cout << sparse[i][j] << " ";
        }
        cout << endl;
    }
}


void toSparse(int arr[][5], int rows, int cols, int sparse[][3])
{
    int nonZeroCount = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] != 0)
            {
                nonZeroCount++;
            }
        }
    }

    sparse[0][0] = rows;
    sparse[0][1] = cols;
    sparse[0][2] = nonZeroCount;

    int k = 1;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] != 0)
            {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = arr[i][j];
                k++;
            }
        }
    }
   cout << "The sparse matrix is: "<<endl;
   printSparse(sparse);
}

void simpleTranspose(int sparse[][3], int trans[][3])
{
    int rows = sparse[0][0];
    int cols = sparse[0][1];
    int nonZero = sparse[0][2];

    trans[0][0] = cols;
    trans[0][1] = rows;
    trans[0][2] = nonZero;

    int k = 1;
    for (int col = 0; col < cols; col++)
    {
        for (int i = 1; i <= nonZero; i++)
        {
            if (sparse[i][1] == col)
            {
                trans[k][0] = sparse[i][1];
                trans[k][1] = sparse[i][0];
                trans[k][2] = sparse[i][2];
                k++;
            }
        }
    }
    cout << "The transpose of sparse matrix is: "<<endl;
    printSparse(trans);
}

int main()
{
    int rows, cols;
    cout << "Enter no of rows: "<<endl;
    cin >> rows;
    cout << "Enter no of cols: "<<endl;
    cin >> cols;

    int ogArr[25][5];
    int trans[25][3];
    int sparse[25][3];
    inputMatrix(ogArr, rows, cols);
    toSparse(ogArr, rows, cols, sparse);
    simpleTranspose(sparse, trans);
    return 0;
}
