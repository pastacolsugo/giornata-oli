#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;


int nPanini, peso[10007], memo[10007];
int dp (int panAtt, int last);

int main (void) {
	//freopen("/Users/utente/Desktop/input.txt", "r", stdin);
	//freopen("/Users/utente/Desktop/output.txt", "w", stdout);

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	memset (memo, -1, sizeof memo);
	cin >> nPanini;
	peso[nPanini] = 100000;
	for (int i=0; i<nPanini; i++)
		cin >> peso[i];
	printf ("%d", dp(0, nPanini));
}

int maxx (int a, int b){
	if (a > b)
		return a;
	return b;
}

int dp (int panAtt, int last){	//indice panino attuale, indice ultimo mangiato
	if (panAtt == nPanini)
		return 0;
	int sePrendo = -1, seNonPrendo;
	if (peso[panAtt] < peso[last]){
		if (memo[panAtt] != -1)
			sePrendo = memo[panAtt];
		else
			sePrendo = memo[panAtt] = dp (panAtt+1, panAtt)+1;
	}
	seNonPrendo = dp (panAtt+1, last);
	return maxx (sePrendo, seNonPrendo);
}

/*

	se prendo:
		albero univoco
	se non prendo:
		albero dipendente dal peso dell'ultimo panino mangiato

*/