#include "xpaint.h"

void trigo(float x, float y, float tamanho, float ang){

	if(tamanho < 1)
		return; 
	int aux = x; 
    int auy = y; 

    for(int i = 0; i < 4; ++i){
	    int xf = aux + tamanho * xm_cos(ang);
	    int yf = auy - tamanho * xm_sin(ang);

	    xd_line(x, y, xf, yf); 

	    trigo(xf, yf, tamanho / 3, ang - 30);
	    trigo(xf, yf, tamanho / 3, ang + 30); 

	    aux = xf;
	    auy = yf; 
	}
}

int main(){
	
	int largura = 1000, altura = 1000;
    x_open(largura, altura); 

    float x = largura / 2; 
    float y = altura - 50;
    float tamanho = 150; 
    float ang = 90; 

    trigo(x, y, tamanho, ang);  
    x_save("trigo"); 
}	
