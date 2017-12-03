#include "graphtypes.h"
#include "error.h"
using namespace std;

void p4() {
    // create the graph
    SimpleGraph airline;
    initiateGraph(airline);
    addNode(airline, "Atlanta");
    addNode(airline, "Boston");
    addNode(airline, "Chicago");
    addNode(airline, "Dallas");
    addNode(airline, "Denver");
    addNode(airline, "Los Angeles");
    addNode(airline, "New York");
    addNode(airline, "Portland");
    addNode(airline, "San Francisco");
    addNode(airline, "Seattle");
    addArc(airline, "Atlanta", "Chicago", 599);
    addArc(airline, "Atlanta", "Dallas", 725);
    addArc(airline, "Atlanta", "New York", 756);
    addArc(airline, "Boston", "New York", 191);
    addArc(airline, "Boston", "Seattle", 2489);
    addArc(airline, "Chicago", "Denver", 907);
    addArc(airline, "Dallas", "Denver", 650);
    addArc(airline, "Dallas", "Los Angeles", 1240);
    addArc(airline, "Dallas", "San Francisco", 1468);
    addArc(airline, "Denver", "San Francisco", 954);
    addArc(airline, "Portland", "San Francisco", 550);
    addArc(airline, "Portland", "Seattle", 130);

    writeGraph(airline, cout);
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
    return *node;
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
    return *arc;
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

}

/*
* Function: pathExistsDFS
* Usage: pathExistsDFS(Node *n1, Node *n2);
* ------------------------------
* Find all path from n1 to n2 using Deap-First search
*/

bool pathExistsDFS(Node *n1, Node *n2) {
    Set<Node *> visited;

}

bool printAllPathsFound(Node *n1, Node *n2) {

}

/*
* Function: printAllPathsFound
* Usage: printAllPathsFound(Node *n1, Node *n2);
* ------------------------------
* Print all paths found from n1 to n2
*/
