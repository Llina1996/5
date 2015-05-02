/** @file Dijkstra-s-algorithm.cpp */
#include <iostream>
using namespace std;

//! Funkcija, kotoraja realizuet algoritm Dejkstry
/*! \fn Dijkstra
@param [in] **a - dvojnoj ukazatel' na massiv
@param [in]   n - razmernost' massiva
@param [in]  st - nachal'naja vershina
*/
void Dijkstra(int **a, int n, int st)
{
	int count, index, i, u, m = st + 1;
	int *distance = new int[n]; /*!< Chislennyj massiv, v kotoryj budut zanosit'sja najdennye kratchajshie puti */
	bool *visited = new bool[n]; /*!< Logicheskij massiv dlja hranenija informacii o poseshhennyh vershinah */
	for (i = 0; i < n; i++)
	{
		distance[i] = INT_MAX; /*!< Iznachal'no sozdaem massiv s rasstojanijami, kotorye zavedomo bol'she ljubogo potencial'nogo puti  */
		visited[i] = false; /*!< Kazhduju vershinu otmechaem kak ne poseshhennuju */
	}
	distance[st] = 0; /*!< Ishodnaja vershina */
	for (count = 0; count < n - 1; count++)
	{/// Poisk sosednih vershin 
		int min = INT_MAX;
		for (i = 0; i < n; i++)
		if (!visited[i] && distance[i] <= min) /*!< Peresmotr rasstojanija */
		{
			min = distance[i]; index = i;
		}
		u = index;
		visited[u] = true; /*!< Pomechaem vershiny kak poseshhennye */
		for (i = 0; i < n; i++)
		if (!visited[i] && a[u][i] && distance[u] != INT_MAX && distance[u] + a[u][i] < distance[i]) /*!< Vychislenie rasstojanija */
			distance[i] = distance[u] + a[u][i];
	}

	cout << "Kratchajshij put' iz nachal'noj vershiny do ostal'nyh:\t\n"; /*!< Vyvod kratchajshego puti */
	for (i = 0; i < n; i++) if (distance[i] != INT_MAX)
		cout << m << " -> " << i + 1 << " = " << distance[i] << endl;
	else cout << m << " -> " << i + 1 << " = " << "marshrut nedostupen" << endl;
}
/*! \fn main
\brief Glavnaja funkcija main()
*/
void main()
{
	//setlocale(LC_ALL, "RUS");	
	int N, start;
	cout << "Vvedite kolichestvo vershin >> "; /*!< Vvod kolichestva vershin */
	cin >> N;
	/// Sozdaem matricu smezhnosti (vmesto edinic v nej budut vystavleny vesa reber)
	int **A = new int *[N];
	for (int i = 0; i < N; i++) A[i] = new int[N];

	cout << "Vvedite matricu smezhnosti " << N << " na " << N << " >>" << endl << endl;
	for (int j = 0; j < N; j++)
	{
		cout << "\t";
		for (int k = 0; k < N; k++)
		{
			cin >> A[j][k];
		}
	}
	cout << endl;

	cout << "Nachal'naja vershina >> "; cin >> start; /*!< Zadaem nachal'nuju vershinu */
	Dijkstra(A, N, start - 1); /*!< Vyzyvaem funkciju, realizujushhuju algoritm Dejkstry #Dijkstra */
	for (int i = 0; i < N; i++) delete[]A[i];
	delete[]A;
	system("pause");
}
