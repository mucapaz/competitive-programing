// All pair shortest paths  - Floyd Warshal algorithm - spm lib

memset(ma,INF,sizeof ma);
for(int k=0;k<v;k++) ma[k][k] = 0;	
	for(int k=0;k<v;k++)
		for(int i=0;i<v;i++)
			for(int j=0;j<v;j++) ma[i][j] = min(ma[i][j],ma[i][k] + ma[k][j]);
