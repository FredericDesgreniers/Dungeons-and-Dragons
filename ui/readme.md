#GuiManager

The GUI manager is what manages screens and takes care of telling a screen when to render things, when to do logic calculations or when the screen is clicked. 

### Screen* setScreen(Screen* screen)

Sets the new screen and returns the old screen. The old screen can be saved for future use or sent to the voidedScreens, which is managed by Renderer.
example: 

```
Screen* screen = this->game->getGuiManager()->setScreen(new ScreenMain(this->game));
Renderer::addVoidScreen(screen);
```

The voided screen will be deleted at the end of the current game loop. 

#Screens

Screens are what is displayed on the game window. The GuiManager will call a screens `render()`, `tick()` and `renderDebug()` functions every tick.

### void render()

This is where all the rendering code should go. You can use the Renderer class or SDL to display things on the screen. 

### void tick()

This is where the screen "logic" goes. So any calculation that needs to be done each tick should be here.

### void renderDebug()

When debug = true, this method is for rendering debug info that should not be displayed normally. This is called last, so the debug info is displayed on top of anything else. 

### void click(int x, int y)

Is called when the user clicks on the screen. The coordinates are the same as the rendering ones, going from top-left to bottom-right

### void addComponent(Component* comp)

Adds a new component to a list

#Component

Components are meant to be smaller ui peices within a screen. They have a position, dimensions (width, height), visibility, logic ticks, ...

This is meant to be a parent class for other components such as a button, a label, a map viewer etc... 

An example of a Compoent is a Button. 

### addOnClick_callback(std::function<void(Component*, int, int)> func))

This function adds a kind of "listener" to the component that gets called when the component is clicked using anonymous functions. 
example:
```
button->addOnClick_callback([this](Component* c, int x, int y)
	{
		//code
	});
  ```

From within the {}, you can use this-> to access the Screen object. For example, ScreenTitle's ENTER button will change screens when clicked:
```
button->addOnClick_callback([this](Component* c, int x, int y)
	{
		Screen* screen = this->game->getGuiManager()->setScreen(new ScreenMain(this->game));
		Renderer::addVoidScreen(screen);
	});
  ```
  
#Style

The Style class extends the Component class and adds style properties to it (kind of like css properties). 

This class is meant to be a parent to classes that use backgrounds, borders or anything related to Style. 

For example, the Button class extends Style

It includes properties such as 

> backgroundColor

> borderSize
> borderColor

> fontColor
> fontUnderline
> fontUnderlineColor

> padding

Most of these properties have a _hover varient. Calling setXXX_both() will set both the non-hover and hover value to the same thing. 


# Button

Button is a component that extends Style. It will display text of a certain font on the screen using the style values.

Example:
```
Button* playBtn = new Button( "Play", &Renderer::FONT_ROBOTO, 100, 100, 100, 30);

	playBtn->setFontColor(255, 255, 255, 255); //set the font color

	playBtn->setBackgroundColor_both(255, 255, 255, 0); //set the background color

	playBtn->setFontUnderlineColor_hover(255, 255, 255, 255); //set the underline color when the button is hovered
	playBtn->setFontUnderline_hover(1); //set the fontunderline height when the button is hovered

	playBtn->setPadding(10); //add some padding to the button

	playBtn->adjustButtonDimensions(); //adjust the width and height to the width and height of "Play", essentially overriding the valus in the constructor

	playBtn->addOnClick_callback([](Component* comp, int x, int y) //register a callback for when the button is clicked
	{
		std::cout << "Go to Play screen!" << std::endl; 
	});
```

This creates a button with RobotoFont and text "play" at coordinates 100,100 and with width/height of 100, 30. This button is later added using 
`addComponent(playBtn);`
