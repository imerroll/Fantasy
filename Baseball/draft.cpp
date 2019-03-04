#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

struct Draft {
	int overall;
	int round;
	int pick;
};

struct Player {
	// string name, team, games, plateApp, atBats, hits, doubles, triples, homeRuns, runs, battedIn, walks, strikeouts, hitByP, stolenBases, caught, wRC, playerID, avg, obp, slg, ops, wOBA, running, fielding, offense, defense, winsAbove, avgDraft;
	// Name,Team,G,PA,AB,H,2B,3B,HR,R,RBI,BB,SO,HBP,SB,CS,AVG,OBP,SLG,OPS,wOBA,wRC+,BsR,Fld,Off,Def,WAR,ADP,playerid

  string name, team, playerID;
	int games, plateApp, atBats, hits, doubles, triples, homeRuns, runs, battedIn, walks, strikeouts, hitByP, stolenBases, caught, wRC;
	float avg, obp, slg, ops, wOBA, running, fielding, offense, defense, winsAbove, avgDraft;

};

struct Team {
	string teamName, startC, start1B, start2B, start3B, startSS, startLF, startCF, startRF, util1, util2, startP1, startP2, startP3, reliefP1, reliefP2, reliefP3, utilP1, utilP2, utilP3, utilP4, bench1, bench2, bench3, bench4, bench5;
	int runs, doubles, triples, homeRuns, battedIn, hWalks, hStrikeouts, netStolen, plateApp, pitchApp, gamesStarted, wins, losses, completeGames, pWalks, pStrikeouts, holds, qualityStarts, netSaves;
	float avg, obp, slg, innings, pERA, pWHIP, pKBB;

	/*
	C, 1B, 2B, 3B, SS, LF, CF, RF
	Util, Util
	3 SP
	3 RP
	4 P
	BN, BN, BN, BN, BN, DL, DL, DL, NA
	*/
};

class DraftTime {
	private:
	Draft* draftArr = nullptr;
	Player* playerArr = nullptr;
	Team* teamArr = nullptr;
  const int maxPlayers = 450;
	public:
	void buildArr();
	void convertString();
	void populateOrder();
	void printOrder();
	void printMenu();
	void projections();
	void importHitters();
  // void importPitchers();
	void searchPlayers();
	void teamStats();
};

int main() {
	DraftTime fantasy;

	fantasy.buildArr();
	fantasy.populateOrder();
	// fantasy.printOrder();

	fantasy.importHitters();
  // fantasy.importPitchers();
  fantasy.printMenu();
	return 0;
}

void DraftTime::buildArr()
{
	draftArr = new Draft[300];
	playerArr = new Player[maxPlayers];
}

void DraftTime::convertString()
{
/*	int strLength = catchString.length();
	for (int i = (strLength - 1); i >= 0; i--)
	{
		convInt += ((scoreEntry[i] - 48) * count);
		count *= 10;
}*/
}

void DraftTime::populateOrder()
{
	for (int i = 0; i < 300; i++)
	{
		draftArr[i].overall = i + 1;
		draftArr[i].round = (i / 12) + 1;
    draftArr[i].pick = (i % 12) + 1;

		// round...
		// overall/12
		// 36/12 = 3
		// less than 1 = round 1
		// less than 2 = round 2


	}
}

void DraftTime::printOrder()
{
	for (int i = 0; i < 36; i++)
	{
		cout << left << "Overall: " << right << setw(3) << draftArr[i].overall << " ";
		cout << left << "Round: " << right << setw(2) << draftArr[i].round << " ";
		cout << left << "Pick: " << right << setw(2) << draftArr[i].pick << endl;
	}

}

