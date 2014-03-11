
/*--- Graph.h -------------------------------------------------------------
                  Header file for Graph Class Template
 -------------------------------------------------------------------------*/

#include <vector>
#include <iostream>

template <typename DataType>
class Graph
{
 public:
  /***** Function Members *****/
  DataType data(int k) const;
  /*-----------------------------------------------------------------------
    Retrieve data value in a given vertex.

    Precondition:  k is the number of a vertex.
    Postcondition: Data value stored in vertex #k is returned.
   -----------------------------------------------------------------------*/

  void read(istream & in, int numVertices, int numEdges);
  /*-----------------------------------------------------------------------
    Input operation.

    Precondition:  istream in is open; numVertices and numEdges are the
        number of vertices and edges in the graph, respectively.
    Postcondition: The vertices and edges of the graph have been read 
        from in and the edge-list representation of this graph stored
        in myEdgeLists.
   -----------------------------------------------------------------------*/

  void depthFirstSearch(int start, vector<bool> & unvisited);
  /*-----------------------------------------------------------------------
    Depth first search of graph via depthFirstSearchAux(), starting
    at vertex start.

    Precondition:  start is a vertex.
    Postcondition: Graph has been depth-first searched from start.
    ----------------------------------------------------------------------*/

  bool isConnected();
  /*-----------------------------------------------------------------------
    Check if graph is connected.

    Precondition:  None.
    Postcondition: True is returned if graph is connected, false if not.
   -----------------------------------------------------------------------*/

 private:
  /***** Edge Nodes *****/
   class EdgeNode
   {
    public:
     int vertex[3];         // Use 1 and 2 for indices
     EdgeNode * link[3];    //   as is customary
   }; // end of EdgeNode class

   typedef EdgeNode * EdgePointer;

  /***** "Head nodes" of edge lists *****/
   class VertexInfo
   { 
    public:
     DataType data;         // data value in vertex
     EdgePointer first;     // pointer to first edge node
   }; // end of VertexInfo class

  /***** Data Members *****/
   vector<VertexInfo> myEdgeLists;

  /***** Private Function Member *****/
   void depthFirstSearchAux(int start, vector<bool> & unvisited);
   /*-----------------------------------------------------------------------
     Recursive depth first search of graph, starting at vertex start.

     Precondition:  start is a vertex; unvisited[i] is true if vertex i has
         not yet been visited, and is false otherwise.
     Postcondition: Vector unvisited has been updated.
    ----------------------------------------------------------------------*/

}; // end of Graph class template declaration

//--- Definition of data()
template <typename DataType>
inline DataType Graph<DataType>::data(int k) const
{
  return myEdgeLists[k].data;
}

//--- Definition of read()
template <typename DataType>
void Graph<DataType>::read(istream & in, int numVertices, int numEdges)
{
  Graph<DataType>::VertexInfo vi;

  // Put a garbage 0-th value so indices start with 1, as is customary
  myEdgeLists.push_back(vi); 

  // Create "head nodes"
  cout << "Enter label of vertex:\n";
  for (int i = 1; i <= numVertices; i++)
  {
    cout << "  " << i << ": ";
    in >> vi.data;
    vi.first = 0;
    myEdgeLists.push_back(vi);
  }

  int endpoint;       // endpoint of an edge   
  // Create edge lists
  cout << "Enter endpoints of edge\n";
  for (int i = 1; i <= numEdges; i++)
  {
    cout << "  " << i << ": ";
    EdgePointer newPtr = new EdgeNode;
    for (int j = 1; j <= 2; j++)
    {
      in >> endpoint;
      // insert new edge node at beginning
      // of edge list for endpoint
      newPtr->vertex[j] = endpoint;
      newPtr->link[j] = myEdgeLists[endpoint].first;
      myEdgeLists[endpoint].first = newPtr;
    }
  }
}

/*--- Utility function to check if all nodes have been visited.
   Precondition:  unvisited tells which nodes have not been 
         visited
   Postcondition: true is returned if all vertices, false if not.
  ---------------------------------------------------------------*/
bool anyLeft(const vector<bool> & unvisited)
{
  for (int i = 1; i < unvisited.size(); i++)
    if (unvisited[i])
      return true;
  return false;
}

//-- Definition of depthFirstSearch()
template <typename DataType>
void Graph<DataType>::depthFirstSearch(int start, vector<bool> & unvisited)
{
  // --- Insert statements here to process visited node
  // Mark start visited, and initialize pointer 
  // to its first edge node to begin DFS.
  unvisited[start] = false; 

  Graph<DataType>::EdgePointer ptr = myEdgeLists[start].first;
  while(anyLeft(unvisited) && ptr != 0)
  {
    // Determine which end of edge is start
    int startEnd = 1,   
        otherEnd = 2;
    if (ptr->vertex[1] != start)
    { startEnd = 2; otherEnd = 1;}

    // Start new (recursive) DFS from vertex at other end
    // if it hasn't already been visited
    int newStart = ptr->vertex[otherEnd];
    if (unvisited[newStart])
      depthFirstSearch(newStart, unvisited);
    // Move to next edge node
    ptr = ptr->link[startEnd];
  }
}

//-- Definition of isConnected()
template <typename DataType>
inline bool Graph<DataType>::isConnected()
{
  vector<bool> unvisited(myEdgeLists.size(), true);
  depthFirstSearch(1, unvisited);
  return !anyLeft(unvisited);
}
