#include "xpaint.h"

void bola(float x, float y, float raio, float ang){
    if(raio < 1)
    	return;

    float x0 = x; 
    float y0 = y; 
	int xf = x + raio * xm_cos(ang);
	int yf = y - raio * xm_sin(ang);
	xd_circle(x, y, raio);

	for(int i = 0; i < 6; i++){
	 
		bola(xf, yf, raio / 3 , ang);   
		bola(xf, yf, raio / 3 , ang + 60);
		bola(xf, yf, raio / 3 , ang + 120);
		bola(xf, yf, raio / 3 , ang + 180);
		bola(xf, yf, raio / 3 , ang + 240);
		bola(xf, yf, raio / 3 , ang + 300);  

		float delta = delta + 60;

		xf = x + raio * xm_cos(delta);
		yf = y - raio * xm_sin(delta);
 	}

}

int main(){
	
	int largura = 5000, altura = 5000;
    x_open(largura, altura); 

    float x = largura / 2; 
    float y = altura / 2; 
    float raio = 1000;
    float ang = 0; 

    bola(x, y, raio, ang);  
    x_save("bola"); 
}


