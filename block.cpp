#include <iostream>

#include "include/block.hpp"

using namespace std;

/*
    Constructors
*/

Block::Block(BlockType blockType, bool active) {
    cout << "Created a block!" << endl;
}

Block::Block(BlockType blockType) : Block(blockType, true) {
    // Nothing new.
}

Block::Block() : Block(Default, true) {
    // Nothing new.
}

Block::~Block() {
    cout << "Destructing block!" << endl;
}

/*
    Methods
*/

BlockType Block::getBlockType() {
    return _type;
}

void Block::setBlockType(BlockType blockType) {
    _type = blockType;
}

bool Block::getActiveFlag() {
    return _active;
}

void Block::setActiveFlag(bool active) {
    _active = active;
}
