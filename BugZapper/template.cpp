// Includes
#include "template.h"

// Namespace
using namespace AGK;

app App;


// Function prototypes
void generateNewBug();
void displayIntro();
void hideIntro();
void playGame();
void closingScreen();


// Constants for the screen resolution
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;

// Constants fo sprites
const int INTRO_INDEX = 1;
const int GRASS_INDEX = 2;
const int BUG_INDEX = 3;

// Constant for the sound file
const int BOINK_SOUND = 1;

// Constants for animation
const int FRAME_WIDTH = 64;
const int FRAME_HEIGHT = 54;
const int FRAME_COUNT = 2;

// Constants for game time
const int MAX_TIME = 10;

// Constants for the possible game states.
const int GAME_JUST_STARTED = 0;
const int GAME_IN_PLAY = 1;
const int GAME_OVER = 3;

// Global counter for the number of bugs zapped.
int g_bugsZapped = 0;
int g_gameState = GAME_JUST_STARTED;

void app::Begin(void)
{
	agk::SetVirtualResolution (SCREEN_WIDTH, SCREEN_HEIGHT);
//	agk::SetClearColor( 151,170,204 ); // light blue
//	agk::SetSyncRate(60,0);
//	agk::SetScissor(0,0,0,0);
	agk::SetWindowTitle("Bug Zapper");
	// Create the background sprite.
	agk::CreateSprite(GRASS_INDEX, agk::LoadImage("BugZapper/Grass.jpg"));
	agk::SetSpriteScale(GRASS_INDEX, 1.8, 1.8);
	// Create the bug sprite.
	agk::CreateSprite(BUG_INDEX, agk::LoadImage("BugZapper/Bug.png"));
	agk::SetSpriteScale(BUG_INDEX, 0.2, 0.2);
	//Create the intro screen sprite.
	agk::CreateSprite(INTRO_INDEX, agk::LoadImage("BugZapper/Intro.png"));
	// Load the sound file.
	agk::LoadSound(BOINK_SOUND, "BugZapper/Boink.wav");
	// Randomly position the bug.
	generateNewBug();
	// Set the sprite animation
	//agk::SetSpriteAnimation(BUG_INDEX, FRAME_WIDTH, FRAME_HEIGHT, FRAME_COUNT);
	// Play the bug animation.
	// agk::PlaySprite(BUG_INDEX);
}

int app::Loop (void)
{
	//agk::Print( agk::ScreenFPS() );

	switch(g_gameState)
	{
		case GAME_JUST_STARTED:
			// Display the intro screen.
			displayIntro();
			
			// Check for a key press.
			if (agk::GetRawLastKey())
			{
				// Hide the intro screen
				hideIntro();

				// Change the game state.
				g_gameState = GAME_IN_PLAY;

				// Reset the timer.
				agk::ResetTimer();
			}
			break;

		case GAME_IN_PLAY:
			// Engae in game play.
			playGame();
			break;
		
		case GAME_OVER:
			// Display the closing screen.
			closingScreen();
			break;
	};

	agk::Sync();

	return 0; // return 1 to close app
}


void app::End (void)
{

}

// The generateNewBug function generates a new bug at random location.
void generateNewBug()
{
	// Get the bug's width and height.
	int bugWidth = agk::GetSpriteWidth(BUG_INDEX);
	int bugHeight = agk::GetSpriteHeight(BUG_INDEX);

	// Generate a new location.
	int x = agk::Random(0, SCREEN_WIDTH - bugWidth);
	int y = agk::Random(0, SCREEN_HEIGHT - bugHeight);

	// Put the bug at that loaction.
	agk::SetSpritePosition(BUG_INDEX, x, y);
}

// The displayIntro function hides the grass and the bug sprite and makes the intro screen visible.
void displayIntro()
{
	// Make the grass and bug invisible.
	agk::SetSpriteVisible(GRASS_INDEX, 0);
	agk::SetSpriteVisible(BUG_INDEX, 0);

	// Make the intro screen visible.
	agk::SetSpriteVisible(INTRO_INDEX, 1);
}


// The hideIntro function hides the intro screen and makes the grass  and bug visible.
void hideIntro()
{
	agk::SetSpriteVisible(INTRO_INDEX, 0);
	agk::SetSpriteVisible(BUG_INDEX, 1);
	agk::SetSpriteVisible(GRASS_INDEX, 1);
}

// the palyGame function processes a frame of game play.
void playGame()
{
	// Variables for mouse coordunates
	float mouseX, mouseY;

	// Do we still have time left?
	if (agk::Timer() < MAX_TIME)
	{
		// Determine if the left mouse button was pressed.
		if (agk::GetRawMouseLeftPressed())
		{
			// Get the mouse pointer location.
			mouseX = agk::GetRawMouseX();
			mouseY = agk::GetRawMouseY();

			// Check to sess if the bug was hit.
			if (agk::GetSpriteHit(mouseX, mouseY) == BUG_INDEX)
			{
				// Play the boink sound.
				agk::PlaySound(BOINK_SOUND);

				// Update the count.
				g_bugsZapped++;

				// Generate a new bug.
				generateNewBug();
			}
		}
	}
	else
	{
		// Time is up, game over.
		g_gameState = GAME_OVER;
	}
}

// The closingScreen function displays the closing screen.
void closingScreen()
{
	// Hide the bug and the grass.
	agk::SetSpriteVisible(GRASS_INDEX, 0);
	agk::SetSpriteVisible(BUG_INDEX, 0);

	// Display the results.
	agk::PrintC("Number of bugs zapped: ");
	agk::Print(g_bugsZapped);
}