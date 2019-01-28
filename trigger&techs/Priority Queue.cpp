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