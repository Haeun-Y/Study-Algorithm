#include <bits/stdc++.h>
using namespace std;

int row, col;
int office[10][10];
bool isMonitored[10][10];
int minBlindSpot;
int totalCCTVNum;
vector<vector<vector<pair<int, int>>>> cctvDirection;
vector<pair<pair<int, int>, bool>> cctv;

void calculateMinBlindSpot()
{
    int result = 0;
    for(int i = 0; i<row; i++)
    {
        for(int j = 0; j<col; j++)
            if(!isMonitored[i][j]) result++;
    }
    if(result < minBlindSpot) 
        minBlindSpot = result;
}
void monitorOffice(pair<int, int> cctvPos, int directIdx, int cctvNum)
{
    for(int i = 0; i< cctvDirection[cctvNum][directIdx].size(); i++)
    {
        int dx = cctvDirection[cctvNum][directIdx][i].first;
        int dy = cctvDirection[cctvNum][directIdx][i].second;

        int curX = cctvPos.first;
        int curY = cctvPos.second;

        while(curX > 0 && curX < row && curY > 0 && curY < col)
        {
            if(office[curX][curY] == 6) break;
            isMonitored[curX][curY] = true;
            curX += dx;
            curY += dy;
        }
    }


}
void checkCCTV(int k)
{
    if(k == totalCCTVNum)
    {
        calculateMinBlindSpot();
        return;
    }
    else
    {
        for(int i = 0; i<totalCCTVNum; i++)
        {
            if(!cctv[i].second)
            {
                //isMonitored 초기화..?
                for(int j = 0; j<cctvDirection[office[cctv[i].first.first][cctv[i].first.second]].size(); j++)
                {
                    int posX = cctv[i].first.first;
                    int posY = cctv[i].first.second;
                    int cctvNum = office[posX][posY];
                    cctv[i].second = true;
                    monitorOffice(make_pair(cctv[i].first.first, cctv[i].first.second), j, cctvNum);
                    checkCCTV(k+1);
                }
                //이 코드 위치...다시 생각해보기
                cctv[i].second = false;
            }

        }
        
    }
    

}
void setCCTVDirection()
{
    pair<int, int> right = make_pair(0, 1);
    pair<int, int> left = make_pair(0, -1);
    pair<int, int> up = make_pair(-1, 0);
    pair<int, int> down = make_pair(1, 0);
    //cctv1 : 우, 좌, 상, 하
    cctvDirection[1].push_back({right});
    cctvDirection[1].push_back({left});
    cctvDirection[1].push_back({up});
    cctvDirection[1].push_back({down});

    //cctv2 : 좌우, 상하
    cctvDirection[2].push_back({left, right});
    cctvDirection[2].push_back({up, down});
    
    //cctv3 : 상우, 상좌, 하우, 하좌
    cctvDirection[3].push_back({up, right});
    cctvDirection[3].push_back({up, left});
    cctvDirection[3].push_back({down, right});
    cctvDirection[3].push_back({down, left});

    //cctv4 : 상좌우, 좌상하, 하좌우, 우상하
    cctvDirection[4].push_back({up, left, right});//down x
    cctvDirection[4].push_back({left, up, down});//right x
    cctvDirection[4].push_back({down, left, right});//up x
    cctvDirection[4].push_back({right, up, down});//left x

    //cctv5 : 상하좌우
    cctvDirection[5].push_back({up, down, left, right});
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> row >> col;
    minBlindSpot = 100;

    setCCTVDirection();

    for(int i = 0; i<row; i++)
    {
        for(int j = 0; j<col; j++)
        {
            int state;
            cin >> state;
            if(state > 0 && state < 6)
                cctv.push_back(make_pair(make_pair(i, j), false));
            office[i][j] = state;
        }
    }
    totalCCTVNum = cctv.size();
    
    //cctv 확인
    checkCCTV(0);
    cout << minBlindSpot;
    
}