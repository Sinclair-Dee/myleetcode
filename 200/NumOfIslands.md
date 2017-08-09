## 200. Number of Islands
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded
by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four
edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
Answer: 3

//思路：
//union-find求解。将grid 中所有上下相邻的陆地合并，合并后并查集中陆地类簇的个数即为岛的个数。

```c++

class UF //并查集数据结构
{
public:
//构造函数，the_len 为前导数组的初始长度，初始化每个结点的初始前导结点为其自身，也即每个结点单独为一类。
UF(int the_len){ //构造函数，the_len 为前导数组的初始长度
pre.resize(the_len);
for(int i=0;i<the_len;i++) //初始化每个结点的初始前导结点为其自身，也即每个结点单独为一类
pre[i]=i;
}
//找到x 所属类簇的根结点root，且将x 至root 路径上的所有结点都直接连到root 上
int find(int x){ 
int root=x;
while(pre[root]!=root) //循环寻找x 所属类簇的根结点root
root=pre[root];
while(x!=root) //将x 至root 路径上的所有结点都直接连到root 上
{
int mid=x;
x=pre[mid];
pre[mid]=root;
}
return root;
}
//判断x 和y 是否属于同一类簇，是则返回true，否则返回false
bool isunion(int x,int y){
return find(x)==find(y);
}
//将x 和y 所属的两个类簇合并，也即将y 所属类簇的根结点ry 连接到x 所属类簇的根结点rx 上
void uniontwo(int x,int y){
int rx=find(x);
int ry=find(y);
pre[ry]=rx;
}
protected:
vector<int> pre; //前导数组，pre[i]表示i 与pre[i]属于同一类，且pre[i]为i 的上一级。每一个类簇的根root 的pre[root]=root
};
class Solution
{
public:
int numIslands(vector<vector<char>>& grid)
{
if(grid.size()==0)
return 0;
int m=grid.size(),n=grid[0].size(); //m,n 分别为grid 的行数与列数
int count=0; //记录岛的个数，初始为0
UF unionfind(m*n); //定义并查集对象
for(int i=0;i<m;i++)
for(int j=0;j<n;j++)
{
if(grid[i][j]!='1') //若grid[i][j]不为'1'，继续下一次循环
continue;
count++; //当grid[i][j]='1'时，岛的个数count 加一
//若陆地grid[i][j]的上方grid[i-1][j]也是陆地，则合并这两块陆地，同时岛的个数减一
if(i>0 && grid[i-1][j]=='1')
{
unionfind.uniontwo(i*n+j-n,i*n+j);
count--;
}
//若陆地grid[i][j]的左侧grid[i][j-1]也是陆地，且这两块陆地当前不属于同一个岛，则合并
这两块陆地，同时岛的个数减一
if(j>0 && grid[i][j-1]=='1' && !unionfind.isunion(i*n+j-1,i*n+j))
{
unionfind.uniontwo(i*n+j-1,i*n+j);
count--;
}
}
return count;
}
};
```