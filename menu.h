
#include <bits/stdc++.h>

using namespace std;

const int Up = 72;
const int Down = 80;

int MenuThuancutee(char td[][100], int size, int width, int arr[], int x){
	hidecursor();
	Draw_frame();
	int chon = 0;
	reset:
		int step = 6;
		for (int i=0; i<size; i++){
			i == chon ? DrawBorder(x, step, width, 2, 12) : DrawBorder(x, step, width, 2, 3);
			i == chon ? SetColor(12) : SetColor(3);

			gotoxy(60, step + 1);
			cout << "                          ";
			gotoxy(arr[i], step + 1);
			cout << td[i];
			step += 4;
		}
		
	step = 6;
	gotoxy(arr[0], step+1);
	
	char input;
	int count = 1;
	do{
		input = getch();
		if(input == -32)
			input = getch();

		SetColor(0);
		switch (input){
			case Up:
				if(chon > 0){
					chon--;
					goto reset;
				}
				break;
				
			case Down:
				if(chon + 1 != size){
					chon++;
					goto reset;
				}
				break;
		case 13:
			return chon + 1;
		}

	} while(1);
}

