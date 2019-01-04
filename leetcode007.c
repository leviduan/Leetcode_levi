#include <stdio.h>

int Dreverse(int x) {
	int t = 0;
	if (x == 0) return 0;
	while (!x%10) {
		x/=10;
	}
	int sum = 0;
	long long reallysum = 0;
	while (x) {
		reallysum *=10;
		sum *= 10;
		t = x%10;
		reallysum+=t;
		sum+=t;
		x/=10;
	}
	if (reallysum != sum) return 0;
	return sum;
}

int reverse(int x) {
	int t = 0;
	if (x == 0) return 0;
	while (!x%10) {
		x/=10;
	}
	int sum = 0;
	int tmp = 0;
	while (x) {
		sum *= 10;
		if (sum/10 != tmp) return 0;
		t = x%10;
		sum+=t;
		x/=10;
		tmp = sum;
	}
	return sum;
}

int main(int argc, char const *argv[])
{
	int t = 1534236469;
	long long res = reverse(t);
	printf("res=%lld\n", res);
	return 0;
}