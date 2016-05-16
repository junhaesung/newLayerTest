#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
 //   auto closeItem = MenuItemImage::create(
 //                                          "CloseNormal.png",
 //                                          "CloseSelected.png",
 //                                          CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
 //   
	//closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
 //                               origin.y + closeItem->getContentSize().height/2));

	MenuItemFont* buttonItem = MenuItemFont::create("menu item font", CC_CALLBACK_1(HelloWorld::showNewLayer, this));
	buttonItem->setPosition(visibleSize.width/2, visibleSize.height/2);

    // create menu, it's an autorelease object
	auto menu = Menu::create(buttonItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);

    
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void HelloWorld::showNewLayer(cocos2d::Ref* pSender)
{
	auto newLayer = LayerColor::create(Color4B::WHITE);

	newLayer->setContentSize(Size(360*1.5, 640*1.5));
	newLayer->setAnchorPoint(Point(0.5, 0.5));
	newLayer->setPosition(Point(360/4, 640/4));

	auto s1 = Sprite::create("HelloWorld.png", Rect(0, 0, 100, 100));
	s1->setPosition(0, 0);
	s1->setAnchorPoint(Point(0, 0));
	newLayer->addChild(s1);

	auto s2 = Sprite::create("HelloWorld.png", Rect(0, 0, 100, 100));
	s1->setPosition(200, 0);
	s2->setAnchorPoint(Point(0, 0));
	newLayer->addChild(s2);

	this->addChild(newLayer);
	

}