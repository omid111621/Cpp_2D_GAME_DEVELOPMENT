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
	Texture backgroundTexture;
	// Setting up our background.
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

		//	Clear everything from the last frame.    //
		window_object.clear();                       //
													 // ____________ This process is called DOUBLE BUFFERING
		//	Draw our game background here.           // 
		window_object.draw(backgroundSpriteObject);  //
		//	Show everything we just drew.            //
		window_object.display();                     //

	}

	// End of the Game Loop!

	return 0;
}