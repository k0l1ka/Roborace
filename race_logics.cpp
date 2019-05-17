#include <iostream>
#include <fstream>
#include <cstdlib>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <iomanip>
#include <cctype>
#include <utility>


using namespace std;

#define player1_id  3
#define player2_id  4
#define track  0  //road
#define grass  7  //not road
#define start  1 
#define finish  2



fstream file_with_Map;
string line;
int line_lenght;
int height;
int width;

int cells_width = 34;
int cells_height = 19;

int Map[100][100];





class Player
{

private:
	int id;
	int currentX, currentY, startX, startY;
	int shiftX, shiftY; //from current point (=player) position
	int radius;
	//wxColor color;

public:
	//friend class Player;
	
	Player(int player_id)
	{
		for (int i = 0; i < cells_height; i++)
		{
			for (int j = 0; j < cells_width; j++)
			{
				if (Map[i][j] == player_id)
				{
					this->startX = j;
					this->startY = i;
				}
			}
		}
		this->shiftX = 0;
		this->shiftY = 0;
		this->id = player_id; 
		this->currentX = startX; // horizontal from left to right
		this->currentY = startY; // vertical from up to down
	};


	pair <int,int> get_current_pos()
	{	
		pair <int,int> position = make_pair(this->currentX, this->currentY);
		return position; 
	}


	int is_collapse(Player partner) //one with another or with grass
	{
		if ( (this->get_current_pos().first == partner.get_current_pos().first) && 
			(this->get_current_pos().second == partner.get_current_pos().second) )
		{
			return 1;
		}
		else
			return 0;

		if (Map[this->get_current_pos().second][this->get_current_pos().first] == grass)
		{
			return 1;
		}
	};

	void move_to_start(Player this_player)
	{
		this->currentX = this->startX;
		this->currentY = this->startY;	
	};

	int player_won()
	{
		int current_X = this->get_current_pos().first;
		int current_Y = this->get_current_pos().second;
		int previous_X = current_X - this->shiftX;
		int previous_Y = current_Y - this->shiftY;

		int finished = 0;

		for (int i = previous_X; i < current_X; i++)
		{
			for (int j = previous_Y; j < current_Y; j++)
			{
				if (Map[j][i] == finish)
				{
					return 1;	
				}
				else 
					return 0;
			}			
		}
	};
	
	void move(int x, int y)
	{
		Map[currentX][currentY] = track;
		cout << "старую позициб замазал\n";
		this->shiftX = x;
		this->shiftY = y;
		cout <"шифт обновил\n";
		currentX += shiftX;
		currentY += shiftY;
		cout <"каррент позицию обновил\n";
		Map[currentX][currentY] = this->id;
		cout <"новую позицию наривал\n";
	}
};











void load_map()//загрузить карту из файла 
{
	file_with_Map.open("./Map1");

	//cout << "loading Map matrix from file\n";

	height = -1;

 	if (file_with_Map.is_open())
 	{
   		while (getline(file_with_Map, line) )
   	 	{
   	 		height++;

   	 		line_lenght = line.size();

   	 		width = -1;

   	 		for (int item = 0; item < line_lenght; item++)
      		{
      			if (isdigit(line[item]))
      			{
      				width++;
      				Map[height][width] = atoi(&line[item]) ; 
      				//cout << setw(3) << line[item] <<"->"<< Map[height][width]; 
      			}
      		}
      		//cout << endl;
    	}

    	file_with_Map.close();
  	}

  	else cout << "Unable to open file"; 
}



void print_map()
{
	for (int i = 0; i < cells_height; i++)
	{
		for (int j = 0; j < cells_width; j++)
		{
			cout << setw(3)<< Map[i][j];
		}
		cout << endl;
	}

	cout << endl << endl << endl;
}



void game()
{
	load_map();
	print_map();

	Player racer1(player1_id);
	Player racer2(player2_id);

	while (!( racer1.player_won() ) && !(racer2.player_won()) )
	{
		int x, y;

		cout << "Ходит 1 игрок: ввести вектор сдвига -- х и у\n";
		cin >> x, y;
		cout << "делаю ход\n";

		racer1.move(x, y);
		
		print_map();

		cout << "Ходит 2 игрок: ввести вектор сдвига -- х и у";
		cin >> x, y;
		racer2.move(x, y);
		print_map();		
	}
	cout << "GAME OVER\n";
}



int main()
{	
/*
// матрицу заполнить нулями

	for (int i = 0; i < cells_height; i++)
	{
		for (int j = 0; j < cells_width; j++)
		{
			Map[i][j] = 0;
		}
	}
//отрисовка границ

	for (int i = 6; i < cells_height; i++)
	{
		Map[i][20] = 7;
	}

	for (int i = 12; i < cells_height; i++)
	{
		Map[i][14] = 7;
	}

	for (int j = 0; j < 20; j++)
	{
		Map[6][j] = 7;
	}

	for (int j = 0; j < 14; j++)
	{
		Map[12][j] = 7;
	}

	for (int j = 14; j < 21; j++)
	{
		Map[cells_height-1][j] = 2;
	}

	for (int i = 6; i < 13; i++)
	{
		Map[i][0] = 1;
	}
*/

//сохранить матрицу в файл

/*
	FILE *temp = fopen("./Map1", "wb");
	fclose(temp);

	file_with_Map.open("./Map1");

	if (file_with_Map.is_open())
 	{
 		for (int i = 0; i < cells_height; i++)
		{
			for (int j = 0; j < cells_width; j++)
			{
				file_with_Map << setw(3) << Map[i][j];
			}
			file_with_Map << endl;
		}

    	file_with_Map.close();
  	}

  	else cout << "Unable to open file";
*/
	game();

	return 0;
}