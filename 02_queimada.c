#include <stdio.h>
#include<stdlib.h>
#include<time.h>

const char TREE = '#';
const char FIRE = 'o';
const char EMPTY = '.';
const char BURN = 'x';

void show(int nl, int nc, char mat[nl][nc]){
	int l; 
	int c; 
    for(l = 0; l < nl; l++){
        for(c = 0; c < nc; c++)
            printf("%c", mat[l][c]);
        puts("");
    }
    getchar(); 
}

int tocar_fogo(int nl, int nc, char mat[nl][nc], int l, int c){
    if((l < 0) || (l >= nl) || (c < 0) || (c >= nc))
        return 0;
    if(mat[l][c] != TREE)
        return 0;
    mat[l][c] = FIRE;
	int cont = 1; 	
    cont += tocar_fogo(nl, nc, mat, l, c + 1);
    cont += tocar_fogo(nl, nc, mat, l, c - 1);
    cont += tocar_fogo(nl, nc, mat, l - 1, c);                                  
    cont += tocar_fogo(nl, nc, mat, l + 1, c);
    show(nl, nc, mat); 
    mat[l][c] = BURN;
    
 	return cont; 
}

int main(){
	srand(time(NULL)); 
    int nl = 0;
    int nc = 0;
    printf("Digite as diemensoes da matriz: "); 
    scanf("%d %d", &nl, &nc);
    int porc_tree; 
    printf("Digite a porcentagem de arvores de 0 - 100: ");
    scanf("%d", &porc_tree); 
    char mat[nl][nc];
    int i, j;
    for(i = 0; i < nl; i++){
        for(j = 0; j < nc; j++){   
            if(rand() % 101 <= porc_tree)
                mat[i][j] = TREE;
            else
                mat[i][j] = EMPTY;
        }
    }    
    int l = 0;
    int c = 0; 
    show(nl, nc, mat);
    printf("Onde comeca o incendio: "); 
    scanf("%d %d", &l, &c); 
    int total = tocar_fogo(nl, nc, mat, l, c);
   	show(nl, nc, mat);
   	printf("Total de arvores queimadas: %d ", total); 
}