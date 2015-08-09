#pragma once
enum BlockType {
    Default = 0,
    Grass,
    Dirt,
    Stone,
};

class Block {
public:
    static const constexpr float BLOCK_SIZE = 1.0f;
    Block(BlockType type, bool active);
    Block(BlockType type);
    Block();
    ~Block();
private:
    bool _active;
    BlockType _type;
    void setActiveFlag(bool active);
    bool getActiveFlag();
    void setBlockType(BlockType blockType);
    BlockType getBlockType();
};
