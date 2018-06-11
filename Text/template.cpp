// Includes
#include "template.h"

// Namespace
using namespace AGK;

app App;

unsigned int TextA;
unsigned int TextB;
unsigned int TextC;
unsigned int TextD;
unsigned int TextE;
unsigned int TextF;

const float SizeA = 12;
const float SizeB = 16;
const float SizeC = 24;
const float SizeD = 36;
const float SizeE = 48;
const float SizeF = 72;


unsigned int LeftText;
unsigned int CenterText;
unsigned int RightText;

const unsigned int AlignLeft = 0;
const unsigned int AlignCenter = 1;
const unsigned int AlignRight = 2;

const float TextSize = 16;
const float CenterX = DEVICE_WIDTH / 2;
const float CenterY = DEVICE_HEIGHT / 2;

unsigned int Text;



const int Ball1Image = 1;
const int Ball2Image = 2;

const int Ball1Sprite = 1;
const int Ball2Sprite = 2;

const float Ball1X = 0;
const float Ball2X = 800;
const float BallY = 575;
const float DISTANCE = 1;

void app::Begin(void)
{
	agk::SetVirtualResolution (DEVICE_WIDTH, DEVICE_HEIGHT);
	agk::SetClearColor( 151,170,204 ); // light blue
	agk::SetSyncRate(60,0);
	agk::SetScissor(0,0,0,0);

	unsigned int TextIndex = agk::CreateText("GAME OVER");

	// agk::DeleteText(TextIndex);

	agk::GetTextExists(TextIndex);

	// 设置文本大小
	agk::SetTextSize(TextIndex, 16);

	// 获取文本大小
	float textSzie = agk::GetTextSize(TextIndex);

	// 这只文本对象位置
	agk::SetTextPosition(TextIndex, 10, 100);

	// 设置对象X坐标
	// agk::SetTextX(TextIndex, X);
	// 设置对象Y坐标
	// agk::SetTextY(TextIndex, Y);


	TextA = agk::CreateText("Text Size 12");
	TextB = agk::CreateText("Text Size 16");
	TextC = agk::CreateText("Text Size 24");
	TextD = agk::CreateText("Text Size 36");
	TextE = agk::CreateText("Text Size 48");
	TextF = agk::CreateText("Text Size 72");
    
	agk::SetTextSize(TextA, SizeA);
	agk::SetTextSize(TextB, SizeB);
	agk::SetTextSize(TextC, SizeC);
	agk::SetTextSize(TextD, SizeD);
	agk::SetTextSize(TextE, SizeE);
	agk::SetTextSize(TextF, SizeF);
	/*
	agk::SetTextSize(TextA, SizeC);
	agk::SetTextSize(TextB, SizeC);
	agk::SetTextSize(TextC, SizeC);
	agk::SetTextSize(TextD, SizeC);
	agk::SetTextSize(TextE, SizeC);
	agk::SetTextSize(TextF, SizeC);
	*/
	agk::SetTextSpacing(TextA, 0);
	agk::SetTextSpacing(TextB, 10);
	agk::SetTextSpacing(TextC, 20);
	agk::SetTextSpacing(TextD, 30);
	agk::SetTextSpacing(TextE, 40);
	agk::SetTextSpacing(TextF, 50);

	float x = 0;
	float y = 0;

	agk::SetTextPosition(TextA, x, y);
	y += SizeA;

	agk::SetTextPosition(TextB, x, y);
	y += SizeB;

	agk::SetTextPosition(TextC, x, y);
	y += SizeC;

	agk::SetTextPosition(TextD, x, y);
	y += SizeD;

	agk::SetTextPosition(TextE, x, y);
	y += SizeE;

	agk::SetTextPosition(TextF, x, y);
	y += SizeF;


	LeftText = agk::CreateText("Left-aligned");
	CenterText = agk::CreateText("Center-aligned");
	RightText = agk::CreateText("Right-aligned");

	agk::SetTextSize(LeftText, TextSize);
	agk::SetTextSize(CenterText, TextSize);
	agk::SetTextSize(RightText, TextSize);

	agk::SetTextAlignment(LeftText, AlignLeft);
	agk::SetTextAlignment(CenterText, AlignCenter);
	agk::SetTextAlignment(RightText, AlignRight);

	agk::SetTextPosition(LeftText, CenterX, CenterY - 40);
	agk::SetTextPosition(CenterText, CenterX, CenterY);
	agk::SetTextPosition(RightText, CenterX, CenterY + 40);


	Text = agk::CreateText("");
	agk::SetTextSize(Text, SizeB);
	agk::SetTextAlignment(Text, AlignCenter);
	agk::SetTextPosition(Text, CenterX, CenterY + 80);


	agk::SetWindowTitle("Sprite Collision");
	agk::LoadImage(Ball1Image, "BowlingBall1.png");
	agk::LoadImage(Ball2Image, "BowlingBall2.png");
	agk::CreateSprite(Ball1Sprite, Ball1Image);
	agk::CreateSprite(Ball2Sprite, Ball2Image);
	agk::SetSpritePosition(Ball1Sprite, Ball1X, BallY);
	agk::SetSpritePosition(Ball2Sprite, Ball2X, BallY);
}

int app::Loop (void)
{
	agk::Print( agk::ScreenFPS() );

	float mouseX = agk::GetRawMouseX();
	float mouseY = agk::GetRawMouseY();

	if (agk::GetTextHitTest(Text, mouseX, mouseY))
	{
		agk::SetTextString(Text, "Ouch! You hit me.");
		agk::SetTextColor(Text, 255, 255, 0);
	}
	else
	{
		agk::SetTextString(Text, "I am a text object.");
		agk::SetTextColor(Text, 0, 255, 255, 55);
	}


	float ball1x = agk::GetSpriteX(Ball1Sprite);
	float ball2x = agk::GetSpriteX(Ball2Sprite);

	// 精灵碰撞
	if (agk::GetSpriteCollision(Ball1Sprite, Ball2Sprite))
	{
		agk::SetSpriteX(Ball1Sprite, Ball1X);
		agk::SetSpriteX(Ball2Sprite, Ball2X);
	}
	else
	{
		agk::SetSpriteX(Ball1Sprite, ball1x + DISTANCE);
		agk::SetSpriteX(Ball2Sprite, ball2x - DISTANCE);
	}

	agk::Sync();

	return 0; // return 1 to close app
}


void app::End (void)
{

}
