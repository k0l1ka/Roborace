#include <iostream>
using namespace std;

void Printm(int m[8][8]){
		for (int i = 0;i < 8; i++){
			for (int j= 0;j < 8; j++){
				cout<<m[i][j]<<"  ";	
			}
			cout<<endl;
		}
	}


int main()
{
	int w[8][8];

	w[0][0]= 0;
	w[1][1]= 0;
	w[2][2]= 0;
	w[3][3]=0 ;
	w[4][4]=0 ;
	w[5][5]= 0;
	w[6][6]= 0;
	w[7][7]= 0;

	w[0][1]= 7;
	w[1][2]= 8;
	w[2][3] = 4;
	w[3][7] =8 ;
	
	w[2][7] = 11;
	w[1][4] = 2;
	w[4][7] = 7;
	w[4][6] = 6;
	
	w[6][7] = 1;
	w[1][5] = 4;
	w[6][5] = 2;
	w[0][5] = 14;



	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			if (w[i][j] > 0){
				w[j][i] = w[i][j]; 
			}
		}
	}

	Printm(w);


	return 0; 
}