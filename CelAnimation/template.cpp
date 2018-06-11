// Includes
#include "template.h"

// Namespace
using namespace AGK;

app App;

const int ScreenWidth = 1024;
const int ScreenHeight = 768;
const int FirstImage = 1;
const int LastImage = 8;
const int SpriteIndex = 1;
const float FPS = 8;
const int MODE = 0;

const int ImageIndex = 11;
const int SpriteIndex2 = 2;
const int FrameWidth = 480;
const int FrameHeight = 480;
const int FrameCount = 8;

const int VirtualButton = 1;
bool bPlay = true;

const int sound = 1;
const int music = 1;


void app::Begin(void)
{
	agk::SetWindowTitle("Cel Animation");

	agk::SetVirtualResolution (ScreenWidth, ScreenHeight);
	agk::SetClearColor( 151,170,204 ); // light blue
	agk::SetSyncRate(FPS,MODE);
	agk::SetScissor(0,0,0,0);

	agk::LoadImage(1, "WalkingMan1.png", 1);
	agk::LoadImage(2, "WalkingMan2.png", 1);
	agk::LoadImage(3, "WalkingMan3.png", 1);
	agk::LoadImage(4, "WalkingMan4.png", 1);
	agk::LoadImage(5, "WalkingMan5.png", 1);
	agk::LoadImage(6, "WalkingMan6.png", 1);
	agk::LoadImage(7, "WalkingMan7.png", 1);
	agk::LoadImage(8, "WalkingMan8.png", 1);

	agk::CreateSprite(SpriteIndex, FirstImage);
	float spriteWidth = agk::GetSpriteWidth(SpriteIndex);
	float spriteHeight = agk::GetSpriteHeight(SpriteIndex);
	float spriteX = ScreenWidth / 2 - spriteWidth / 2;
	float spriteY = ScreenHeight / 2 - spriteHeight / 2;

	agk::SetSpritePosition(SpriteIndex, spriteX, spriteY);

	// ?
	agk::LoadImage(ImageIndex, "Clock.png");
	agk::CreateSprite(SpriteIndex2, ImageIndex);
	agk::SetSpriteScale(SpriteIndex2, 2, 2);
	float FrameWidth = agk::GetSpriteWidth(SpriteIndex2);
	float FrameHeight = agk::GetSpriteHeight(SpriteIndex2);
	// 将精灵设置为动画
	agk::SetSpriteAnimation(SpriteIndex2, FrameWidth, FrameHeight, FrameCount);

	float SpriteX = ScreenWidth / 2 - FrameWidth / 2;
	float SpriteY = ScreenHeight / 2 - FrameHeight / 2;
	agk::SetSpritePosition(SpriteIndex2, SpriteX, SpriteY);
	agk::PlaySprite(SpriteIndex2);

	agk::AddVirtualButton(VirtualButton, 100, 100, 50);

	agk::LoadSound(sound, "_sound_trial.mp3");
	agk::PlaySound(sound);

	agk::LoadMusic(music, "mySound.mp3");
	agk::PlayMusic(music);
}

int app::Loop (void)
{
	agk::Print( agk::ScreenFPS() );

	int currentImage = agk::GetSpriteImageID(SpriteIndex);

	if (currentImage == LastImage)
	{
		currentImage = FirstImage;
	}
	else
	{
		currentImage++;
	}

	agk::SetSpriteImage(SpriteIndex, currentImage);

	if (agk::GetVirtualButtonPressed(VirtualButton))
	{
		if (bPlay)
		{
			// 停止精灵的动画序列
			agk::StopSprite(SpriteIndex);
			bPlay = false;
		}
		else
		{
			// 恢复精灵的的动画序列
			agk::ResumeSprite(SpriteIndex);
			bPlay = true;
		}

	}

	if (bPlay)
	{
		agk::SetVirtualButtonText(VirtualButton, "OFF");
	}
	else
	{
		agk::SetVirtualButtonText(VirtualButton, "ON");
	}
	agk::Sync();

	return 0; // return 1 to close app
}


void app::End (void)
{

}
