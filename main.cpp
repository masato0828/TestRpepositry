#include "_debug/_DebugConOut.h"
#include "_debug/_DebugDispOut.h"
#include <Dxlib.h>
#include <array>
#include <windows.h>

#define RUN_MAX 6

struct  Vector2
{
	float x, y;
	
};

//float Left() const {
//
//}
//float Right() const {
//
//}
//float Top() const {
//
//}
//float Bottom() const {
//
//}


//adventurer - run - 05.png

int image[RUN_MAX];
//void MoveByInput()
//{
//	constexpr float speed = 4.0f;
//	if (keystate[KEY_INPUT_LEFT]) {
//		rcA.center.x -= speed;
//	}
//	if (keystate[KEY_INPUT_RIGHT]) {
//		rcA.center.x += speed;
//	}
//	if (keystate[KEY_INPUT_UP]) {
//		rcA.center.y -= speed;
//	}
//	if (keystate[KEY_INPUT_DOWN]) {
//		rcA.center.y += speed;
//	}
//}
int count;
int p;


Vector2 pos,size;
int charaMoveSpeed;

bool SysInit(void)
{
	SetWindowText("2016014_çüë∫âÎêl");
	SetGraphMode(640, 480, 32);
	ChangeWindowMode(true);


	if (DxLib_Init() == -1)
	{
		return false;
	}
	return true;
}

void MoveChara(void)
{
	if (CheckHitKey(KEY_INPUT_UP))
	{
		pos.y -= charaMoveSpeed;
		size.y -= charaMoveSpeed;
	}
	if (CheckHitKey(KEY_INPUT_DOWN))
	{
		pos.y += charaMoveSpeed;
		size.y += charaMoveSpeed;
	}
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		pos.x -= charaMoveSpeed;
		size.x -= charaMoveSpeed;
	}
	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		pos.x += charaMoveSpeed;
		size.x += charaMoveSpeed;
	}

}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PSTR lpCmdLine, int nCmdShow)
{

	if (!SysInit())
	{
		return  -1;
	}

	image[0] = LoadGraph("../Asset/Adventurer-1.5/Individual Sprites/adventurer-run-00.png");
	if (image[0] == -1)
	{
		TRACE("0 = âÊëúÇÃì«Ç›çûÇ›Ç…é∏îs\n");
	}
	image[1] = LoadGraph("../Asset/Adventurer-1.5/Individual Sprites/adventurer-run-01.png");
	image[2] = LoadGraph("../Asset/Adventurer-1.5/Individual Sprites/adventurer-run-02.png");
	image[3] = LoadGraph("../Asset/Adventurer-1.5/Individual Sprites/adventurer-run-03.png");
	image[4] = LoadGraph("../Asset/Adventurer-1.5/Individual Sprites/adventurer-run-04.png");
	image[5] = LoadGraph("../Asset/Adventurer-1.5/Individual Sprites/adventurer-run-05.png");

	
	/*Rect rcA = { 100,100,50,50 };
	KeyboarData_t keystate;*/

	p = 0;
	count = 0;

	pos = {0,0};
	size = {50,37};

	charaMoveSpeed = 4;


	SetDrawScreen(DX_SCREEN_BACK);
	while (ProcessMessage() != -1)
	{
		count++;

		if (count = count % 10)
		{
			if(count == 9)
			p++;
		}
		if (p == 6)
		{
			p = 0;
		}

		MoveChara();

		ClearDrawScreen();
		
		DrawFormatString(0, 0, 0xffffff, "count = %d\n", count);
		
		DrawExtendGraph(pos.x, pos.y, size.x+50*2, size.y+37*2, image[p], true);
		//DrawGraph(0, 0, image[p], true);
		
		//DrawGraph(0, 0, image[0], true);

			

		/*DrawGraph(50, 0, image[1], true);
		DrawGraph(100, 0, image[2], true);
		DrawGraph(150, 0, image[3], true);
		DrawGraph(200, 0, image[4], true);
		DrawGraph(250, 0, image[5], true);*/

		/*GetHitKeyStateAll(keystate.date());
		MoveByInput(keystate, rcA.center);
		DrawBox(rcA.Left(), rcA.Top(), rcA.Right(), rcA.Bottom(), 0xffffff, true);
		char out[64];
		sprintf_s(out, 64,"x=%f,y=%f\n",rcA,center.x, rcA, center.y,)
		
		OutputDebugStringA(out);*/
		ScreenFlip();
	}
	DxLib_End();

}

