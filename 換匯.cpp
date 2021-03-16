#include <iostream>
#include <conio.h>
#include <cstdlib>
using namespace std;

double minimum = 100;
double smallest_unit = 0.01;

void ask()
{
    while(1)
    {
        double a, min = 999, max = -1;
        cout<<"台幣換外幣-賣匯 (0)離開：";
        cin>>a;
        if(a==0) break;
        for(double num = (int)(minimum/a*20)/20; num<=(int)(minimum/a*20)/20.0+10; num+=smallest_unit)
        {
            double temp = a * num;
            if (temp < minimum-0.5) continue;
            int temp2 = temp;

            if(((int)(temp*10)%10<=4)&&temp2/num<=min)
                printf("%.5f %.2f %.5f\n",temp, num, min=temp2/num);

            /*
            if(temp - (int)(temp)<0.5 && temp - (int)(temp)>=max)
                printf("%.5f %.2f %.5f\n",temp, num, max=temp - (int)(temp));
            */
        }
    }
}

void bid()
{
    while(1)
    {
        double b, max = -1;
        cout<<"外幣換台幣-買匯 (0)離開：";
        cin>>b;
        if(b==0) break;
        for(double num = (int)(minimum/b*20)/20; num<=(int)(minimum/b*20)/20.0+10; num+=smallest_unit)
        {
            double temp = b * num;
            if (temp < minimum-0.5) continue;
            int temp2 = temp+1;

            if(((int)(temp*10)%10>=5)&&temp2/num>=max)
                printf("%.5f %.2f %.5f\n",temp, num, max=temp2/num);

        }
    }
}

void setup_min()
{
    cout<<"設定換匯門檻(單位：台幣)：";
    cin>>minimum;
}

void setup_su()
{
    cout<<"設定外幣最小單位：";
    cin>>smallest_unit;
}

int main()
{
    while (1)
    {
        cout<<"(1)台幣換外幣 (2)外幣換台幣 (3)設定換匯門檻(預設$100) (4)設定外幣最小單位(預設$0.01) (0)離開\n";
        char c = getch();
        system("cls");
        if(c == '1') ask();
        else if(c == '2') bid();
        else if(c == '3') setup_min();
        else if(c == '4') setup_su();
        else if(c == '0') exit(0);
        else continue;
        system("cls");
    }
}
