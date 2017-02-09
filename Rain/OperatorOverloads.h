#pragma once
#include <iostream>
#include <vec2.hpp>
#include "EntityLoader.h"

/* input output overlood */

std::ostream& operator<<(std::ostream& os, EntityLoader loader) {
	return os << "{ name : " << loader.entityName << " , "
		<< "width : " << loader.width << " , "
		<< "height : " << loader.height << " , "
		<< "drawPriority : " << loader.drawPriority << " , "
		<< "startingPositionX : " << loader.startingPositon.x << " , "
		<< "startingPositionY : " << loader.startingPositon.y << " }";
}


std::istream& operator >> (std::istream& is, EntityLoader& loader) {
	char c;
	std::string str;
	int num;
	if (!(is >> c) || c != '{') { is.setstate(std::ios_base::failbit); return is; }
	if (!(is >> str) || str != "name") { is.setstate(std::ios_base::failbit); return is; }
	if (!(is >> c) || c != ':') { is.setstate(std::ios_base::failbit); return is; }
	//if (!(is >> c) || c != '\"') { is.setstate(std::ios_base::failbit); return is; }
	//str.clear();
	/*while (is >> c && c != '\"') {
		str += c;
	}*/
	if (!(is >> str)) { is.setstate(std::ios_base::failbit); return is; }
	loader.entityName = str;
	if (!(is >> c) || c != ',') { is.setstate(std::ios_base::failbit); return is; }
	if (!(is >> str) || str != "width") { is.setstate(std::ios_base::failbit); return is; }
	if (!(is >> c) || c != ':') { is.setstate(std::ios_base::failbit); return is; }
	if (!(is >> num)) { is.setstate(std::ios_base::failbit); return is; }
	loader.width = num;
	if (!(is >> c) || c != ',') { is.setstate(std::ios_base::failbit); return is; }
	if (!(is >> str) || str != "height") { is.setstate(std::ios_base::failbit); return is; }
	if (!(is >> c) || c != ':') { is.setstate(std::ios_base::failbit); return is; }
	if (!(is >> num)) { is.setstate(std::ios_base::failbit); return is; }
	loader.height = num;
	if (!(is >> c) || c != ',') { is.setstate(std::ios_base::failbit); return is; }
	if (!(is >> str) || str != "drawPriority") { is.setstate(std::ios_base::failbit); return is; }
	if (!(is >> c) || c != ':') { is.setstate(std::ios_base::failbit); return is; }
	if (!(is >> num)) { is.setstate(std::ios_base::failbit); return is; }
	loader.drawPriority = num;
	if (!(is >> c) || c != ',') { is.setstate(std::ios_base::failbit); return is; }
	if (!(is >> str) || str != "startingPositionX") { is.setstate(std::ios_base::failbit); return is; }
	if (!(is >> c) || c != ':') { is.setstate(std::ios_base::failbit); return is; }
	if (!(is >> num)) { is.setstate(std::ios_base::failbit); return is; }
	loader.startingPositon.x = num;
	if (!(is >> c) || c != ',') { is.setstate(std::ios_base::failbit); return is; }
	if (!(is >> str) || str != "startingPositionY") { is.setstate(std::ios_base::failbit); return is; }
	if (!(is >> c) || c != ':') { is.setstate(std::ios_base::failbit); return is; }
	if (!(is >> num)) { is.setstate(std::ios_base::failbit); return is; }
	loader.startingPositon.y = num;
	if (!(is >> c) || c != '}') { is.setstate(std::ios_base::failbit); return is; }
	return is;
}
