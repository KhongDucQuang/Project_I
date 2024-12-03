// Description
// The data about bank transactions consists of a sequence of transactions: the information of each transaction has the following format:
//                                                                     <from_account>   <to_account>   <money>   <time_point>   <atm>
// In which:
// •	<from_account>: the account from which money is transferred (which is a string of length from 6 to 20 )
// •	<to_account>: the account which receives money in the transaction (which is a string of length from 6 to 20)
// •	<money>: amount of money transferred in the transaction (which is an integer from 1 to 10000)
// •	<time_point>: the time point at which the transaction is performed, it is a string under the format HH:MM:SS  (hour: minute: second)
// •	<atm>: the code of the ATM where the transaction is taken (a string of length from 3 to 10)
// Example: T00112233445 T001234002 2000 08:36:25 BIDV (at the ATM BIDV, account T00112233445 transfers 2000$ to account T001234002 at time point 08:36:25 (08 hour, 36 minutes, 25 seconds) 
// A transaction cycle of length k starting from account a1 is defined to be a sequence of distinct account a1, a2, …, ak  in which there are transactions from account a1 to a2, from a2 to a3, …, from ak to a1.
// Write a program that process the following queries: 
// ?number_transactions: compute the total number of transactions of the data
// ?total_money_transaction: compute the total amount of money of transactions  
// ?list_sorted_accounts: compute the sequence of bank accounts (including sending and receiving accounts) appearing in the transaction (sorted in an increasing (alphabetical) order)  
// ?total_money_transaction_from <account>: compute the total amount of money transferred from the account <account>  
// ?inspect_cycle <account> k : return 1 if there is a transaction cycle of length k, starting from <account>, and return 0, otherwise
// Input (stdin)
// The input consists of 2 blocks of information: the data block and the query block
// •	The data block consists of lines:
// o	Each line contains the information about a transaction described above
// o	The data is terminated by a line containing #
// •	The query block consists of lines:
// o	Each line is a query described above
// o	The query block is terminated by a line containing #

// Output (stdout)
// •	Print to stdout (in each line) the result of each query described above

// Example
// Input
// T000010010 T000010020 1000 10:20:30 ATM1
// T000010010 T000010030 2000 10:02:30 ATM2
// T000010010 T000010040 1500 09:23:30 ATM1
// T000010020 T000010030 3000 08:20:31 ATM1
// T000010030 T000010010 4000 12:40:00 ATM2
// T000010040 T000010010 2000 10:30:00 ATM1
// T000010020 T000010040 3000 08:20:31 ATM1
// T000010040 T000010030 2000 11:30:00 ATM1
// T000010040 T000010030 1000 18:30:00 ATM1
// #
// ?number_transactions
// ?total_money_transaction
// ?list_sorted_accounts
// ?total_money_transaction_from T000010010
// ?inspect_cycle T000010010 3
// #
// Output
// 9
// 19500
// T000010010 T000010020 T000010030 T000010040
// 4500
// 1
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <set>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

int timeToSecond(const string& time_point) {
    return 3600 * ((time_point[0] - '0') * 10 + (time_point[1] - '0')) +
           60 * ((time_point[3] - '0') * 10 + (time_point[4] - '0')) +
           ((time_point[6] - '0') * 10 + (time_point[7] - '0'));
}

bool dfs(const string& start, const string& current, unordered_map<string, vector<string>>& graph, int depth, int k, unordered_set<string>& visited) {
    if (depth == k) {
        return current == start;
    }
    visited.insert(current);
    for (const string& neighbor : graph[current]) {
        if (visited.find(neighbor) == visited.end() || (neighbor == start && depth == k - 1)) {
            if (dfs(start, neighbor, graph, depth + 1, k, visited)) {
                return true;
            }
        }
    }
    visited.erase(current);
    return false;
}

int inspect_cycle(const string& account, int k, unordered_map<string, vector<string>>& graph) {
    unordered_set<string> visited;
    return dfs(account, account, graph, 0, k, visited) ? 1 : 0;
}

int main() {
    unordered_map<string, vector<string>> graph;
    unordered_map<string, long long> total_money_from_account;
    unordered_set<string> accounts;
    int number_transactions = 0;
    long long total_money_transaction = 0;
    string from_account, to_account, time_point, atm;
    int money;

    // Đọc dữ liệu giao dịch
    while (true) {
        cin >> from_account;
        if (from_account == "#") break;
        cin >> to_account >> money >> time_point >> atm;

        // Cập nhật dữ liệu
        number_transactions++;
        total_money_transaction += money;
        accounts.insert(from_account);
        accounts.insert(to_account);
        total_money_from_account[from_account] += money;
        graph[from_account].push_back(to_account);
    }

    // Xử lý các truy vấn
    string query;
    while (true) {
        cin >> query;
        if (query == "#") break;

        if (query == "?number_transactions") {
            cout << number_transactions << endl;
        }
        else if (query == "?total_money_transaction") {
            cout << total_money_transaction << endl;
        }
        else if (query == "?list_sorted_accounts") {
            set<string> sorted_accounts(accounts.begin(), accounts.end());
            for (const auto& account : sorted_accounts) {
                cout << account << " ";
            }
            cout << endl;
        }
        else if (query == "?total_money_transaction_from") {
            string account;
            cin >> account;
            cout << total_money_from_account[account] << endl;
        }
        else if (query == "?inspect_cycle") {
            string account;
            int k;
            cin >> account >> k;
            cout << inspect_cycle(account, k, graph) << endl;
        }
    }
    return 0;
}