#include <stdio.h>
#include<stdbool.h>


void mostrarVetor(int* v, int size){
	int i; 
		printf("[");
		bool eh_o_primeiro = true; 
		
	for(i = 0; i < size; i++){
		
		if(v[i] != 0){
			if(eh_o_primeiro){
				eh_o_primeiro = false;
			}
			else{
			printf(" "); 
		}
		printf("%d", v[i]);
		}
	}
	
	printf("]\n");
	
}

void preencherVetor(int* v, int size, int sinal){
	
	v[0] = sinal;
	int value = 2;
	int i; 
	
	for(i = 1; i < size; ++i){
		sinal *= -1;
		v[i] = value*sinal;
		value++;
	}
}

int vaiMorrer(int* v, int size, int escolha){
	int pos = escolha;

	if(v[pos] > 0){
		pos = (pos+1)%size;
	} else {
		if(pos == 0){
			pos = size-1;
		} else {
			pos--;
		}
	}

	while(v[pos] == 0){
		if(v[escolha] > 0){
			pos = (pos+1)%size;
		} else {
			if(pos == 0){
				pos = size-1;
			} else {
				pos--;
			}
		}
	}
	return pos;
}

int andarCasas(int* v, int escolha, int size){
	
	int pos = escolha;
	int casas;

	if(v[escolha] > 0){
		casas = v[escolha];
	} else {
		casas = v[escolha] * (-1);
	}
	while(casas > 0){
		if(v[escolha] > 0){
			pos = (pos+1)%size;
		} else {
			if(pos == 0){
				pos = size-1;
			} else {
				pos--;
			}
		}
		if(v[pos] != 0){
			casas--;
		}
	}
	return pos;
}

int main(){

	int escolha;
	int size;
	int sinal;

	printf("Digite o tamanho do vetor: ");
	scanf("%d", &size);
	printf("Digite o sinal: ");
	scanf("%d", &sinal);
	printf("Digite a sua escolha: ");
	scanf("%d", &escolha);

	escolha--;

	int v[size];
	int qtd = size - 1;

	preencherVetor(v, size, sinal);
	mostrarVetor(v, size);
	printf("\n");

	while(qtd--){
		v[vaiMorrer(v, size, escolha)] = 0;
		escolha = andarCasas(v, escolha, size);
		mostrarVetor(v, size);
		printf("\n");
	}

}
