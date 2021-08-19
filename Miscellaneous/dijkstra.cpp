#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

#define GRAPH_SIZE 200

// This is not a general purpose heap
// It is designed for the Dijkstra's algorithm
class Heap
{
public:
    Heap();
    int Count();
    pair<int, int> DeleteMin();
    void FixDown(int index);
    void FixUp(int index);
    void SwapNodes(int heap_index_1, int heap_index_2);
    void Update(int node, int cost);
private:
    int heap_size;
    int node_heap[GRAPH_SIZE + 1]; // A mapping from node id to heap index
    int heap_node[GRAPH_SIZE + 1]; // A mapping from heap index to node id
    int heap_cost[GRAPH_SIZE + 1]; // A mapping from heap index to cost to that node 
};

Heap::Heap()
{
    for (int i = 1; i <= GRAPH_SIZE; i++)
    {
        node_heap[i] = -1; // Indicate the node is not in the heap
    }

    int max = ~(1 << 31); 

    node_heap[1] = 1; // Node 1 is in heap position 1
    heap_node[1] = 1; // Heap position 1 is node 1
    heap_cost[1] = 0; // There is no cost to reach the source
    heap_size = 1;
}

int Heap::Count()
{
    return heap_size;
}

pair<int, int> Heap::DeleteMin()
{
    int min_node = this->heap_node[1];
    int min_cost = this->heap_cost[1];
    node_heap[min_node] = -2;

    if (heap_size > 1)
    {
        heap_node[1] = heap_node[heap_size];
        heap_cost[1] = heap_cost[heap_size];
        node_heap[heap_node[1]] = 1;

        heap_node[heap_size] = 10086;
        heap_cost[heap_size] = 10086;
        heap_size--;

        FixDown(1);
    }
    else
    {
        heap_size--;
    }
    return pair<int, int>(min_node, min_cost);
}

void Heap::FixDown(int index)
{
    int left_child = index * 2;
    int right_child = left_child + 1;
    if (right_child <= heap_size)
    {
        if (heap_cost[left_child] < heap_cost[right_child])
        {
            if (heap_cost[index] < heap_cost[left_child])
            {
                // we are good, index < left < right
            }
            else
            {
                SwapNodes(index, left_child);
                FixDown(left_child);
            }
        }
        else
        {
            if (heap_cost[index] < heap_cost[right_child])
            {
                // we are good, index < right < left 
            }
            else
            {                
                SwapNodes(index, right_child);
                FixDown(right_child);
            }
        }
    }
    else if (left_child <= heap_size)
    {
        if (heap_cost[index] < heap_cost[left_child])
        {
            // we are good, index < left < right
        }
        else
        {
            SwapNodes(index, left_child);
            FixDown(left_child);        }
    }
}

void Heap::FixUp(int index)
{
    if (index == 1)
    {
        return;
    }
    int parent = index / 2;
    if (heap_cost[parent] > heap_cost[index])
    {
        SwapNodes(parent, index);
        FixUp(parent);
    }
}

void Heap::SwapNodes(int heap1, int heap2)
{
    int node1 = heap_node[heap1];
    int node2 = heap_node[heap2];
    int cost1 = heap_cost[heap1];
    int cost2 = heap_cost[heap2];

    heap_cost[heap2] = cost1;
    heap_cost[heap1] = cost2;
    heap_node[heap1] = node2;
    heap_node[heap2] = node1;

    node_heap[node1] = heap2;
    node_heap[node2] = heap1;
}

void Heap::Update(int node, int cost)
{
    if (node_heap[node] < 0)
    {
        // Case 1: The node is not in the heap yet, so we do an insertion
        heap_size++;
        node_heap[node] = heap_size;
        heap_node[heap_size] = node;
        heap_cost[heap_size] = cost;
        FixUp(heap_size);
    }
    else
    {
        // Case 2: The node is already in the heap, let's check cost first
        int heap = node_heap[node];
        if (heap_cost[heap] > cost)
        {
            heap_cost[heap] = cost;
            FixUp(heap);
        }
    }
}

int main()
{
    // Step 1£º Read the input
    ifstream fin;
    fin.open("dijkstraData.txt");

    vector<vector<pair<int, int>>> graph;
    graph.resize(GRAPH_SIZE + 1);
    for (int i = 0; i < GRAPH_SIZE; i++)
    {
        int src;
        fin >> src;
        char c;
        while (true)
        {
            int dst;
            int len;
            fin >> dst;
            fin >> c;

            fin >> len;
            while (fin.peek() == 9)
            {
                c = fin.get();
            }

            graph[src].push_back(pair<int, int>(dst, len));
            if (fin.peek() == '\n')
            {
                break;
            }

        } 
    }
    fin.close();

    // Step 2£º Implements the Dijkstra's algorithm

    Heap heap;
    int cost[GRAPH_SIZE + 1];
    for (int i = 1; i <= GRAPH_SIZE; i++)
    {
        cost[i] = -1; // Indicating we do not know what is the cost to reach there
    }
    cost[1] = 0; // The cost to reach source is 0

    int l = 1;
    while (heap.Count() > 0)
    {
        pair<int, int> choice = heap.DeleteMin();

        int current_node = choice.first;
        int current_cost = choice.second;
        cost[current_node] = current_cost;

        for (unsigned int n = 0; n < graph[current_node].size(); n++)
        {
            int neighbor_node = graph[current_node][n].first;
            int neighbor_cost = graph[current_node][n].second + current_cost;
            if (cost[neighbor_node] == -1)
            {
                // We never reached neighbor node yet
                heap.Update(neighbor_node, neighbor_cost);
            }
        }
    }

    int required[] = {7,37,59,82,99,115,133,165,188,197};
    for (int i =0 ; i < _countof(required); i++)
    {
        cout << cost[required[i]] << ",";
    }
    cout << endl;

    return 0;
}
