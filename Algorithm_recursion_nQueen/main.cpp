#include <iostream>
#include <cstdlib>
#include <cstdbool>

#define N 5

using namespace std;

int* cols = new int[N + 1];

bool promising(int level) { //level�� �� ��° �������� ��Ÿ����.
	for (int i = 1; i < level; i++) {
		if (cols[i] == cols[level]) //cols[x] = 5�� ���ϴ� ����, x��° ����, 5��° ���� ���� ��ġ�ߴٴ� ��
			return false;
		else if (level - i == abs(cols[level] - cols[i])) //�밢���� ��ġ���� Ȯ��
			return false;
	}
	return true;
}

bool queens(int level) {
	if (!promising(level)) //������ ��ġ���� �ƴ��� Ȯ��
		return false;
	else if (level == N) { //������ ���� �´� ��ġ�� �ξ���.
		for (int i = 1; i <= N; i++)
			cout << "(" << i << ", " << cols[i] << ")" << endl;
		return true;
	}

	for (int i = 1; i <= N; i++) {
		cols[level + 1] = i; //level+1 ��° ���� i��° ���� �� ��ġ
		if (queens(level + 1))
			return true;
	}
	return false;
}


int main() {
	if (!queens(0))
		cout << "No chance" << endl;
}
