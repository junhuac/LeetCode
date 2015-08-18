/*
Author: Junhua Chang
Email: junhuac@hotmail.com
Date: 08/18/2015
Notes:
	Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.

	OJ's undirected graph serialization:
	Nodes are labeled from 0 to N - 1, where N is the total nodes in the graph.
	We use # as a separator for each node, and , as a separator for each neighbor of the node.
	As an example, consider the serialized graph {1,2#2#2}.
	The graph has a total of three nodes, and therefore contains three parts as separated by #.
	Connect node 0 to both nodes 1 and 2.
	Connect node 1 to node 2.
	Connect node 2 to node 2 (itself), thus forming a self-cycle.
	Visually, the graph looks like the following:
	1
	/ \
	/   \
	0 --- 2
	/ \
	\_/
Solution: 
	1. DFS. 2. BFS.*/

#include <queue>

using namespace std;

class Solution
{
public:
	Solution() {}
	~Solution() {}

	string CloneGraph(string Graph)
	{
		string clone = "";
		int digit = 0;
		queue<int> neighbors;

		for (int i = 0; i <= Graph.length(); i++)
		{
			if (i == Graph.length() || '#' == Graph.at(i))
			{
				bool first = true;
				while (!neighbors.empty())
				{
					char label[10];
					int neighbor = neighbors.front();
					neighbors.pop();

					if (!first)
					{
						clone.append(",");
					}
					_itoa_s(neighbor, label, 10);
					clone = clone.append(label);
					first = false;
				}
				if (i < Graph.length())
				{
					clone.append("#");
				}
			}
			else
			{
				if (isdigit(Graph.at(i)))
				{
					buffer[digit++] = Graph.at(i);
				}

				if (i == Graph.length() - 1 || ',' == Graph.at(i + 1) || '#' == Graph.at(i + 1))
				{
					neighbors.push(atoi(&buffer[0]));
					memset(buffer, 0, sizeof(buffer));
					digit = 0;
				}
			}
		}

		return clone;
	}
private:
	char buffer[10];
};