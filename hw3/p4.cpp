/*
 * File: p4.cpp
 * --------------------------
 * This is the answer to question 4 of assignmet 3 of CSC 3002 at CUHKSZ
 * Done by Shuqian Ye, 115010269
 */

#include "graphtypes.h"
#include "error.h"
#include "queue.h"
#include "stack.h"

using namespace std;

//Prototypes
void initiateGraph(SimpleGraph & g);
Node *addNode(SimpleGraph & g, string name);
Arc *addArc(SimpleGraph & g, Node *n1, Node *n2, double cost);
void writeGraph(const SimpleGraph & g, ostream & out);
void printAllPathsFound(Node *n1, Node *n2, SimpleGraph & g);
bool pathExistsBFS(Node *n1, Node *n2);
bool pathExistsDFS(Node *n1, Node *n2);
void findPaths(Node *destination, SimpleGraph & airline, Vector<Vector<Node *>> *paths, Vector<Node *> visited);

void p4() {
    // create the graph
    SimpleGraph airline;
    initiateGraph(airline);
    Node *ATL = addNode(airline, "Atlanta");
    Node *BOS = addNode(airline, "Boston");
    Node *ORD = addNode(airline, "Chicago");
    Node *DFW = addNode(airline, "Dallas");
    Node *DEN = addNode(airline, "Denver");
    Node *LAX = addNode(airline, "Los Angeles");
    Node *JFK = addNode(airline, "New York");
    Node *PDX = addNode(airline, "Portland");
    Node *SFO = addNode(airline, "San Francisco");
    Node *SEA = addNode(airline, "Seattle");
    Node *HNL = addNode(airline, "Honolulu");

    // both dirction
    addArc(airline, ATL, ORD, 599);
    addArc(airline, ATL, DFW, 725);
    addArc(airline, ATL, JFK, 756);
    addArc(airline, BOS, JFK, 191);
    addArc(airline, BOS, SEA, 2489);
    addArc(airline, ORD, DEN, 907);
    addArc(airline, DFW, DEN, 650);
    addArc(airline, DFW, LAX, 1240);
    addArc(airline, DFW, SFO, 1468);
    addArc(airline, DEN, SFO, 954);
    addArc(airline, PDX, SFO, 550);
    addArc(airline, PDX, SEA, 130);

    addArc(airline, ORD, ATL, 599);
    addArc(airline, DFW, ATL, 725);
    addArc(airline, JFK, ATL, 756);
    addArc(airline, JFK, BOS, 191);
    addArc(airline, SEA, BOS, 2489);
    addArc(airline, DEN, ORD, 907);
    addArc(airline, DEN, DFW, 650);
    addArc(airline, LAX, DFW, 1240);
    addArc(airline, SFO, DFW, 1468);
    addArc(airline, SFO, DEN, 954);
    addArc(airline, SFO, PDX, 550);
    addArc(airline, SEA, PDX, 130);

    writeGraph(airline, cout);

    cout << endl << "path exists from Honolulu to Portland using Deep-first search: "
         << pathExistsDFS(HNL, PDX)<< endl;
    cout << "path exists from Honolulu to Portland using Breadth-first search: "
         << pathExistsBFS(HNL, PDX)<< endl;
    cout << "path exists from Denver to Portland using Deep-first search: "
         << pathExistsDFS(DEN, PDX)<< endl;
    cout << "path exists from Denver to Portland using Breadth-first search: "
         << pathExistsBFS(DEN, PDX)<< endl;

    cout << endl;
    //printAllPathsFound(HNL, PDX, airline);
    //printAllPathsFound(LAX, DFW, airline);
    //printAllPathsFound(DFW, LAX, airline);
    printAllPathsFound(JFK, BOS, airline);
}

/*
* Function: addNode
* Usage: addNode(g, name);
* ------------------------
* Adds a new node with the specified name to the graph.
*/

Node *addNode(SimpleGraph & g, string name) {
    Node *node = new Node;
    node->name = name;
    g.nodes.add(node);
    g.nodeMap[name] = node;
    return node;
}

/*
* Function: addArc
* Usage: addArc(g, n1, n2, cost);
* -------------------------------
* Adds a directed arc to the graph connecting n1 to n2.
*/

Arc *addArc(SimpleGraph & g, Node *n1, Node *n2, double cost) {
    Arc *arc = new Arc;
    arc->start = n1;
    arc->finish = n2;
    arc->cost = cost;
    g.arcs.add(arc);
    n1->arcs.add(arc);
    return arc;
}

