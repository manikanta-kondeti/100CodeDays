#include<stdio.h>          //to use the printf function
#include<stdlib.h>
#include<math.h>         //to use the rand function
#include<time.h>
#define DIM_POP 4
#define PAR_MIN -15.0      // studying the function into established interval [-2^3, 2^3]
#define PAR_MAX 15.0
#define TABU_SIZE 4
#define TABU_TENURE 3
#define STEP_SIZE_MAX 0.01
#define RANGE_MAX (1/4)*STEP_SIZE_MAX

typedef struct
{
        float point[2];    //it is a vector containing (x,y) coordinates
        float fitness;
        int tabu_tenure;
}info;

info tabu_list[TABU_SIZE];
int iter_best=0;                     /* iteration where best was found */
info best;                             /* best value of object function in next_neighborhood */
int S;                              //no. of generated neighborhood
int itcall=0;                      //no of calls to object function 
float neighbor[2][DIM_POP]; 

float z(float x, float y);                          
void tabu_search(int max_iter, float seed_x, float seed_y, float fseed);
void neighborhood(info curr_best, info curr_neighborhood[DIM_POP]);
void insert_tabu(info p);
float distance(float p_gen[2], float point_tabu[2]);
void best_object_function(info curr_neighborhood[DIM_POP]);

int main()                                    // the main function
{
        int num;                                     // num is the no. of iterations
        int i,j;
        float seed_x; 
        float seed_y;
        float fseed;

        printf("\nMaximum of the function z = -x^2-y^2 + 5 ");                         // introduction to the program


enter: printf("\nPlease enter the no. of iterations:  ");
       scanf("%d",&num);                           // enter the no. of iterations in num

       if(num<1)                                       // if a -ve number is inserted .. enter num again
               goto enter;

       srand(time(NULL));                            //initializing the generator

       seed_x=(PAR_MAX-PAR_MIN)*(((float)rand())/RAND_MAX)+PAR_MIN;
       //printf("\nseed=%f", seed_x);
       seed_y=(PAR_MAX-PAR_MIN)*(((float)rand())/RAND_MAX)+PAR_MIN;
       fseed=z(seed_x,seed_y);

       tabu_search(num, seed_x, seed_y, fseed);  

       printf("\nPress any key to end ! ");

       getche();                                        // wait for a character from the keyboard to end

}                                                      //end of main



float z(float x, float y)          // the y function that we look for it's maximum value takes (x,y) value
{
        float t;
        t=-(x*x)-(y*y)+5;            // the function is z= - ( x^ 2 ) - (y^ 2) +5
        return(t);              
}                              // end of z function


void tabu_search(int max_iter, float seed_x, float seed_y, float fseed)
{
        int iter=0;                      /* iteration counter */                                
        info curr_neighborhood[DIM_POP];
        for(int i=0;i<TABU_SIZE;i++)        //tabu list initialization
                tabu_list[i].tabu_tenure=0;


        best.point[0]=seed_x;
        best.point[1]=seed_y;
        best.fitness=fseed;
        printf("\n seed=(%f,%f) with fitness=%f", seed_x, seed_y, best.fitness);
        neighborhood(best, curr_neighborhood);
        iter++;
        do{
                neighborhood(best, curr_neighborhood);
                for(int k=0;k<TABU_SIZE;k++)
                {
                        if(iter-tabu_list[k].tabu_tenure>TABU_TENURE) 
                                tabu_list[k].tabu_tenure=0;
                }
                best_object_function(curr_neighborhood); 
                itcall=itcall+S;
                printf("\n no. iter=%d  no. neigh=%d\n", iter, S);               
                iter++;
        }while(iter<max_iter);
        printf("\n best point (x,y)=(%f,%f) and best fitness f(x,y)=%f ", 
                        best.point[0], best.point[1], best.fitness);

}

