#pragma once


class Map {
public:
	void addEdge(Axis p1, Axis p2) {
		int id1 = tmp.axisToId(p1.x, p1.y, limitY);
		int id2 = tmp.axisToId(p2.x, p2.y, limitY);
		//
		mp[id1].insert(id2); //
		///./////
		mp[id2].insert(id1); //
	}
	// id: node(id, onpath,x,y)
	bool removeEdge(Axis p1, Axis p2) {
		int id1 = tmp.axisToId(p1.x, p1.y, limitY);
		int id2 = tmp.axisToId(p2.x, p2.y, limitY);
		//
		if (mp[id1].find(id2) != mp[id1].end()) {
			mp[id1].erase(id2);
			mp[id2].erase(id1);
			return 1;
		}
		return 0;
	}
	//
	void deleteNode(Axis p)
	{
		int id = tmp.axisToId(p.x, p.y, limitY);
		//
		for (auto it : mp[id]) {
			mp[it].erase(id);
		}
		mp[id].clear();
		mp.erase(id);
	}
	//
	void AddNode(Axis p) {
		int id = tmp.axisToId(p.x, p.y, limitY);
		mp[id];
	}
	//
	void display() {
		for (auto& i : mp) {
			cout << "[ " << i.first << " ]: ";
			for (auto& j : i.second) {
				cout << j << ", ";
			}
			cout << "\n";
		}
	}
	int limitX, limitY; // limits of plane

	// [id] -> id(j)---->id(n)
	map<int,set<int>>mp;
	NodeConverter tmp;
};