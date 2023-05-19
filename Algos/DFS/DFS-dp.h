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
