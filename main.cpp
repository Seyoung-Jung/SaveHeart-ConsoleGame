#ifndef __HEARTGAME_H__
#define __HEARTGAME_H__
#include "HeartGame.h"
#endif

using namespace std;

int main(){
//	changeInit();
//	Sleep(1000);
	system("color 07");
	Init();
	Game game1 = Game();
	game1.gameStart();

	return 0;
}