/*
* Function: initiateGraph
* Usage: initiateGraph(g);
* -------------------------------
* Initiate all the data in the graph g.
*/

void initiateGraph(SimpleGraph &g) {
    g.nodes.clear();
    g.arcs.clear();
    g.nodeMap.clear();
}

/*
* Function: writeGraph
* Usage: writeGraph(g, outfile);
* ------------------------------
* Writes out a simple description of the graph g to the output stream.
*/

void writeGraph(const SimpleGraph & g, ostream & out) {
    for (Node *node : g.nodes) {
        out << node->name << " -> ";
        bool first = true;
        for (Arc *arc : node->arcs) {
            if (!first) out << ", ";
            out << arc->finish->name;
            first = false;
        }
        out << endl;
    }
}

/*
* Function: pathExistsBFS
* Usage: pathExistsBFS(Node *n1, Node *n2);
* ------------------------------
* Find all path from n1 to n2 using Breadth-First search
*/

bool pathExistsBFS(Node *n1, Node *n2) {
    Set<Node *> visited;
    Queue<Node *> queue;
    queue.enqueue(n1);
    while (!queue.isEmpty()) {
       Node *node = queue.dequeue();
       if (node == n2) return true;
       if (!visited.contains(node)) {
          visited.add(node);
          for (Arc *arc : node->arcs) {
             queue.enqueue(arc->finish);
          }
       }
    }
    return false;
}

/*
* Function: pathExistsDFS
* Usage: pathExistsDFS(Node *n1, Node *n2);
* ------------------------------
* Find all path from n1 to n2 using Deap-First search
*/

bool pathExistsDFS(Node *n1, Node *n2) {
    Set<Node *> visited;
    Stack<Node *> stack;
    stack.push(n1);
    while (!stack.isEmpty()) {
        Node *current = stack.pop();
        if (current == n2) return true;
        if (!visited.contains(current)) {
            visited.add(current);
            for (Arc *arc : current->arcs) {
                stack.push(arc->finish);
            }
        }
    }
    return false;
}

/*
* Function: printAllPathsFound
* Usage: printAllPathsFound(Node *n1, Node *n2);
* ------------------------------
* Print all paths found from n1 to n2
*/

void printAllPathsFound(Node *n1, Node *n2, SimpleGraph & airline) {
    Vector<Vector<Node*>> paths;
    Vector<Node *> visited;
    visited.push_back(n1);
    findPaths(n2, airline, &paths, visited);

    // print result
    int count = paths.size();
    if (count == 0) {
        cout << "There is no paths from " << n1->name
             << " to " << n2->name << "!" << endl;
    } else if (count > 1) {
        cout << "There is " << count << " paths "
             << "from " << n1->name
             << " to " << n2->name << ":" << endl;
        for (int i = 0; i < count; i++) {
            cout << i+1 << ".";
            //print path
            Vector<Node *> path = paths.get(i);
            for (int j = 0; j < path.size(); j++) {
                cout << path.get(j)->name;
                if (j < (path.size() - 1)) {
                    cout << " -> ";
                }
            }
            cout << endl;
        }
    } else {
        cout << "There is 1 path " << "from " << n1->name
             << " to " << n2->name << ":" << endl;
        //print path
        Vector<Node *> path = paths.get(0);
        for (int j = 0; j < path.size(); j++) {
            cout << path.get(j)->name;
            if (j < (path.size() - 1)) {
                cout << " -> ";
            }
        }
        cout << endl;
    }
}

void findPaths(Node *destination, SimpleGraph & airline, Vector<Vector<Node *>> *paths, Vector<Node *> visited) {
    Node *current = visited.get(visited.size() - 1);
    for (Arc *arc : (current->arcs)) {

        Node *next = arc->finish;
        bool beenVisited = false;
        for (Node *visitedNode : visited) {
            if (visitedNode == next) {
                beenVisited = true;
                continue;
            }
        }
        if (!beenVisited) {
            if (next == destination) {
                visited.push_back(destination);
                Vector<Node *> path = visited;
                cout << "======" << endl;
                paths->push_back(path);
            } else {

                visited.push_back(next);
                //test
//                        for (int j = 0; j < visited.size(); j++) {
//                            cout << visited.get(j)->name;
//                            if (j < (visited.size() - 1)) {
//                                cout << " -> ";
//                            }
//                        }
//                        cout << endl;

                findPaths(destination, airline, paths, visited);

            }
        } // if the next node is not visted, continue finding path


    }
}
