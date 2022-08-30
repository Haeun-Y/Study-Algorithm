#include <bits/stdc++.h>
using namespace std;
int row;
int col;
int stickerNum;
bool laptop[42][42];
int turn[4] = {0, 90, 180, 270};

int countStickers()
{
    int result = 0;
    for(int i = 0; i<row; i++)
    {
        for(int j = 0; j<col; j++)
        {
            if(laptop[i][j]) result++; 
        }
    }

    return result;
}
//노트북의 x, y 부터 시작해서 (왼쪽 위 위치) 스티커를 붙일 수 있는지 반환해줌
bool canAttach(vector<vector<int>>& gridPaper, int startX, int startY)
{
    int targetX = startX;
    int targetY = startY;
    int gridRow = gridPaper.size();
    int gridCol = gridPaper[0].size();

    for(int i = 0; i< gridRow; i++)
    {
        for(int j = 0; j< gridCol; j++)
        {
            //모눈종이에 스티커가 붙은 칸인데 노트북의 해당위치에 스티커의 한칸이 들어갈 수 없을 때
            if(gridPaper[i][j] == 1 && laptop[targetX][targetY])
                return false;
            
            targetX++;
            targetY++;
        
        }
    }
    
    targetX = startX;
    targetY = startY;
    
    for(int i = 0; i<gridRow; i++)
    {
        for(int j = 0; j<gridCol; j++)
        {
            if(gridPaper[i][j])
                laptop[targetX][targetY] = true;
            
            targetX++;
            targetY++;
        
        }
    }

    return true;
    
}
bool attachSticker(vector<vector<int>>& gridPaper)
{
    //되는지 확인하고 붙이는 과정이 너무 비효율적인거같다 되면 걍 바로 붙일 순 없나..?
    //TODO : FOR문 IDX 확인하기
    //TODO : 스티커 회전시키는 부분 확인하기
    //TODO : 주석 정리

    for(int i = 0; i<4; i++)
    {
        int turnAngle = turn[i];
        for(int j = 0; j<row; j++)
        {
            for(int k = 0; k<col; k++)
            {
                if(canAttach(gridPaper, j, k))
                {
                    return true;
                }
            }

        }
    }

    return false;
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> row >> col >> stickerNum;

    for(int i = 0; i<stickerNum; i++)
    {
        int gridRow, gridCol;
        cin >> gridRow >> gridCol;

        vector<vector<int>> gridPaper(gridRow, vector<int>(gridCol));

        for(int j = 0; j<gridRow; j++)
        {
            for(int k = 0; k<gridCol; k++)
                cin >> gridPaper[j][k];
        }
        if(!attachSticker(gridPaper)) continue;
    }

    cout << countStickers();
    


}