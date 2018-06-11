// Includes
#include "template.h"

// Namespace
using namespace AGK;

app App;

const int SCREEN_WIDH = 1200; //640;
const int SCREEN_HEIGHT = 840; //480;

unsigned int iClone;

void app::Begin(void)
{
//	agk::SetVirtualResolution (1024, 768);
	// �����ɫ
	agk::SetClearColor( 151,170,204 ); // light blue
//	agk::SetSyncRate(60,0);
//	agk::SetScissor(0,0,0,0);

	// ���õ�ͼ��С������ֱ���640��480�����аٷֱ�
	agk::SetVirtualResolution(SCREEN_WIDH, SCREEN_HEIGHT);
	// ����ͼƬ
	unsigned int iBack = agk::LoadImage("back.png");
	// 1-4294967295  2^32
	agk::CreateSprite(1, iBack);

	unsigned int iElf = agk::LoadImage("elf1.jpg");
	agk::CreateSprite(2, iElf);

	agk::CreateSprite(3, iElf);
	// ����λ��
	agk::SetSpritePosition(3, 200, 0);

	// ����˳��(0-100)  100�ڵ�
	agk::SetSpriteDepth(2, 12);
	agk::SetSpriteDepth(1, 100);
	agk::SetSpriteDepth(3, 0);

	// ����x y
	agk::CreateSprite(4, iElf);
	agk::SetSpriteX(4, 400);
	agk::SetSpriteY(4, 200);
	agk::SetSpriteDepth(4, 0);

	// ����
	agk::SetSpriteScale(4, 1.5, 1.5);
	agk::SetSpriteScale(3, 0.5, 0.5);

	// ��ת 0-359
	agk::SetSpriteAngle(3, 35);
	agk::SetSpriteAngle(4, 90);

	// ��������ʾ 0���ɼ�,1�ɼ�
	agk::SetSpriteVisible(3, 0);
	agk::SetSpriteVisible(4, 1);

	// ��¡
	iClone = agk::CloneSprite(3);
	agk::SetSpriteVisible(iClone, 1);
	agk::SetSpriteAngle(iClone, 90);
	agk::SetSpriteY(iClone, 200);
	agk::SetSpriteDepth(iClone, 0);

	// ��ɫ͸����������   ��ɫ����͸��1, 0��ʾ��ɫ
	// agk::LoadImag(ImageIndex, ImageFile, BlackToTransparent);

	// ɾ��
	// agk::DeleteSprite(iClone);

	// ͬ��Ƶ�ʣ��ֳ�֡Ƶ����Ĭ��ÿ��ִ��Լ60�Σ�(60fps)
	// agk::SetSyncRate(FramesPerSecond, Mode);
	// FramesPerSecond ָ��֡
	// Mode ��0,1�� 0������ʹ�ý��ٵ�CPU�����������ƶ��豸���ã���1��������ܼ���ʹ��CPU����������Ĺ��ţ���ͬ��Ƶ�ʻ����ȷ��
	agk::SetSyncRate(15, 1);
}

const float ROTATION = 1;
const float GHOST_END_X = 540;
const int INCREMENT = 1;

const int elf1 = 4;
const int elf2 = 2;

int sprite1 = 0;
int sprite2 = 50;
int sprite3 = 100;
int sprite4 = 150;
int sprite5 = 200;
int sprite6 = 250;

int app::Loop (void)
{
//	agk::Print( agk::ScreenFPS() );
	
	float ghostAngle = agk::GetSpriteAngle(4);
	agk::SetSpriteAngle(4, ghostAngle + ROTATION);

	float ghostX = agk::GetSpriteX(4);
	if (ghostX < GHOST_END_X)
	{
		agk::SetSpriteX(4, ghostX + INCREMENT);
	}
	else
	{
		agk::SetSpriteX(4, 0);
	}

	// ��ɫ 0-255 ���� ����
/*	agk::SetSpriteColorRed(elf1, 0);
	agk::SetSpriteColorRed(elf2, 255);*/

	agk::SetSpriteColorRed(elf1, ++sprite1);
	if (sprite1 == 255)
		sprite1 = 0;

	agk::SetSpriteColorGreen(elf2, ++sprite2);
	if (sprite2 == 255)
		sprite2 = 0;
	agk::SetSpriteColorBlue(iClone, ++sprite3);
	if (sprite3 == 255)
		sprite3 = 0;
	// ͸���� 0-255
	agk::SetSpriteColorAlpha(elf1, ++sprite4);	// ��͸��
	if (sprite4 == 255)
		sprite4 = 0;
	agk::SetSpriteColorAlpha(elf2, ++sprite5);
	if (sprite5 == 255)
		sprite5 = 0;
	agk::SetSpriteColorAlpha(iClone, ++sprite6);
	if (sprite6 == 255)
		sprite6 = 0;
	//agk::SetSpriteColorAlpha(elf2, 0);
	//agk::SetSpriteColorAlpha(elf2, 0);		// 0���ɼ�
	//agk::SetSpriteColorAlpha(iClone, 255);	// 255��͸��


	// ͬ����Ļ����̨������
	int iNum = 1;
	float fNum = 99.5;
	std::string str = "ssss";
	AGK::uString ustr = "sssss";
	agk::Print("This demonstrates the agk::Print function.");
	agk::Print("Here are an int and a float:");
	agk::Print(iNum);
	agk::Print(fNum);
	agk::Print(str.c_str());
	agk::Print(ustr);

	str += "\n";
	ustr += "\n";
	agk::PrintC(str.c_str());
	agk::PrintC(ustr);

	agk::SetWindowTitle("My AGK Program");

	agk::Sync();

	return 0; // return 1 to close app
}


void app::End (void)
{

}
