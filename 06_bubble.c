#include "xpaint.h"
#include "xvet.h"

#define SWAP(a, b, tipo) {tipo SWAP; SWAP = a; a = b; b = SWAP;};   

void bubble_sort(int vet[], int size){

	for(int i = 0; i < size;i++){
		for(int j = 0; j < size - i; j++){
			xs_partition(0, (size - 1)- i);
				if(vet[j] > vet[j + 1]){
					xd_vet(vet, size, "rb", j , j + 1);
					SWAP(vet[j], vet[j + 1], int);
				}
			
			xd_vet(vet, size, "rb", j, j + 1);
		}
		
	}



}

int main(){
    x_open(800, 500);
    int size = 40;
    xs_log("imagens/");
    int vet[size];
    srand(1);
    for(int i = 0; i < size; i++)
        vet[i] = rand() % 191 + 10;
    xd_vet(vet, size, "");
    bubble_sort(vet, size);
    xd_vet(vet, size, "");
    x_close();
}