#pragma once

class Snake final {
public:
    enum class Direction{
        Up,
        Down,
        Left,
        Right
    };
    void ExecuteWay(const Direction dir);
    Direction get_dir() const;
private:
    Direction m_dir;
};