void DraftTime::printMenu()
{
	int menu;
	bool quit = false;
	do {
		cout << "\n1. Draft player\n";
		cout << "2. Show projections\n";
		cout << "3. Search player\n";
		cout << "4. Compare team stats\n";
		cout << "9. Quit\n\n";

		cout << "Enter selection: ";
		cin >> menu;
		switch (menu){
			case 1: cout << "Menu" << endl;
				break;
			case 2: projections();
				break;
			case 3: searchPlayers();
				break;
			case 4: teamStats();
				break;
			case 9: cout << "Are you sure you'd like to quit? " << endl;
			quit = true;
				break;
			default: ;
		}
	} while(!quit);
}

void DraftTime::searchPlayers()
{
	string playerSearch;

	cout << "Enter player you would like to search for: ";
	cin.ignore();
	getline(cin, playerSearch);

  for (int i = 0; i < maxPlayers; i++)
  {
    if (playerSearch == playerArr[i].name)
      cout << playerArr[i].name << ", " << playerArr[i].playerID << endl;
  }
}

void DraftTime::teamStats()
{
	// add stats and average
	// sqrt((teamstat - average) ^ 2) / (n - 1)
}

void DraftTime::projections()
{
	for (int i = 0; i < 5; i = i + 2)
	{
		cout << "\n" << left << setw(30) << playerArr[i].name << "            " << setw(30) << playerArr[i+1].name << endl;
		//      "Player:                                   Player:"
		cout << "  H  2B  3B  HR    R                        H  2B  3B  HR    R\n";
		cout << right << setw(3) << playerArr[i].hits << "  " << setw(2) << playerArr[i].doubles << "  " << setw(2) << playerArr[i].triples << "  " << setw(2) << playerArr[i].homeRuns << "  " << setw(3) << playerArr[i].runs << "                      " << setw(3) << playerArr[i+1].hits << "  " << setw(2) << playerArr[i+1].doubles << "  " << setw(2) << playerArr[i+1].triples << "  " << setw(2) << playerArr[i+1].homeRuns << "  " << setw(3) << playerArr[i+1].runs << endl;
	}
}

void DraftTime::importHitters()
{
  /*
  string name, team;
	int games, plateApp, atBats, hits, doubles, triples, homeRuns, runs, battedIn, walks, strikeouts, hitByP, stolenBases, caught, wRC, playerID;
	float avg, obp, slg, ops, wOBA, running, fielding, offense, defense, winsAbove, avgDraft;
  */

	string catchString = "";
	ifstream hittersFile;
	hittersFile.open("hitters.csv");
	// int i = 0;
	// while (hittersFile)
  for (int i = 0; i < maxPlayers; i++)
	{
		getline(hittersFile, playerArr[i].name, ',');
		getline(hittersFile, playerArr[i].team, ',');

    getline(hittersFile, catchString, ',');
    playerArr[i].games = stoi(catchString);

    getline(hittersFile, catchString, ',');
    playerArr[i].plateApp = stoi(catchString);

    getline(hittersFile, catchString, ',');
    playerArr[i].atBats = stoi(catchString);

    getline(hittersFile, catchString, ',');
    playerArr[i].hits = stoi(catchString);

    getline(hittersFile, catchString, ',');
    playerArr[i].doubles = stoi(catchString);

    getline(hittersFile, catchString, ',');
    playerArr[i].triples = stoi(catchString);

    getline(hittersFile, catchString, ',');
    playerArr[i].homeRuns = stoi(catchString);

    getline(hittersFile, catchString, ',');
    playerArr[i].runs = stoi(catchString);

    getline(hittersFile, catchString, ',');
    playerArr[i].battedIn = stoi(catchString);

    getline(hittersFile, catchString, ',');
    playerArr[i].walks = stoi(catchString);

    getline(hittersFile, catchString, ',');
    playerArr[i].strikeouts = stoi(catchString);

    getline(hittersFile, catchString, ',');
    playerArr[i].hitByP = stoi(catchString);

    getline(hittersFile, catchString, ',');
    playerArr[i].stolenBases = stoi(catchString);

    getline(hittersFile, catchString, ',');
    playerArr[i].caught = stoi(catchString);

    getline(hittersFile, catchString, ',');
    playerArr[i].avg = stof(catchString);

    getline(hittersFile, catchString, ',');
    playerArr[i].obp = stof(catchString);

    getline(hittersFile, catchString, ',');
    playerArr[i].slg = stof(catchString);

    getline(hittersFile, catchString, ',');
    playerArr[i].ops = stof(catchString);

    getline(hittersFile, catchString, ',');
    playerArr[i].wOBA = stof(catchString);

    getline(hittersFile, catchString, ',');
    playerArr[i].wRC = stoi(catchString);

    getline(hittersFile, catchString, ',');
    playerArr[i].running = stof(catchString);

    getline(hittersFile, catchString, ',');
    playerArr[i].fielding = stof(catchString);

    getline(hittersFile, catchString, ',');
    playerArr[i].offense = stof(catchString);

    getline(hittersFile, catchString, ',');
    playerArr[i].defense = stof(catchString);

    getline(hittersFile, catchString, ',');
    playerArr[i].winsAbove = stof(catchString);

    getline(hittersFile, catchString, ',');
    playerArr[i].avgDraft = stof(catchString);

    getline(hittersFile, playerArr[i].playerID);
		// i++;
	}

	cout << endl;

	for (int i = 1; i < 13; i++)
	{
		cout << playerArr[i].name << " - " << playerArr[i].team << ".\n";
	}

	hittersFile.close();
}


