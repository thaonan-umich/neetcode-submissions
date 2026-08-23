/*

上下左右移动，移动读取一次设置为-999 表示已经访问过

*/

// 先定义一个枚举方向类，写明白各个方向遇到挡住的情况要转换成什么样子

enum class Direction{
    RIGHT,
    DOWN,
    LEFT,
    UP
};

Direction nextDirection(Direction dir) {
    switch (dir) {
            case Direction::RIGHT: return Direction::DOWN;
            case Direction::DOWN:  return Direction::LEFT;
            case Direction::LEFT:  return Direction::UP;
            case Direction::UP:    return Direction::RIGHT;
    }
}

pair<int, int> move(Direction dir){
    switch (dir) {
        case Direction::RIGHT: return {0, 1};
        case Direction::DOWN: return {1, 0};
        case Direction::LEFT: return {0, -1};
        case Direction::UP: return {-1, 0};
    }

    return {0, 0};
}

pair<int, int> add(
    pair<int, int> a,
    pair<int, int> b
) {
    return {
        a.first + b.first,
        a.second + b.second
    };
}

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        // start at [0][0];
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> res;
        pair<int, int> location = {0, 0};
        Direction direction = Direction::RIGHT;

        // 先访问起点
        res.push_back(matrix[location.first][location.second]);
        matrix[location.first][location.second] = -999;

        while (res.size() < m * n) {
            
            pair<int, int> move_step = move(direction);
            pair<int, int> try_location = add(location, move_step);

            if (!canMove(matrix, try_location)){

                direction = nextDirection(direction);
                move_step = move(direction);

                try_location = add(location, move_step);
            }

            // 确认移动
            location = try_location;

            // 读取
            res.push_back(matrix[location.first][location.second]);

            matrix[location.first][location.second] = -999;
        }

        return res;
    }

private:
    bool canMove(vector<vector<int>>& matrix, pair<int, int> new_location){

        int m = matrix.size();
        int n = matrix[0].size();

        int i = new_location.first;
        int j = new_location.second;


        return (i >= 0 && i < m && j >= 0 && j < n && matrix[i][j] != -999);
    }
};
