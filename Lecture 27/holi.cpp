#include <iostream>
#include <list>

using namespace std;

class Graph
{
	int V;
	list<pair<int, int> > *l;
public:
	Graph(int v){
		V = v;
		l = new list<pair<int, int> >[V];
	}

	void addEdge(int u, int v, int wt, bool bidirct = true){

			l[u].push_back(make_pair(v,wt));

			if(bidirct){
				l[v].push_back(make_pair(u,wt));
			}
	}
	
	int dfsHelper(int node, int &ans, bool *visited){
		int count =1;
		visited[node] =true;
		int x = 0;
		for(auto p:l[node]){
			int child = p.first;
			int wt = p.second;

			if(!visited[child]){
				x = dfsHelper(child, ans, visited);
				ans+= 2*wt*(min(x, V-x));
				count += x;
			}
		}
		return count;
	}



	int dfscity(){
		int ans = 0;
		bool *visited = new bool[V]{0};

		dfsHelper(0, ans, visited);

		return ans;

	}
	
};



int main(int argc, char const *argv[])
{
	/* code */
// 4
// 1 2 3
// 2 3 2
// 4 3 2


	Graph g(4);
	g.addEdge(0, 1, 3);
	g.addEdge(1, 2, 2);
	g.addEdge(3, 2, 2);

	cout<<g.dfscity()<<endl;

	return 0;
}








