#include<stdio.h>
int main()
{
    int page[100],i,n_pages,f,page_size,offset,page_no;
    int choice=0;
    printf("\nEnter the no of  pages in memory: ");
    scanf("%d",&n_pages);
    printf("\nEnter page size: ");
    scanf("%d",&page_size);
    printf("\nEnter no of frames: ");
    scanf("%d",&f);
    for(i=0;i<n_pages;i++)
        page[i]=-1;
    printf("\nEnter the page table\n");
    printf("(Enter frame no as -1 if that page is not present in any frame)\n\n");
    printf("\npageno\tframeno\n-------\t-------");
    for(i=0;i<n_pages;i++)
    {
        printf("\n%d\t",i);
        scanf("%d",&page[i]);
    }
    do
    {
        printf("\n\nEnter the logical address(i.e,page no & offset):");
        scanf("%d %d",&page_no,&offset);
        if(page[page_no]==-1)
            printf("\nThe required page is not available in any of frames");
        else
            printf("\nPhysical address(i.e,frame no & offset):%d,%d",page[page_no],offset);
        printf("\nDo you want to continue(1/0)?:");
        scanf("%d",&choice);
    }while(choice==1);
    return 1;
}