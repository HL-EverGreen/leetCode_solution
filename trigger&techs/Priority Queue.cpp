template <class T, class Container = vector<T>,
  class Compare = less<typename Container::value_type> > class priority_queue;

Usage:
priority_queue<int, vector<int>, greater<int> > q;

默认是less大顶堆，使用greater可以改为小顶堆

若T为自定义struct，需要如下写greater：

#include <iostream>
#include <queue>

using namespace std;

struct Node{
    int x, y;
    Node( int a= 0, int b= 0 ):
        x(a), y(b) {}
};

struct cmp{
    bool operator() ( Node a, Node b ){
        if( a.x== b.x ) return a.y> b.y;
       
        return a.x> b.x; }
};

int main(){
    priority_queue<Node, vector<Node>, cmp> q;
   
    for( int i= 0; i< 10; ++i )
    q.push( Node( rand(), rand() ) );
   
    while( !q.empty() ){
        cout << q.top().x << ' ' << q.top().y << endl;
        q.pop();
    }
   
    getchar();
    return 0;
}

// 用数组实现priority_queue (heap)
// e.g. min_heap
/*
int heap[MAXN], size_heap = 0;
//插入数值
void push(int x){
    int i = size_heap++;
    while(i > 0){
        //父节点的编号
        int p = (i-1)/2;
        //如果大小关系满足，则退出循环
        if(heap[p] <= x) break;
        //将父节点放下，把自己向上提
        heap[i] = heap[p];
        i = p;
    }
    heap[i] = x;
}

//获取最小值，并删除最小值
int top(){
    //最小值
    int ret = heap[0];
    //最后一个节点
    int x = heap[--size_heap];
    int i = 0;
    while(2*i+1 < size_heap){
        int a = 2*i+1, b = 2*i+2;
        //比较两个儿子的值
        if(b < size_heap && heap[b] < heap[a]) a = b;
        //满足大小关系
        if(heap[a] >= x) break;
        //将数值小的那个儿子提上来
        heap[i] = heap[a];
        i = a;
    }
    heap[i] = x;
    
    return ret;
}
*/