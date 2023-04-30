#pragma once
#define ll long long
//

class Algorithm {
public:
	void run(Map &graph) {};
	bool getPath(Map& graph) { return 1; };
	long long dst(Axis p1, Axis p2) {
		return sqrtl((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
	}
	//
	NodeConverter tmp;
};

//
class Dijkstra:public Algorithm {
public:
	Dijkstra(Axis src,Axis dst) {
		this->src = src;
		this->ds = dst;
	}
	void run(Map& graph) {
		int start = tmp.axisToId(src.x, src.y, graph.limitY);
		//
		distance[start].d = 0;
		pq.push({ 0,start });
		//
		while (pq.size()) {
			int node, d;
			tie(d,node) = pq.top();
			pq.pop();
			d = -d;
			//
			for (auto& to : graph.mp[node]) {
				ll nCost = d + dst(tmp.idToAxis(node, graph.limitY), tmp.idToAxis(to, graph.limitY));
				if (nCost < distance[to].d) {
					distance[to].d = nCost;
					pq.push({ -nCost,to });
					parent[to] = node;
				}
			}
		}
	}
	//
	bool getPath(Map& graph) {
		if (distance[tmp.axisToId(ds.x, ds.y, graph.limitY)].d == 1e18) {
			return 0;
		}
		//
		cout << "Path: " << distance[tmp.axisToId(ds.x, ds.y, graph.limitY)].d << "\n";

		stack<Axis>path;
		while (!(ds.compare(src))) {
			//cout << "( " << ds.x << " - " << ds.y <<" )" << "\n";
			path.push(ds);
			//
			ds = tmp.idToAxis(parent[tmp.axisToId(ds.x, ds.y, graph.limitY)], graph.limitY);
		}
		//
		path.push(src);
		while (path.size()) {
			cout << "( " << path.top().x<< " - " << path.top().y <<" )" << "\n";
			path.pop();
		}
		//
		return 1;

	}

private:
	struct InfStruct {
		ll d = 1e18;
	};

	priority_queue<pair<ll,ll >>pq;
	map<ll,InfStruct>distance;
	map<ll, ll>parent;
	Axis src, ds;
	
};

//
class DFS :public Algorithm {
public:
	DFS(Axis src, Axis dst) {
		this->src = src;
		this->ds = dst;
	}
	ll run(Map& graph,int parID) {
		Axis cur = tmp.idToAxis(parID, graph.limitY);
		//
		if (cur.compare(ds)) {
			return 0;
		}
		//
		auto& ret = dp[parID];
		if (ret.d != -1)return ret.d;
		//
		ret.d = 1e14;
		//
		for (auto& to : graph.mp[parID]) {
			ll cost = this->run(graph, to) + dst(tmp.idToAxis(parID, graph.limitY), tmp.idToAxis(to, graph.limitY));
			if (ret.d > cost) {
				ret.d = cost;
				path[parID] = to;
			}
		}
		//
		return ret.d;
	}
	//
	bool getPath(Map& graph) {
		auto srcID = tmp.axisToId(src.x, src.y, graph.limitY);
		if (dp[srcID].d >= 1e14)return false;
		//
		Axis cur = src;
		cout << "Path: " << dp[srcID].d << "\n";

		while (!cur.compare(ds)) {
			cout << "( " << cur.x << " - " << cur.y << " )" << "\n";
			cur = tmp.idToAxis(path[tmp.axisToId(cur.x, cur.y, graph.limitY)], graph.limitY);
		}

		cout << "( " << ds.x << " - " << ds.y << " )" << "\n";

		//
		return true;
	}
	//
	ll getSrcId(Map& graph) {
		return tmp.axisToId(src.x, src.y, graph.limitY);
	}
private:
	struct InfStruct {
		ll d = -1;
	};
	Axis src, ds;
	map<ll,ll>path;
	map<ll, InfStruct>dp;
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//

class BFS :public Algorithm {
public:
	BFS(Axis src, Axis dst) {
		this->src = src;
		this->ds = dst;
	}
	void run(Map& graph) {
		int start = tmp.axisToId(src.x, src.y, graph.limitY);
		//
		distance[start].d = 0;
		q.push({ start,0 });
		//vis[start] = 1;
		//
		while (q.size()) {
			int node, w;
			node = q.front().ID;
			w = q.front().onPath;

			q.pop();
			//
			if (w) {
				q.push({ node,w - 1 });
			}
			else {
				if (vis[node])continue;
				vis[node] = 1;
				//
				for (auto& to : graph.mp[node]) {
					ll on = dst(tmp.idToAxis(node, graph.limitY), tmp.idToAxis(to, graph.limitY));
					ll nCost = distance[node].d + on;
					if (nCost < distance[to].d) {
						distance[to].d = nCost;
						q.push({ to,on-1 });
						parent[to] = node;
					}
				}
			}
		}
	}
	//
	bool getPath(Map& graph) {
		if (distance[tmp.axisToId(ds.x, ds.y, graph.limitY)].d == 1e18) {
			return 0;
		}
		//
		cout << "Path: " << distance[tmp.axisToId(ds.x, ds.y, graph.limitY)].d << "\n";

		stack<Axis>path;
		while (!(ds.compare(src))) {
			//cout << "( " << ds.x << " - " << ds.y <<" )" << "\n";
			path.push(ds);
			//
			ds = tmp.idToAxis(parent[tmp.axisToId(ds.x, ds.y, graph.limitY)], graph.limitY);
		}
		//

		path.push(src);
		while (path.size()) {
			cout << "( " << path.top().x << " - " << path.top().y << " )" << "\n";
			path.pop();
		}
		//
		return 1;

	}

private:
	struct InfStruct {
		ll d = 1e18;
	};
	struct Vertex
	{
		ll ID, onPath=0;
	};
	queue<Vertex>q;
	map<ll, InfStruct>distance;
	map<ll, ll>parent;
	map<ll,bool>vis;
	Axis src, ds;

};
class Floyd :public Algorithm {
public:
	
	//
	void setPoints(Axis src, Axis dst) {
		this->src = src;
		this->ds = dst;
	}
	//
	void run(Map& graph) {
		for (auto& it : graph.mp) {
			for (auto& i : graph.mp) {
				for (auto& j : graph.mp) {
					if (dp[{i.first, j.first}].d > dp[{i.first, it.first}].d + dp[{it.first, j.first}].d) {
						dp[{i.first, j.first}].d = dp[{i.first, it.first}].d + dp[{it.first, j.first}].d;
						path[{i.first, j.first}] = path[{i.first, it.first}];
					}
				}
			}
		}
	}
	//
	bool getPath(Map& graph) {
		int u = tmp.axisToId(src.x,src.y,graph.limitY), v = tmp.axisToId(ds.x, ds.y, graph.limitY);
		if (dp[{u, v}].d == 1e18) {
			return 0;
		}
		cout << "Path: " << dp[{u, v}].d << "\n";
		vector<ll>vv = { u };
		while (u!=v) {
			u = path[{u,v}].d;
			vv.push_back(u);
		}
		for (auto& it : vv) {
			Axis tmpp = tmp.idToAxis(it,graph.limitY);
			cout << "( " << tmpp.x << " - " << tmpp.y << " )" << "\n";
		}
		return 1;
	}

	void build(Map& graph) {
		for (auto& i : graph.mp) {
			for (auto& j : i.second) {
				ll tmpDist = dst(tmp.idToAxis(i.first, graph.limitY), tmp.idToAxis(j, graph.limitY));
				
				dp[{i.first, j}].d = tmpDist;
				
				path[{i.first, j}].d = j;
			}
		}
	}
private:

	struct InfStruct {
		ll d = 1e18;
	};
	Axis src, ds;
	map<pair<int, int>, InfStruct>dp;
	map<pair<ll,ll>, InfStruct>path;
	

};