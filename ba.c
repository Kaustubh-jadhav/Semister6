// Banker's Algorithm
#include <stdio.h>
int main()
{
	// P0, P1, P2, P3, P4 are the Process names here

	int n, m, i, j, k;

    printf("\n Enter number of process :");
    scanf("%d",&n);
	//n = 5; // Number of processes
    printf("\n Enter number of available instance :");
    scanf("%d",&m);
    int alloc[n][m],max[n][m],avail[m];
	//m = 3; // Number of resources
    printf("\n -- allocation--\n");

    for ( i = 0; i < n; i++)
    {
        printf("\n Enter alloction for process P[%d]",i+1);
        for ( j = 0; j < m; j++)
        {
            scanf("%d",&alloc[i][j]);
        }
        printf("\n");
    }
    printf("\n -- Maximum need --\n");

     for ( i = 0; i < n; i++)
    {
        printf("\n Enter Maximum need for process P[%d]",i+1);
        for ( j = 0; j < m; j++)
        {
            scanf("%d",&max[i][j]);
        }
        printf("\n");
    }
    printf("\n -- Maximum need --\n");
    printf("\n -- Enter available resources Total resources - allocated resorces :");
    for ( i = 0; i < m; i++)
    {
        scanf("%d",&avail[i]);
    }
	int f[n], ans[n], ind = 0;
	for (k = 0; k < n; k++) {
		f[k] = 0;
	}
	int need[n][m];
    printf("\n -- need -- \n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
        {
			need[i][j] = max[i][j] - alloc[i][j];
            printf("%d\t",need[i][j]);
        }
        printf("\n");
	}
    printf("\n -- available -- \n");
	int y = 0;
	for (k = 0; k < 5; k++) {
		for (i = 0; i < n; i++) {
			if (f[i] == 0) {
				int flag = 0;
				for (j = 0; j < m; j++) {
					if (need[i][j] > avail[j]){
						flag = 1;
						break;
					}
				}
				if (flag == 0) {
					ans[ind++] = i;
					for (y = 0; y < m; y++)
                    {
						avail[y] += alloc[i][y];
                        printf("%d\t",avail[y]-alloc[i][y]);
                    }
                    printf("\n");
					f[i] = 1;
				}
			}
		}
	}
	int flag = 1;
	
	for(int i=0;i<n;i++)
	{
	if(f[i]==0)
	{
		flag=0;
		printf("The following system is not safe");
		break;
	}
	}
	
	if(flag==1)
	{
	printf("Following is the SAFE Sequence\n");
	for (i = 0; i < n - 1; i++)
		printf(" P%d ->", ans[i]);
	printf(" P%d", ans[n - 1]);
	}
	return (0);
}
