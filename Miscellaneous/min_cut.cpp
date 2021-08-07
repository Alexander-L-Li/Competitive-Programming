#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <cstdlib>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
    // Step 1: Read the input
    ifstream input;
    input.open("kargerMinCut.in");
    string line;
    vector<vector<int>> raw_graph;
    while (getline(input, line))
    {
        istringstream is(line);
        raw_graph.push_back(vector<int>(istream_iterator<int>(is), istream_iterator<int>()));
    }
    input.close();

    srand(0);
    int minCutSize = raw_graph.size();

    for (int i = 0; i < 10000; i++)
    {
        if (i % 100 == 0)
        {
            cout << i / 100 << '%' << endl;
        }

        // Step 2: Convert the input to an edge list
        vector<pair<int, int>> edges;
        for (int src = 0; src < raw_graph.size(); src++)
        {
            for (int dst = 1; dst < raw_graph[src].size(); dst++)
            {
                edges.push_back(pair<int, int>(raw_graph[src][0], raw_graph[src][dst]));
            }
        }

        int num_nodes = raw_graph.size();
        int num_edges = edges.size();

        while (num_nodes > 2)
        {
            int edgeIndex = rand() % num_edges;

            int src = edges[edgeIndex].first;
            int dst = edges[edgeIndex].second;

            // Consider speeding this up with an appropriate index
            for (int e = 0; e < num_edges; e++)
            {
                int testSrc = edges[e].first;
                int testDst = edges[e].second;

                // rename all dst to src
                if (testSrc == dst) { testSrc = edges[e].first = src; }
                if (testDst == dst) { testDst = edges[e].second = src; }

                // Eliminate self loop
                if (testSrc == testDst)
                {
                    edges[e] = edges[num_edges - 1];
                    num_edges--;
                    e--;
                }
            }

            num_nodes--;
        }

        minCutSize = min(minCutSize, num_edges);
    }
    
    // Be careful with the fact that the edges are duplicated
    cout << minCutSize / 2 << endl;

    return 0;
}
