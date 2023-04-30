#include<bits/stdc++.h>
using namespace std;

#include"Node.h"
#include"Map.h"
#include"Algorithm.h"

int main() {
	Map graph;
	int limitX, limitY;
	cin >> limitX >> limitY;
	graph.limitX = limitX;
	graph.limitY = limitY;
	//
	int edges;
	cin >> edges;
	while (edges--) {
		Axis a, b;
		cin >> a.x >> a.y >> b.x >> b.y;
		//
		graph.addEdge(a, b);
	}
	//
	int queires;
	cin >> queires;
	//
	Floyd* floyd = new Floyd();
	Axis a, b;
	floyd->build(graph);
	floyd->run(graph);
	while (queires--) {

		string algoName;
		cin >> algoName;
		transform(algoName.begin(), algoName.end(), algoName.begin(), ::tolower);
		cin >> a.x >> a.y >> b.x >> b.y;

		if (algoName =="dijkstra") {
			Dijkstra* algo = new Dijkstra(a, b);
			algo->run(graph);
			if (!algo->getPath(graph))cout << "No Path!\n";

		}
		else if (algoName == "dfs") {
			DFS* algo = new DFS(a, b);
			
			algo->run(graph, algo->getSrcId(graph));
			if (!algo->getPath(graph))cout << "No Path!\n";

		}
		else if (algoName == "bfs") {
			BFS* algo = new BFS(a, b);
			algo->run(graph);
			if (!algo->getPath(graph))cout << "No Path!\n";

		}
		else if (algoName == "floyd") {
			floyd->setPoints(a, b);

			if (!floyd->getPath(graph))cout << "No Path!\n";

		}
		else {
			cout << "DOZ!, NEMO!\n";
		}
	}
	return 0;
}
/*
structre map,node -> input - file
-> 4 algos
--> dfs,bfs,
--> dij,floyed




*/


