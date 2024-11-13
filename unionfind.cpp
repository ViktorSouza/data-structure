#include <iostream>
#include<map>

#include <vector>
using namespace std;

class UnionFind
{
private:
	unordered_map<string, int> list;
public:
	UnionFind(string nodes[])
	{
		for (int i = 0; i < nodes->length(); i++)
		{
			list[nodes[i]] = i;
		}
	};
	int unify(string a, string b)
	{
		list[a] = list[b];
	};
	vector<string> getUnion(string node)
	{
		vector<string> nodes;
		for (const auto& value : list)
		{
			if (value.second == list[node])
			{
				nodes.push_back(value.second);
			}
		}
		return nodes;
	};

};

int main()
{
	string nodes[] = {"A","B","C"};
	UnionFind bah(nodes);
	return 0;
}
