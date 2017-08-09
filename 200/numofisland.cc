//思路：
//union-find求解。将grid 中所有上下相邻的陆地合并，合并后并查集中陆地类簇的个数即为岛的个数。
#include <iostream>
#include <vector>
using namespace std;

class UF{ //并查集数据结构
public:
//union-find构造函数.
//参数:the_len(前导数组的初始长度).
//思路:初始化每个结点的初始前导结点为其自身，也即每个结点单独为一类。
void UF(int the_len){
    pri.resize(the_len);
    for(int i=0;i<the_len;i++){
        pri[i] = i;
    }
}
//找到x所属类簇的根结点root，且实现数据压缩(将x至root路径上的所有结点都直接连到root上)。
int find(int x){
    //查找根节点
    int root = x;
    while(pri[root] !=root)
        root = pri[root];
    //压缩
    while(pri[x] != root){
        int pri_temp = pri[x];
        pri[x] = root;
        x = pri_temp;
    }
    //返回根节点
    return root;
}
//判断x 和y 是否属于同一类簇，是则返回true，否则返回false。
bool isunion(int x,int y){
    return find(x) == find(y);//这种写法比较简短
/********************************
    x = find(x);
    y = find(y);
    if(x == y) 
        return true;
    else 
        return false;
*******************************/
}
//将x 和y 所属的两个类簇合并，也即将y 所属类簇的根结点ry连接到x所属类簇的根结点rx上。
void uniontwo(int x,int y){
    pri(x) = pri(find(y));
}
protected:
vector<int> pre; //前导数组，pre[i]表示i 与pre[i]属于同一类，且pre[i]为i的上一级。每一个类簇的根root的pre[root]=root
};

class Solution{
public:
int numIslands(vector<vector<char>>& grid){
    //如果vector长度为0，则返回0.
    if(grid.size() = 0)
        return 0;
    //建立 m,n。分别为grid 的行数与列数
    int m = grid.size();
    int n = grid[0].size();
//记录岛的个数，初始为0
int count = 0;
//定义并查集对象，大小为m*n。
UF unionfind(m*n);
//判断岛屿数目算法
//s1两层for循环，从左上到右下遍历，初始认为一个1就是一个岛屿,岛屿+1；如果有零，退出这次循环。
//如果是1
//先和上边的比较，如果上边也是1，那么并入上边并查集，岛屿减一。
//再和左边的相比，左边也是1，同时该陆地和左边的岛屿没有在一个连通分量中。那么并入左边并查集，岛屿减一。
//返回岛屿数量count。
for(int i=0;i<m;i++)
    for(int j=0;j<n;j++){
        if(gird[i][j] != '1')
            continue;
        count++;
        
        if(i>0 && gird[i-1][j] = '1'){
            unionfind.uniontwo((i-1)*m+j-1,i*m+j-1);
            count--;
        }

        if(j>0 && gird[i][j-1] = '1'){
            unionfind.uniontwo((i*m+(j-1)-1,i*m+j-1);   
            count--;
        }
    }
return count;
    }
};

//test
int main(){
    int m,n;
    vector<vector<char>> grid;
    cin>>m>>n;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++){
            int in;
            cout>>in;
            grid[i][j] = in;
        }
    Solution solution;
    int count = solution.numIslands(grid);
    cout<<count<<endl;
    return 0;
}