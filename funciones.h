/************
Michelle Aylin Calzada Montes
A01706202
Act 1
************/

#ifndef FUNCIONES_H
#define FUNCIONES_H

class Funciones{
	public:
		Funciones();
		long sumaIterativa(int n);
		long sumaRecursiva(int n);
		long sumaDirecta(int n);
};

Funciones::Funciones(){}

long Funciones::sumaIterativa(int n){
	if(n < 0)
	    return 0;
	    
	else{
	    int sum = 0;
	    for(int i = 1; i <= n; i++){
	    sum += i;	
		}
		return sum;
    }
}

long Funciones::sumaRecursiva(int n){
	if(n < 0)
	    return 0;
	    
	else
	    return (n + sumaRecursiva(n-1));
}

long Funciones::sumaDirecta(int n){
	if(n < 0)
	    return 0;
	
	else
		return (n*(n+1)/2);
}

#endif