/*
void DraftTime::importHitters()
{

  string name, team;
	int games, plateApp, atBats, hits, doubles, triples, homeRuns, runs, battedIn, walks, strikeouts, hitByP, stolenBases, caught, wRC, playerID;
	float avg, obp, slg, ops, wOBA, running, fielding, offense, defense, winsAbove, avgDraft;


	string catchString = "";
	ifstream hittersFile;
	hittersFile.open("hitters.csv");
	// int i = 0;
	// while (hittersFile)
  for (int i = 0; i < maxPlayers; i++)
	{
		getline(hittersFile, playerArr[i].name, ',');
		getline(hittersFile, playerArr[i].team, ',');
		getline(hittersFile, playerArr[i].games, ',');
	//	playerArr[i].games = static_cast<int>(catchString);
		getline(hittersFile, playerArr[i].plateApp, ',');
		getline(hittersFile, playerArr[i].atBats, ',');
		getline(hittersFile, playerArr[i].hits, ',');
		getline(hittersFile, playerArr[i].doubles, ',');
		getline(hittersFile, playerArr[i].triples, ',');
		getline(hittersFile, playerArr[i].homeRuns, ',');
		getline(hittersFile, playerArr[i].runs, ',');
		getline(hittersFile, playerArr[i].battedIn, ',');
		getline(hittersFile, playerArr[i].walks, ',');
		getline(hittersFile, playerArr[i].strikeouts, ',');
		getline(hittersFile, playerArr[i].hitByP, ',');
		getline(hittersFile, playerArr[i].stolenBases, ',');
		getline(hittersFile, playerArr[i].caught, ',');
		getline(hittersFile, playerArr[i].avg, ',');
		getline(hittersFile, playerArr[i].obp, ',');
		getline(hittersFile, playerArr[i].slg, ',');
		getline(hittersFile, playerArr[i].ops, ',');
		getline(hittersFile, playerArr[i].wOBA, ',');
		getline(hittersFile, playerArr[i].wRC, ',');
		getline(hittersFile, playerArr[i].running, ',');
		getline(hittersFile, playerArr[i].fielding, ',');
		getline(hittersFile, playerArr[i].offense, ',');
		getline(hittersFile, playerArr[i].defense, ',');
		getline(hittersFile, playerArr[i].winsAbove, ',');
		getline(hittersFile, playerArr[i].avgDraft, ',');
		getline(hittersFile, playerArr[i].playerID);
		// i++;
	}

	cout << endl;

	for (int i = 1; i < 13; i++)
	{
		cout << playerArr[i].name << " - " << playerArr[i].team << ".\n";
	}

	hittersFile.close();
}
*/
