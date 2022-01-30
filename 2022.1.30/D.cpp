#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int maxn = 3e5 + 5;
const ll inf = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(), x.rend()
//卡题没时间写 copy一下
/*
方法一：并查集+枚举
本题中我们需要关注的是字符集合，且题目说了每个字符串中都不包含相同的字母。因此我们可以将每个字符串转为对应的一个二进制数。

下面考虑三种操作：

删除：相当于把某一位从 1 变为 0
添加：相当于把某一位从 0 变为 1
修改：相当于把一个 0 变为 1， 同时把一个 1 变为 0（不考虑保持不变的情况）
从而删除和添加可以合并为一种操作，也即修改一位的操作；而修改则对应于修改两位的操作。当然，还可以保持不变。

题目要求的分组关系实际上就是并查集。我们遍历所有字符串（对应的二进制数），然后枚举所有可能的操作，判断操作后的结果是否已经在之前的遍历中出现过。如果已经出现过，则在并查集中连边。

最后统计并查集中每个连通分量的信息即可得到答案。

作者：吴自华
链接：https://leetcode-cn.com/circle/discuss/UECpIR/view/6QKQ4h/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    
    return 0;
}