#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> memorie(m, vector<int>(n, -1)); // Inicializa o caminho de cada nó com -1
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; // Norte, Sul, Leste, Oeste

        int longestPath = 0;
        for (int x = 0; x < m; ++x) {
            for (int y = 0; y < n; ++y) {
                longestPath = max(longestPath, dfs(x, y, matrix, memorie, directions));
            }
        }

        return longestPath;
    }

private:
    int dfs(int x, int y, vector<vector<int>>& matrix, vector<vector<int>>& memorie, vector<pair<int, int>>& directions) {
        if (memorie[x][y] != -1) 
            return memorie[x][y]; // Se o caminho já foi calculado, retorna o valor

        memorie[x][y] = 1; // Inicializa o caminho com 1
        for (auto& dir : directions) { 
            int nx = x + dir.first, ny = y + dir.second; // Calcula a posição do vizinho
            if (nx >= 0 && nx < matrix.size() && ny >= 0 && ny < matrix[0].size() && matrix[nx][ny] > matrix[x][y]) {
                memorie[x][y] = max(memorie[x][y], dfs(nx, ny, matrix, memorie, directions) + 1);
            }
        }
        return memorie[x][y];
    }
};

int main(){
    vector<vector<int>> matrix = {{9,9,4},{6,6,8},{2,1,1}};
    Solution s;
    cout << s.longestIncreasingPath(matrix) << endl;
    return 0;
}