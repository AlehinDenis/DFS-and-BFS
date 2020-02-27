#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void dfsRecursive(vector<vector<int>> graph, int v = 0)
{
	static vector<bool> visited;
	if(visited.size() == 0)
		for (int i = 0; i < graph.size(); i++)
			visited.push_back(false);

	visited[v] = true;
	for (int i = 0; i < graph[v].size(); i++)
		if (!visited[graph[v][i]])
			dfsRecursive(graph, graph[v][i]);
}

void bfs(vector<vector<int>> graph)
{
	static vector<bool> visited;
	if (visited.size() == 0)
		for (int i = 0; i < graph.size(); i++)
			visited.push_back(false);

	queue<int> v;
	for (int i = 0; i < graph[0].size(); i++)
		v.push(graph[0][i]);
	visited[0] = true;
	while (v.size())
	{
		int temp = v.front();
		v.pop();
		for (int i = 0; i < graph[temp].size(); i++)
			if (!visited[graph[temp][i]])
				v.push(graph[temp][i]);
		visited[temp] = true;
	}

}

int main()
{
	vector<vector<int>> graph = vector<vector<int>>(5);
	graph[0] = { 1,2,3,4 };
	graph[1] = { 0,2,4 };
	graph[2] = { 0,1 };
	graph[3] = { 0,4 };
	graph[4] = { 0,1,3 };
	dfsRecursive(graph);
	bfs(graph);
}