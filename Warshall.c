#define min(a,b) (a<=b?a:b)

void Warshall(int ** tab, int sommets)
{
	int i,j,k;
	int ** cpy_tab = tab;
	for(k = 0; k < sommets; k++)
	   for(i = 0; i < sommets; i++)
	      for(j = 0; j < sommets; j++)
	         cpy_tab[i][j] = cpy_tab[i][j] || (cpy_tab[i][k] && cpy_tab[k][j]);
	
	afficherMatrice(cpy_tab,sommets);
}
void FloydWarshall(int ** tab, int sommets)
{
	int i,j,k,x;
	int ** cpy_tab = tab;
	for(i = 0; i < sommets; i++)
	   for(j = 0; j < sommets; j++)
	   	if(cpy_tab[i][j] == 0 )
	   	{
	   		cpy_tab[i][j] = -1;
	   		if ( i == j )
	   		cpy_tab[i][j] = 0;
	   	}  	
	for(k = 0; k < sommets; k++)
	   for(i = 0; i < sommets; i++)
	      for(j = 0; j < sommets; j++)
	      {
		      
		    if(cpy_tab[i][k] !=-1 &&  cpy_tab[k][j]!=-1)
		    {
			    printf("[%i][%i] = %i || [%i][%i] + [%i][%i] = %i \n",i,j,cpy_tab[i][j],i,k,k,j, (cpy_tab[i][k]+cpy_tab[k][j]) );
				cpy_tab[i][j] = min(cpy_tab[i][j], (cpy_tab[i][k]+cpy_tab[k][j]) );
				if(cpy_tab[i][j]==-1)
			    	cpy_tab[i][j] = (cpy_tab[i][k]+cpy_tab[k][j]);
	      	}
	      }
	for(i = 0; i  <sommets; i++)
	   for(j = 0; j < sommets; j++)
	   	if(cpy_tab[i][j] == -1 )
	   		cpy_tab[i][j] = 0;
	afficherMatrice(cpy_tab,sommets);   		

}