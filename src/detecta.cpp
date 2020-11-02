#include <stdio.h>
#include <memory>
#include <iostream>

class Detecta {
	public:
		int **visao(int direcao, int alcance, int x, int y, int n, int m);
		int deteccao(int** Mapa, int** V, int x_visao, int y_visao, int x_jog, int y_jog, int n, int m);
};

int** Detecta::visao(int direcao, int alcance, int x, int y, int n, int m){
	int aux1;
	aux1 = x; x = y; y = aux1;
	aux1 = n; n = m; m = aux1;
	int** V = new int*[n];
	for (int i = 0; i < n; ++i)
    		V[i] = new int[m];
	int aux;
	switch (direcao) {
		case 0:
			V[x][y] = 1;
			for (int i = x + 1; i < alcance + x + 1; i++) {
				if(i >= n) break;
				V[i][y] = 1;
				aux = y;
				while(1) {
					if(V[i-1][aux] == 1) {
						if(aux + 1 < m) V[i][aux+1] = 1;
						if(aux - 1 >= 0) V[i][aux-1] = 1;
					}
					if(V[i-1][aux+1] == 1) {
						if(aux + 1 < m) V[i][aux+1] = 1;
						if(aux + 2 < m) V[i][aux+2] = 1;
						if(aux - 1 >= 0) V[i][aux-1] = 1;
						if(aux - 2 >= 0) V[i][aux-2] = 1;
						aux++;
					}
					else break;
				}
			}
		return V;

		case 1:
			V[x][y] = 1;
			for (int i = x - 1; i > x - alcance - 1; i--) {
				if(i < 0) break;
				V[i][y] = 1;
				aux = y;
				while(1) {
					if(V[i+1][aux] == 1) {
						if(aux + 1 < m) V[i][aux+1] = 1;
						if(aux - 1 >= 0) V[i][aux-1] = 1;
					}
					if(V[i+1][aux+1] == 1) {
						if(aux + 1 < m) V[i][aux+1] = 1;
						if(aux + 2 < m) V[i][aux+2] = 1;
						if(aux - 1 >= 0) V[i][aux-1] = 1;
						if(aux - 2 >= 0) V[i][aux-2] = 1;
						aux++;
					}
					else break;
				}
			}
		return V;

		case 2:
			V[x][y] = 1;
			for (int i = y + 1; i < alcance + y + 1; i++) {
				if(i >= m) break;
				V[x][i] = 1;
				aux = x;
				while(1) {
					if(V[aux][i-1] == 1) {
						if(aux + 1 < m) V[aux+1][i] = 1;
						if(aux - 1 >= 0) V[aux-1][i] = 1;
					}
					if(V[aux+1][i-1] == 1) {
						if(aux + 1 < n) V[aux+1][i] = 1;
						if(aux + 2 < n) V[aux+2][i] = 1;
						if(aux - 1 >= 0) V[aux-1][i] = 1;
						if(aux - 2 >= 0) V[aux-2][i] = 1;
						aux++;
					}
					else break;
				}
			}
		return V;

		case 3:
			V[x][y] = 1;
			for (int i = y - 1; i > y - alcance - 1; i--) {
				if(i < 0) break;
				V[x][i] = 1;
				aux = x;
				while(1) {
					if(V[aux][i+1] == 1) {
						if(aux + 1 < m) V[aux+1][i] = 1;
						if(aux - 1 >= 0) V[aux-1][i] = 1;
					}
					if(V[aux+1][i+1] == 1) {
						if(aux + 1 < n) V[aux+1][i] = 1;
						if(aux + 2 < n) V[aux+2][i] = 1;
						if(aux - 1 >= 0) V[aux-1][i] = 1;
						if(aux - 2 >= 0) V[aux-2][i] = 1;
						aux++;
					}
					else break;
				}
			}
		return V;

		case 4:
			for (int i = 0; i <= alcance; i++) {
				if((x + i) >= n || (y + i) >= m) break;
				V[x+i][y+i] = 1;
				for (int j = 1; j < (2*(alcance - i)) + 1; j++)  {
					if(x + j + i < n) V[x+j+i][y+i] = 1;
					if(y + j + i < m) V[x+i][y+j+i] = 1;
				}
			}
		return V;

		case 5:
			for (int i = 0; i <= alcance; i++) {
				if((x - i) < 0 || (y + i) >= m) break;
				V[x-i][y+i] = 1;
				for (int j = 1; j < (2*(alcance - i)) + 1; j++)  {
					if(x - j - i >= 0) V[x-j-i][y+i] = 1;
					if(y + j + i < m) V[x-i][y+j+i] = 1;
				}
			}
		return V;

		case 6:
			for (int i = 0; i <= alcance; i++) {
				if((x + i) >= n || (y - i) < 0) break;
				V[x+i][y-i] = 1;
				for (int j = 1; j < (2*(alcance - i)) + 1; j++)  {
					if(x + j + i < n) V[x+j+i][y-i] = 1;
					if(y - j - i >= 0) V[x+i][y-j-i] = 1;
				}
			}
		return V;

		case 7:
			for (int i = 0; i <= alcance; i++) {
				if((x - i) < 0 || (y - i) < 0) break;
				V[x-i][y-i] = 1;
				for (int j = 1; j < (2*(alcance - i)) + 1; j++)  {
					if(x - j - i >= 0) V[x-j-i][y-i] = 1;
					if(y - j - i >= 0) V[x-i][y-j-i] = 1;
				}
			}
		return V;
	}
}

int Detecta::deteccao(int** Mapa, int** V, int x_visao, int y_visao, int x_jog, int y_jog, int n, int m) {
	if(V[x_jog][y_jog] != 1) return 0;
	int delta_x = x_jog - x_visao;
	int delta_y = y_jog - y_visao;
	int delta = delta_y/delta_x;
	if(delta_x > 0 && delta_y > 0) {
		for (int i = x_visao; i < x_visao + delta_x; i++) {
			for (int j = y_visao; j < y_visao + delta_y; j++) {
				if((y_visao - j) - (delta*(x_visao - i)) <= 3) {
					if(i < n && j < m) {
						if(Mapa[i][j] != 0) return 0;
					}
				}
			}
		}
	}

	else if(delta_x > 0 && delta_y < 0) {
		for (int i = x_visao; i < x_visao + delta_x; i++) {
			for (int j = y_visao; j > y_visao + delta_y; j--) {
				if((y_visao - j) - (delta*(x_visao - i)) <= 3) {
					if(i < n && j > 0) {
						if(Mapa[i][j] != 0) return 0;
					}
				}
			}
		}
	}

	else if(delta_x < 0 && delta_y > 0) {
		for (int i = x_visao; i > x_visao + delta_x; i--) {
			for (int j = y_visao; j < y_visao + delta_y; j++) {
				if((y_visao - j) - (delta*(x_visao - i)) <= 3) {
					if(i > 0 && j < m) {
						if(Mapa[i][j] != 0) return 0;
					}
				}
			}
		}
	}

	else if(delta_x < 0 && delta_y < 0) {
		for (int i = x_visao; i > x_visao + delta_x; i--) {
			for (int j = y_visao; j > y_visao + delta_y; j--) {
				if((y_visao - j) - (delta*(x_visao - i)) <= 3) {
					if(i > 0 && j > 0) {
						if(Mapa[i][j] != 0) return 0;
					}
				}
			}
		}
	}

	return 1;
}
