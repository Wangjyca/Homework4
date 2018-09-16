#include <cstring>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>

using namespace std;

void Distribute(int []);///After put the pile of the target numer to middle position, this function distributes the 21 numbers.
void DisplayThreepiles(int[]);/// To show three piles numbers
void Setmiddlepile(int[], int);///To place the pile of the target numer to middle position


int card[21]; ///Store 21 numbers

int main()
{
	srand(time(0));
	
	char exitSign;

	char EnterPileNum; ///To get the pile number of the target number from player
	int PileNumwithTargetNum;///To record the pile number to call function Setmiddlepile(card, PileNumwithTargetNum) 
	
		do
		{
			cout << endl << endl<< "Welcome to number guessing game: " << endl;
			
		

			for (int i = 0; i < 21 ;i++)
			{
				card[i] = rand() % (4) + ((i+1) * 4); ///To make sure that there no daplicated numbers generated
			}
			DisplayThreepiles(card);


			cout << "Pick a number from above and keep it in your biran..." << endl << endl;

			cout << "Hit key 0 to start or other key to exit (0/Not 0) :";
			cin >> exitSign;

			if (exitSign !='0') 
			{return 0;}

			

			cout << endl << endl;

			for (int i = 1; i < 4; i++)
			{
					do
					{
						cout << "Prompt" << i << ": The number you chose is in pile (1/2/3): ";
						cin >> EnterPileNum;

						if (EnterPileNum != '1' && EnterPileNum != '2' && EnterPileNum != '3')
						{
							cout << "You enetred worng number. Enter again." << endl;
						}

					} while (EnterPileNum != '1' && EnterPileNum != '2' && EnterPileNum != '3');
						
						PileNumwithTargetNum = EnterPileNum -48 ;
						Setmiddlepile(card, PileNumwithTargetNum); /// To make sure the pile of the target number at middle
						//DisplayThreepiles(card);
						Distribute(card);/// distributes the 21 numbers in a new order


						 cout << endl << "I changed the numbers' order: " << endl;
						 DisplayThreepiles(card);
						
						 if (i == 3) { cout << endl << "The number you chose is " << card[10] << ".   is it right?" << endl << "=========================================="; }
			}
			 

			
		} while (exitSign == '0');

	return 0;
}

void Distribute(int card[])
{

	cout << endl;
	int j = -1;
	int k;
	int cardPiles[3][7];

	for (int i = 0; i < 21; i++)
	{
		j++;
		if (j > 2)
		{
			j = 0;
		}

		k = i / 3;
		//cout << j << '@' << k<< "    ";
		

		cardPiles[j][i / 3] = card[i];
	}

	int jj = 0;
	for (int i=0; i<3;i++)
	{ 
		for (int k=0; k < 7; k++)
		{
			card[jj] = cardPiles[i][k];
			jj++;
	    }
	}

}

void DisplayThreepiles(int[])/// To show three piles numbers
{

	int jj = 0;



	for (int i = 1; i <= 3; i++)
	{
		cout << "Pile" << i << ": ";

		for (int j = 0; j < 7; j++)
		{

			cout << setw(3) << card[jj] << "  ";
			jj++;
		}

		cout << endl;

	}

}

void Setmiddlepile(int card[], int TrgetPileNum)///To place the pile of the target numer to middle position
{

	switch (TrgetPileNum)
	{
		case 1:  ///Target pile is changed from position one to two.
			for (int i = 0; i < 7; i++)
			{
				card[i] = card[i] + card[i + 7];
				card[i + 7] = card[i] - card[i + 7];
				card[i] = card[i] - card[i + 7];
			}

			break;
		case 3:///Target pile is changed from position three to two.
			for (int i = 7; i < 14; i++)
			{
				card[i] = card[i] + card[i + 7];
				card[i + 7] = card[i] - card[i + 7];
				card[i] = card[i] - card[i + 7];
			}
			break;
		default:///Since target pile is at the middle position, nothing is to do.
		{}
	}

}