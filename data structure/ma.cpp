#include <stdio.h>
#define ROW 5
#define COL 9
int chess[ROW][COL] ;        //棋盘
int step ;                    //记录步数
int search(int x1, int y1, int x2, int y2)    
//x1和y1分别是当前位置行号和列号
//x2和y2分别是B位置行号和列号                                                            
{
    int i, j ;
    int success = 0 ;
    if(x1 == x2 && y1 == y2)    //走通
    {
        for(i = 0; i < ROW; i++)
        {
            for(j = 0; j < COL; j++)
            {
                printf("%d ", chess[i][j]) ;
            }
            printf("\n") ;
        }
        return 1;
    }
    //逆时 针顺序 尝试四种走法
    //第一种
    if(x1+2<ROW && y1+1<COL)
    {
        step++ ;    //步数+1
        chess[x1+2][y1+1] = step ;
        success = search(x1+2, y1+1, x2, y2) ;
        if(success)    //从这条路可以走通
            return 1 ;
        step-- ;    //没走通，回退
        chess[x1+2][y1+1] = 0 ;
    }
//第二种
    if(x1+1<ROW && y1+2<COL)
    {
        step++ ;    //步数+1
        chess[x1+1][y1+2] = step ;
        success = search(x1+1, y1+2, x2, y2) ;
        if(success)
            return 1 ;
        step-- ;    //没走通，回退
        chess[x1+1][y1+2] = 0 ;
    }
//第三种
    if(x1-1<ROW && y1+2<COL)
    {
        step++ ;    //步数+1
        chess[x1-1][y1+2] = step ;
        success = search(x1-1, y1+2, x2, y2) ;
        if(success)
            return 1 ;
        step-- ;    //没走通，回退
        chess[x1-1][y1+2] = 0 ;
    }
//第四种
    if(x1-2<ROW && y1+1<COL)
    {
        step++ ;    //步数+1
        chess[x1-2][y1+1] = step ;
        success = search(x1-2, y1+1, x2, y2) ;
        if(success)
            return 1 ;
        step-- ;    //没走通 回退
        chess[x1-2][y1+1] = 0 ;
    }    
    return 0 ;
}
int main()
{
    int i, j ;
    int x, y ;
    for(i = 0; i < ROW; i++)
        for(j = 0; j < COL; j++)
            chess[i][j] = 0 ;
    step = 1 ;
    
    printf("请输入起始点(x,y)\n") ;
    scanf("%d,%d", &x, &y) ;
    chess[x][y] = step ;
    if(search(x, y, 0, 8)) 
        printf("共计%d步。\n", step) ;
    return 0 ;
}