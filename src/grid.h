#pragma once // to make sure can be only included once
#include <vector>
#include <raylib.h>
class Grid{
    public:
        Grid();
        void Initialize();
        void Print();
        void Draw();
        bool isCellOutside(int row, int column);
        bool IsCellEmpty(int row, int column);
        int clearFullRows();
        int grid[20][10];
    private:
        int numRows;
        int numCols;
        int cellSize;
        std::vector<Color> colors;
        bool IsRowFull(int row);
        void ClearRow(int row);
        void moveRowDown(int row, int numRows);
};
