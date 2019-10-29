#include <iostream>
#include <algorithm>

using namespace std;

int nPanini, peso[10007], memo[10007];

int dp(int panAtt, int last){	//indice panino attuale, indice ultimo mangiato
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

	return max(sePrendo, seNonPrendo);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	memset (memo, -1, sizeof memo);
	cin >> nPanini;
	peso[nPanini] = 100000;

	for (int i=0; i<nPanini; i++)
		cin >> peso[i];

	cout <<  dp(0, nPanini);
}

/*
	se prendo:
		albero univoco
	se non prendo:
		albero dipendente dal peso dell'ultimo panino mangiato
*/
