// Description
// Data about sales in an e-commerce company (the e-commerce company has several shops) consists a sequence of lines, each line (represents an order) has the following information:
//             <CustomerID> <ProductID> <Price> <ShopID> <TimePoint>
// in which the customer <CustomerID> buys a product <ProductID> with price <Price> at the shop <ShopID> at the time-point <TimePoint>
// <CustomerID>: string of length from 3 to 10
// <ProductID>: string of length from 3 to 10
// <Price>: a positive integer from 1 to 1000
// <ShopID>: string of length from 3 to 10
// <TimePoint>: string representing time-point with the format HH:MM:SS (for example, 09:45:20 means the time-point 9 hour 45 minutes 20 seconds)


// Perform a sequence of queries of following types:
// ?total_number_orders: return the total number of orders
// ?total_revenue: return the total revenue the e-commerce company gets
// ?revenue_of_shop <ShopID>: return the total revenue the shop <ShopID> gets 
// ?total_consume_of_customer_shop <CustomerID> <ShopID>: return the total revenue the shop <ShopID> sells products to customer <CustomerID> 
// ?total_revenue_in_period <from_time> <to_time>: return the total revenue the e-commerce gets of the period from <from_time> to <to_time> (inclusive)

// Input
// The input consists of two blocks of data:
// The first block is the operational data, which is a sequence of lines (number of lines can be upto 100000), each line contains the information of a submission with above format 
// The first block is terminated with a line containing the character #
// The second block is the query block, which is a sequence of lines (number of lines can be upto 100000), each line is a query described above
// The second block is terminated with a line containing the character #

// Output
// Write in each line, the result of the corresponding query 

// Example
// Input
// C001 P001 10 SHOP001 10:30:10
// C001 P002 30 SHOP001 12:30:10
// C003 P001 40 SHOP002 10:15:20
// C001 P001 80 SHOP002 08:40:10
// C002 P001 130 SHOP001 10:30:10
// C002 P001 160 SHOP003 11:30:20
// #
// ?total_number_orders
// ?total_revenue
// ?revenue_of_shop SHOP001
// ?total_consume_of_customer_shop C001 SHOP001 
// ?total_revenue_in_period 10:00:00 18:40:45
// #


// Output 
// 6
// 450
// 170
// 40
// 370
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
int timeToSecond(const string& this_time) {
    return 3600 * ((this_time[0] - '0') * 10 + (this_time[1] - '0')) +
           60 * ((this_time[3] - '0') * 10 + (this_time[4] - '0')) +
           ((this_time[6] - '0') * 10 + this_time[7] - '0');
}

int main() {
    vector<pair<int, int>> revenue_timePoint;
    int total_number_orders = 0;
    long long total_revenue = 0;
    unordered_map<string, long long> revenue_of_shop;
    unordered_map<string, long long> total_consume_of_customer_shop;
    string customerID, productID, shopID, timePoint;
    int price;

    while (true) {
        cin >> customerID;
        if (customerID == "#") break;
        cin >> productID >> price >> shopID >> timePoint;

        total_number_orders++;
        total_revenue += price;
        revenue_of_shop[shopID] += price;
        total_consume_of_customer_shop[customerID + shopID] += price;

        int this_time = timeToSecond(timePoint);
        revenue_timePoint.push_back({this_time, price});
    }

    sort(revenue_timePoint.begin(), revenue_timePoint.end());
    vector<long long> prefix_sum(revenue_timePoint.size());
    prefix_sum[0] = revenue_timePoint[0].second;
    for (size_t i = 1; i < revenue_timePoint.size(); ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + revenue_timePoint[i].second;
    }
    string cmd;
    while (true) {
        cin >> cmd;
        if (cmd == "#") break;

        if (cmd == "?total_number_orders") {
            cout << total_number_orders << endl;
        } 
        else if (cmd == "?total_revenue") {
            cout << total_revenue << endl;
        } 
        else if (cmd == "?revenue_of_shop") {
            string s; cin >> s;
            cout << revenue_of_shop[s] << endl;
        } 
        else if (cmd == "?total_consume_of_customer_shop") {
            string s, v; cin >> s >> v;
            cout << total_consume_of_customer_shop[s + v] << endl;
        } 
        else if (cmd == "?total_revenue_in_period") {
            string startTime, endTime; cin >> startTime >> endTime;
            int start_time = timeToSecond(startTime);
            int end_time = timeToSecond(endTime);

            auto start_it = lower_bound(revenue_timePoint.begin(), revenue_timePoint.end(), make_pair(start_time, 0));
            auto end_it = upper_bound(revenue_timePoint.begin(), revenue_timePoint.end(), make_pair(end_time, INT_MAX));

            long long res = 0;
            if (start_it != revenue_timePoint.end() && start_it < end_it) {
                int start_index = start_it - revenue_timePoint.begin();
                int end_index = end_it - revenue_timePoint.begin() - 1;

                res = prefix_sum[end_index] - (start_index > 0 ? prefix_sum[start_index - 1] : 0);
            }
            cout << res << endl;
        }
    }

    return 0;
}
