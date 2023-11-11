#include <stdio.h>

void input_manu();

int manu[3][4];
char* manu_name[12];

int main(void) {
	input_manu();
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			printf(manu[i][j]);
		}
		printf("\n");
	}
}

void input_manu() {
	manu_name[0] = "1. 우유";
	manu_name[1] = "2. 커피";
	manu_name[2] = "3. 주스";
	manu_name[3] = "4. 탄산음료";
	manu_name[4] = "5. 칸칩";
	manu_name[5] = "6. 거북칩";
	manu_name[6] = "7. 감자칩";
	manu_name[7] = "8. 고구마칩";
	manu_name[8] = "9. 안타볼";
	manu_name[9] = "10. 초코버섯";
	manu_name[10] = "11. 가재깡";
	manu_name[11] = "12. 씨리얼";
}