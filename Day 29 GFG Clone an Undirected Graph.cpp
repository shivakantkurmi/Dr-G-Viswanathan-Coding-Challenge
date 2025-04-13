/*
Clone an Undirected Graph
Difficulty: MediumAccuracy: 67.49%Submissions: 33K+Points: 4
Given a connected undirected graph represented by adjacency list, adjList[][] with n nodes, having a distinct label from 0 to n-1, where each adj[i] represents the list of vertices connected to vertex i.

Create a clone of the graph, where each node in the graph contains an integer val and an array (neighbors) of nodes, containing nodes that are adjacent to the current node.

class Node {
    val: integer
    neighbors: List[Node]
}
Your task is to complete the function cloneGraph( ) which takes a starting node of the graph as input and returns the copy of the given node as a reference to the cloned graph.

Note: If you return a correct copy of the given graph, then the driver code will print true; and if an incorrect copy is generated or when you return the original node, the driver code will print false.

Examples :

Input: n = 4, adjList[][] = [[1, 2], [0, 2], [0, 1, 3], [2]]
Output: true
Explanation: 

As the cloned graph is identical to the original one the driver code will print true.
*/

// struct Node {
//     int val;
//     vector<Node*> neighbors;
//     Node() {
//         val = 0;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val) {
//         val = _val;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val, vector<Node*> _neighbors) {
//         val = _val;
//         neighbors = _neighbors;
//     }
// };

class Solution {
  public:
    unordered_map<Node*, Node*> store;
    unordered_map<Node*, bool> visited;
    unordered_map<Node*, bool> vis2;
    
    void storeFun(Node* n){
        store[n] = new Node(n->val);
        visited[n] = true;
        for(auto z : n->neighbors){
            if(!visited[z])
                storeFun(z);
        }
        return;
    }
    
    void clone(Node* n){
        vis2[n] = true;
        for(auto z : n->neighbors){
            store[n]->neighbors.push_back(store[z]);
            if(!vis2[z])
                clone(z);
        }
        return;
    }
    
  
    Node* cloneGraph(Node* node) {
        // code here
        if(!node)
            return NULL;
        storeFun(node);
        clone(node);
        return store[node];
    }
};
