#include<iostream>
#include<list>
#include<queue>
using namespace std;
void add_edge(list<int >adj[],int x ,int y)
{
	adj[x].push_back(y);
	adj[y].push_back(x);
}
void print( list<int>adj[])
{
	for(int i=0;i<4;i++)
	{
		cout<<i<<"--->";
		for(auto x: adj[i] )
		{
			cout<<x;
		}
		cout<<endl;
	}
}
void bfs( list<int> adj[], int src)
{
	queue<int> q;
	int *visited= new int [4]{0};
    q.push(src);
    visited[ src]=true;
    while (!q.empty())
    {
    	int x=q.front();
    	q.pop();
    	cout<<x<<endl;
    	for ( auto nbr: adj[x])
    	{
    		if ( !visited[nbr])
    		{
    			q.push(nbr);
    			visited[nbr]=true;
    		}
    	}
    }
}
int main()
{
	list<int> *adj;
	adj=new list<int>[4];
	add_edge(adj,0,1);
	add_edge(adj,1,2);
	add_edge(adj,2,3);
	add_edge(adj,3,0);
	print(adj);
    // bfs(adj,0);


}