#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max 10
/*
    TODO List 
    변수
        1. 확률 percent (int)
        2. 돌 ( 유물이냐? 전설이냐? ) stone = 1, 2 (int)
        3. 각인별 변수 (3개) up1, up2, down [배열] (char)
        4. 각인의 최대 수 index (int)
        ** 5. 각인별 최대 수 up1Count, up2Count, downCount ** (int)
    
    기능 
        1. 확률 계산
        2. UI 
        3. o, x 반환 myResult
        4. 배열 초기화 기능 myFormat
    
    빨래 끝
*/

// 강화 실패, 성공 반환
typedef struct {
    char up1[max], up2[max], down[max];
} workSetting;

char myResult(int* percent, int shuffle){
    srand((unsigned int)time(NULL) + shuffle);
    int random = rand() % 100;

    if(random < *percent) {
        if(*percent > 25) {
            *percent -= 10;
        }
        return 'o';
    }
    else {
        if(*percent < 75) {
            *percent += 10;
        }
        return 'x';
    }
}

// 모든 배열 "-"로 초기화
void myFormat(char arr[], char arr2[], char arr3[]){
    int i;

    for(i=0; i<max; i++){
        arr[i] = '-';
        arr2[i] = '-';
        arr3[i] = '-';
    }
}

void myUI(workSetting setStone, int percent, int n){
    int i;

    printf(" ┌──────[전설]돌 세공 시뮬레이터──────┐\n");
    printf(" │      원하는 각인을 선택하세요.     │\n");
    printf(" │        세공확률 : %d%%              │ \n", percent);
    printf(" └────────────────────────────────────┘\n");

    printf("\n1. 증가각인 1 │ ");
    for(i = 0; i < n; i++){
        printf("%c ", setStone.up1[i]);
    }
    printf("\n2. 증가각인 2 │ ");
    for(i = 0; i < n; i++){
        printf("%c ", setStone.up2[i]);
    }
    printf("\n3. 감소각인   │ ");
    for(i = 0; i < n; i++){
        printf("%c ", setStone.down[i]);
    }
}


int main(){
    int percent = 75, stone, index, choice;
    int up1Count = 0, up2Count = 0, downCount = 0;

    int i;

    workSetting setStone;

    do{
        stone = 0;
        myFormat(setStone.up1, setStone.up2, setStone.down);

        printf(" ┌──────────────────────────┐\n");
        printf(" │    돌세공 시뮬레이터     │\n");
        printf(" └──────────────────────────┘\n");
        printf("세공할 돌의 종류를 선택하세요.\n");
        printf(" [1] 유물 [2] 전설 [3] 나가기\n");
        printf("메뉴 선택 : ");
        scanf("%d", &stone);
        system("clear");

        // 1이 유물 10칸
        index = (11 - stone) * 3;
        if(stone == 1){
            for(i=0; i<index; i++){
                myUI(setStone, percent, (11 - stone));
                printf("\n각인 선택 : ");
                scanf("%d", &choice);

                if(choice == 1){
                    if(up1Count < (11 - stone)){
                        setStone.up1[up1Count++] = myResult(&percent, i);
                    } else {
                        i--;
                    }
                }
                else if(choice == 2){
                    if(up2Count < (11 - stone)){
                        setStone.up2[up2Count++] = myResult(&percent, i);
                    } else {
                        i--;
                    }
                }
                else if(choice == 3){
                    if(downCount < (11 - stone)){
                        setStone.down[downCount++] = myResult(&percent, i);
                    } else {
                        i--;
                    }
                }
                else {
                    i--;
                } 
                system("clear");
            }
        }
        // 2가 전설 9칸
        else if(stone == 2){
            for(i=0; i<index; i++){
                myUI(setStone, percent, (11 - stone));
                printf("\n각인 선택 : ");
                scanf("%d", &choice);

                if(choice == 1){
                    if(up1Count < (11 - stone)){
                        setStone.up1[up1Count++] = myResult(&percent, i);
                    } else {
                        i--;
                    }
                }
                else if(choice == 2){
                    if(up2Count < (11 - stone)){
                        setStone.up2[up2Count++] = myResult(&percent, i);
                    } else {
                        i--;
                    }
                }
                else if(choice == 3){
                    if(downCount < (11 - stone)){
                        setStone.down[downCount++] = myResult(&percent, i);
                    } else {
                        i--;
                    }
                }
                else {
                    i--;
                } 
                system("clear");
            }
        }

        myUI(setStone, percent, (11 - stone));
        printf("\n종료하시려면 아무키나 누르세요.");
        scanf("%d", &choice);

        system("clear");

    }while(stone != 3);


    return 0;
}