#include <iostream>
#define N 8
using  namespace std;

void Print(char field[N][N]) //вывод доски
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << field[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

bool possible(char field[N][N], int row, int col) //возможно ли поставить ферзя
{
    for (int i = 0; i < row; i++)
    {
        if (field[i][col] == 'Q') return false; // возвращаем false, если ферзи стоят на одной и той же строке
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (field[i][j] == 'Q') return false; // возвращаем false, если ферзи стоят на одной диагонали (вверх влево)
    }

    for (int i = row, j = col; i >= 0 && j < N; i--, j++)
    {
        if (field[i][j] == 'Q') return false; // возвращаем false, если ферзи стоят на одной диагонали (вверх вправо)
    }

    return true;
}

void ferz(char field[N][N], int row)
{
    for (int i = 0; i < N; i++) //i - номер столбца
    {
        if (possible(field, row, i)) //если возможна установка ферзя
        {
            field[row][i] = 'Q'; //ставим ферзя на клетку
            //Print(field);
            ferz(field, row + 1); //повторяем действия для следующей строки
            //Print(field);
            field[row][i] = '*'; //просмотрели вариант, откатились назад, если не 8
        }
    }
        if (row == N) //если смогли поставить 8 ферзей, выводим
    {
        Print(field);
         exit(0);//если не писать, выведутся все возможные варианты
        return;
    }
}

int main() {
    char field[N][N]; //поле
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            field[i][j] = '*'; //* - пустая клетка
        }
    }
    ferz(field, 0);
}
