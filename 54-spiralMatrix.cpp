#include <iostream>
#include <vector>

using namespace std;
//my sol:
//(a,b)->(c,d)
vector<int> printEdge(vector<vector<int>>& matrix, int a, int b, int c, int d) {
	vector<int> ans;
	if (a == c) {
		for (int i = b; i <= d; i++) {
			ans.push_back(matrix[a][i]);
		}
	}else if (b == d) {
		for (int i = a; i <= c; i++) {
			ans.push_back(matrix[i][b]);
		}
	}else {
		for (int i = b; i < d; i++) {
			ans.push_back(matrix[a][i]);
			//cout << matrix[a][i] << " ";
		}
		for (int i = a; i < c; i++) {
			ans.push_back(matrix[i][d]);
			//cout << matrix[a][i] << " ";
		}
		for (int i = d; i > b; i--) {
			ans.push_back(matrix[c][i]);
			//cout << matrix[a][i] << " ";
		}
		for (int i = c; i > a; i--) {
			ans.push_back(matrix[i][b]);
			//cout << matrix[a][i] << " ";
		}
	}
	return ans;
}
vector<int> spiralOrder(vector<vector<int>>& matrix) {
	vector<vector<int>> ans;
	vector<int> res;
	if(matrix.size() == 0)
	return res;
	int zr = 0;
	int zc = 0;
	int yr = matrix.size() - 1;
	int yc = matrix[0].size() - 1;
	while (zr <= yr && zc <= yc) {
		ans.push_back(printEdge(matrix, zr++, zc++, yr--, yc--));
	}
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			res.push_back(ans[i][j]);
		}
	}
	return res;
}
//sol2:
vector<int> spiralOrder2(vector<vector<int>>& matrix) {
	vector<int> ans;
	if (matrix.size() == 0) return ans;
	int R = matrix.size();
	int C = matrix[0].size();
	vector<vector<bool>> seen(R, vector<bool>(C, false));
	int c = 0, r = 0, di = 0;
	int nc = 0;
	int nr = 0;
	vector<int> dr = {0, 1, 0, -1};
	vector<int> dc = {1, 0, -1, 0};
	for (int i = 0; i < R*C; i++) {
		ans.push_back(matrix[r][c]);
		seen[r][c] = true;
		nr = r + dr[di];
		nc = c + dc[di];
		if(nr >=0 && nr < R && nc >= 0 && nc < C && !seen[nr][nc]) {
			r = nr;
			c = nc;
		} else {
			di = (di + 1) % 4;
			r += dr[di];
			c += dc[di];
		}
	}
	return ans;
}
int main() {
	vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
	vector<int> v;
	//vector<vector<int>> matrix = { { 1, 2, 3 } };
	//v = printEdge(matrix, 0, 0, 2, 2);
	v = spiralOrder2(matrix);
	for (int a : v) cout << a << " ";
	return 0;
}
