/*
2  *统计（x,y）周围一圈雷的个数
3  */
4 int MainWindow::sumMine(int x, int y)
5 {
6     int mineNum=0;
7     if(x-1>=0&&y-1>=0&&map[x-1][y-1]==1) mineNum++;
8     if(x-1>=0&&map[x-1][y]==1) mineNum++;
9     if(x-1>=0&&y+1<mapCols&&map[x-1][y+1]==1) mineNum++;
10     if(y-1>=0&&map[x][y-1]==1) mineNum++;
11     if(y+1<mapCols&&map[x][y+1]==1) mineNum++;
12     if(x+1<mapRows&&y-1>=0&&map[x+1][y-1]==1) mineNum++;
13     if(x+1<mapRows&&map[x+1][y]==1) mineNum++;
14     if(x+1<mapRows&&y+1<mapCols&&map[x+1][y+1]==1) mineNum++;
15     return mineNum;
16
17 }
18
19 /*
20  *从（x,y）开始进行扩展
21  */
22 void MainWindow::expendBlock(int x, int y)
23 {
24     int mineAround=sumMine(x,y);
25     if(mineAround!=0){
26         //在（x，y）显示雷的个数,然后结束递归
27         QTableWidgetItem * temp=new QTableWidgetItem;
28         temp->setText(QString::number(mineAround,10));
29         temp->setTextAlignment(Qt::AlignCenter);
30         temp->setBackgroundColor(QColor(251,246,246));
31         mapUI->setItem(x,y,temp);
32         mapFlag[x][y]=1;
33         return ;
34     }
35     //翻开（x，y），并从周围八个方向递归，要判断越界
36
37     list<POINT> expendList;
38     POINT point;
39     point.x=x;
40     point.y=y;
41     expendList.push_back(point);
42     while (!expendList.empty()) {
43         point=expendList.front();
44         expendList.pop_front();
45         x=point.x;
46         y=point.y;
47         mineAround=sumMine(x,y);
48         if(mineAround!=0){
49             QTableWidgetItem * temp=new QTableWidgetItem;
50             temp->setText(QString::number(mineAround,10));
51             temp->setTextAlignment(Qt::AlignCenter);
52             temp->setBackgroundColor(QColor(251,246,246));
53             mapUI->setItem(x,y,temp);
54             mapFlag[x][y]=1;
55             continue;
56         }
57         QTableWidgetItem * temp1=new QTableWidgetItem;
58         temp1->setBackgroundColor(QColor(251,246,246));
59         temp1->setTextAlignment(Qt::AlignCenter);
60         mapUI->setItem(x,y,temp1);
61         mapFlag[x][y]=1;
62         if(x-1>=0&&y-1>=0&&mapFlag[x-1][y-1]==0){
63             point.x=x-1;
64             point.y=y-1;
65
66             expendList.push_back(point);
67         }
68         if(x-1>=0&&mapFlag[x-1][y]==0){
69             point.x=x-1;
70             point.y=y;
71
72             expendList.push_back(point);
73         }
74         if(x-1>=0&&y+1<mapCols&&mapFlag[x-1][y+1]==0){
75             point.x=x-1;
76             point.y=y+1;
77
78             expendList.push_back(point);
79         }
80         if(y-1>=0&&mapFlag[x][y-1]==0){
81             point.x=x;
82             point.y=y-1;
83
84             expendList.push_back(point);
85         }
86         if(y+1<mapCols&&mapFlag[x][y+1]==0){
87             point.x=x;
88             point.y=y+1;
89
90             expendList.push_back(point);
91         }
92         if(x+1<mapRows&&y-1>=0&&mapFlag[x+1][y-1]==0){
93             point.x=x+1;
94             point.y=y-1;
95
96             expendList.push_back(point);
97         }
98         if(x+1<mapRows&&mapFlag[x+1][y]==0){
99             point.x=x+1;
100             point.y=y;
101
102             expendList.push_back(point);
103         }
104         if(x+1<mapRows&&y+1<mapCols&&mapFlag[x+1][y+1]==0){
105             point.x=x+1;
106             point.y=y+1;
107             expendList.push_back(point);
108         }
109     }
110
111 }