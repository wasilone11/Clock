
/* Authored by Rittik Basak , Nafiz Islam , Abdul Wasi and Mahmudnobe */



# include "iGraphics.h"
# include <stdio.h>
# include <string.h>
# include <time.h>
# include <ctype.h>
# include <windows.h>
#include<mmsystem.h>

int f = 0, log1_y = 600, len=0, m3, mm3, stop_dec = 0, log2_y = 800, m1, m2, mm1, mm2, point = 0,x=3, c_point = 0, waiting = 0;
int i, ans_f =0, p, c, s, l, log3_y = 1000, c3=0, c4 = 0, lev=50, type = 0, life = 3, log4_y = 1200,pq=0, level=0;
int file_f=0, sq_x = 400, sq_y = 400;
char n1[4], nn1[4], c1 = 0, c2 = 0, score[4],lives[3], in_name[20], str_level[4];
char ch, in_ans[100], in_ans2[100], log1_math[4], log2_math[4],signs[4]={'+','-','x','/0'};
char colour[5][50] = {"Red","Green", "Orange", "Blue", "Purple"};
char shape[5][50] = {"Square", "Circle", "Triangle", "Diamond", "Pentagon"};
FILE *fp, *fp_hs;;
int n,j,nn;
char word[100][30], ans_letter, word2[30], input;
struct highscore{
    char name[20];
    char score_str[20];
    int score;
};

struct highscore hs[5];

void log1_y_dec(void);
void log2_y_dec(void);
void score_in(void);
int intConvert(char in_ans[]);

void initialize(){
    f = 0;
    log1_y = 600, log2_y = 800, log3_y = 1000, log4_y = 1200;
    point = 0;
    c1=0, c2=0, c3 = 0, c4 =0;
    stop_dec = 0;
    lev=50;
    x=3;
    life = 3;
    file_f = 0;
}


void high_score_check(int score)
{
    int i=0, j;

    fp_hs = fopen("highscores.txt", "r");

    /*if(fp_hs==NULL){
        printf("Error");
        return;
    }*/

    for(i=0; i<=5; i++){
        fscanf(fp_hs, "%s %d", hs[i].name, &hs[i].score);
    }

    fclose(fp_hs);

    for(i=0; i<5; i++){
        if(score>=hs[i].score){
            file_f = 1;
            break;
        }
    }

    return;
}

void high_score_add(int score)
{
    int i=0, j, t;
    char t_name[20];

    fp_hs = fopen("highscores.txt" , "w");
    strcpy(hs[4].name, in_name);
    hs[4].score = score;
    for(i=0; i<5; i++){
        for(j=i+1; j<5; j++){
            if(hs[i].score < hs[j].score){
                t = hs[j].score;
                hs[j].score = hs[i].score;
                hs[i].score = t;
                strcpy(t_name, hs[j].name);
                strcpy(hs[j].name, hs[i].name);
                strcpy(hs[i].name, t_name);
            }
        }
    }


    for(i=0; i<5; i++)
        fprintf(fp_hs, "%s %d\n", hs[i].name, hs[i].score);

    fclose(fp_hs);
}


int intConvert(char in_ans[])
{
    /*this function converts a string of numbers to interger number. it's parameter is the string that takes input from the keyboard
    it will be cosidered the ans to the math expression.*/
    int i, ans, k = 0;
    ans = in_ans[strlen(in_ans) - 1] - 48;
    if(in_ans[0]=='-')k=1;
    for (i = strlen(in_ans) - 2; i >= k; i--){
        ans = ans + (in_ans[i] - 48)*10;
    }
    if(k==0)return ans;
    else return ans*-1;
}

int type_no()
{
    type = rand()%3;
    return type;
}

int colour_exp()
{
    c = rand()%5;
    return c;
}

int shape_exp()
{
    s = rand()%5;
    return s;
}

void word_exp()
{
    n=rand()%10;
    int len = strlen(word[n]);
    word[n][len] = '\0';
    nn=rand()%(len-1);
    ans_letter=word[n][nn];
    strcpy(word2,word[n]);
    word2[nn]='_';
    word2[len-1] = '\0';
}

void loss(int n)
{
    life--;
    if(life == 0 )
    {
        f = 4;
        c_point = 0;
    }
    if(n==1)log1_y += 800;
    else if (n==2) log2_y += 800;
    else if (n==3) log3_y += 800;
    else log4_y += 800;
}

