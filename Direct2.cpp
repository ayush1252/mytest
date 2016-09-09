#include <stdio.h>
#include <string.h>
#include<iostream>


using namespace std;
//you may add more methods here

/* Using int instead of bool. Return 0 to signify false, and 1 to signify true. */

int findWord(char grid[128][128], int m, int n, char word[32],int x,int y, int point,int len)
{
	if(point==len)
	return 1;
	else
	{
		 if(x<0||x>m||y<0||y>n)
		 return 0;
		else if(grid[x][y]!=word[point])
		return 0;
		else
		{
			int x=0;
			x=findWord(grid,m,n,word,x+1,y,point+1,len);
			if(x==1)
			return 1;
			x=findWord(grid,m,n,word,x+1,y+1,point+1,len);
			if(x==1)
			return 1;
			x=findWord(grid,m,n,word,x,y+1,point+1,len);
			if(x==1)
			return 1;
			x=findWord(grid,m,n,word,x,y-1,point+1,len);
			if(x==1)
			return 1;
			x=findWord(grid,m,n,word,x-1,y,point+1,len);
			if(x==1)
			return 1;
			x=findWord(grid,m,n,word,x-1,y-1,point+1,len);
			if(x==1)
			return 1;
			x=findWord(grid,m,n,word,x+1,y-1,point+1,len);
			if(x==1)
			return 1;
			x=findWord(grid,m,n,word,x-1,y+1,point+1,len);
			if(x==1)
			return 1;
			
		}
	
	}
	return 0;
}

int findWordInAGrid(char grid[128][128], int m, int n, char word[32]) {
    
    int len=strlen(word);
//    int flag=0;
    for(int i=0; i<m; i++)
	for(int j=0; j<n; j++) 
	{
	 
	  int x=findWord(grid,m,n,word,i,j,0,len);
	  if(x==1)
	  {
//    cout<<i<<j<<endl;	
 	   return x;
      }
    
  }
    
    return 0;
}

int main() {
    int m, n;
    char grid[128][128];
    int k;
    char word[32];
    int i, j;

    scanf("%d%d",&m,&n);
    for(i=0;i<m;i++) scanf("%s",grid[i]);
    scanf("%d",&k);
    while(k--) {
        scanf("%s",word);
        printf("%s\n",findWordInAGrid(grid, m, n, word) ? "true" : "false");
    }
    return 0;
}

