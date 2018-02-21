# include <stdio.h>
# include <math.h>
# include <stdlib.h>

# define X(coor) (coor[0])
# define Y(coor) (coor[1])

void usage(){
    fprintf(stderr, "chaos.exe <triangle height>");
    exit(-1);
}

void initialize(int**, int, int*, int*, int*);
void print_file(char*, int**, int);

int main(int argc, char* argv[]){
    // int color_code;
    int edge;

    int cnr1[2];
    int cnr2[2];
    int cnr3[2];


    int** grid;

    // if (argc < 2) usage();

    char* filename = "test.out";
    // edge = atoi(argv[1]);
    edge = 1;


    initialize(grid, edge, cnr1, cnr2, cnr3);

    print_file(filename, grid,edge);
}

/* Initialize the grid with the first 3 points */
void initialize(int** grid, int edge, int* cnr1, int* cnr2, int* cnr3){
    int i;

    if(edge < 10){
        edge = 11;
    }

    if (edge % 2){
        edge++;
    }

    grid = calloc(edge, sizeof(int*));

    for(i = 0; i < edge; i++)
        grid[i] = calloc(edge, sizeof(int));

    X(cnr1) = edge-1;
    Y(cnr1) = 0;

    X(cnr2) = edge-1;
    Y(cnr2) = edge-1;

    X(cnr3) = (2.0-sqrt(3.0)) / 2.0 * (float) edge;
    Y(cnr3) = (edge-1)/2;

    grid[X(cnr1)][Y(cnr1)] = 255;
    grid[X(cnr2)][Y(cnr2)] = 255;
    grid[X(cnr3)][Y(cnr3)] = 255;
}


void print_file(char* filename, int** grid, int edge){
    FILE* fp;
    int i, j;

    // fp = fopen(filename, "w");
    
    printf("%d\n", edge);

    for(i = 0; i < edge; i++){
        for(j = 0; j < edge; j ++){
            printf("%d", grid[i][j]);
            if(j != edge - 1){
                printf(", ");
            }
        }
        printf("\n");
    }

    // fclose(fp);

}
