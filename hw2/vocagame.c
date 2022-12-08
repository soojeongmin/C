#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include<string.h>
 
struct vocabulary
{
    char eng[10];
    char kor[10];
};
 
int main()
{
    int choice, fc_day, fc_print;
    int wordcount, langcount, mixlist[10];
    int try, life;
    char flip, guess;
    bool flag = true, clear_flag = true;
    
    struct vocabulary dict[7][10] =
    {
        {
            { "address", "주소" },
            { "banana", "바나나" },
            { "chicken", "닭" },
            { "dad", "아버지" },
            { "egg", "달걀" },
            { "face", "얼굴" },
            { "game", "오락" },
            { "hair", "머리칼" },
            { "ink", "잉크" },
            { "job", "직업" }
        },
        {
            { "afternoon", "오후" },
            { "bank", "은행" },
            { "child", "어린이" },
            { "dance", "춤" },
            { "eraser", "지우개" },
            { "fact", "사실" },
            { "garden", "정원" },
            { "hamburger", "햄버거" },
            { "island", "섬" },
            { "juice", "음료수" }
        },
        {
            { "age", "나이" },
            { "bath", "목욕" },
            { "chopstick", "젓가락" },
            { "date", "날짜" },
            { "evening", "저녁" },
            { "fall", "가을" },
            { "gate", "출입구" },
            { "hand", "손" },
            { "idea", "생각" },
            { "jacket", "외투" }
        },
        {
            { "airport", "공항" },
            { "beach", "해변" },
            { "church", "교회" },
            { "daughter", "딸" },
            { "example", "예시" },
            { "family", "가족" },
            { "girl", "여아" },
            { "handle", "손잡이" },
            { "insect", "벌레" },
            { "jungle", "밀림" }
        },
        {
            { "animal", "동물" },
            { "bear", "곰" },
            { "circle", "원" },
            { "desk", "책상" },
            { "exercise", "운동" },
            { "farm", "농장" },
            { "glass", "유리" },
            { "hat", "모자" },
            { "issue", "화제" },
            { "jail", "감옥" }
        },
        {
            { "answer", "답" },
            { "bed", "침대" },
            { "city", "도시" },
            { "diary", "일기" },
            { "eye", "눈" },
            { "film", "영화" },
            { "gold", "금" },
            { "head", "머리" },
            { "iron", "철" },
            { "joke", "농담" }
        },
        {
            { "apple", "사과" },
            { "bench", "의자" },
            { "class", "교실" },
            { "death", "죽음" },
            { "end", "끝" },
            { "finger", "손가락" },
            { "grape", "포도" },
            { "holiday", "휴일" },
            { "ice", "얼음" },
            { "jam", "잼" }
        },
    };
    
    while(flag)
    {
        clear_flag = true;
        
        printf(">> 영어 단어 암기 프로그램 <<\n");
        printf("1. 플래쉬 카드     2. 게임     3. 프로그램 종료\n\n");
        
        printf("번호를 선택하세요 : ");
        scanf("%d", &choice);
        
        if(choice==1)
        {
            printf("학습 일차 : ");
            scanf("%d", &fc_day);
            if(fc_day <= 7 && fc_day > 0)
            {
                printf("출력 방식(수동모드 : 1, 자동모드 : 2) : ");
                scanf("%d", &fc_print);
            
                srand((unsigned int)time(NULL));
 
                for (int i = 0; i < 10; i++)
                {
                    mixlist[i] = rand() % 10;
                    for (int j = 0; j < i; j++)
                    {
                        if (mixlist[i] == mixlist[j]) i--;
                    }
                }
 
                wordcount = 0;
                langcount = 0;
                
                if(fc_print == 1)
                {
                    while(wordcount < 20)
                    {
                        flip = getchar();
                        if(flip == '\n')
                        {
                            system("clear");
                            printf(">> 영어 단어 암기 프로그램 : 플래쉬카드 <<\n\n\n\n");
                            if(wordcount%2 == 0)
                            {
                                printf("%s\n", dict[fc_day-1][mixlist[langcount]].eng);
                                wordcount++;
                            }
                            else
                            {
                                printf("%s\n", dict[fc_day-1][mixlist[langcount]].kor);
                                wordcount++;
                                langcount++;
                            }
                        }
                    }
                }
                else if(fc_print == 2)
                {
                    while(wordcount < 20)
                    {
                        system("clear");
                        printf(">> 영어 단어 암기 프로그램 : 플래쉬카드 <<\n\n\n\n");
                        if(wordcount%2 == 0)
                        {
                            printf("%s\n", dict[fc_day-1][mixlist[langcount]].eng);
                            wordcount++;
                        }
                        else
                        {
                            printf("%s\n", dict[fc_day-1][mixlist[langcount]].kor);
                            wordcount++;
                            langcount++;
                        }
                        sleep(1);
                    }
                }
            }
        }
        else if(choice==2)
        {
            printf("학습 일차 : ");
            scanf("%d", &fc_day);
            int rnd;
            if(fc_day <= 7 && fc_day > 0)
            {
                srand((unsigned int)time(NULL));
                rnd = rand() % 10;
                
                try = 0;
                life = 6;
                bool check = false;
 
 
                char ch[10], solved[10], temp[10];
                strcpy(ch, dict[fc_day-1][rnd].eng);
                
                for(int i=0;i<strlen(ch);i++) strcpy(&solved[i], "_");
                strcpy(temp, solved);
                
                while(clear_flag)
                {
                    strcpy(temp, solved);
                    try++; check = false;
                    system("clear");
                    printf(">> 영어 단어 암기 프로그램 : 게임 <<\n");
                    printf("(힌트) %s\n\n", dict[fc_day-1][rnd].kor);
                    printf("-------------------+\n");
                    
                    if(life==6)
                    {
                        printf("\n\n\n\n");
                    }
                    else if(life==5)
                    {
                        printf("                   O\n\n\n\n");
                    }
                    else if(life==4)
                    {
                        printf("                   O\n");
                        printf("                   |\n\n\n");
                    }
                    else if(life==3)
                    {
                        printf("                   O\n");
                        printf("                  /|\n\n\n");
                    }
                    else if(life==2)
                    {
                        printf("                   O\n");
                        printf("                  /|\\\n\n\n");
                    }
                    else if(life==1)
                    {
                        printf("                   O\n");
                        printf("                  /|\\\n");
                        printf("                   /\n\n");
                    }
                    else if(life==0)
                    {
                        printf("                   O\n");
                        printf("                  /|\\\n");
                        printf("                   /\\\n\n");
                        sleep(3);
                        clear_flag = false; break;
                    }
    
                    for(int i=0;i<strlen(ch);i++) printf("%c ", solved[i]);
                    printf("\n");
                    printf("%d번째 시도 : ", try);
                    scanf(" %c", &guess);
                    
                    for(int i=0;i<strlen(ch);i++) if(guess==ch[i]) solved[i] = ch[i];
                    if(strcmp(temp, solved)==0) life--;
                    if(strcmp(solved, ch)==0 && life!=0)
                    {
                        printf("     ##########################\n");
                        printf("     ### Congratulations!!! ###\n");
                        printf("     ##########################\n");
                        sleep(3);
                        clear_flag = false;
                    }
                }
            }
        }
        else if(choice==3) flag = false;
        system("clear");
    }
    return 0;
}





