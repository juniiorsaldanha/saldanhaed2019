#include "xpaint.h"
#include "xvet.h"

#define SWAP(a, b, tipo) {tipo SWAP; SWAP = a; a = b; b = SWAP;};   

void insert_sort(int vet[], int size){
	int i, j, aux;
    for (i = 1; i < size; i++) {
        aux = vet[i];
        for(j = i - 1; j >= 0 && aux < vet[j]; j--){
        	xs_partition(0, i - 1);
        	xs_pivot(aux);
        	xd_vet(vet, size,"rb",j ,j + 1); 
        	vet[j + 1] = vet[j]; 
        }
        vet[j + 1] = aux;  
    }
}

int main(){
    x_open(800, 500);
    int size = 40;
    xs_log("images/");
    int vet[size];
    srand(1);
    for(int i = 0; i < size; i++)
        vet[i] = rand() % 191 + 10;
    xd_vet(vet, size, "");
    insert_sort(vet, size);
    xd_vet(vet, size, "");
    x_close();
}