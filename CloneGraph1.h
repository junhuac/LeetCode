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

#include <vector>
#include <queue>

using namespace std;

class NODE
{
public:
    NODE(int nodelabel)
        :label(nodelabel)
    {
    }

    ~NODE()
    {
    }

    int label;
    vector<NODE*> neighbors;
};

class Solution
{
public:
    Solution()
    {
    }

    ~Solution()
    {
        for (int i = 0; i < (int)nodes.size(); i++)
        {
            delete nodes[i];
        }
    }

    string Serialize()
    {
        string graph;

        for (int i = 0; i < (int)nodes.size(); i++)
        {
            string neighbors;

            NODE* pNode = nodes[i];

            for (int j = 0; j < (int)pNode->neighbors.size(); j++)
            {
                char buf[10];
                _itoa_s(pNode->neighbors[j]->label, buf, 10);
                neighbors += buf;

                if (j < (int)pNode->neighbors.size() - 1)
                {
                    neighbors += ",";
                }
            }

            graph += neighbors;

            if (i < (int)nodes.size() - 1)
            {
                graph += "#";
            }
        }

        return graph;
    }

    NODE* UnSerialize(string graph)
    {
        int label = 0;
        int digit = 0;
        vector<int> neighbors;
        char buffer[10];

        memset(buffer, 0, sizeof(buffer));

        for (int i = 0; i <= graph.length(); i++)
        {
            if (i == graph.length() || '#' == graph.at(i))
            {
                NODE* pNode = NULL;
                
                if (label < (int)nodes.size())
                {
                    pNode = nodes[label];
                }
                else
                {
                    pNode = new NODE(label);
                    nodes.push_back(pNode);
                }

                for (int j = 0; j < (int)neighbors.size(); j++)
                {
                    pNode->neighbors.push_back(nodes[neighbors[j]]);
                }

                label++;
                neighbors.clear();
            }
            else
            {
                if (isdigit(graph.at(i)))
                {
                    buffer[digit++] = graph.at(i);
                }

                if (i == graph.length() - 1 || ',' == graph.at(i + 1) || '#' == graph.at(i + 1))
                {
                    int neighbor = atoi(&buffer[0]);

                    if (neighbor > (int)nodes.size() - 1)
                    {
                        for (int j = nodes.size(); j <= neighbor; j++)
                        {
                            NODE* pNode = new NODE(j);
                            nodes.push_back(pNode);
                        }
                    }

                    neighbors.push_back(neighbor);
                    memset(buffer, 0, sizeof(buffer));
                    digit = 0;
                }
            }
        }
        
        return nodes[0];
    }


    NODE* CloneGraph(NODE* pNode)
    {
        int label = -1;
        queue<NODE*> neighbors;
        neighbors.push(pNode);

        while (!neighbors.empty())
        {
            NODE* pNeighbor = neighbors.front();
            neighbors.pop();

            for (int i = 0; i < pNeighbor->neighbors.size(); i++)
            {
                neighbors.push(pNeighbor->neighbors[i]);
            }

            NODE* pNewNode = NULL;
            
            if (-1 == label || label != pNeighbor->label)
            {
                label = pNeighbor->label;
            }
            else if (label == pNeighbor->label)
            {
                break;
            }

            if (pNeighbor->label < nodes.size())
            {
                pNewNode = nodes[pNeighbor->label];
            }
            else
            {
                pNewNode = new NODE(pNeighbor->label);
                nodes.push_back(pNewNode);
            }

            for (int j = 0; j < pNeighbor->neighbors.size(); j++)
            {
                if (pNeighbor->neighbors[j]->label > nodes.size() - 1)
                {
                    for (int k = nodes.size(); k <= pNeighbor->neighbors[j]->label; k++)
                    {
                        nodes.push_back(new NODE(k));
                    }
                }
                pNewNode->neighbors.push_back(nodes[pNeighbor->neighbors[j]->label]);
            }
        }

        return nodes[0];
    }

private:
    vector<NODE*> nodes;
};
