/*
 * File: p4.cpp
 * --------------------------
 * This is the answer to question 4 of assignmet 3 of CSC 3002 at CUHKSZ
 * Done by Shuqian Ye, 115010269
 */

#include "graphtypes.h"
#include "error.h"
#include "queue.h"

using namespace std;

//Prototypes
void initiateGraph(SimpleGraph & g);
Node *addNode(SimpleGraph & g, string name);
Arc *addArc(SimpleGraph & g, Node *n1, Node *n2, double cost);
void writeGraph(const SimpleGraph & g, ostream & out);
void printAllPathsFound(Node *n1, Node *n2);
void pathExistsDFS(Node *destination, vector<vector<Node *>> *paths, vector<Node *> visited);
vector<vector<Node *>> pathExistsBFS(Node *n1, Node *n2);

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

    cout << "The graph:" << endl;
    writeGraph(airline, cout);

    // get input of airports
    cout << endl;
    cout << "The departure airport: ";
    string departure;
    getline(cin, departure);
    cout << endl << "The destination airport: ";
    string destination;
    getline(cin, destination);
    cout << endl;

    // find the node with the matched name and find path
    Node *n1;
    Node *n2;
    bool found = false;
    for (Node *node : airline.nodes) {
        if (node->name == departure) {
            n1 = node;
            found = true;
            break;
        }
    }
    if (!found) error("Cannot find the matched departure airport");

    found = false;
    for (Node *node : airline.nodes) {
        if (node->name == destination) {
            n2 = node;
            found = true;
            break;
        }
    }
    if (!found) error("Cannot find the matched departure airport");
    printAllPathsFound(n1, n2);
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
* Function: printAllPathsFound
* Usage: printAllPathsFound(Node *n1, Node *n2);
* ------------------------------
* Print all paths found from n1 to n2
*/

void printAllPathsFound(Node *n1, Node *n2) {
    //DFS
    vector<vector<Node*>> paths;
    vector<Node *> visited;
    visited.push_back(n1);
    pathExistsDFS(n2, &paths, visited);

    // print result
    int count = paths.size();
    if (count == 0) {
        cout << "There is no paths from " << n1->name
             << " to " << n2->name << " finding by using Deep-first Search!" << endl;
    } else if (count > 1) {
        cout << "There are " << count << " paths "
             << "from " << n1->name
             << " to " << n2->name << " finding by using Deep-first Search:" << endl;
        for (int i = 0; i < count; i++) {
            cout << i+1 << ".";
            //print path
            Vector<Node *> path = paths.at(i);
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
             << " to " << n2->name << " finding by using Deep-first Search:" << endl;
        //print path
        Vector<Node *> path = paths.at(0);
        for (int j = 0; j < path.size(); j++) {
            cout << path.get(j)->name;
            if (j < (path.size() - 1)) {
                cout << " -> ";
            }
        }
        cout << endl;
    }

    cout << endl;

    //BFS
    paths.clear();
    paths = pathExistsBFS(n1, n2);

    // print result
    count = paths.size();
    if (count == 0) {
        cout << "There is no paths from " << n1->name
             << " to " << n2->name << " finding by using Breadth-first Search!" << endl;
    } else if (count > 1) {
        cout << "There are " << count << " paths "
             << "from " << n1->name
             << " to " << n2->name << " finding by using Breadth-first Search:" << endl;
        for (int i = 0; i < count; i++) {
            cout << i+1 << ".";
            //print path
            Vector<Node *> path = paths.at(i);
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
             << " to " << n2->name << " finding by using Breadth-first Search:" << endl;
        //print path
        Vector<Node *> path = paths.at(0);
        for (int j = 0; j < path.size(); j++) {
            cout << path.get(j)->name;
            if (j < (path.size() - 1)) {
                cout << " -> ";
            }
        }
        cout << endl;
    }
}

/*
* Function: pathExistsBFS
* Usage: vector<vector<Node *>> pathExistsBFS(Node *n1, Node *n2);
* -----------------------------------------------------------------------------------------------
* Find all paths from the first node in visited to destination using Breadth-First search
*/

vector<vector<Node *>> pathExistsBFS(Node *n1, Node *n2) {
    vector<vector<Node *>> paths;
    vector<Node *> begin;
    begin.push_back(n1);
    paths.push_back(begin);
    bool finished = false;
    Node* lastNode;
    int possible; // count the possible next node
    int indexOrigin; // the index of the original path
    bool pass;
    vector<bool> deleted;
    deleted.push_back(false); // mark the path deleted or not
    int loopTimes;
    bool pushDelete; //used to push_bkack into deleted

    while (!finished) {
        finished = true;
        loopTimes = paths.size();
        for (int i = 0; i < loopTimes; i++) {
            if (!deleted.at(i)) {
                for (int j = 0; j < paths.size(); j++) {
                    if (!deleted.at(j)) {
                        indexOrigin = j;
                        deleted.at(indexOrigin) = true; // delete the origin path
                        break;
                    }
                }
                lastNode = paths.at(indexOrigin).back();
                possible = lastNode->arcs.size();
                for (Arc *arc : lastNode->arcs) {
                    //count++;
                    pass = false;
                    for (Node *visited : paths.at(indexOrigin)) { // search all possible nodes
                        if (visited == arc->finish) { // if the node should be added has been in the path
                            pass = true;
                            break;
                        }
                    }
                    if (!pass) {
                        paths.push_back(paths.at(indexOrigin)); // copy the origin path
                        paths.back().push_back(arc->finish); // add the new node
                        pushDelete = false;
                        deleted.push_back(pushDelete);
                        finished = false;
                    }
                }

            }
        }
    }

    vector<vector<Node *>> successPaths; // filter out the successful paths
    for (vector<Node *> successPath : paths) {
        if (successPath.back() == n2){
            successPaths.push_back(successPath);
        }
    }
    return successPaths;
}

/*
* Function: pathExistsDFS
* Usage: pathExistsDFS(Node *destination, vector<vector<Node *>> *paths, vector<Node *> visited);
* -----------------------------------------------------------------------------------------------
* Find all paths from the first node in visited to destination using Deap-First search
*/

void pathExistsDFS(Node *destination, vector<vector<Node *>> *paths, vector<Node *> visited) {
    Node *current = visited.at(visited.size() - 1);
    for (Arc *arc : (current->arcs)) {
        Node *last = visited.at(visited.size() - 1);

        // check whea the node is visited
        if (last->name != current->name) visited.pop_back();
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
                vector<Node *> path = visited;
                paths->push_back(path);
            } else {
                visited.push_back(next);
                pathExistsDFS(destination, paths, visited);

            }
        } // if the next node is not visted, continue finding path


    }
}
