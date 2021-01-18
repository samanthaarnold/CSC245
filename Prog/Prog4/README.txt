Progject 4 README 

1) Client Algorithm-
    Methods to inculde-
        -Building the graph
        -Determine the index value a given string is within your array of strings.
        -Initialize your array(s).
        -Printing a given row in your summary table
        -Finding the minimum value among your current unmarked vertices
        -Determining whether a string entered by the user is a valid index

2) Outline of Graph Class-
    Graph is implimented as multi-dimensional array of weights. if there is no weight,
    it means no connection and should be a 0.

    Graph();          // constructor, default of 50 vertices.
    Graph(int maxV);  // parameterized constructor, maxV <= 50.
    ~Graph();         // destructor
    void MakeEmpty();
    bool IsEmpty() const;
    bool IsFull() const;
    void AddVertex(VertexType);
    void AddEdge(VertexType, VertexType, int);
    int WeightIs(VertexType, VertexType) const;
    void GetToVertices(VertexType, Queue<VertexType>&) const;
    void ClearMarks();
    void MarkVertex(VertexType);
    bool IsMarked(VertexType) const;

    private:
        int numVertices;
        int maxVertices;
        VertexType vertices[50];
        int edges[50][50];
        bool marks[50]; // marks[i] is mark for vertices[i].

        int IndexIs(VertexType vertex) const;

    Data structors used to build graph

3) Sample Input and Sample Output-
    Austin;Dallas;200
    Dallas;Austin;200
    Washington;Dallas;1300
    Washington;Atlanta;600
    Atlanta;Washington;600
    Atlanta;Houston;800
    Houston;Atlanta;800
    Denver;Chicago;1000
    Austin;Houston;160
    Chicago;Denver;1000
    Dallas;Chicago;900
    Dallas;Denver;780
    Denver;Atlanta;1400

    ^^^^^^^^^^^^^^^^^^^^^^^^^^^ DIJKSTRA'S ALGORITHM  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

    A Weighted Graph Has Been Built for These 7 Cities : 

            Atlanta                 Austin                  Chicago
            Dallas                  Denver                  Houston
            Washington

    Please input your starting vertex: Dallas
    ----------------------------------------------------------------------------------
                Vertex          Distance            Previous

                Dallas                   0                 N/A
                Austin                 200              Dallas
                Houston                 360              Austin
                Denver                 780              Dallas
                Chicago                 900              Dallas
                Atlanta                2180              Denver
            Washington                2780             Atlanta

4) Dijkstra's Algorithm
    1. Determine how many vertices have been input. Assign this to an integer.
    2. Declare and initialize four parallel arrays.
        -The strings representing the different vertices
        -The booleans to mark a vertex once the weight of a vertex has been choosen as the
        smallest amng the current unmarked ones. All values should start off as false.
        -The integers represting the total distance used in reaching this vertex. All values
        should start off with a value like INT_MAX so they will not be considered among 
        the current smallest of those already initialized.
        -The string representing the previous vertex visited before reaching a vertex.
    3. Determine the index within your local container of vertices where the starting vertex
    is located. Mark it as visited and flush its distance to 0. Print out the data corresponding
    to this index with "N/A" used as the previous vertex.
    4. Determine the vertices which are adjacent to your current vertex using the GetToVertices 
    operation.
    5. Now, for each vertex that is adjacent to your current vertex, determine the weight value 
    that exists between each one and your current vertex. If an adjacent vertex is currently 
    unmarked and its distance value in the table is greater than the sum of the weight value plus
    the distance of the last marked vertex (your current vertex), reset its distance value to 
    this smaller sum. Store the name of the current vertex as the previous vertex of each adjacent
    vertex.
    6. Find the minimum distance value amoung all unmarked vertices, and set the vertex that corresponds
    to this minimum distance as your new current vertex. Mark this vertex.
    7. Print out the data corresponding to your current marked vertex. 
    8. Repeat the previous four steps above until all your vertices have been marked.  