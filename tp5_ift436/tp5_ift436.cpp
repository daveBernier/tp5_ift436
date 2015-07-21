// tp5_ift436.cpp : définit le point d'entrée pour l'application console.
//

#include "TriFusion.h"
#include "TriSelection.h"
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;
int main()
{


	void print(vector<int>&);
	void constructVector(vector<int>&);
	vector<int> vectorBase{}, vectorSelection{}, vectorMerge{}, vectorShell{};

	constructVector(vectorBase);

	//print(v);
	//cout << "------------------" << endl;

	//Tri par sélection
	char date_time[32];
	cout << "Tri Selection\n";
	time_t t = time(0);
	strftime(date_time, 31, "%c", localtime(&t));
	cout << date_time << " - Temps initial." << endl;

	clock_t t1 = clock();
	if (t1 == clock_t(-1))
	{
		cerr << "*** No clock." << endl;   exit(1);
	}

	TriSelection triSelection;
	vectorSelection = triSelection.selectionSort(vectorBase);

	clock_t t2 = clock();
	if (t2 == clock_t(-1))
	{
		cerr << "*** No clock." << endl;   exit(1);
	}

	cout << "  Temps de traitement: " << t2 - t1 << " ticks ("
		<< CLOCKS_PER_SEC << " ticks per second)" << endl;

	t = time(0);
	strftime(date_time, 31, "%c", localtime(&t));
	cout << date_time << " - Temps final." << endl;
	cout << "-------------------------------------------------------------------------------" << endl;


	//Tri fusion(merge sort)
	date_time[32];
	cout << "Tri Fusion" << endl;
	t = time(0);
	strftime(date_time, 31, "%c", localtime(&t));
	cout << date_time << " - Temps initial." << endl;

	t1 = clock();
	if (t1 == clock_t(-1))
	{
		cerr << "*** No clock." << endl;   exit(1);
	}

	TriFusion fusion{};
	vectorMerge = fusion.mergeSort(vectorBase);

	t2 = clock();
	if (t2 == clock_t(-1))
	{
		cerr << "*** No clock." << endl;   exit(1);
	}

	cout << "  Temps de traitement: " << t2 - t1 << " ticks ("
		<< CLOCKS_PER_SEC << " ticks per second)" << endl;

	t = time(0);
	strftime(date_time, 31, "%c", localtime(&t));
	cout << date_time << " - Temps final." << endl;
	cout << "-------------------------------------------------------------------------------" << endl;

	//tri de Shell (Shell Sort)
	cout << "Tri Shell (404 not found)" << endl;
	//print(v);

	

	system("PAUSE");
	return 0;
}

void constructVector(vector<int>& v){
	int nombreValue;
	cout << "Entrez le nombre de valeur a trier \n"
		<< "Selection: " << endl;
	cin >> nombreValue;


	srand((unsigned)time(0));
	int random_integer;
	int lowest = 0, highest = 20000;
	int range = (highest - lowest) + 1;
	for (int index = 0; index<nombreValue; index++){
		random_integer = lowest + int(range*rand() / (RAND_MAX + 1.0));
		v.push_back(random_integer);
	}
}
void print(vector<int>& v)
{
	for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
	cout << endl;
}


