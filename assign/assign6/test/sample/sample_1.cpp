/*
* 10189 - 扫雷
*
* 题意：一个n行m列的大框（一共n×m个方格），“*”代表雷，“.”代表没有雷；
* 输出每个方格的周围有多少个雷。每个方格的周围最多有八个方格。
*
* 作者 仪冰
*
* 学校 山东理工大学
*
* QQ 974817955
*
* 语言 C++
*
[样例输入]
4 4
*...
....
.*..
....
3 5
**...
.....
.*...
0 0
[样例输出]
Field #1:
*100
2210
1*10
1110
 
Field #2:
**100
33200
1*100
*/
 
#include<iostream>
 
using namespace std;
 
//在计算地雷总数时，有一个小技巧，设置边界数组，让其控制点(x,y)的八个变换坐标。
//在很多题目中都有用到边界数组。
int coordinate[8][2] = {-1,0, -1,1, 0,1, 1,1, 1,0, 1,-1, 0,-1, -1,-1};
 
int count(int x, int y, int a[100][100], int row, int column);  //计算一个方格周围的雷数
 
int main()
{
    int number = 0;                 //数据的组数
    int row = 1;                //行数
    int column = 1;             //列数
    int mineSweeper[100][100];  //存放雷的信息
    char symbol = '.';          //存放雷的符号
 
    while (cin >> row >> column)
    {
        if ((row == 0) || (column == 0)) //有一个为0那就没有意义了，退出。
        {
            break;
        }
 
        //初始化数组
        for (int i=0; i<100; i++)
        {
            for (int j=0; j<100; j++)
            {
                mineSweeper[i][j] = -1;
            }
        }
 
        //输入操作
        for (int i=0; i<row; i++)
        {
            for (int j=0; j<column; j++)
            {
                cin >> symbol;  //输入一个符号
 
                if (symbol == '.')   //如果不是雷
                {
                    mineSweeper[i][j] = 0;  //先赋值为0，区别于雷（是雷的话默认-1）
                }
            }
        }
 
        if (number > 0) //这是为了最后的一组数据不输出换行
        {
            cout << endl;
        }
        number++;
 
        //输出每组数据的固定头部
        cout << "Field #" << number << ':' << endl;
 
        //计算每个方格周围的雷数
        for (int i=0; i<row; i++)
        {
            for (int j=0; j<column; j++)
            {
                if (mineSweeper[i][j] == -1) //等于-1说明是雷
                {
                    cout << '*';
                }
                else
                {
                    cout << count(i, j, mineSweeper, row, column);
                }
            }
 
            cout << endl;
        }
    }
 
    return 0;
}
 
int count(int x, int y, int a[100][100], int row, int column)
{
    int num = 0;  //雷的数目
    int xc = 0;   //纪录横坐标的更新值
    int yc = 0;   //纪录纵坐标的更新值
 
    //计算雷的数目
    for (int i=0; i<8; i++)
    {
        xc = x + coordinate[i][0];
        yc = y + coordinate[i][1];
 
        //判断数组是否出界
        if ((xc >= 0) && (xc < row) && (yc >= 0) && (yc < column))
        {
            if (a[xc][yc] == -1)
            {
                num ++;   //雷数加一
            }
        }
    }
 
    return num;
}