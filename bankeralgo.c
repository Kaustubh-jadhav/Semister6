#include<stdio.h>
#define MA 10
int main(){
    int n ,i ,p[MA],m,alloc[MA][MA],j,max[MA][MA],avail[MA],need[MA][MA];
    char res;
    printf("\n Enter total number of process :");
    scanf("%d",&n);
    printf("\n Enter total number of resource instances :");
    scanf("%d",&m);

    //alloction matric scan
    printf("\n Enter allocation matrix :");
    for ( i = 0; i < n; i++)
    {
        printf("\n process P%d :",i+1);
        for ( j = 0; j < m; j++)
        scanf("%d",&alloc[i][j]);
    }

    printf("\n Enter Available :");
    for ( i = 0; i < m; i++)
    scanf("%d",&avail[i]);
    printf("\n Process \t Allocation \t Max \t Need \t Available \n");
    for( i = 0; i < n; i++)
    {
        printf("\n P %d \t ",i);
        for(j=0;j<m;j++)
        printf("%d\t",alloc[i][j]);
        for(j=0;j<m;j++)
        printf("%d\t",max[i][j]);
        for(j=0;j<m;j++)
        {
            need[i][j]=max[i][j]-alloc[i][j];
            printf("%d\t",need[i][j]);
        }
        if(i==0)
            for(j=0;j<m;j++)
                printf("%d\t",avail[j]);
    }
    return 0;
}