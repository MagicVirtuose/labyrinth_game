#include <stdio.h>
#include <stdlib.h>
#include "labyrinth.h"
#include "generator.h"

/*
char** generate_labyrinth(){
    srand( time( NULL ) );

    char** labyrinth = init_labyrinth();
    

    for (int i=0; i <21;i++){
        for (int j=0; j <22; j++){
            labyrinth[i][j] = "|";
            
        }
    }

    
    int x = rand()%22;
    int y = rand()%23;
    char* current_cell = labyrinth[x][y];
    
    labyrinth[x][y] = "";
    char * frontiers = get_frontiers(labyrinth, x, y);
    int n = sizeof(frontiers)/sizeof(frontiers[0]);
    
    while(n != 0){
        x = rand()%22;
        y = rand()%23;
        //frontiers[n+1] = labyrinth[x][y];
        
        //Connect the chosen frontier and a random neighbor.
        connect_to_neighbor(labyrinth,x,y);

        //Add the frontiers of the chosen frontier to the frontier list.
        tmp = get_frontiers(labyrinth,x,y);
        int size = sizeof(tmp)/sizeof(tmp[0]);

        for ( i=0; i < size; i++ ){
            frontiers[n+(1+i)] = tmp[i];
        }

    }

    return labyrinth;
}

char* get_frontiers(char** labyrinth, int x, int y){

    char* frontiers = malloc(30* sizeof(char));
    int tmp[] = {(0,2),(2,0),(2,2),(0,-2),(-2,0),(-2,-2)};
    
    for (int i = 0; i<6; i++){
        if (x+tmp[i][0] < 22 && y+tmp[i][1] < 21){
            if ( labyrinth[x+tmp[i][0]][y+tmp[i][1]] =="|"){
                frontiers[i] = 
            } 
        }
    }
    return frontiers;
}

void save_labyrinth(char** labyrinth){

    char* filename = "3.txt";

    // open the file for writing
    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("Error opening the file %s", filename);
        return -1;
    }


    // write to the text file
    for (int i = 0; i < 21; i++){
        fprintf(fp, "\n");

        for(int j = 0; j<22; j++){
            fprintf(fp, "%s", labyrinth[i][j] );
        }
    }
        

    // close the file
    fclose(fp);

    return 0;
}

int main(){

    save_labyrinth(generate_labyrinth());
}

*/