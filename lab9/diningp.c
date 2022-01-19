#include<stdio.h>
int completed_P = 0,i,n;

struct fork{
        int taken;
};

struct Phil{
        int left;
        int right;
};
struct fork F[10];
struct Phil P_status[10];
void goForDinner(int P_id){
        if(P_status[P_id].left==10 && P_status[P_id].right==10)
        printf("Philosopher %d completed his dinner\n",P_id+1);
        else if(P_status[P_id].left==1 && P_status[P_id].right==1){

            printf("Philosopher %d completed his dinner\n",P_id+1);

            P_status[P_id].left = P_status[P_id].right = 10;
            int otherFork = (P_id+(n-1))%n;
            F[P_id].taken = F[otherFork].taken = 0;
            printf("Philosopher %d released fork %d and fork %d\n",P_id+1,P_id+1,otherFork+1);
            completed_P++;
        }
        else if(P_status[P_id].left==1 && P_status[P_id].right==0){
                if(P_id==(n-1)){
                    if(F[P_id].taken==0){
                        F[P_id].taken = P_status[P_id].right = 1;
                        printf("Fork %d taken by philosopher %d\n",P_id+1,P_id+1);
                    }else{
                        printf("Philosopher %d is waiting for fork %d\n",P_id+1,P_id+1);
                    }
                }else{
                    int dupphilID = P_id;
                    P_id=(P_id+(n-1))%n;
                    if(F[P_id].taken == 0){
                        F[P_id].taken = P_status[dupphilID].right = 1;
                        printf("Fork %d taken by Philosopher %d\n",P_id+1,dupphilID+1);
                    }else{
                        printf("Philosopher %d is waiting for Fork %d\n",dupphilID+1,P_id+1);
                    }
                }
            }
            else if(P_status[P_id].left==0){
                    if(P_id==(n-1)){
                        if(F[P_id-1].taken==0){
                            F[P_id-1].taken = P_status[P_id].left = 1;
                            printf("Fork %d taken by philosopher %d\n",P_id,P_id+1);
                        }else{
                            printf("Philosopher %d is waiting for fork %d\n",P_id+1,P_id);
                        }
                    }else{
                        if(F[P_id].taken == 0){
                            F[P_id].taken = P_status[P_id].left = 1;
                            printf("Fork %d taken by Philosopher %d\n",P_id+1,P_id+1);
                        }else{
                            printf("Philosopher %d is waiting for Fork %d\n",P_id+1,P_id+1);
                        }
                    }
        }else{}
}

int main(){
    printf("Enter the number of Philosophers: \n");
    scanf("%d",&n);
        for(i=0;i<n;i++)
        F[i].taken=P_status[i].left=P_status[i].right=0;

        while(completed_P<n){
                for(i=0;i<n;i++)
            goForDinner(i);
                printf("\nTill now no of philosophers completed dinner are %d\n\n",completed_P);
        }

        return 0;
}