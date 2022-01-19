#include <stdio.h>
int main()
{
	int proc, res, i, j, k;
	printf("Enter the number of processes and resources\n");
	scanf("%d %d",&proc,&res);
	int alloc[proc][res] ;
    printf("Enter Allocation Matrix:\n");
    for(i=0;i<proc;i++)
        for(j=0;j<res;j++)
            scanf("%d",&alloc[i][j]);
	int max[proc][res];
	int need[proc][res];
    printf("Enter Max Claim Matrix:\n");
    for(i=0;i<proc;i++)
        for(j=0;j<res;j++)
            {
                scanf("%d",&max[i][j]);
                need[i][j] = max[i][j] - alloc[i][j];
            }
	int avail[res];
    printf("Enter Available Resource:\n");
    for(j=0;j<res;j++)
        scanf("%d",&avail[j]);
	int f[proc], ans[proc], ind = 0;
	for (k = 0; k < proc; k++) {
		f[k] = 0;
	}
	int y = 0;
	for (k = 0; k < proc; k++) {
		for (i = 0; i < proc; i++) {
			if (f[i] == 0) {

				int flag = 0;
				for (j = 0; j < res; j++) {
					if (need[i][j] > avail[j]){
						flag = 1;
						break;
					}
				}
				if (flag == 0) {
					ans[ind++] = i;
					for (y = 0; y < res; y++)
						avail[y] += alloc[i][y];
					f[i] = 1;
				}
			}
		}
	}
	for(i=0;i<proc;i++)
    {
        if(f[i]!=1)
        {
            printf("Process %d cannot be resolved.\nDeadlock will occur.",i+1);
            return 0;
        }
    }
	printf("The Safe Sequence is:\n");
	for (i = 0; i < proc - 1; i++)
		printf(" P%d ->", ans[i]+1);
	printf(" P%d", ans[proc - 1]+1);
	return (0);
}
