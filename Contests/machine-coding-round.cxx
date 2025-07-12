#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int teamWillChase(int overs, vector<pair<string, int>> &team1, int teamType)
{
    int totalWickets = team1.size();
    int numOfCurrentWickets = 0;
    int totalScore = 0;
    int overCount = 0;

    // next batsmen counter
    int next = 0;

    while ((overCount < overs) && (numOfCurrentWickets != totalWickets))
    {
        cout << overCount + 1 << " over will be going now." << endl;

        int totalAttemptPerOver = 6;
        int attemptsPlayed = 0;
        int validAndInvalidBalls = 0;

        int attempt;

        // batsmen code
        bool isBatsManP1OnStrike = true;
        int batsmanP1 = 0, batsmanP2 = 1;
        int count4s = 0, count6s = 0;

        while (attemptsPlayed <= totalAttemptPerOver)
        {
            if (numOfCurrentWickets >= totalWickets)
                break;
            if (attemptsPlayed == 6)
            {
                cout << overCount + 1 << " is done !" << endl;
                cout << "Total team score of " << teamType << ": " << totalScore << endl;
                cout << "Score of batsmen-" << team1[batsmanP1].first << " => " << team1[batsmanP1].second << endl;
                cout << "Score of batsmen-" << team1[batsmanP2].first << " => " << team1[batsmanP2].second << endl;
                cout << "Total balls faced : " << validAndInvalidBalls << endl;
                validAndInvalidBalls = 0;
                ++overCount;

                cout << "Total wickets gone : " << numOfCurrentWickets << endl;
                cout << "Number of 4s : " << count4s << endl;
                cout << "Number of 6s : " << count6s << endl;
                break;
            }

            cout << "What type of attempt u wanna make ?" << endl;
            cout << "1.Wide" << ", 2.No-ball" << ", 3.Good-ball" << ", 4.Wicket" << endl;
            cin >> attempt;

            switch (attempt)
            {
            case 1: // wide
                validAndInvalidBalls++;
                cout << validAndInvalidBalls << " is a wide ball!" << endl;
                totalScore++;
                break;

            case 2: // no ball
                validAndInvalidBalls++;
                cout << validAndInvalidBalls << " is a no-ball!" << endl;
                break;

            case 3: // good ball
                validAndInvalidBalls++;
                attemptsPlayed++;
                break;

            case 4: // wicket
                validAndInvalidBalls++;
                attemptsPlayed++;
                numOfCurrentWickets++;

                next = max(batsmanP1, batsmanP2) + 1;
                if (next < totalWickets)
                {
                    if (isBatsManP1OnStrike)
                    {
                        cout << team1[batsmanP1].first << " got out. A wicket has happened !" << endl;
                        batsmanP1 = next;
                    }
                    else
                    {
                        cout << team1[batsmanP2].first << " got out. A wicket has happened !" << endl;
                        batsmanP2 = next;
                    }
                }
                break;

            default:
                cout << attempt << " does not exist please try again";
            }

            if (attempt == 3)
            {

                int batsmenChoice;
                do
                {
                    cout << " Enter the batsman choice : " << endl;
                    cout << "1. Hit 6s" << endl;
                    cout << "2. Hit 4s" << endl;
                    cout << "3. Hit 1s" << endl;
                    cout << "4. Hit 2s" << endl;
                    cout << "5. Dodge the Ball !" << endl;
                    cout << "Enter the Batsmen Choice pls : ";
                    cin >> batsmenChoice;
                    if (batsmenChoice <= 5 && batsmenChoice >= 1)
                        break;
                } while (batsmenChoice < 1 || batsmenChoice > 5);

                switch (batsmenChoice)
                {
                case 1:
                    // hit 6
                    totalScore += 6;
                    count6s += 1;
                    if (isBatsManP1OnStrike)
                    {
                        team1[batsmanP1].second += 6;
                    }
                    else
                    {
                        team1[batsmanP2].second += 6;
                    }
                    break;

                case 2:
                    // hit 4.
                    count4s += 1;
                    totalScore += 4;
                    if (isBatsManP1OnStrike)
                    {
                        team1[batsmanP1].second += 4;
                    }
                    else
                    {
                        team1[batsmanP2].second += 4;
                    }
                    break;

                case 3:
                    // hit 1a.
                    totalScore += 1;
                    if (isBatsManP1OnStrike)
                    {
                        team1[batsmanP1].second += 1;
                    }
                    else
                    {
                        team1[batsmanP2].second += 1;
                    }

                    isBatsManP1OnStrike = !isBatsManP1OnStrike;
                    break;

                case 4:
                    // hit 2s
                    totalScore += 2;
                    if (isBatsManP1OnStrike)
                    {
                        team1[batsmanP1].second += 2;
                    }
                    else
                    {
                        team1[batsmanP2].second += 2;
                    }
                    break;

                case 5:
                    if (isBatsManP1OnStrike)
                    {
                        cout << " Batsmen - " << team1[batsmanP1].first << " just dodged the ball" << endl;
                    }
                    else
                    {
                        cout << " Batsmen - " << team1[batsmanP2].first << " just dodged the ball" << endl;
                    }
                    break;
                }
            }
            else if (attempt == 1)
            {
                // wide , add +1 to corresponding batsment

                if (isBatsManP1OnStrike)
                {
                    team1[batsmanP1].second++;
                }
                else
                {
                    team1[batsmanP2].second++;
                }
            }
            attempt = -1;
        }
    }
}

int main()
{

    cout << "cricket score board" << endl;

    int N;
    cout << " Enter the number of players : ";
    cin >> N;

    vector<pair<string, int>> team1;
    vector<pair<string, int>> team2;
    string s;

    cout << endl;
    cout << "Enter the names of players(unique entry is required) for team1" << endl;
    for (int i = 1; i <= N; i++)
    {
        cin >> s;
        team1.push_back({s, 0});
    }

    cout << "Enter the names of players(unique entry is required) for team2" << endl;

    for (int i = 1; i <= N; i++)
    {
        cin >> s;
        team2.push_back({s, 0});
    }

    int overs;
    cout << "Enter total overs : ";
    cin >> overs;

    int targetOfTeam1 = teamWillChase(overs, team1, 1) + 1;

    cout << "Team 2 need to chase " << targetOfTeam1 << endl;
    int targetOfTeam2 = teamWillChase(overs, team2, 2);

    if (targetOfTeam1 > targetOfTeam2)
    {
        cout << "Team 1 is the winner !";
    }
    else
    {
        cout << "Team 2 is the winner !";
    }

    return 0;
}