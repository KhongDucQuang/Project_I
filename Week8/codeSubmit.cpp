// Description
// Data about submission of a programming contest consists a sequence of lines, each line has the following information:
//                                                       <UserID> <ProblemID> <TimePoint> <Status> <Point>
// in which the user <UserID> submits his/her code to solve the problem <ProblemID> at time-point <TimePoint>, and gets status <Status> and point <Point>
// <UserID>: string of length from 3 to 10
// <ProblemID>: string under the format Pxy where x, y are digits 0,1,...,9 (for example P03, P10)
// <TimePoint>: string representing time-point with the format HH:MM:SS (for example, 09:45:20 means the time-point 9 hour 45 minutes 20 seconds)
// <Status>: string with two cases (ERR, OK)
// <Point>: integer from {0, 1, 2, ..., 10}

// A user can submit the code for solving each problem several time. The point that the user gets for a problem is the maximal point among the submissions for that problem.

// Perform a sequence of queries of following types:
// ?total_number_submissions: return the number of submissions of the contest
// ?number_error_submision: return the number of submissions having status ERR 
// ?number_error_submision_of_user <UserID>: return the number of submission having status ERR of user <UserID> 
// ?total_point_of_user <UserID>: return the total point of user <UserID> 
// ?number_submission_period <from_time_point> <to_time_point>: return the number of submissions in the period from <from_time_point> to <to_time_point> (inclusive)

// Input
// The input consists of two blocks of data:
// The first block is the operational data, which is a sequence of lines (number of lines can be up to 100000), each line contains the information of a submission with above format .The first block is terminated with a line containing the character #
// The second block is the query block, which is a sequence of lines (number of lines can be up to 100000), each line is a query described above. The second block is terminated with a line containing the character #

// Output
// Write in each line, the result of the corresponding query 

// Example
// Input
// U001 P01 10:30:20 ERR 0
// U001 P01 10:35:20 OK 10
// U001 P02 10:40:20 ERR 0
// U001 P02 10:55:20 OK 7
// U002 P01 10:40:20 ERR 0
// U001 P01 11:35:20 OK 8
// U002 P02 10:40:20 OK 10
// #
// ?total_number_submissions
// ?number_error_submision
// ?number_error_submision_of_user U002 
// ?total_point_of_user U001 
// ?number_submission_period 10:00:00 11:30:45
// #


// Output 
// 7
// 3
// 1
// 17
// 6
#include <bits/stdc++.h>
using namespace std;

struct inforTest {
    string problemID;
    string timePoint;
    bool status;
    int score;
};
typedef struct inforTest inforTest;

unordered_map<string, vector<inforTest>> userInfor;
unordered_map<string, int> errTest;
unordered_map<string, unordered_map<string, int>> highestScoreUser;
map<string, int> scoreUser;

int sumErrorTest() {
    int result = 0;
    for(const auto& err : errTest) {
        result += err.second;
    }
    return result;
}

void calculateTotalScoreForUser(const string& checkUser) {
    scoreUser[checkUser] = 0;
    for(const auto& [problemID, maxScore] : highestScoreUser[checkUser]) {
        scoreUser[checkUser] += maxScore;
    }
}

inline int convertTime(const string& timeconvert) {
    return (timeconvert[0] - '0') * 36000 + (timeconvert[1] - '0') * 3600 +
           (timeconvert[3] - '0') * 600 + (timeconvert[4] - '0') * 60 +
           (timeconvert[6] - '0') * 10 + (timeconvert[7] - '0');
}

int checkTime(const string& startTime, const string& endTime, const vector<int>& timePoints) {
    int start = convertTime(startTime);
    int end = convertTime(endTime);
    auto under = lower_bound(timePoints.begin(), timePoints.end(), start);
    auto upper = upper_bound(timePoints.begin(), timePoints.end(), end);
    return upper - under;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> timePoints;
    int countTest = 0;

    while (true) {
        string UserID;
        cin >> UserID;
        if(UserID == "#") {
            break;
        } else {
            string ProblemID, TimePoint, Status;
            int Score;
            cin >> ProblemID >> TimePoint >> Status >> Score;
            bool statusYN = (Status == "OK");

            userInfor[UserID].push_back({ProblemID, TimePoint, statusYN, Score});

            if (!statusYN) {
                errTest[UserID]++;
            }

            if (highestScoreUser[UserID][ProblemID] < Score) {
                highestScoreUser[UserID][ProblemID] = Score;
            }

            countTest++;
            int time = convertTime(TimePoint);
            timePoints.push_back(time);
        }
    }
    sort(timePoints.begin(), timePoints.end());

    while (true) {
        string request;
        cin >> request;
        if(request == "?total_number_submissions") {
            cout << countTest << endl;
        }
        else if(request == "?number_error_submision") {
            cout << sumErrorTest() << endl;
        }
        else if(request == "?number_error_submision_of_user") {
            string checkUser;
            cin >> checkUser;
            cout << errTest[checkUser] << endl;
        }
        else if(request == "?total_point_of_user") {
            string checkUser;
            cin >> checkUser;
            if (scoreUser.find(checkUser) == scoreUser.end()) {
                calculateTotalScoreForUser(checkUser);
            }
            cout << scoreUser[checkUser] << endl;
        }
        else if(request == "?number_submission_period") {
            string startTime, endTime;
            cin >> startTime >> endTime;
            cout << checkTime(startTime, endTime, timePoints) << endl;
        }
        else if(request == "#") {
            break;
        }
    }

    return 0;
}
