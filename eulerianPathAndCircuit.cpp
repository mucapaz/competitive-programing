
// Eulerian path and circuit - - spm lib
/*
In graph theory, a Eulerian trail (or Eulerian path) is a trail in a graph which visits every edge exactly once.
Similarly, an Eulerian circuit or Eulerian cycle or Eulerian tour is an Eulerian trail which starts and ends on the same vertex.   

An undirected graph has a closed Euler tour iff it is connected and each vertex has an even degree.

An undirected graph has an open Euler tour iff it is connected, and each vertex, except for exactly two vertices, has an even degree. The two vertices of odd degree have to be the endpoints of the tour.

A directed graph has a closed Euler tour iff it is strongly connected and the in-degree of each vertex is equal to its out-degree.

Similarly, a directed graph has an open Euler tour iff for each vertex the difference between 
its in-degree and out-degree is 0, except for two vertices, where one has difference +1 
(the start of the tour) and the other has difference -1 (the end of the tour) and, if you add
an edge from the end to the start, the graph is strongly connected.

*/


void eu( int u ){
        for(int j=0;j< (int) adj[u].size();j++){
                if(adj[u][j].second){
                        adj[u][j].second = 0;
                        for(int k =0; k< (int)adj[adj[u][j].first].size();k++ ){
                               
                                if(adj[adj[u][j].first][k].first == u  && adj[adj[u][j].first][k].second){
                                        adj[adj[u][j].first][k].second = 0;    
                                        break;
                                }      
                        }
                        eu(adj[u][j].first);
                }      
        }
        vec.pb(u);
}
