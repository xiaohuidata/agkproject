// Includes
#include "template.h"

// Namespace
using namespace AGK;

app App;


const int RobotImage = 1;
const int PizzaImage = 2;
const int YumImage = 3;

const int RobotSprite = 1;
const int PizzaSprite = 2;
const int YumSprite = 3;

const int FrameWidth = 128;
const int FrameHeight = 128;
const int FrameCount = 3;
const float FramesPerSecond = 3;

const float RobotMove = 4;

const float RobotX = 0;

const float RobotY = DEVICE_HEIGHT - FrameHeight;
const int HalfSecond = 500;

const int Hide = 0;
const int Show = 1;

void updateRobot();
void detectCollision();
void showYum();
void generatePizza();

void app::Begin(void)
{
	agk::SetVirtualResolution (1024, 768);
	agk::SetClearColor( 151,170,204 ); // light blue
	agk::SetSyncRate(60,0);
	agk::SetScissor(0,0,0,0);


	agk::SetWindowTitle("PizzaBot");
	
	agk::LoadImage(RobotImage, "PizzaBot/Robot.png");
	agk::LoadImage(PizzaImage, "PizzaBot/Pizza.png");
	agk::LoadImage(YumImage, "PizzaBot/Yum.png");

	agk::CreateSprite(RobotSprite, RobotImage);
	agk::CreateSprite(PizzaSprite, PizzaImage);
	agk::CreateSprite(YumSprite, YumImage);

	agk::SetSpriteAnimation(RobotSprite, FrameWidth, FrameHeight, FrameCount);

	agk::SetSpritePosition(RobotSprite, RobotX, RobotY);

	agk::PlaySprite(RobotSprite, FramesPerSecond);
	
	generatePizza();
}

int app::Loop (void)
{
	agk::Print( agk::ScreenFPS() );


	updateRobot();

	detectCollision();


	agk::Sync();

	return 0; // return 1 to close app
}


void app::End (void)
{

}


void updateRobot()
{
	float robotX = agk::GetSpriteX(RobotSprite);
	float robotY = agk::GetSpriteY(RobotSprite);

	if (agk::GetRawKeyState(AGK_KEY_DOWN))
	{
		robotY += RobotMove;
	}

	if (agk::GetRawKeyState(AGK_KEY_UP))
	{
		robotY -= RobotMove;
	}

	if (agk::GetRawKeyState(AGK_KEY_LEFT))
	{
		robotX -= RobotMove;
	}

	if (agk::GetRawKeyState(AGK_KEY_RIGHT))
	{
		robotX += RobotMove;
	}

	agk::SetSpritePosition(RobotSprite, robotX, robotY);
}

void generatePizza()
{
	float width = agk::GetSpriteWidth(PizzaSprite);
	float height = agk::GetSpriteHeight(PizzaSprite);

	float maxX = DEVICE_WIDTH - width;
	float maxY = DEVICE_HEIGHT + height;

	float x = (float)(agk::Random(0, (int)maxX));
	float y = (float)(agk::Random(0, (int)maxY));

	agk::SetSpriteVisible(YumSprite, Hide);
	agk::SetSpritePosition(PizzaSprite, x, y);
	agk::SetSpritePosition(YumSprite, x, y);
	agk::SetSpriteVisible(PizzaSprite, Show);
}

void showYum()
{
	agk::SetSpriteVisible(PizzaSprite, Hide);

	agk::SetSpriteVisible(YumSprite, Show);

	agk::Sync();

	agk::Sleep(HalfSecond);
}

void detectCollision()
{
	if (agk::GetSpriteCollision(RobotSprite, PizzaSprite))
	{
		showYum();
		
		generatePizza();
	}
}