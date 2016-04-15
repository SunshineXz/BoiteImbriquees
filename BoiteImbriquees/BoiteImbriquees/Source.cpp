#include "boite.h"
#include "Cadre.h"
#include "ComboHorizontal.h"
#include "ComboVertical.h"
#include <iostream>
#include <string>
using namespace std;

ostream& operator << (ostream& os, const Boite& boite)
{
	//Cadre(boite, os);
	boite.print(os);
	return os;
}

int main()
{
	Boite b;
	//cout << b << endl;
	string texte = R"(Man! Hey!!!
ceci est un test
multiligne)";
	string aut_texte = "Ceci\nitou, genre";
	Boite b0{ texte };
	Boite b1{ aut_texte };
    cout << b0 << endl << b1 << endl;
	ComboVertical cv{ b0, b1 };
	cout << Boite{ cv } << endl;
	ComboHorizontal ch{ b0, b1 };
	cout << Boite{ ch } << endl;
	ComboVertical cvplus{ Boite{ cv }, Boite{ ch } };
	cout << Boite{ cvplus } << endl;
	ComboHorizontal chplus{ Boite{ cv }, Boite{ ch } };
	//cout << Boite{ chplus } << endl;
	ComboVertical cvv{ ch, ch};
    cout << Boite{ cvv } << endl;
	/*cout << Boite{
		ComboHorizontal{
		Boite{ "a\nb\nc\nd\ne" },
		Boite{
		ComboVertical{
		Boite{ "allo" }, Boite{ "yo" }
	}
	}
	}
	} << endl;*/
}

