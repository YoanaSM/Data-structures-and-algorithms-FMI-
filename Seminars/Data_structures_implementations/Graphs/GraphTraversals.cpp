#include <iostream>
#include <vector>
#include <queue>
#include <stack>


class Graph {
	std::vector<std::vector<int>> adjList;
	bool oriented;

	void DFS_HELP(size_t start, std::vector<bool>& visited) const;
	void hasCycleHelp(int start, std::vector<bool>& mySt, std::vector<bool>& visited> const;
        bool hasPathHelp(int start, int end,vector<bool>& visited) const;
public:
	Graph(size_t vertexCount, bool isOriented);

	void addEdge(size_t start, size_t end);
        bool hasPath(int start, int end) const;
	void BFS(size_t start) const;
	void DFS_ITERATIVE(size_t start) const;
	void DFS_RECURSIVE(size_t start) const;
        bool hasCycle()const;
        int shortestPath(int start, int end) const;
};


int Graph::shortestPath(int start, int end)const{

	if (start == end) {
		return 0;
	}

	vector<bool>visited(graph.size(), false);
	queue<int>myQ;

	myQ.push(start);
	visited[start] = true;
	size_t dist = 0;

	while (!myQ.empty()) {

		size_t currLSize = myQ.size();

		for (size_t i = 0; i < currLSize; i++)
		{
			int topEl = myQ.front();
			myQ.pop();

			for (auto neighbor : graph[topEl]) {

				if (!visited[neighbor]) {
					if (neighbor == end) {
						return dist + 1;//we add the last one that is the target 
					}
				}
				myQ.push(neighbor);
				visited[neighbor] = true;
			}
		}
		dist++;
	}
	return -1;

}

void Graph :: hasPathHelp(int start, int end, vector<bool>&visited) const{
  if(start == end){
  return true;

  visited[start] = true;
  for(auto it : adj[start]){
      if(!visited[i] && hasPathHelp(it,end,visited)){
            return true;
      }
  }
  return false;
  }
 
void Graph :: hasPath(int start, int end)const{

  vector<bool>visited(adj.size(),false);
  return hasPathHelp(start,end,visited);
}
void Graph::DFS_HELP(size_t start, std::vector<bool>& visited) const
{
	visited[start] = true;
	std::cout << start << " ";
	for (auto iter : adjList[start]) {
		if (!visited[iter]) {
			DFS_HELP(iter, visited);
		}
	}
}


void Graph::DFS_RECURSIVE(size_t start) const
{
	std::vector<bool>visited(adjList.size(), false);
	DFS_HELP(start, visited);
}



Graph::Graph(size_t vertexCount, bool isOriented) :adjList(vertexCount)
{
	this->oriented = isOriented;
}

void Graph::addEdge(size_t start, size_t end)
{
	adjList[start].push_back((int)end);
	if (!oriented) {
		adjList[end].push_back((int)start);
	}
}

void Graph::BFS(size_t start) const
{

	std::vector<bool> visited(adjList.size(), false);
	std::queue<size_t>myQ;
	myQ.push(start);
	visited[start];
	while (!myQ.empty()) {

		size_t curr = myQ.front();
		myQ.pop();
		std::cout << curr << " ";

		for (auto iter : adjList[curr]) {

			if (visited[iter]) {
				continue;
			}
			myQ.push(iter);
			visited[iter] = true;
		}
	}
}

void Graph::DFS_ITERATIVE(size_t start) const
{
	std::vector<bool>visited(adjList.size(), false);

	std::stack<size_t>myS;
	myS.push(start);

	while (!myS.empty()) {

		size_t curr = myS.top();
		myS.pop();
		
		if (visited[curr]) {
			continue;
		}

		visited[curr] = true;
		std::cout << curr << " ";

		for (auto iter : adjList[curr]) {
			myS.push(iter);
		}
	}
}

void Graph::hasCycleHelp(int start, std::vector<bool>& mySt, std::vector<bool>& visited){

   if(!visited[start]){

     mySt[start] = true;
     visited[start] = true;

    for(auto iter : adj[start]){

      if(!visited[iter] && hasCycleHelp(iter,mySt,visited){
          return true;
      }else if(mySt[iter]){
         return true;
      }
    }
   }
    mySt[start] = false;
    return false;
 }


void Graph::hasCycle()const{
	std::vector<bool>mySt;
        std::vector<bool>visited;

for(int i = 0; i < adj.size();i++){
   if(hasCycleHelp(i,mySt,visited)){
         return true;
   }
}return false;
}