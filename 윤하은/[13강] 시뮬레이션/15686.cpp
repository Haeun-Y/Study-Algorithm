#include <bits/stdc++.h>
using namespace std;

int row, col;
int targetChickenStore;
int city[50][50];
int totalChickenStore;
vector<pair<int, int>> chickenStore;
int result;

//bfs로 해결해보기
int calculateChickenDis(int posHomeX, int posHomeY, int posChickenStoredX, int posChickenStoreY)
{
    return (abs(posHomeX-posChickenStoredX) + abs(posHomeY-posChickenStoreY));
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> row;
    col = row;

    cin >> targetChickenStore;
    result = 100000;

    for(int i = 0; i<row; i++)
    {
        for(int j = 0; j<col; j++)
        {
            int status;
            cin >> status;
            if(status == 2) //치킨집일 경우
            {
                totalChickenStore++;
                chickenStore.push_back(make_pair(i, j));
            }   
            city[i][j] = status;
        }    
    }

    int tmp[20];
    for(int i = 0; i<totalChickenStore; i++)
    {
        if(i < targetChickenStore) tmp[i] = 0;
        else tmp[i] = 1;
    }
    
    do
    {
        int chickenSum = 0;
        for(int i = 0; i<totalChickenStore; i++)
        {
            //해당 치킨집이 선택됨
            if(tmp[i] == 0)
            {
                int chickenX = chickenStore[i].first;
                int chickenY = chickenStore[i].second;

                for(int j = 0; row; i++)
                {
                    for(int k = 0; col; j++)
                    {
                        if(city[i][j] == 1)
                            chickenSum += calculateChickenDis(j, k, chickenX, chickenY);
                    }
                }


            }
        }

        if(chickenSum < result) result = chickenSum;

    }while(next_permutation(tmp, tmp+totalChickenStore));
    
    cout << result;
    

}