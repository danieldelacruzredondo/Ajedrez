#include"freeglut.h"
#include"ListaPeones.h"
#include"Peon.h"
#include"VPosicion.h"

void ListaPeones::agregar(Peon* aux1,Peon* aux2)
{
	if (numero0 < MAX_PEONES) {
		lista0[numero0++] = aux1;
	}
	if (numero1 < MAX_PEONES) {
		lista1[numero1++] = aux2;
	}
}

void ListaPeones::inicializa()
{
	float j = 1.0;
	for (int i = 0; i < MAX_PEONES; i++)
	{
		lista0[i]->setcolor(FALSE);
		lista1[i]->setcolor(TRUE);
		VPosicion a{ j,3 }, b{j,13};
		lista0[i]->setpos(a);
		lista1[i]->setpos(b);
		j += 2.0;
	}
}

void ListaPeones::dibuja()
{
	for (int i = 0; i < MAX_PEONES; i++)
	{
		lista0[i]->dibuja();
		lista1[i]->dibuja();
	}
}
