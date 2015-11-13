#include "Block.hpp"

//static GQE::ImageAsset imagearray[] = {
//	GQE::ImageAsset("resources/Empty.png", GQE::AssetLoadNow),
//	GQE::ImageAsset("resources/Player.png", GQE::AssetLoadNow)
//};
//
//GQE::ImageAsset* Block::image = imagearray;

	//Block::Block()
	//{
	//	sp = sf::Sprite();
	//}
	Block::Block(int id, int x, int y)
	{
		sf::Texture t;
		if (id == 0)
			t = GQE::ImageAsset("resources/Empty.png", GQE::AssetLoadNow).GetAsset();
		else
			t = GQE::ImageAsset("resources/Player.png", GQE::AssetLoadNow).GetAsset();
		sp = sf::Sprite(t);
		setPosition(x,y);
	}
	void Block::setPosition(int x, int y)
	{
		sp.setPosition(x,y);
	}
	sf::Sprite Block::getSprite()
	{
		return sf::Sprite(sp);
	}
	void Block::setTexture(sf::Texture t)
	{
		sp.setTexture(t);
	}