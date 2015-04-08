// Convex Hull  - Monotone chain algorithm - spm lib

struct point{
	int x,y;
	//point(double x1,double y1){x = x1; y = y1;};

	bool operator <(const point& p) const{
		return x < p.x || (x == p.x && y < p.y);
	}	
};

struct vec{
	double x,y;
	vec(double x1, double y1){x=x1;y=y1;};
};
vec toVec(point a, point b){
	return vec(b.x-a.x,b.y-a.y);
}
double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }

void ps(vector<point> in){
	for(int x=0;x<in.size();x++){
		printf("(%d  %d) ",in[x].x,in[x].y);
	}printf("\n");	
	
}

vector<point> pre(vector<point> in){
	point fst;
	fst.x = in[0].x;	
	fst.y = in[0].y;
	vector<point> ret;
	ret.pb(fst);
	for(int x=1;x<in.size();x++){
		if(!(in[x].x == fst.x && in[x].y == fst.y)){
			fst = in[x];
			ret.pb(in[x]);
		}
	}
	return ret;
}

vector<point> ch(vector<point> in){
	sort(in.begin(),in.end());
	in = pre(in);
	int n = in.size(), k = 0;
	vector<point> r(2*n);	

	for(int i=0;i<n;i++){
		while(k>=2 && cross(toVec(r[k-2],r[k-1]),toVec(r[k-2],in[i])) < 0) k--;
		r[k++] = in[i];	
	}
	
	for(int i = n-2, j = k + 1;i>=0;i--){
		while(k >=j && cross(toVec(r[k-2],r[k-1]),toVec(r[k-1],in[i])) < 0) k--;
		r[k++] = in[i];
	}
	
	r.resize(k);
	return r;
}



// end Convex hull
