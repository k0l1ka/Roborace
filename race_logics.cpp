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

#define player1  3
#define player2  4
#define track  0
#define grass  7
#define start  1
#define finish  2



class Player()
{

private:
	int currentX, currentY, startX, startY;
	int vx, vy;
	int radius;
	//wxColor color;

public:
	//friend class Player;
	pair <int,int> get_current_pos()
	{	
		pair <int,int> pos = make_pair(this->currentX, this->currentY);
		return pos; 
	}

	Player(int player_id)
	{
		for (int i = 0; i < cells_height; i++)
		{
			for (int j = 0; j < cells_width; j++)
			{
				if (Map[i][j] == player_id)
				{
					startX = j;
					startY = i;
				}
			}
		}

		currentX = startX;
		currentY = startY;
	};

	int is_collapse(Player partner)
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

	int check_win()
	{
		for (int i = this->get_current_pos().second; i < this->get_current_pos().first - vy; i++)
	};
	
}



int game_over()
{

}





fstream file_with_Map;
string line;
int line_lenght;
int height;
int width;
int cells_width = 34;
int cells_height = 19;
int Map[100][100];



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

	while (!())
	{

	} 
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

	load_map();
	print_map();
	
	return 0;
}