void neighborhood(info curr_best, info curr_neighborhood[DIM_POP])  /* make a neighborhood of each point of the curr_neighborhood */
{
        int i;
        int j;
        int k;
        float gen[2];
        int M=0;
        double dist;
        int flag_tabu=0;
        int flag_step=0;
        float step_size=STEP_SIZE_MAX;
        float point_tabu[2];
        int counter=0;
        S=0;
        srand(time(NULL));
        while(S!=DIM_POP && M!=5*DIM_POP ) //the loop stops when S=DIM_POP or when it is reached a establish max number without has found neighborhoods
        {

                switch (counter)
                {
                        case 0:
                                gen[0]=curr_best.point[0]+(step_size*(PAR_MAX-PAR_MIN));  /* generate a neighborhood of the point ax into the established interval [PAR_MAX, PAR_MIN] */
                                if(gen[0]>PAR_MAX)
                                        gen[0]=PAR_MAX;
                                else if(gen[0]<PAR_MIN)
                                        gen[0]=PAR_MIN;
                                gen[1]=curr_best.point[1];
                                counter++;
                                break;
                        case 1:
                                gen[0]=curr_best.point[0];
                                gen[1]=curr_best.point[1]+(step_size*(PAR_MAX-PAR_MIN));  /* generate a neighborhood of the point ax into the established interval [PAR_MAX, PAR_MIN] */
                                if(gen[1]>PAR_MAX)
                                        gen[1]=PAR_MAX;
                                else if(gen[1]<PAR_MIN)
                                        gen[1]=PAR_MIN;
                                counter++;
                                break;
                        case 2:
                                gen[0]=curr_best.point[0]-(step_size*(PAR_MAX-PAR_MIN));  /* generate a neighborhood of the point ax into the established interval [PAR_MAX, PAR_MIN] */
                                if(gen[0]>PAR_MAX)
                                        gen[0]=PAR_MAX;
                                else if(gen[0]<PAR_MIN)
                                        gen[0]=PAR_MIN;
                                gen[1]=curr_best.point[1];
                                counter++;
                                break;
                        case 3:
                                gen[0]=curr_best.point[0];
                                gen[1]=curr_best.point[1]-(step_size*(PAR_MAX-PAR_MIN));  /* generate a neighborhood of the point ax into the established interval [PAR_MAX, PAR_MIN] */
                                if(gen[1]>PAR_MAX)
                                        gen[1]=PAR_MAX;
                                else if(gen[1]<PAR_MIN)
                                        gen[1]=PAR_MIN;
                                counter++;
                        default:  
                                break;

                }           

                M++;
                for(j=0;j<TABU_SIZE;j++)
                {
                        if(tabu_list[j].tabu_tenure!=0)
                        {
                                for(k=0;k<2;k++)
                                        point_tabu[k]=tabu_list[j].point[k];
                                dist=distance(gen, point_tabu);
                                if(dist<RANGE_MAX) 
                                        flag_tabu++;
                        }
                }
                if(flag_tabu==0)
                {
                        for(k=0;k<2;k++)
                                neighbor[k][S]=gen[k];
                        S++;
                }
                flag_tabu=0;
        }

        for(i=0;i<S;i++)
        {
                for(k=0;k<2;k++)
                        curr_neighborhood[i].point[k]=neighbor[k][i];
                curr_neighborhood[i].fitness=z(curr_neighborhood[i].point[0], 
                                curr_neighborhood[i].point[1]);
        }
        best_object_function(curr_neighborhood);                

}


void insert_tabu(info p)        //creating tabu list as a FIFO sistem
{
        int i=0;
        while(tabu_list[i].tabu_tenure!=0)
                i++;
        for(int k=0;k<2;k++)
                tabu_list[i].point[k]=p.point[k];
        tabu_list[i].fitness=p.fitness;
        tabu_list[i].tabu_tenure=TABU_TENURE;
}

float distance(float p_gen[2], float point_tabu[2])
{
        float dist;
        dist=sqrt(pow(p_gen[0]-point_tabu[0],2)+pow(p_gen[1]-point_tabu[1],2));
        return (dist);
}


void best_object_function(info curr_neighborhood[DIM_POP])
{
        for(int i=0;i<S;i++)
        {
                if(curr_neighborhood[i].fitness>best.fitness)
                {
                        insert_tabu(best);
                        best.fitness=curr_neighborhood[i].fitness;
                        for(int k=0;k<2;k++)
                                best.point[k]=curr_neighborhood[i].point[k];
                        iter_best=itcall;
                }
                else
                {      
                        insert_tabu(curr_neighborhood[i]);
                }
        }
        printf("\n Current best point=(%f,%f)", best.point[0], best.point[1]);
}
