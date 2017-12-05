//Caleb Brock, COP_2000, 11/22/2017, Number guessing game
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

//prototypes
int beginGame(int);
void displayBoard(int);
bool Test_Answer_Choice(int&, int&, int);
void displayinstruction();
int Random_Number(int);
bool CheckInput(int);
bool checkforchampion(bool);

bool checkforchampion(bool Check[3])
{
    if (Check[0] && Check[1] && Check[2] == true)
    {
        cout<<"*** You are the number guessing champion!!   CONGRATULATIONS!! ***"<<endl;
        return true;
    }
    else
        return false;
}
bool CheckInput(int Input)
{
    
    if (Input>=1)
    {
        return true;
    }
    else
        return false;
}

int Random_Number(int randomNum)
{
    randomNum =( rand() % 3);
    return randomNum;
    
}

void displayBoard(int board[4][3])//FINALIZED
{
    cout<<setw(3)<<board[0][0]<<"  "<<board[0][1]<<"  "<<board[0][2]<<endl;
    cout<<setw(3)<<board[1][0]<<"  "<<board[1][1]<<"  "<<board[1][2]<<endl;
    cout<<setw(3)<<board[2][0]<<"  "<<board[2][1]<<"  "<<board[2][2]<<endl;
    cout<<setw(3)<<board[3][0]<<"  ?  "<<board[3][2]<<endl;
}

bool Test_Answer_Choice(int answer_choice, int board_number, int answerboard[3])//NEEDS TESTING
{
    
    switch (board_number)
    {
        bool status;
        case '1':
            if (answer_choice == answerboard[0])
            {
                status=true;
                return status;
            }
            else
                status=false;
                return status;
        case '2':
                if (answer_choice == answerboard[1])
                {
                    status=true;
                    return status;
                }
                else
                    status=false;
                    return status;
        case '3':
            if (answer_choice == answerboard[2])
            {
                status=true;
                return status;
            }
            else
                status=false;
                return status;

    }
}

void displayinstructions()//FINALIZED
{
    cout<<"****************************************************************************************"<<endl;
    cout<<setw(50)<<"MISSING NUMBERS GAME"<<endl;
    cout<<setw(50)<<"A fun brain game..."<<endl<<endl;
    cout<<setw(70)<<"Please Enter a whole number to guess the missing number..."<<endl;
    cout<<setw(50)<<"Program Developed by: Caleb Brock"<<endl;
    cout<<"****************************************************************************************"<<endl<<endl;
}

int main()
{
    int winnerchoice;
    int guessesmade=0;
    int randomNum=0;
    const int ROW_SIZE=4;
    const int COL_SIZE=3;
    int answerpicked;
    int display_Board_1[ROW_SIZE][COL_SIZE]={ 38, 11, 83,//Correct
                                              15, 6, 33,
                                              11, 2, 20,
                                              86, 0, 95};
    int display_Board_2[ROW_SIZE][COL_SIZE]={ 28, 10, 55,//Correct
                                              89, 17, 98,
                                              22, 4, 31,
                                              69, 0, 78};
    int display_Board_3[ROW_SIZE][COL_SIZE]={ 90, 9, 45,//Correct
                                              66, 12, 48,
                                              34, 7, 70,
                                              44, 0, 26};
    int answer_board[3]={14,15,8};//Correct
    int Available_Boards[3]={display_Board_1[ROW_SIZE][COL_SIZE], display_Board_2[ROW_SIZE][COL_SIZE], display_Board_3[ROW_SIZE][COL_SIZE]};
    bool Championcounter [3]={false, false, false};
    int NumberChosen[3]={false, false, false};
    
    replay:
    displayinstructions();
    //I can't figure it out
    //beginGame(NumberChosen[3]);
    guessesmade=0;
    checkforchampion(Championcounter);
        switch (randomNum)
    {
        case 0:
            while (guessesmade<3)
            {
            displayBoard(display_Board_1);
            caseoneinvalid:
            cout<<"Enter Guess or 0 to Exit >> ";
            cin>>answerpicked;
            CheckInput(answerpicked);
            if (answerpicked==true)
            {
                guessesmade++;
                Test_Answer_Choice(answerpicked, 1, answer_board);
                if (answerpicked==true)
                {
                    cout<<answerpicked<<"You are a number genius!!"<<endl<<endl;
                    cout<<"Do you wish to play again?? ";
                    Championcounter[0]=true;
                }
                else
                    cout<<"I am sorry that was incorrect..."<<endl;
                    goto caseoneinvalid;
            }
            else
                if (answerpicked<0)
                {
                    cout<<endl<<"Invalid input retry input"<<endl;
                    goto caseoneinvalid;
                }
                else
                    exit;
            }
        case 1:
            while (guessesmade<3)
            {
            displayBoard(display_Board_2);
            casetwoinvalid:
            cout<<"Enter Guess or 0 to Exit >> ";
            cin>>answerpicked;
            CheckInput(answerpicked);
            if (answerpicked==true)
            {
                guessesmade++;
                Test_Answer_Choice(answerpicked, 2, answer_board);
                if (answerpicked==true)
                {
                    cout<<answerpicked<<"You are a number genius!!"<<endl<<endl;
                    cout<<"Do you wish to play again?? ";
                    Championcounter[1]=true;
                    cout<<"Enter 0 to Exit or any number to contine...>>";
                    cin>>winnerchoice;
                    if (winnerchoice==0)
                    {
                    exit;
                    }
                    else
                        goto replay;
                }
                else
                    cout<<"I am sorry that was incorrect..."<<endl;
                    goto casetwoinvalid;
            }
            else
                if (answerpicked<0)
                {
                    cout<<endl<<"Invalid input retry input"<<endl;
                    goto casetwoinvalid;
                }
                else
                    exit;
            }
        case 2:
            while (guessesmade<3)
            {
            displayBoard(display_Board_3);
            casethreeinvalid:
            cout<<"Enter Guess or 0 to Exit >> ";
            cin>>answerpicked;
            CheckInput(answerpicked);
            if (answerpicked==true)
            {
                guessesmade++;
                Test_Answer_Choice(answerpicked, 2, answer_board);
                if (answerpicked==true)
                {
                    cout<<answerpicked<<"You are a number genius!!"<<endl<<endl;
                    cout<<"Do you wish to play again?? ";
                    Championcounter[2]=true;
                }
                else
                    cout<<"I am sorry that was incorrect..."<<endl;
                    goto casethreeinvalid;
            }
            else
                if (answerpicked<0)
                {
                    cout<<endl<<"Invalid input retry input"<<endl;
                    goto casethreeinvalid;
                }
                else
                    exit;
            }
    }
    cout<<"Sorry...You are out of guesses...";
    cout<<"Enter 0 to Exit or any number to contine...>>";
    cin>>winnerchoice;
    if (winnerchoice==0)
    {
    return 0;
    }
    else
        goto replay;
}

int beginGame(int NumberChosen[3])
{
    int randomNum;
    retry:
    Random_Number(randomNum);
    switch (randomNum)
    {
        case 0:
        {
            if (NumberChosen[0]==false)
            {    NumberChosen[0]=true;
                return randomNum;
            }
            else
                goto retry;
        }
        case 1:
        {
            if (NumberChosen[1]==false)
            {    NumberChosen[1]=true;
                return randomNum;
            }
            else
                goto retry;
        }
        case 2:
        {
            if (NumberChosen[2]==false)
            {    NumberChosen[2]=true;
                return randomNum;
            }
            else
                goto retry;
        }
    }
}
