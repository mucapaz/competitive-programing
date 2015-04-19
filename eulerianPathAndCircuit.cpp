
// Eulerian path and circuit - - spm lib
/*
In graph theory, a Eulerian trail (or Eulerian path) is a trail in a graph which visits every edge exactly once.
Similarly, an Eulerian circuit or Eulerian cycle or Eulerian tour is an Eulerian trail which starts and ends on the same vertex.   
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
