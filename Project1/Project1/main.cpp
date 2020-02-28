#include <iostream>
#include <vector>
#include <queue>
#include <stack>

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

void bfs(vector<vector<int>> graph, int start = 0)
{
	static vector<bool> visited;
	if (visited.size() == 0)
		for (int i = 0; i < graph.size(); i++)
			visited.push_back(false);

	queue<int> v;
	vector<int> distance(graph.size());
	distance[start] = 0;

	for (int i = 0; i < graph[start].size(); i++)
	{
		v.push(graph[start][i]);
		distance[i]++;
	}
	visited[start] = true;

	while (v.size())
	{
		int temp = v.front();
		v.pop();

		for (int i = 0; i < graph[temp].size(); i++)
			if (!visited[graph[temp][i]])
			{
				distance[graph[temp][i]] = distance[temp] + 1;
				v.push(graph[temp][i]);
			}

		if (visited[temp] == false)
			cout << temp << " ";
		visited[temp] = true;
	}
	cout << endl;
	for (int i = 0; i < distance.size(); i++)
		cout << i << " - " << distance[i] << endl;
}

void dfs(vector<vector<int>> graph, int start = 0)
{
	static vector<bool> visited;
	if (visited.size() == 0)
		for (int i = 0; i < graph.size(); i++)
			visited.push_back(false);

	stack<int> v;
	for (int i = 0; i < graph[start].size(); i++)
		v.push(graph[start][i]);
	visited[start] = true;
	cout << start<<" ";
	while (v.size())
	{
		int temp = v.top();
		v.pop();
		for (int i = 0; i < graph[temp].size(); i++)
			if (!visited[graph[temp][i]])
				v.push(graph[temp][i]);
		if (visited[temp] == false)
			cout << temp << " ";
		visited[temp] = true;
	}
}

int main()
{
	vector<vector<int>> graph = vector<vector<int>>(7);
	graph[0] = { 1,2,3,4 };
	graph[1] = { 0,2,4 };
	graph[2] = { 0,1,5,6 };
	graph[3] = { 0,4 };
	graph[4] = { 0,1,3 };
	graph[5] = { 2,6 };
	graph[6] = { 2,5 };
	cout << "DFS: ";
	dfs(graph);
	cout << "\nBFS: ";
	bfs(graph, 0);
}