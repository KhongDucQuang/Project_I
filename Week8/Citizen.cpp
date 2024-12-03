// Description
// CITIZEN
// Given a DataBase about citizen, perform queries over this DataBase.
// Input
// The input consists of two blocks: the first block is the DataBase and the second block is the list of queries. Two blocks are separated by a line containing a character *.
// 1. The first block (DataBase about citizen) consists of lines (number of lines can be upto 100000), each line is the information about a person and is under the format:
//                                    <code>  <dat_of_birth>  <fathher_code>   <mother_code>  <is_alive>  <region_code>
// in which:
//  <code>: the code of the person which is a string of length 7
//  <date_of_birth>: the date of birth of the person and has the format YYYY-MM-DD (for example 1980-02-23), <date_of_birth> is before 3000-12-31
//  <fathher_code> and <mother_code> is the code of father and mother: they are also strings of length 7. If the code is 0000000, then the current person does not has information about his father or mother
//  <is_alive>: a character with two values: ‘Y’ means that the person is still alive, and ‘N’ means tat the current person is died.
//  <region_code>: the code of the region where the person lives

// 2. The second block is the list of queries (number of queries can be upto 100000) over the DataBase which consists of following commands:
//  NUMBER_PEOPLE: return the number of people (number of lines of the DataBase)
//  NUMBER_PEOPLE_BORN_AT <date>: return the number of people having date-of-birth is equal to <date>
//  MOST_ALIVE_ANCESTOR <code>: find the most ancestor (farthest in term of generation distance) of the given person <code>. Return the generation distance between the ancestor found and the given person
//  NUMBER_PEOPLE_BORN_BETWEEN <from_date> <to_date>: compute the number of people having date-of-birth between <from_date> and <to_date> (<from_date> and <to_date> are under the form YYYY-MM-DD, <to_date> is before 3000-12-31)
//  MAX_UNRELATED_PEOPLE: find a subset of people in which two any people of the subset do not have father/mother-children and the size of the subset is maximal. Return the size of the subset found.
// The second block is terminated by a line containing ***.
// Output
//  Each line presents the result of the corresponding query (described above).
// Example
// Input
// 0000001 1920-08-10 0000000 0000000 Y 00002
// 0000002 1920-11-03 0000000 0000000 Y 00003
// 0000003 1948-02-13 0000001 0000002 Y 00005
// 0000004 1946-01-16 0000001 0000002 Y 00005
// 0000005 1920-11-27 0000000 0000000 Y 00005
// 0000006 1920-02-29 0000000 0000000 Y 00004
// 0000007 1948-07-18 0000005 0000006 Y 00005
// 0000008 1948-07-18 0000005 0000006 Y 00002
// 0000009 1920-03-09 0000000 0000000 Y 00005
// 0000010 1920-10-16 0000000 0000000 Y 00005
// *
// NUMBER_PEOPLE
// NUMBER_PEOPLE_BORN_AT 1919-12-10
// NUMBER_PEOPLE_BORN_AT 1948-07-18
// MAX_UNRELATED_PEOPLE
// MOST_ALIVE_ANCESTOR 0000008
// MOST_ALIVE_ANCESTOR 0000001
// NUMBER_PEOPLE_BORN_BETWEEN 1900-12-19 1928-11-16
// NUMBER_PEOPLE_BORN_BETWEEN 1944-08-13 1977-12-15
// NUMBER_PEOPLE_BORN_BETWEEN 1987-01-24 1988-06-03
// ***
// Output
// 10
// 0
// 2
// 6
// 1
// 0
// 6
// 4
// 0
#include <bits/stdc++.h>
using namespace std;

struct citizen{
    string birthday;
    string codeDad;
    string codeMom;
    bool is_alive;
    string codeRegion;
};
typedef struct citizen citizen;

unordered_map<string, citizen> people_data;
unordered_map<string, int> cntBirthday;
vector<string> people_code;

int findAncestor(const string &code){
	if(people_data.count(code) == 0) return 0;

    unordered_set<string> visited;
    queue<pair<string, int>> q;
    q.push({code, 0});
    int max_distance = 0;

    while(!q.empty()) {
        string current = q.front().first;
        int distance = q.front().second;
        q.pop();

        if(visited.count(current)) continue;
        visited.insert(current);

        if(people_data.count(current) && people_data[current].is_alive){
            max_distance = max(max_distance, distance);
        }

        string dad = people_data[current].codeDad;
        if(dad != "0000000" && people_data.count(dad)) {
            q.push({dad, distance + 1});
        }

        string mom = people_data[current].codeMom;
        if(mom != "0000000" && people_data.count(mom)) {
            q.push({mom, distance + 1});
        }
    }
    return max_distance;
}

