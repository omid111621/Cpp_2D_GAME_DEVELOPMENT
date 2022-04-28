// Include important libraries here
#include <SFML/Graphics.hpp>

using namespace sf;

// This is where our game starts from
int main()
{
	// Create a video mode object
	VideoMode video_mode_object(1920, 1080);
	// Create and open a window for the game
	RenderWindow window_object(video_mode_object, "Timber!!!", Style::Fullscreen);

	/*
	***************************************************************************************
									*Working with graphics*
	***************************************************************************************
		Every graphic we use in our game needs to be loaded in the first place.
	To illustate, the graphic needs to be loaded from our harddrive to the GPU.
	This is a bulky and relatively slow process and affects our codes's efficiency.
	The reason is that, imagine in every incrimentatiion of the game's loop all the graphics
	be loaded from our hard drive!
	To prevent this issue, we do the following precedures for each graphicbefore we use it
	in our game:
	1) First we define an object type of Texture for our graphic.
	2) Then we allocate an actual graphic from our harddrive to the Graphic Texture Object.
	3) Then we define an Object type of Sprite for our graphic.
	4) Then we allocated the Graphic Texture Object to the Graphic Sprite Object.

	* This way we only need to load a graphic once!
	* Everything is going to be a Sprite, even the background.
	*/

	// Setting up the background.
	//step 1.
	Texture backgroundTextureObject;
	//step 2.
	backgroundTextureObject.loadFromFile("graphics/background.png");
	//step 3.
	Sprite backgroundSpriteObject;
	//step 4.
	backgroundSpriteObject.setTexture(backgroundTextureObject);
	//Set the position of backgroundSpritebject in order to cover the entire sceen.
	backgroundSpriteObject.setPosition(0, 0);

	// Setting up the tree.
	//step 1.
	Texture treeTextureObject;
	//step 2.
	treeTextureObject.loadFromFile("graphics/tree.png");
	//step 3.
	Sprite treeSpriteObject;
	//step 4.
	treeSpriteObject.setTexture(treeTextureObject);
	//Set the position of treeSpritebject in order to cover the entire sceen.
	treeSpriteObject.setPosition(810, 0);

	// Setting up the bee.
	//step 1.
	Texture beeTextureObject;
	//step 2.
	beeTextureObject.loadFromFile("graphics/bee.png");
	//step 3.
	Sprite beeSpriteObject;
	//step 4.
	beeSpriteObject.setTexture(beeTextureObject);
	//Set the position of treeSpritebject in order to cover the entire sceen.
	beeSpriteObject.setPosition(0, 800);
	// The bee's activity parameters.
	bool beeActivityStatus = false;
	float beeSpeed = 0.0f;
	
	// Setting up the 3 clouds.
	//step 1.
	Texture cloudTextureObject;
	//step 2.
	cloudTextureObject.loadFromFile("graphics/cloud.png");
	//step 3.
	Sprite cloudOneSpriteObject;
	Sprite cloudTwoSpriteObject;
	Sprite cloudThreeSpriteObject;
	//step 4.
	cloudOneSpriteObject.setTexture(cloudTextureObject);
	cloudTwoSpriteObject.setTexture(cloudTextureObject);
	cloudThreeSpriteObject.setTexture(cloudTextureObject);
	//Set the position of treeSpritebject in order to cover the entire sceen.
	cloudOneSpriteObject.setPosition(0, 0);
	cloudTwoSpriteObject.setPosition(0, 250);
	cloudThreeSpriteObject.setPosition(0, 500);
	// The clouds' activity parameters.
	bool cloudOneActivityStatus = false;
	bool cloudTwoActivityStatus = false;
	bool cloudThreeActivityStatus = false;
	float cloudOneSpeed = 0.0f;
	float cloudTwoSpeed = 0.0f;
	float cloudThreeSpeed = 0.0f;
	//Starting the Game Loop.
	while (window_object.isOpen()) {

		/*
		****************************************************
				Handle the players' input
		****************************************************
		*/

		if (Keyboard::isKeyPressed(Keyboard::Escape)) {

			window_object.close();
		}

		/*
		***************************************
				Updte the sene!
		***************************************
		*/

		/*
		***************************************
				Draw the sene!
		***************************************
		*/

		//	Clear everything from the last frame.      //                                                                                          //
		window_object.clear();                         //                                                                                          //
													   //                                                                                          //
		//	Draw the game's scene here.                //                                                                                          //
		window_object.draw(backgroundSpriteObject);    //                                                                                          //
		window_object.draw(treeSpriteObject);	       //Note, however, the order in which we draw the different                                   //
		window_object.draw(treeSpriteObject);	       //objects to the screen.We must draw all of the graphics after the background, or they      //____________ This process is called DOUBLE BUFFERING
		window_object.draw(beeSpriteObject);	       //will be covered, and we must draw the clouds before the tree, or they will look a bit     //
	    window_object.draw(cloudOneSpriteObject);	   //odd drifting in front of the tree.The bee would look OK either in front or behind         //
		window_object.draw(cloudTwoSpriteObject);	   //the tree.I opted to draw the bee in front of the tree so that it can try and distract our //
		window_object.draw(cloudThreeSpriteObject);	   //lumberjack, a bit like a real bee might.                                                  //
		//	Show everything we just drew.              //                                                                                          //
		window_object.display();                       //                                                                                          //

	}

	// End of the Game Loop!

	return 0;
}