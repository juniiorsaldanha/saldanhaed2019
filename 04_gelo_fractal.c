#include "xpaint.h"

void ice(float x, float y, float tamanho, float ang){	
	if(tamanho < 1)
		return; 

    for(int i = 0; i < 5; i++){
    	int xf = x + tamanho * xm_cos(ang);
    	int yf = y - tamanho * xm_sin(ang); 

    	xd_line(x, y, xf, yf);
    	ice(xf, yf, tamanho / 3, ang);
    	ang += 72; 	   

	}
}

int main(){
	
	int largura = 1000, altura = 1000;
    x_open(largura, altura); 

    float x = largura / 2; 
    float y = altura  / 2; 
    float tamanho = 300; 
    float ang = 270; 

    ice(x, y, tamanho, ang);  
    x_save("gelo"); 
}