void math_sum_exp(void)
{
    /*generates a mathematical expression with a plus sign.
    PROBLEM: once compiles it gives the same expresion until it is compiled again*/
    //int m1, m2;
    srand(time(NULL));
    m1 = rand() % 10;
    n1[0] = 48 + m1;
    //n1[1] = '+';
    m2 = rand() % 10;
    n1[2] = 48 + m2;
    n1[3] = '=';
    //m3 = m1 + m2;
    n1[4] = '\0';

    int sign1 = rand() % 3;
    n1[1] = signs[sign1];

    if(sign1 == 0) m3 = m1 + m2;
    else if (sign1 == 1) m3 = m1 - m2;
    else m3 = m1 * m2;

    strcpy(log1_math,n1);
}

void log1_y_dec(void)
{
    /*decreases the logs y co-ordinate to lower it. if the log crashes with the boat y coordinate is set back to initial*/
    if (f == 1)
    {
            log1_y -= 3 + x;
            log2_y -= 3+x;
            log3_y -= 3+x;
            log4_y -= 3+x;
    }
}

void done(int nnn)
{
    point += 5;
    switch (nnn)
    {
    case 1:
        log1_y += 800;
        c1 = 0;
        break;
    case 2:
        log2_y += 800;
        c2 = 0;
        break;
    case 3:
        log3_y += 800;
        c3 = 0;
        break;
    default:
        log4_y += 800;
        c4 = 0;
        break;
    }
}
/*
function iDraw() is called again and again by the system.
*/
void iDraw()
{
    iClear();
    if (f == 0)
    {
        ///home screen
        iShowBMP(0, 0, "home back.bmp");
        iSetColor(255, 0, 0);
        iRectangle(130, 300, 240, 50);///lower box
        iRectangle(130, 350, 240, 50);///middle box
        iRectangle(130, 400, 240, 50);///upper box
        iRectangle(130, 450, 240, 50);
        iText(215, 470, "START", GLUT_BITMAP_TIMES_ROMAN_24);
        iText(165, 420, "INSTRUCTIONS", GLUT_BITMAP_TIMES_ROMAN_24);
        iText(175, 365, "HIGHSCORES", GLUT_BITMAP_TIMES_ROMAN_24);
        iText(220, 315, "QUIT", GLUT_BITMAP_TIMES_ROMAN_24);
    }

    if (f == 1)
    {
        ///main game page

        ///Back ground image
        iSetColor(47, 141, 255);
        iFilledRectangle(100, 0, 300, 600);

        iSetColor(0, 0, 0);
        iText(290,60,"YOUR ANSWER:");

        level = point/60;
        x = 3 + level;
        //iText(320,40,in_ans, GLUT_BITMAP_TIMES_ROMAN_24);

        //if(stop_dec==0){
        //if (intConvert(in_ans2) != m3){
        iShowBMP(100, log1_y, "log1.bmp");
        if (c1 == 0){
            math_sum_exp();
            //puts(n1);
            c1++;
        }

        iSetColor(255, 255, 255);
        iText(240, log1_y + 25, log1_math, GLUT_BITMAP_9_BY_15);


        //}

        iShowBMP(100,log2_y, "log2.bmp");
        if (c2 == 0){
            c = colour_exp();
            c2++;
        }

        iText(240, log2_y + 25, colour[c], GLUT_BITMAP_9_BY_15);

        iShowBMP(100, log3_y, "log1.bmp");
        if (c3 == 0){
            s = shape_exp();
            //puts(n1);
            c3++;
        }

        iText(240, log3_y + 25, shape[s], GLUT_BITMAP_9_BY_15);

        iShowBMP(100,log4_y, "log2.bmp");
        if (c4 == 0){
            word_exp();
            c4++;
        }

        iText(240, log4_y + 25, word2, GLUT_BITMAP_9_BY_15);

        iSetColor(0, 0, 0);
        iText(320,40,in_ans, GLUT_BITMAP_TIMES_ROMAN_24);

        //if (intConvert(in_ans2) == mm3)
        //    stop_dec = 2;
        // this portion checks keyboard input string converted to an integer and compares it to the actual answer of the expression
        //if they match stops loading the log image
        // PROBLEM: Doesn't set the log back, doesn't work for continuos logs.
        iSetColor(0, 0, 0);
        iFilledRectangle(0, 600, 500, 50);

        ///level
        iSetColor(255, 255, 255);
        iText(20, 620, "LEVEL: ");

        l = level+1;
        for(i=1;i>=0;i--){
            str_level[i] = l%10 + 48;
            l /= 10;
        }
        str_level[2]='\0';

        iText(80,620,str_level);

        ///life
        if(life > 2)
            iShowBMP(380, 610, "heart.bmp");
        if(life > 1)
            iShowBMP(420, 610, "heart.bmp");
        if(life > 0)
            iShowBMP(460, 610, "heart.bmp");
        //iSetColor(255, 255, 255);
        //iText(420, 620, "Life: ");

        lives[0] = '0';
        lives[1] = life%10 + 48;
        lives[2] = '\0';

        //iText(480,620,lives);

        ///SCORE
        iSetColor(255, 255, 255);
        iText(200, 620, "SCORE: ");

        p = point;
        for(i=2;i>=0;i--){
            score[i] = p%10 + 48;
            p /= 10;
        }
        score[3]='\0';

        iSetColor(255, 255, 255);
        iText(260,620,score);

        iText(30, 550, "SHAPES");
        iText(430, 550, "COLORS");

        iSetColor(255, 255, 255);
        iShowBMP(218, 0, "boat.bmp");

        iLine(0, 600, 500, 600);///draws horizontal line

        ///for shapes buttons
        iSetColor(255, 0, 0);///square
        iFilledRectangle(0, 0, 100, 100);

        iSetColor(0, 255, 0);///circle
        iFilledRectangle(0, 100, 100, 100);

        iSetColor(255, 173, 47);///triangle
        iFilledRectangle(0, 200, 100, 100);

        iSetColor(0, 0, 255);///diamond
        iFilledRectangle(0, 300, 100, 100);

        iSetColor(160, 32, 240);///pentagon
        iFilledRectangle(0, 400, 100, 100);

        iSetColor(255, 255, 255);
        iFilledRectangle(30, 30, 40, 40);
        iFilledCircle(50, 150, 20);
        iFilledCircle(50, 250, 20, 3);
        iFilledEllipse(50, 350, 20, 30, 4);
        iFilledCircle(50, 450, 20, 5);

        ///for color buttons
        iSetColor(255, 0, 0);///red
        iFilledRectangle(400, 0, 100, 100);

        iSetColor(0, 255, 0);///green
        iFilledRectangle(400, 100, 100, 100);

        iSetColor(255, 173, 47);///orange
        iFilledRectangle(400, 200, 100, 100);

        iSetColor(0, 0, 255);///blue
        iFilledRectangle(400, 300, 100, 100);

        iSetColor(160, 32, 240);///purple
        iFilledRectangle(400, 400, 100, 100);

        iSetColor(255, 255 ,255);
        iRectangle(sq_x, sq_y, 100, 100);

        if (log1_y <= 128)loss(1);
        if (log2_y <= 128)loss(2);
        if (log3_y <= 128)loss(3);
        if (log4_y <= 128)loss(4);

    }
    if (f == 2)
    {
        ///instruction page
        iShowBMP(0, 0, "ins.bmp");
        iSetColor(255, 255, 200);
        iText(10, 10, "GO BACK", GLUT_BITMAP_TIMES_ROMAN_24);

    }
    if (f == 3)
    {
        ///quit button
        exit(1);
    }
    if (f == 4)
    {
        ///end screen
        //iShowBMP(0,450,"game-over.bmp");
        //iShowBMP(0, 0, "home back.bmp");
        iShowBMP(0,0,"sinking-boat.bmp");
        iShowBMP(0,450,"game-over.bmp");
        //iText(180, 550, "GAME OVER", GLUT_BITMAP_TIMES_ROMAN_24);
        //iText(175, 450, "YOUR SCORE: ", GLUT_BITMAP_TIMES_ROMAN_24);
        //iText(230, 430, score, GLUT_BITMAP_TIMES_ROMAN_24);
        //iText(10, 10, "RETURN HOME", GLUT_BITMAP_9_BY_15);

        high_score_check(point);
        if(file_f==1){
            f = 5;
        }

    }

    if(f == 5){
        iText(180, 550, "CONGRATULATIONS", GLUT_BITMAP_TIMES_ROMAN_24);
        iText(180, 450, "YOU HAVE MADE A HIGHSCORE", GLUT_BITMAP_9_BY_15);
        iText(150, 300, "ENTER YOUR NAME: ", GLUT_BITMAP_9_BY_15);
        iText(200, 250, in_ans, GLUT_BITMAP_9_BY_15);
    }

    if(f==6) ///High Score
    {
        fp_hs = fopen("highscores.txt", "r");
        for(i=0;i<5;i++)
        {
            fscanf(fp_hs, "%s %s", hs[i].name, hs[i].score_str);
        }

        fclose(fp_hs);

        for(i=0;i<5;i++)
        {
            iSetColor(0,256,0);
            //iRectangle(0,0,500,650);

            //iSetColor(0,0,0);
            iText(150,500,"HIGH SCORES: ", GLUT_BITMAP_TIMES_ROMAN_24);
            iLine(145,480,320,480);

            for(i=0;i<5;i++)
            {
                char ii[2] = {i+49,'\0'};
                iText(100,430-50*i,ii, GLUT_BITMAP_TIMES_ROMAN_24);
                iText(130,430-50*i,hs[i].name, GLUT_BITMAP_TIMES_ROMAN_24);
                iText(290,430-50*i,hs[i].score_str, GLUT_BITMAP_TIMES_ROMAN_24);
            }
        }

    }
}
/*
function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
    //place your codes here
}
/*
function iMouse() is called when the user presses/releases the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        //place your codes here
        if (mx>130 && my>450 && mx <370 && my<500 && f == 0)
        {
            f = 1;
        }
        if (mx>130 && my>400 && mx <370 && my<450 && f == 0)
        {
            f = 2;
        }
        if (mx>130 && my>350 && mx <370 && my<400 && f == 0)
        {
            f = 6;
        }

        if (mx>130 && my>300 && mx <370 && my<350 && f == 0)
        {
            f = 3;
        }

        if (mx>10 && my>10 && mx <100 && my<50 && f == 2)
        {
            f = 0;
        }
        if (mx>10 && my>10 && mx < 100 && my < 50 && f == 4){
            initialize();
        }

        ///colour answer
        if(log2_y < 600 && log2_y >= 128)
        {
            ///red
            if(c==0 && mx > 400 && mx < 500 && my > 0 && my < 100)
            done(2);

            ///green
            if(c==1 && mx > 400 && mx < 500 && my > 100 && my < 200)
            done(2);

            ///orange
            if(c==2 && mx > 400 && mx < 500 && my > 200 && my < 300)
            done(2);

            ///blue
            if(c==3 && mx > 400 && mx < 500 && my > 300 && my < 400)
            done(2);


            ///purple
            if(c==4 && mx > 400 && mx < 500 && my > 400 && my < 500)
            done(2);


        }

        ///shape answer
        if(log3_y < 600 && log3_y >= 128)
        {
            ///square
            if(s==0 && mx > 0 && mx < 100 && my > 0 && my < 100)
            done(3);

            ///circle
            if(s==1 && mx > 0 && mx < 100 && my > 100 && my < 200)
            done(3);

            ///Triangle
            if(s==2 && mx > 0 && mx < 100 && my > 200 && my < 300)
            done(3);

            ///diamond
            if(s==3 && mx > 00 && mx < 100 && my > 300 && my < 400)
            done(3);

            ///pentagon
            if(s==4 && mx > 00 && mx < 100 && my > 400 && my < 500)
            done(3);

        }

    }
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        //place your codes here
    }
}
/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
    /// takes input from keyboard to a string
    int i;
    if (f == 1){
        if(key == '\r')
        {
            //it'll set the string to zero

            in_ans[len] = '\0';

            strcpy(in_ans2,in_ans);
            for(i=0;i<len;i++)
                in_ans[i] = 0;

            len = 0;

            if(log4_y < 600 && log4_y >= 128)
                if(toupper(in_ans2[0]) == ans_letter)
                    done(4);
            if(log1_y < 600 && log1_y >= 128)
                if(intConvert(in_ans2) == m3)
                    done(1);
        }
        else
        {
            in_ans[len] = key;
            len++;
        }
    }

    if (f == 5){
        if(key == '\r')
        {
            //it'll set the string to zero

            in_ans[len] = '\0';

            strcpy(in_name,in_ans);
            high_score_add(point);
            for(i=0;i<len;i++)
                in_ans[i] = 0;

            len = 0;

        }
        else
        {
            in_ans[len] = key;
            len++;
        }
        /*if(pause == 0 && key == ' '){
            pause = 1;
        }
        if(pause == 1 && key == ' '){
            pause = 0;
        }*/
    }

    //place your codes for other keys here
}
/*
function iSpecialKeyboard() is called whenver user hits special keys likefunction
keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11,
GLUT_KEY_F12, GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN,
GLUT_KEY_PAGE UP, GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END,
GLUT_KEY_INSERT */
void iSpecialKeyboard(unsigned char key)
{
    if (key == GLUT_KEY_LEFT && sq_x != 0)
    {
        sq_x = 0;
    }

    if (key == GLUT_KEY_RIGHT && sq_x != 400)
    {
        sq_x = 400;
    }

    if (key == GLUT_KEY_UP && sq_y != 400)
    {
        sq_y += 100;
    }

    if (key == GLUT_KEY_DOWN && sq_y != 0)
    {
        sq_y -= 100;
    }
    //place your codes for other keys here
}

int main()
{
    //place your own initialization codes here.
    //iSetTimer(10000,increase);

    fp = fopen("words.txt", "r");

    for(i=0;i<10;i++)
    {
        fgets(word[i], 30, fp);
    }
    iSetTimer(lev, log1_y_dec);
    PlaySound(TEXT("movinout.wav"),NULL,SND_LOOP | SND_FILENAME);
    iInitialize(500, 650, "RIVER LEARNING");
    return 0;
}


