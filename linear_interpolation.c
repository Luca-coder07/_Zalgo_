/* 

Author : Luca RANDRIANIRINA (lucarandrianirina2507@gmail.com)

Linear interpolation (Lerp) 
Calcul d'un point intermediaire entre le point A et B
Facteur time ou alpha (entre 0 et 1)

pt_pos = pos_deb + (pos_fin - pos_deb) * factor

*/

float	lerp(float pos_deb, float pos_fin, float factor)
{
	if (factor < 0 || factor > 1)
		return (pos_deb);
	return (pos_deb + (pos_fin - pos_deb) * factor);
}


// Main Test
#include <stdio.h>
int main(void)
{
	float position;

	position = lerp(15.0f, 20.0f, 0.5f);
	printf("%0.2f\n", position);
}