int convertDate(const string& timeconvert) {
    string year = timeconvert.substr(0, 4);
    string month = timeconvert.substr(5, 2);
    string day = timeconvert.substr(8, 2);

    int time = stoi(year) * 10000 + stoi(month) * 100 + stoi(day) - 10000 * 1000;
    return time;
}

int checkTime(int startTime, int endTime, vector<int> people_dates) {
    auto under = lower_bound(people_dates.begin(), people_dates.end(), startTime);
    auto upper = upper_bound(people_dates.begin(), people_dates.end(), endTime);
    int result = upper - under;
    return result;
}

bool isBipartite(const vector<vector<int>>& graph, vector<int>& color, int node, int& seta_count, int& setb_count) {
    queue<int> q;
    q.push(node);
    color[node] = 0;
    seta_count = 1;
    setb_count = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : graph[u]) {
            if (color[v] == -1) {
                color[v] = 1 - color[u];
                if (color[v] == 0) seta_count++;
                else setb_count++;
                q.push(v);
            } else if (color[v] == color[u]) {
                return false;
            }
        }
    }
    return true;
}


int maxUnrelatedPeople(const vector<vector<int>>& graph, int n) {
    vector<int> color(n, -1);
    int maxUnrelated = 0;

    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {
            int seta_count = 0, setb_count = 0;
            if (isBipartite(graph, color, i, seta_count, setb_count)) {
                maxUnrelated += max(seta_count, setb_count);
            } else {
                return -1;
            }
        }
    }
    return maxUnrelated;
}



int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
    int cntPeople = 0;
    vector<int> people_dates;
    unordered_map<string, int> code_to_index;

    while(1){
        string code;
        cin >> code;
        if(code == "*"){
            break;
        }
        else{
            string birth;
            string codeDaddy;
            string codeMommy;
            string alive;
            string code_region;

            cin >> birth >> codeDaddy >> codeMommy >> alive >> code_region;
            bool checkLive = (alive == "Y") ? true : false;
            people_data[code] = {birth, codeDaddy, codeMommy, checkLive, code_region};
            people_code.push_back(code);
            cntBirthday[birth]++;
            cntPeople++;
            int time = convertDate(birth);
            people_dates.push_back(time);
            code_to_index[code] = cntPeople - 1;
        }
    }

    sort(people_dates.begin(), people_dates.end());
    vector<vector<int>> graph(cntPeople);


    for (auto &people : people_code) {
    int idx_people = code_to_index[people];
    string dad = people_data[people].codeDad;
    string mom = people_data[people].codeMom;

    if (code_to_index.count(dad) > 0) {
        int idx_dad = code_to_index[dad];
        graph[idx_people].push_back(idx_dad);
        graph[idx_dad].push_back(idx_people);
    }
    if (code_to_index.count(mom) > 0) {
        int idx_dad = code_to_index[mom];
        graph[idx_people].push_back(idx_dad);
        graph[idx_dad].push_back(idx_people);
    }
}


    while(1){
        string request;
        cin >> request;
        if(request == "NUMBER_PEOPLE"){
            cout << cntPeople << endl;
        }
        else if(request == "NUMBER_PEOPLE_BORN_AT"){
            string date;
            cin >> date;
            cout << cntBirthday[date] << endl;
        }
        else if(request == "MOST_ALIVE_ANCESTOR"){
            string code;
            cin >> code;
            cout << findAncestor(code) << endl;
        }
        else if(request == "NUMBER_PEOPLE_BORN_BETWEEN"){
            string startDay, endDay;
            cin >> startDay >> endDay;
            int startDate = convertDate(startDay);
            int endDate = convertDate(endDay);
            cout << checkTime(startDate, endDate, people_dates) << endl;
        }
        else if(request == "MAX_UNRELATED_PEOPLE"){
            cout << maxUnrelatedPeople(graph, cntPeople) << endl;
        }
        else if(request == "***"){
            break;
        }
    }

    return 0;
}
