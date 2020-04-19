#include<iostream>

using namespace std;
//1表示西墙 2表示北 4表示东 8表示 南
int row;
int col;
int room[60][60];
int color[60][60];
int room_count = 0;
int max_area = 0;
int cur_area = 0;
void Dfs(int i, int j)
{
    if (color[i][j])
        return;
    color[i][j] = room_count;
    cur_area++;
    if ((room[i][j] & 1) == 0) Dfs(i, j - 1);
    if ((room[i][j] & 2) == 0)Dfs(i - 1, j);
    if ((room[i][j] & 4 )== 0)Dfs(i, j + 1);
    if ((room[i][j] & 8 )== 0)Dfs(i + 1, j);

}
int main() {
    cin >> row >> col;
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
            cin >> room[i][j];
    }
    memset(color, 0, sizeof(color));
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            if (color[i][j] == 0)
            {
                room_count++;
                cur_area = 0;
                Dfs(i, j);
                max_area = cur_area > max_area ? cur_area : max_area;
            }

        }
    }
    cout << room_count<<endl;
    cout << max_area;
}