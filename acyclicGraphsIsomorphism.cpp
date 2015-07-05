
#include <bits/stdc++.h> 
#include <bitset> 
using namespace std;
// priority_queue< ii, vector<ii>, greater<ii> > pq;  pq.push pq.pop pq.top;
// priority_queue por default ordena decrescente
 
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define NVI -1
#define db if(0)
#define pb push_back
#define EPS 1e-9
#define fst first
#define scd second
#define mp make_pair
#define fr(a,b,c) for(int a=b;a<c;a++)

typedef unsigned long long ull;
typedef long long ll;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector<vector<int > > vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<vector<pair<int, int> > > ve;
typedef pair<double,double> dd;

vector<vector<int> > adj[2];
vector<vector<int> > grau[2];
int n;
bool funcao(const vector<int> &v1, const vector<int> &v2){
	if(v1.size() != v2.size()) return v1.size() > v2.size();
	for(int x=0;x<v1.size();x++){
		if(v2[x] != v1[x]) return v1[x] > v2[x];
	}
	
	return false;
}
int main(void){	
	
	while(scanf("%d",&n) !=EOF){
		int a1,a2;
		adj[0].clear();adj[1].clear();
		adj[0].resize(n,vi());adj[1].resize(n,vi());
		
		grau[0].clear();grau[1].clear();
		grau[0].resize(n,vi());grau[1].resize(n,vi());
		
		for(int y=0;y<2;y++) {for(int x=0;x<n-1;x++){
			scanf("%d%d",&a1,&a2);
			a1--;a2--;
			adj[y][a1].pb(a2);
			adj[y][a2].pb(a1);
		}
		}
		for(int k=0;k<2;k++){
			for(int x=0;x<n;x++){
				for(int y=0;y<adj[k][x].size();y++){
					grau[k][x].pb(adj[k][adj[k][x][y]].size());
				}
				sort(grau[k][x].begin(), grau[k][x].end());
			}
		}
		sort(grau[0].begin(), grau[0].end(),funcao);
		sort(grau[1].begin(), grau[1].end(),funcao);
		
		bool ok = true;
		
		if(grau[0].size() != grau[1].size()) ok = false;
		
		for(int x=0;x<grau[0].size();x++){
			if(!ok) break;
			if(grau[0][x].size() != grau[1][x].size()) ok = false;
			if(!ok) break;
			for(int y=0;y<grau[0][x].size();y++){
				if(grau[0][x][y] != grau[1][x][y]) {
					ok = false;
				}
			}
			if(!ok)break;
		}
		
		if(ok)cout<<"S\n";
		else cout<<"N\n";
		
	}
	
	
	return 0;
}







