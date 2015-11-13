#include <SFML/Graphics.hpp>
#include <GQE/Core/assets/ImageAsset.hpp>
#ifndef BLOCK_HPP
#define BLOCK_HPP

class Block{
public:
	//Block();
	Block(int id=0, int x=0, int y=0);
	void setPosition(int x, int y);
	sf::Sprite getSprite();
	void setTexture(sf::Texture t);
private:
	sf::Sprite sp;
	//static GQE::ImageAsset* image;
};

#endif