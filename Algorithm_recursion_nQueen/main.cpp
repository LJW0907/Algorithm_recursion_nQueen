#include <iostream>
#include <cstdlib>
#include <cstdbool>

#define N 5

using namespace std;

int* cols = new int[N + 1];

bool promising(int level) { //level은 몇 번째 행인지를 나타낸다.
	for (int i = 1; i < level; i++) {
		if (cols[i] == cols[level]) //cols[x] = 5가 뜻하는 것은, x번째 행의, 5번째 열에 말이 위치했다는 것
			return false;
		else if (level - i == abs(cols[level] - cols[i])) //대각선에 겹치는지 확인
			return false;
	}
	return true;
}

bool queens(int level) {
	if (!promising(level)) //말들이 겹치는지 아닌지 확인
		return false;
	else if (level == N) { //말들을 전부 맞는 위치에 두었다.
		for (int i = 1; i <= N; i++)
			cout << "(" << i << ", " << cols[i] << ")" << endl;
		return true;
	}

	for (int i = 1; i <= N; i++) {
		cols[level + 1] = i; //level+1 번째 행의 i번째 열에 말 배치
		if (queens(level + 1))
			return true;
	}
	return false;
}


int main() {
	if (!queens(0))
		cout << "No chance" << endl;
}
