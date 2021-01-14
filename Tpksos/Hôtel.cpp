#include "H�tel.h"

H�tel::H�tel(int id, string nom, string ville, vector<Chambre> liste)
{
	_id = id;
	_nom = nom;
	_ville = ville;
	_liste = liste;
}

int H�tel::getid()
{
	return _id;
}

string H�tel::getnom()
{
	return _nom;
}

string H�tel::getville()
{
	return _ville;
}

vector <Chambre> H�tel::getliste()
{
	return _liste;
}

void H�tel::addChambre(Chambre chambre)
{
	_liste.push_back(chambre);
}

string H�tel::tostring()
{

	string temp = to_string(getid()) + " " + getnom() + " " + getville() + " ";
	for (int i = 0; i < getliste().size(); i++)
	{
		temp += "\n\t- " + getliste().at(i).tostring();
	}
	return temp;
}

bool H�tel::chambre_existe(int num)
{
	for (int i = 0; i < _liste.size(); i++)
	{
		if (_liste.at(i).getid() == num)
		{
			return true;
		}
	}
	return false;
}

Chambre H�tel::getchambre(int num)
{
	for (int i = 0; i < _liste.size(); i++)
	{
		if (_liste.at(i).getid() == num)
		{
			return _liste.at(i);
		}
	}
}
