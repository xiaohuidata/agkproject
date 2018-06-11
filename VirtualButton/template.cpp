// Includes
#include "template.h"

// Namespace
using namespace AGK;

app App;

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;
const int SPRITE_INDEX = 1;
const int SHOW_BUTTON_INDEX = 1;
const int HIDE_BUTTON_INDEX = 2;
const float BUTTON_SIZE = 100.0;

void app::Begin(void)
{
	agk::SetWindowTitle("Virtual Buttons");
	agk::SetVirtualResolution (SCREEN_WIDTH, SCREEN_HEIGHT);
	agk::SetClearColor( 151,170,204 ); // light blue
	agk::SetSyncRate(60,0);
	agk::SetScissor(0,0,0,0);

	agk::CreateSprite(SPRITE_INDEX, agk::LoadImage("rabbit.png"));

	float spriteWidth = agk::GetSpriteWidth(SPRITE_INDEX);
	float spriteX = (SCREEN_WIDTH - spriteWidth) / 2;
	float spriteY = 0.0;

	agk::SetSpritePosition(SPRITE_INDEX, spriteX, spriteY);

	float showButtonX = SCREEN_WIDTH / 2 - BUTTON_SIZE;
	float showButtonY = SCREEN_HEIGHT - BUTTON_SIZE;

	float hideButtonX = SCREEN_WIDTH / 2 + BUTTON_SIZE;
	float hideButtonY = SCREEN_HEIGHT - BUTTON_SIZE;

	// agk::AddVirtualButton(Index, x, y, Size)
	// index 1-12; x����, y���꣬Size ��С
	agk::AddVirtualButton(SHOW_BUTTON_INDEX, showButtonX, showButtonY, BUTTON_SIZE);
	agk::AddVirtualButton(HIDE_BUTTON_INDEX, hideButtonX, hideButtonY, BUTTON_SIZE);

	// ��ʾ�ı�
	agk::SetVirtualButtonText(SHOW_BUTTON_INDEX, "Show");
	agk::SetVirtualButtonText(HIDE_BUTTON_INDEX, "Hide");
	
	// ��ť��С
	agk::SetVirtualButtonSize(SHOW_BUTTON_INDEX, 50);

	// ��ť��ɫ
	// SetVirtualButtonColor(Index, Red, Green, Blue)
	// �����ֱ��Ǻ졢�̡�����0-255
	agk::SetVirtualButtonColor(HIDE_BUTTON_INDEX, 255, 255, 0);

	// ��ť͸���� 0-255
	agk::SetVirtualButtonAlpha(HIDE_BUTTON_INDEX, 40);

	// ��ʾ�����ذ�ť 0���� 1��ʾ
	agk::SetVirtualButtonVisible(SHOW_BUTTON_INDEX, 0);

	// ���û���ð�ť 0���� 1����
	agk::SetVirtualButtonActive(HIDE_BUTTON_INDEX, 0);

	// �޸İ�ťͼ��
	// agk::SetVirtualButtonImageUp(1, up);  ��ţ̌��ʱͼ��
	// agk::SetVirtualButtonImageDown(2, dowm); ��ť����ʱͼ��
}

int app::Loop (void)
{
//	agk::Print( agk::ScreenFPS() );
	// agk::GetVirtaulButtonPressed(1); ���°�ť����1��֮�󷵻�0
	// agk::GetVirtaulButtonState(1);   ��ť����ס���ŷ���1�����򷵻�0
	// agk::GetVirtaulButtonReleased(1);��ť�ɿ�ʱ����1��֮�󷵻�0
	if (agk::GetVirtualButtonPressed(SHOW_BUTTON_INDEX))
	{
		agk::SetSpriteVisible(SPRITE_INDEX, 1);
	}

	if (agk::GetVirtualButtonPressed(HIDE_BUTTON_INDEX))
	{
		agk::SetSpriteVisible(SPRITE_INDEX, 0);
	}

	agk::Sync();

	return 0; // return 1 to close app
}


void app::End (void)
{

}
