// Includes
#include "template.h"
#include <iostream>
#include <string>

// Namespace
using namespace AGK;

app App;

void app::Begin(void)
{
	agk::SetVirtualResolution (320, 480);
	agk::SetClearColor( 151,170,204 ); // light blue
	agk::SetSyncRate(60,0);
	agk::SetScissor(0,0,0,0);

	unsigned int bgImage = agk::LoadImage("background.jpg");
	unsigned int bgSprite = agk::CreateSprite(bgImage);

	unsigned int balloon = agk::CreateSprite(0);
	agk::SetSpritePosition(balloon, 130, 200);

	std::vector<int> animImages;
	for (int i = 0; i <= 4; i++)
	{
		std::string str_teger = { "item" + std::to_string(i) + ".png" };
		unsigned int integer = agk::LoadImage(str_teger.c_str());
		agk::AddSpriteAnimationFrame(balloon, integer);
	}

	agk::PlaySprite(balloon, 10, 1, 1, 5);
}

int app::Loop (void)
{
	agk::Print( agk::ScreenFPS() );
	agk::Sync();

	return 0; // return 1 to close app
}


void app::End (void)
{

}
