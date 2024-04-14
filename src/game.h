#pragma once
#include "grid.h"
#include "blocks.cpp"
class Game{
    public:
        Game();
        ~Game();
        Block GetRandomBlock();
        std::vector<Block> GetAllBlocks();
        void Draw();
        void HandleInput();
        void MoveBlockLeft();
        void MoveBlockRight();
        void MoveBlockDown();
        Grid grid;
        bool gameOver;
        int score;
        Music Music;
        bool Paused;
    private:
        bool IsBlockOutside();
        void RotateBlock();
        bool BlockFits();
        void UpdateScore(int linesCleared, int moveDownPoints);
        std::vector<Block> blocks;
        void LockBlock();
        void Reset();
        Block currentBlock;
        Block nextBlock;
        Sound rotateSound;
        Sound clearSound;
};