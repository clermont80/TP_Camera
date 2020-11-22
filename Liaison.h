//---------------------------------------------------------------------------

#ifndef LiaisonH
#define LiaisonH
#include <winsock.h>

class Liaison
{
	private:

	   HANDLE hcom;

	public:
	   bool Ouvrirport();
	   bool envoitrame(char* buffer);  //createfile a besoin du chemin du fichier
	   bool lireport(char * c);
	   bool fermerport();


};
#endif
